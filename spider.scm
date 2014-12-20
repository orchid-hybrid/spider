;; rlwrap csi pat.scm sequence.scm atomic.scm verify.scm assignment-form.scm spider.scm -e '(import spider)' -e '(main)'

;; TODO: renaming builtins
;; TODO: wrapping functions
;; TODO: handling invoke-closure

;; TODO:

;; (define ((struct scm) scm-main ((struct scm) e))
;;   (declare (struct scm) r0)
;;   (declare (struct scm) r1)
;;   (declare (struct scm) r2)
;;   (refcount-dec e 1)
;;   (declare (struct scm) clor3)
;;   (set! clor3 (scm-wrap-fptr f))
;;   (set! r1 (scm-string-to-vector "Hello"))
;;   (set! r2 (scm-string-to-vector "World"))
;;   (declare (type scm-fptr) clo4)
;;   (declare (struct scm) env5)
;;   (set! clo4
;;     (struct-ref
;;       (struct-ref
;;         (array-ref (struct->ref (struct-ref (struct-ref clor3 val) v) elt) 0)
;;         val)
;;       f))
;;   (set! env5
;;     (array-ref (struct->ref (struct-ref (struct-ref clor3 val) v) elt) 1))
;;   (set! r0 (clo4 env5 r1 r2))
;;   (refcount-dec-one clor3)
;;   (return r0))

;; we should realy inc env5 before passing it in I think


(module spider (main)
(import chicken scheme)
(use extras)
(use pat verify reference-count assignment-form codegen)


(define (main debug)
  (let ((file-name (car (command-line-arguments))))
    (let ((content (read-file file-name)))
      (verify-program content)
      (when debug
        (display ";; input program") (newline)
        (for-each (lambda (definition) (pretty-print definition) (newline))
                  content)
        (newline)
        (newline))

      (when debug
        (display ";; reference counting") (newline))
      (let ((content (reference-count-program debug content)))
        (when debug
          (newline)
          (newline)
          (for-each (lambda (definition) (pretty-print definition) (newline))
                    content)
          (newline)
          (newline))
        
        (let ((af (assignment-form-program content)))
          (when debug
            (display ";; assignment form") (newline)
            (for-each (lambda (definition) (pretty-print definition) (newline))
                      af)
            (newline)
            (newline))
          
          (let ((cf (gen-program af)))
            (display ";; c") (newline)
            (for-each (lambda (definition) (pretty-print definition) (newline))
                      cf))
          ))

      )))

(main #f)

)
