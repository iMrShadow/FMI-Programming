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

(dependent? '(2 6 4) '(3 9 6))
(dependent? '(1 2) '(3 4))


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


(define (gauss row1 row2)
  (let [(coeff (- (/ (head row2) (head row1))))]
    (map (lambda (x y) (+ (* coeff x) y))
              row1
              row2)))

; от минали упражнения
(define (all? p? lst)
  (or (null? lst)
      (and (p? (head lst))
           (all? p? (tail lst)))))
(define (dependent?* lst1 lst2)
  (all? zero? (gauss lst1 lst2))) ;)

(define (determinant m)
  (* (head (head m))
     (if (null? (tail m)) 1
         (determinant (map (lambda (row)
                             (tail (gauss (head m) row)))
                           (tail m))))))

; Дървета
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

(define test-tree
  (make-tree 10
             (make-tree 7
                        (make-leaf 10)
                        (make-leaf 2))
             (make-tree 3
                        (make-tree 4
                                   (make-leaf 1)
                                   (make-leaf 2))
                        empty-tree)))

; Зад.1.
(define (height t)
  (if (empty-tree? t) 0
      (+ 1 (max (height (left-tree t))
                (height (right-tree t))))))

; Зад.2.
(define (get-level n t)
  (cond [(empty-tree? t) '()]
        [(= n 0) (list (root-tree t))]
        [else (append (get-level (- n 1) (left-tree t))
                      (get-level (- n 1) (right-tree t)))]))

(get-level 2 test-tree)




(define (find-longest-path t)
    (define (longer lst1 lst2)
      (if (> (length lst1) (length lst2)) lst1 lst2))
     (if (empty-tree? t) '()
         (cons (root-tree t)
       (longer (find-longest-path (left-tree t))
      (find-longest-path (right-tree t))))))
  
  ;(cond [(empty-tree? t) '()]
  ;      [(> (length (find-longest-path (left-tree t)))
  ;          (length (find-longest-path (right-tree t))))
  ;          (cons (root-tree t)
  ;                 (find-longest-path (left-tree t)))]
  ;      [else
  ;       (cons (root-tree t)
  ;             (find-longest-path (right-tree t)))]))

;  (let [(left-path (find-longest-path (left-tree t)))
;      (right-path (find-longest-path (right-tree t)))]
;  (cond [(empty-tree? t) '()]
;        [(> (length left-path) (length right-path))
;         (cons (root-tree t) left-path)]
;        [else (cons (root-tree t) right-path)])))

;  (if (empty-tree? t) '()
;      (let [(left-path (find-longest-path (left-tree t)))
;            (right-path (find-longest-path (right-tree t)))]
;        (if (> (length left-path) (length right-path))
;            (cons (root-tree t) left-path)
;            (cons (root-tree t) right-path)))))

(find-longest-path test-tree)

(define (tree-map f t)
  (if (empty-tree? t) '()
      (make-tree (f (root-tree t))
                 (tree-map f (left-tree t))
             (tree-map f (right-tree t)))))


(define (tree->list t)
  (if (empty-tree? t) '()
  (append (tree->list (left-tree t))
          (list (root-tree t))
          (tree->list (right-tree t)))))


(define (bst-insert val t)
  (cond [(empty-tree? t) (make-leaf val)]
        [(< val (root-tree t)) (make-tree
                               (root-tree t)
                               (bst-insert val (left-tree t))
                               (right-tree t))]
       [else (make-tree (root-tree t)
                        (left-tree t)
                        (bst-insert val (right-tree t)))]))

(define (tree-sort lst)
  (tree->list
   (foldr (lambda (el res) (bst-insert el res))
         empty-tree
         lst)))

(tree-sort '(2 5 4 3 6 3 1 3 3 3 7 8))
;(tree-sort test-tree)

  







