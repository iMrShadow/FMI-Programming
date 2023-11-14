#lang racket

(define head car)
(define tail cdr)

;argmax

(define (argmax f lst)
  (foldr (lambda (el res)
           (if (> (f el) (f res)) el res))
         (head lst)
         (tail lst)))

(define (argmax* f lst)
  (foldl (lambda (res el)
           (if (> (f el) (f res)) el res))
         (head lst)
         (tail lst)))

(argmax (lambda (x) (remainder x 7)) '(40 41 42 43 44))
(argmax* (lambda (x) (remainder x 7)) '(40 41 42 43 44))

;(define (amplitudes lst)
;  (car
;  (foldr (lambda (el res)
;           (let [(newMin (if res (min el (car (cdr res))) el))
;                (newMax (if res (max el (cdr (cdr res))) el))]
;          (cons (cons (- newMax newMin) (if res (car res))
;         (cons newMin newMax))))
;        #f
;        lst)))
; (amplitudes '(2 3 10 -2 3 5 -1 3))


(define (uniques lst)
(if (null? lst) '()
    (let [(res (uniques (tail)))]
      (if (member (head lst) res)
          res
          (cons (head lst) res)))))
  
(define (cons-if-not x lst)
  (if (member x lst) lst (cons x lst)))

(define (uniques** lst)
  (foldr cons-if-not '() lst))

(define (insert cmp val lst)
  (cond [(null? lst) (list val)]
        [(< val (head lst)) (const val lst)]
        [else (cons (head lst)
                    (insert val (tail lst)))]))

(define (insertion-sort lst)
  (foldl insert '() lst))

(define (longest-interval lst)
  (foldr (lambda (el res)
           (if (> (interval el) (interval res)) res el))
         (head lst)
         (tail lst)))

  
(define (interval lst)
  (- (car lst) (cdr lst)))

(define (in-range lst lst1)
  (if (and (>= (car lst) (car lst1)) (<= (cdr lst) (cdr lst1)))
      #t
      #f))
        





