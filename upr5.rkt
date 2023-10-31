#lang racket

(define (accumulate op nv a b term next)
  (if (> a b) nv
      (op (term a)
          (accumulate op nv (next a) b term next))))
          
(define (accumulate-i op nv a b term next)
  (if (> a b) nv
      (accumulate-i op (op nv (term a)) (next a) b term next)))

(define (id x) x)
(define (two x) 2)

(define (!! n)
  (accumulate *
              1
              (if (odd? n) 1 2)
              n
              id
              (lambda (i) (+ i 2))))

(define (nchk n k)
  (define up 
    (accumulate *
                1
                1
                n
                id
                (lambda (i) (+ i 1))))
  (define down (accumulate *
                           1
                           1
                           (- n k)
                           id
                           (lambda (i) (+ i 1))))

  (define down2 (accumulate *
                            1
                            1
                            k
                            id
                            (lambda (i) (+ i 1))))
  (/ up (* down down2)))

(define (2^ n) (accumulate *
                           1
                           1
                           n
                           id
                           (lambda (i) (+ i 1))))

(define (all? p? a b)
  (accumulate (lambda (x y) (and x y)
                #t
                a
                b
                id
                (lambda (i) (+ i 1)))))
  
(define (any? p? a b)
  (accumulate (lambda (x y) (or x y)
                #f
                a
                b
                id
                (lambda (i) (+ i 1)))))

(define  (divisors-sum n)
  (accumulate +
              0
              1
              n
              (lambda (x) (if (= (remainder n x) 0) x 0))
              (lambda (i) (+ i 1))))

(define (count p? a b)
  (accumulate +
              0
              a
              b
              (lambda (x) (if (p? x) 1 0))
              (lambda (i) (+ i 1))))

(define  (prime? n)
  (define t (accumulate +
              0
              2
              (- n 1)
              (lambda (x) (if (= (remainder n x) 0) 1 0))
              (lambda (i) (+ i 1))))
  (if (and (> n 1) (= t 0)) #t #f))
  
  
  
  
