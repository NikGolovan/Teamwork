(define (carre x)
  (* x x))

(define (hypothenuse cote1 cote2)
  (sqrt (+ (carre cote1) (carre cote2))))


(define (f x y)
  (+ (/ (- x 3) (+ (carre y) 1)) (/ 1 (+ (* x (carre x)) 3))))

(f 2 2)


(define (cel->far C)
  (+ (* (/ 9 5) C) 32))

(cel->far 0)


(define (distance1D A B)
  (- (if (> A B) A B) (if (> A B) B A)))

(define (distance2D xA yA xB yB)
  (hypothenuse (distance1D xA xB) (distance1D yA yB)))

(distance2D 1 1 2 5)


(define (m->s m)
  (* 60 m))

(define (h->m h)
  (* 60 h))

(define (h->s h m s)
  (+ (m->s (+ (h->m h) m)) s))

(h->s 1 30 25)


(define (moy-pond n1 c1 n2 c2)
  (/ (+ (* n1 c1) (* n2 c2)) (+ c1 c2)))

(exact->inexact (moy-pond 10 1 15 3))