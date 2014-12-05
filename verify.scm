(module verify (verify-program)
(import chicken scheme)
(import pat)
(import atomic) (use srfi-1)

(define (verify-exp t)
  (match t
    (`(begin) => (error "empty begin"))
    (`(begin . ,exps) => (begin ;(print "verifying begin")
                                (for-each verify-exp exps)))
    (`(if ,p ,t ,e) => (begin ;(print "verifying if")
                              (for-each verify-exp (list p t e))))
    (`(if . ,rest) => (error "bad if!"))
    (`(,f . ,args) => (begin ;(print "verifying application")
                             (unless (symbol? f)
                               (error (list "bad apple" f)))
                             (verify-exp f)
                             (for-each verify-exp args)))
    (else (if (or (symbol? t) (atomic? t))
              (begin
                ;;(print "OK!")
                )
              (error (list "Invalid exp!" t))))))

(define (verify-def d)
  ;;(print "verifying definition")
  (match d
    (`(define (,name . ,args) ,body) =>
     (begin (unless (every symbol? (cons name args))
              (error (list "Invalid definition!" d)))
            (verify-exp body)))
    (else (error(list "Invalid exp!" d)))))

(define (verify-program p)
  (for-each verify-def p))

)
