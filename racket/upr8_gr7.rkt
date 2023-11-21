#lang racket

(define head car)
(define tail cdr)

(define (head-rows m) (head m))
(define (head-cols m) (map head m))
(define (tail-rows m) (tail m))
(define (tail-cols m) (map tail m))
(define (null-m? m) (or (null? m) (null? (head m))))

(define (dependent? l1 l2)
(let [(coeff (/ (head l2) (head l1)))]
  (equal? (map (lambda (x) (* x coeff)) l1)
          l2)))

(define (member-by cmp el lst)
  (cond [(null? lst) #f]
        [(cmp el (head lst)) #t]
        [else (member-by cmp el (tail lst))]))

(define (cons-if-not-by cmp x lst)
  (if (member-by cmp x lst) lst (cons x lst)))

(define (uniques-by cmp lst)
  (foldr (lambda (el res)
           (cons-if-not-by cmp el res))
         '()
         lst))


(define (pseudorank m)
  (length (uniques-by dependent? m)))

(pseudorank '((2 6 4)
              (6 3 6)
              (3 9 6)
              (8 4 8)
              (1 3 2)))


(define (tree? t)
  (or (null? t)
      (and (list? t)
           (= (length t) 3))
           (tree? (cadr t))
           (tree? (caddr t))))
(define empty-tree '())
(define (make-tree root left right) (list root left right))      ; не искаме просто (define make-tree list) - защо?
(define (make-leaf root) (make-tree root empty-tree empty-tree)) ; за удобство
(define root-tree car)
(define left-tree cadr)
(define right-tree caddr)
(define empty-tree? null?)



(define (height t)
  (cond [(empty? t) max]
        [(not (empty? (left-tree)) (idk t)]
        [(not (empty? (right-tree)) ...)]
         
    ))
  (idk t 0 0))





