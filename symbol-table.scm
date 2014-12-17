(module symbol-table (make-symbol-table
                      update-symbol-table!
                      lookup-symbol-table
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
            (cons i (cdr t))
            (loop (cdr t) (+ i 1))))))

(define (join-symbol-tables t1 t2)
  ;; mutates t2
  (if (null? t1)
      t2
      (let ((s (caar t1))
            (k (cdar t1)))
        (join-symbol-tables
         (cdr t1)
         (update-symbol-table! t2 s k)))))



)
