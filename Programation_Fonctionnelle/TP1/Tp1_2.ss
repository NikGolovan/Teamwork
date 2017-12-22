(define TVA_GL 12.5)

(define (prixttc1 TVA HT)
  (+ HT (/ (* TVA HT) 100)))

(prixttc1 10 2.10)

(newline)

(define (prixttc2 TVA HT)
  (display "Prix HT  : ")
  (display HT)
  (newline)
  (display "TVA      : ")
  (display TVA)
  (newline)
  (display "---------------")
  (newline)
  (display "Prix TTC : ")
  (display (+ HT (/ (* TVA HT) 100)))
  (newline))

(prixttc2 10 2.10)

(newline)

(define (prixttc3 HT)
  (display "Prix HT  : ")
  (display HT)
  (newline)
  (display "TVA      : ")
  (display TVA_GL)
  (newline)
  (display "---------------")
  (newline)
  (display "Prix TTC : ")
  (display (+ HT (/ (* TVA_GL HT) 100)))
  (newline))

(prixttc3 2.10)

(newline)

(define (prixttc4)
  (display "Prix HT : ")
  (define HT (read))
  (display "Prix HT  : ")
  (display HT)
  (newline)
  (display "TVA      : ")
  (display TVA_GL)
  (newline)
  (display "---------------")
  (newline)
  (display "Prix TTC : ")
  (display (+ HT (/ (* TVA_GL HT) 100)))
  (newline))

(prixttc4)




(define (emballer_100 D)
  (display (quotient D 100))
  (display " boite(s) de 100 remplie(s)")
  (newline)
  (remainder D 100))

(emballer_100 180)


(define (emballer_50 D)
  (display (quotient D 50))
  (display " boite(s) de 50 remplie(s)")
  (newline)
  (remainder D 50))

(emballer_50 180)



(define (emballer_10 D)
  (display (quotient D 10))
  (display " boite(s) de 10 remplie(s)")
  (newline)
  (remainder D 10))

(emballer_10 180)


(define (emballer_tout D)
  (emballer_10 (emballer_50 (emballer_100 D)))
  (newline)
  (display "Emballage terminé !")
  (newline))

(emballer_tout 280)

(newline)

(define (menu a b c)
  (display "MENU")
  (newline)
  (display "----")
  (newline)
  (newline)
  (display "1 : ")
  (display a)
  (newline)
  (display "2 : ")
  (display b)
  (newline)
  (display "3 : ")
  (display c)
  (newline)
  (newline)
  (display "Votre choix : ")
  (read))

(menu "Lire" "Ecrire" "Quitter")
  