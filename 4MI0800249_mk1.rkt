#lang racket

(define head car)
(define tail cdr)

(define (accumulate op nv a b term next)
  (if (> a b) nv
      (op (term a)
          (accumulate op nv (next a) b term next))))

(define (accumulate-i op nv a b term next)
  (if (> a b) nv
      (accumulate-i op (op nv (term a)) (next a) b term next)))

(define (path1 i)
  (cond [(= i 1) (cons -7 2)]
        [(= i 2) (cons 3 -3)]
        [(= i 3) (cons 1 5)]))

(define (id x) x)

(define (destination f n)
  (define x (accumulate
             +
             0
             0
             n
             (head (f id)) ;i want to take the left value
             (lambda (i) (+ i 1))))
  (define y (accumulate
             +
             0
             0
             n
             (head (tail (f id))) ;i want to take the right value
             (lambda (i) (+ i 1))))
  (cons x y))

(define (pow x) (* x x))

(define  (path-length f n)
  (define (loop f n res i)
  (cond [(> i n) res]
        [else (loop f n (+ (sqrt (+ (pow (head (f i))) (pow (head (tail (f i)))))) res) (+ i 1))]))
 (loop f n 0 0))

(define (destination* f n bounds)
  (define x (accumulate
             +
             0
             0
             n
              (if (< (head bounds) (head (f id))) (head (f id)) 0) ;i want to take the left value 
             (lambda (i) (+ i 1))))
  (define y (accumulate
             +
             0
             0
             n
             (if (< (head (tail bounds)) (head (tail (f id))))(head (tail (f id))) 0) ;i want to take the right value
             (lambda (i) (+ i 1))))
  (cons x y))
  

  
  