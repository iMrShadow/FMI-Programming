#lang racket

;(define (const c)
;  (lambda (x) c))
;(define (const x) 21)
;(define (forever-21 x) (const 21))
;(define forever-21  (const 21))

;(define (flip f)
;(lambda (x y) (f y x)))

;(define (less-than-5? x) (< x 5))

;(define (complement p)
;(lambda (x) (not (p x))))
  
;(define f (complement less-than-5?))

;(define f (compose (lambda (x) (+ x 1)) (lambda (x) (* x x))))

(define (compose f g)
  (lambda (x) (f (g x))))
;(define f (compose (lambda (x) (+ x 1)) (lambda (x) (* x x))))


(define (id x) x)

(define (repeat n f)
  (if (= n 0) id
      (compose f (repeat (- n 1) f))))
;(lambda (x) (f ((repeat (- n 1) f) x)))))

;(define f (repeat 5 (lambda (x) (+ x 1))))

(define dx 0.000001)
(define (derive f)
  (lambda (x) (/ (- (f (+ x dx)) (f x)) dx)))

(define (derive-n n f)
  (repeat n derive))
;  (lambda (x)
 ;   (if (= n 0) (derive id)
 ;       (derive-n (derive (- n 1) f))
  ;      )))
(if (= n 0)
    (derive (derive-n (- n 1) f)))








;; WWW.DRRACKET.COM/WILSON_RACKETS
