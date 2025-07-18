# Bluetooth_Robot_Car_deuxieme_exemple
contrôle d'un robot à deux roues via  Bluetooth. Tant que vous maintenez 'F', 'B', 'L', ou 'R', le robot continue le mouvement
Fonction stopMotors() : Arrête tous les moteurs en mettant toutes les broches à LOW
3.Logique d'arrêt automatique : Si aucune donnée n'est disponible sur le port série, le robot s'arrête
4.Commande 'S' optionnelle : Pour arrêter manuellement le robot

Comment cela fonctionne :

* Appui maintenu : Tant que vous maintenez 'F', 'B', 'L', ou 'R', le robot continue le mouvement
** Relâchement : Dès que vous relâchez (pas de nouvelle commande), Serial.available() devient false et le robot s'arrête
*** Réactivité : Sans delay, le robot réagit quasi-instantanément

Côté application Bluetooth :
Votre application devra envoyer :

La commande en continu tant que le bouton est pressé
Plus rien quand le bouton est relâché (ou envoyer 'S')

