(module reference-count (reference-count-program)
(import chicken scheme)
(use pat)
(use atomic symbol-table) (use srfi-1)

;;; special forms (are some just normal functions)
;; invoke-closure
;; make-closure
;; vector [?]
;; scm-vector-ref [?]
;; scm-wrap-fptr

(define (bump-symbol-table-down t args)
  (add-symbol-tables! t
                      (map (lambda (s) (cons s -1))
                           args)))

(define (subtract-symbol-tables t tneg)
  (add-symbol-tables! t
                      (map (lambda (s) (cons (car s) (- (cdr s))))
                           tneg)))

(define (reference-count-exp* ts)
  (if (null? ts)
      (values (make-symbol-table) '())
      (call-with-values (lambda ()
                          (reference-count-exp (car ts)))
        (lambda (t1 x)
          (call-with-values (lambda ()
                              (reference-count-exp* (cdr ts)))
            (lambda (t2 xs)
              (values (add-symbol-tables! t1 t2)
                      (cons x xs))))))))

(define (reference-count-exp t)
  (match t
    (`(begin) => (error "empty begin"))
    (`(begin . ,exps) => (call-with-values (lambda () (reference-count-exp* exps))
                           (lambda (t xs)
                             (values t (cons 'begin xs)))))
    (`(if ,p ,t ,e)
     => (call-with-values (lambda () (reference-count-exp p))
          (lambda (pt po)
            (call-with-values (lambda () (reference-count-exp t))
              (lambda (tt to)
                (call-with-values (lambda () (reference-count-exp e))
                  (lambda (et eo)
                    ;; REF: This is the tricky part
                    ;; since add-symbol-tables! mutates the second arg, we pass jt in first
                    (let ((jt (join-symbol-tables tt et)))
                      (values (add-symbol-tables! jt pt)
                              `(if ,po ;; we annotate if expressions with the refcounting information each branch needs
                                   ,(subtract-symbol-tables tt jt) ,to ;; so that we can add some decrements as necessary
                                   ,(subtract-symbol-tables et jt) ,eo ;; (these numbers will always be negative)
                                   ))))))))))
    (`(if . ,rest) => (error "bad if!"))
    
    (`(make-closure ,fptr ,env) => (call-with-values (lambda () (reference-count-exp env))
                                     (lambda (t envo)
                                       (values t
                                               `(make-closure ,fptr ,envo)))))
    (`(invoke-closure . ,inv) => (call-with-values (lambda () (reference-count-exp inv))
                                   (lambda (t invo)
                                     (values t
                                             `(invoke-closure . ,invo)))))
    (`(scm-wrap-fptr ,p) => (values (make-symbol-table)
                                    `(scm-wrap-fptr ,p)))
    (`(vector . ,elts) => (call-with-values (lambda () (reference-count-exp* elts))
                            (lambda (t eltso)
                              (values t
                                      `(vector . ,eltso)))))
    (`(scm-vector-ref ,fake-env ,env ,i)
     => (call-with-values (lambda () (reference-count-exp* (list fake-env env i)))
          (lambda (t stuff)
            (let ((fake-envo (car stuff))
                  (envo (cadr stuff))
                  (io (caddr stuff)))
              (values t
                      `(scm-vector-ref ,fake-envo ,envo ,io))))))
    
    (`(,f . ,args) => (reference-count-exp* (cons f args)))
    (else (if (symbol? t)
              (values (update-symbol-table! (make-symbol-table) t 1)
                      t)
              (if (atomic? t)
                  (values (reference-count-exp* '())
                          t)
                  (begin
                    ;;(print "OK!")
                    (error (list "Invalid exp!" t))))))))

(define (reference-count-def debug d)
  ;;(print "reference-counting definition")
  (match d
    (`(define (,name . ,args) ,body) =>
     (begin (unless (every symbol? (cons name args))
              (error (list "Invalid definition!" d)))
            (call-with-values (lambda ()
                                (reference-count-exp body))
              (lambda (resulto new-body)
                (let ((result (bump-symbol-table-down resulto args)))
                  (when debug
                    (print name)
                    (print result)
                    (newline))
                  `(define (,name . ,args) ,result ,new-body)
                  )))))
    (else (error (list "Invalid exp!" d)))))

(define (reference-count-program debug p)
  (map (lambda (p) (reference-count-def debug p)) p))

)
