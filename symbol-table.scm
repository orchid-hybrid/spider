(module symbol-table (make-symbol-table
                      update-symbol-table!
                      lookup-symbol-table
                      add-symbol-tables!
                      join-symbol-tables)
(import chicken scheme)

(define (make-symbol-table)
  '())

(define (update-symbol-table! t s k)
  (cond ((assoc s t) => (lambda (entry) (set-cdr! entry (+ (cdr entry) k))
                                t))
        (else (cons (cons s k) t))))

;; (define (update-symbol-table t s)
;;   (if (member s t)
;;       t
;;       (cons s t)))

(define (lookup-symbol-table t s)
  (let loop ((t t)
             (i 0))
    (if (null? t)
        #f
        (if (eq? (caar t) s)
            (cons i (cdar t))
            (loop (cdr t) (+ i 1))))))

(define (add-symbol-tables! t1 t2)
  ;; mutates t2
  (if (null? t1)
      t2
      (let ((s (caar t1))
            (k (cdar t1)))
        (add-symbol-tables!
         (cdr t1)
         (update-symbol-table! t2 s k)))))

(define (join-symbol-tables t1 t2)
  ;; copy t2 so that we arent destructive
  (join-symbol-tables* t1 (map (lambda (pair) (cons (car pair) (cdr pair))) t2)))
(define (join-symbol-tables* t1 t2)
  (define (insert-maximum! sym val t)
    (let ((result (lookup-symbol-table t sym)))
      (if result
          (let ((other-val (cdr result)))
            (if (<= other-val val)
                (update-symbol-table! t sym (- val other-val))
                t
                ))
          (cons (cons sym val) t))))
  ;; take the maximum of each
  (if (null? t1)
      t2
      (join-symbol-tables* (cdr t1) (insert-maximum! (caar t1) (cdar t1) t2))))

;; #;1> (import symbol-table)
;; #;2> (define t1 (list (cons 'x 3) (cons 'y 5) (cons 'z 1)))
;; #;3> (define t2 (list (cons 'a 2) (cons 'z 3) (cons 'x 1)))
;; #;4> (join-symbol-tables t1 t2)
;; ((y . 5) (a . 2) (z . 3) (x . 3))


)
