(module atomic (atomic?)
(import chicken scheme)

(define (atomic? t)
  (or (number? t) (boolean? t) (char? t) (string? t)))

)
