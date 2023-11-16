#lang racket

(define (count-digit d n)
  (define (loop res n)
    (cond [(= n 0) res]
          [(= d (remainder n 10)) (loop (+ res 1)
                                        (quotient n 10))]
          [else (loop res (quotient n 10))]))
  (loop 0 n))

(define (fib n)
  (cond [(= n 0) 0]
        [(= n 1) 1]
        [else (+ (fib (- n 1)) (fib (- n 2)))]))

(define (prime? n)
  (define (loop i)
    (cond [(> i (sqrt n)) #t]
          [(zero? (remainder n i)) #f]
          [else (loop (+ i 1))]))
 ; (if (<= n 1) #f)
  (and (> n 1) (loop 2)))

(define (increasing? n)
  (define (loop n rem)
    (cond [(= n 0) #t]
          [(>= (remainder n 10) rem) #f]
          [else (loop (quotient n 10) (remainder n 10))]))
(loop n n))

(define (countFirstZeros n)
  (define (loop n res)
    (cond [(= (remainder n 2) 1) res]
          [else (loop (quotient n 2) (+ res 1))]
          ))
    (loop n 0))

(define (toBinary n)
  (define zeros (countFirstZeros n))
  (define (loop n res)
    (cond [(= n 0) res]
          [else (loop (quotient n 2) (+ (* res 10) (remainder n 2)))]
          ))
  (define x (loop n 0))
  (define (reverse n res)
    (cond [(= n 0) res]
          [else (reverse (quotient n 10) (+ (* 10 res) (remainder n 10)))]
          ))
  (reverse x 0)
  (define (addZeros res num)
    (cond [(= num 0) res]
          [else (addZeros (* 10 res) (- num 1))]
          ))
  (addZeros x zeros))
