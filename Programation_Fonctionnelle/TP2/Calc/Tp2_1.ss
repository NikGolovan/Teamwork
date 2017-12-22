(load "libcalc.ss")

(define (add a b)
   (if(non_zero? b)
     (add (incrementer a) (decrementer b))
     a))


(define (sou a b)
  (if (sup_egal? a b)
      (if(non_zero? b)
         (sou (decrementer a) (decrementer b))
         a)
      (begin
        (display "Erreur : ")
        (display a)
        (display " est inférieur à ")
        (display b))))

;(define (mul a b)
 ; (if (non_zero? (decrementer b))
  ;    (begin
   ;     (sup_egal? b 1)
    ;    (add (add a a) (mul a (decrementer (decrementer b)))))
     ; a))

(define (mul a b)
  (if (non_zero? (decrementer (decrementer b))
      (mul (add a a) (decrementer b))
      a))

;(mul 3 2)
(mul 4 3)