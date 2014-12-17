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

(define (reference-count-exp* ts)
  (if (null? ts)
      (make-symbol-table)
      (let ((t1 (reference-count-exp (car ts)))
            (t2 (reference-count-exp* (cdr ts))))
        (join-symbol-tables t1 t2))))

(define (reference-count-exp t)
  (match t
    (`(begin) => (error "empty begin"))
    (`(begin . ,exps) => (begin ;(print "reference-counting begin")
                                (reference-count-exp* exps)))
    (`(if ,p ,t ,e) => (begin ;(print "reference-counting if")
                              (reference-count-exp* (list p t e))))
    (`(if . ,rest) => (error "bad if!"))
    
    (`(make-closure ,fptr ,env) => (reference-count-exp env))
    (`(invoke-closure . ,inv) => (reference-count-exp inv))
    (`(scm-wrap-fptr ,p) => (reference-count-exp* '()))
    (`(vector . ,elts) => (reference-count-exp* elts))
    (`(scm-vector-ref ,fake-env ,env ,i) => (reference-count-exp* (list fake-env env i)))
    
    (`(,f . ,args) => (begin (reference-count-exp* (cons f args))))
    (else (if (symbol? t)
              (update-symbol-table! (make-symbol-table) t 1)
              (if (atomic? t)
                  (reference-count-exp* '())
                  (begin
                    ;;(print "OK!")
                    
                    (error (list "Invalid exp!" t))))))))

(define (reference-count-def d)
  ;;(print "reference-counting definition")
  (match d
    (`(define (,name . ,args) ,body) =>
     (begin (unless (every symbol? (cons name args))
              (error (list "Invalid definition!" d)))
            (let ((result (reference-count-exp body)))
              (print name)
              (print result)
              (newline)
              )))
    (else (error(list "Invalid exp!" d)))))

(define (reference-count-program p)
  (for-each reference-count-def p))

)
