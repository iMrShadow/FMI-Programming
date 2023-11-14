#lang racket

;cons - ( , )
;car left (head)
;cdr right
;(cons 10 '())
;(list 2 1 1 1 1 )
;'(2 3 5 8) if exists
;(length '(3 2 5 10))
;(map sq '(5 1 3)) //prilaga sq vurhu lista
;(filter even? '(1 2 3 4)) - vrusha spisuk (even? e predicat)
;(foldr + 0 '(1 2 3)) - accumulate za spisuk

(define head car)
(define tail cdr)

(define (length* lst)
  (if (null? lst)
      0
      (+ 1 (length* (tail lst)))))
  
(define (length** lst)
  (define (loop lst res)
    (if (null? lst)
        res
        (loop (tail lst) (+ res 1))))
  (loop lst 0))


(define (reverse* lst)
  (define (loop lst res)
    (if (null? lst)
      res
      (loop (tail lst)
            (cons (head lst) res))))
  (loop lst '()))

(define (foldr op nv lst)
  (if (null? lst) nv
      (op (head lst)
          (foldr op nv (tail lst)))))

(define (drop n lst)
  (define (loop lst res i)
    (cond [(null? lst) res]
          [(>= i n) (loop
                 (tail lst)
                 (cons (head lst) res)
                 (+ 1 i))]
          [else (loop
                 (tail lst)
                 res
                 (+ 1 i))
                ]))
  (reverse (loop lst '() 0)))

(define (take n lst)
  (define (loop lst res i)
    (cond [(null? lst) res]
          [(>= i n) res]
          [else (loop
                 (tail lst)
                 (cons (head lst) res)
                 (+ 1 i))
                ]))
  (if (zero? n) lst
  (reverse (loop lst '() 0))))




(define (all? p? lst)
  (define lst1(filter p? lst))
  (if (null? lst1) #t #f))

(define (any? p? lst)
  (define lst1 (filter p? lst))
  (if (zero? (length lst1)) #t #f))

(define (zip lst1 lst2)
   (define (loop lst1 lst2 res i)
    (cond [(or (null? lst1) (null? lst2)) res]
          [(or (>= (length lst1) i) (>= (length lst1) i)) res]
          [else (loop
                 (tail lst1)
                 (tail lst2)
                 (cons ((cons ((head lst1) (head lst2)))) res)
                 (+ 1 i))
                ]))
  (reverse (loop lst1 lst2 '() 0)))

