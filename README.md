# Mini-projet Volet Magique (technologie web & applications professionnelles)
Il s'agit d'effectuer un programme pour mesurer la luminosité ambiante d'une pièce au moyen d'une photorésistance et d'une carte Arduino. 
Ainsi que la création d'une mini interface web pour gerer la fermeture et ouverture d'un volet (dans notre cas on utilisera une Carte relais).
# Partie Arduino

## Le matériel

-Un Arduino (UNO dans mon cas).
-Une photorésistance (1M ohms).
-Une résistance (10Kohm) (marron / noir / orange).
-Une Carte relais à 2-canaux à LEDs indicateurs (5V) (Indicator Light LED Two 2 Channel Relay Module).
-Une breadboard (plaque d'essai).
-Des fils de connexion mâle / mâle pour câbler notre montage.

Nous verrons d'abord comment fonctionne une photorésistance et une carte relais, puis comment les utiliser.

## La photorésistance ?

Une photorésistance est un composant dont la résistivité dépend de la luminosité ambiante. Pour faire simple, c'est une résistance dont la valeur change en fonction de la lumière qu'elle reçoit. Pour plus d'informations: https://learn.adafruit.com/photocells
Il existe différents types de photorésistances, chacune ayant des valeurs de résistance différentes en fonction de la luminosité ambiante. On va utilisé le type le plus classique de photorésistances [[ de 1M ohms (obscurité) / 12K ohms (pleine lumière)]]. 
Le "lux" est l'unité de mesure de la lumière.

La photorésistance et son symbole:
![photoresistance](https://cloud.githubusercontent.com/assets/22649502/23108994/e8da7fdc-f714-11e6-965d-3e9b4dff0516.png)

Voici un graphe qui montre l’évolution en lux en fonction de la résistance :
![courbe](https://cloud.githubusercontent.com/assets/22649502/23108854/7a0ce532-f713-11e6-8e6d-d63227ee49d0.jpg)

Courbe lumière VS résistance [Source](https://cdn.instructables.com/FNE/0LR9/FVS7L1OF/FNE0LR9FVS7L1OF.MEDIUM.gif) .


Exemples de valeurs, [Source](https://fr.wikipedia.org/wiki/Lux_%28unit%C3%A9%29) .
![expl](https://cloud.githubusercontent.com/assets/22649502/23108896/e6ec5f16-f713-11e6-930d-dee17ef601dc.png)

## La Carte relais à deux canaux (5V) (Indicator Light LED Two 2 Channel Relay Module) ?

Il s'agit d'une carte d'interface relais à 2 canaux de niveau 5V basse et chaque canal a besoin d'un courant de 15-20 mA. Il peut être utilisé pour contrôler divers appareils et équipements avec un courant important. Il est équipé de relais à courant élevé qui fonctionnent sous AC250V 10A ou DC30V 10A. Il a une interface standard qui peut être contrôlée directement par le microcontrôleur.

![relais](https://cloud.githubusercontent.com/assets/22649502/23108922/367fd85a-f714-11e6-9fd8-506e276bca64.png)

La Carte relais à deux canaux [Cliquez ici pour en savoir plus](https://www.sunfounder.com/wiki/index.php?title=2_Channel_5V_Relay_Module)

## Montage

### Montage initial

Le but du 1er montage est de mesurer la luminosité ambiante d'une pièce et d'envoyer la valeur mesurée vers l'ordinateur via le câble USB.

![vue_shematique](https://cloud.githubusercontent.com/assets/22649502/23108944/6e6f10b4-f714-11e6-9577-0072add79ce5.png)
1er montage vue shematique

![photocellmontage](https://cloud.githubusercontent.com/assets/22649502/23108961/9b7d965c-f714-11e6-95cc-cd0efcff7fc0.png)
1ère Vue du prototypage du montage

#### Le code du programme Arduino sous [Arduino IDE](https://www.arduino.cc/en/main/software) contient:
La photoresistance et resistance 10Kohm sont connectés à A0.
La lecture analogique.
-Fonction setup(), appelée au démarrage de la carte Arduino qui contient:
    -L'envoi des informations de débogage via le moniteur Serial.
-Fonction loop(), appelée en boucle tant que la carte Arduino est alimentée qui contient:
    -Mesure de la tension sur la broche A0
    -Envoi la mesure au PC pour affichage et attends 5000ms avec conditions selon la mesure de la tension en déterminant qualitativement quelques seuils.
    
Le code est disponible dans le fichier "luminosite".

## Le résultat

Image: Capture d'écran du moniteur série

### Montage final

Dans le montage final, on a ajouté la carte relais à LEDs indicateurs:
-De l'allimentation 5V de la carte Aruino et du coté gauche de la photorésistance, on branche la carte relais en VCC.
-De GND de la carte Aruino et du coté droit de la résistance on branche la carte relais en GND.
-Si on prend le fil blanc (du GND et resistance) branché à IN1 de la carte relais, la LED indicateur en couleur rouge 1 (gauche) s'allume (IMG1).
-Si on prend le fil blanc (du GND et resistance) branché à IN2 de la carte relais, la LED indicateur couleur rouge 2 (droite) s'allume (IMG2).
comme suit:
(IMG1)
![1](https://cloud.githubusercontent.com/assets/22649502/23109088/e56bcbc0-f715-11e6-91db-d8439e09c3a8.png)

(IMG2)
![2](https://cloud.githubusercontent.com/assets/22649502/23109292/1f2a0a50-f718-11e6-90a6-1ebe7a11f0dd.png)

# Partie mini interface web

Pour lancer cette application, vous devez installer toutes les dépendances
```bash
clone ...
cd voletMagique
npm install express --save
node app.js```
![1](https://cloud.githubusercontent.com/assets/22649502/23110122/0b796922-f71f-11e6-92ea-de7fb5031ae8.png)

Inserssion Image rsulats final de la page web-controle ...

