# 33162-Capteur Couleur GROVE

Capteur Couleur GROVE [33162](https://www.pierron.fr/capteur-de-couleur-grove.html)

<div style="text-align: justify">Module capteur de couleur compatible Grove permettant de détecter la couleur d'une source lumineuse ou d'un objet. Le capteur est composé de 16 photodiodes avec différents filtres (4 rouges, 4 verts, 4 bleus et 4 sans filtre). Ce module se raccorde sur un port I2C de la Base Shield via un câble 4 conducteur.</div>
<br>

Caractéristiques techniques :
- Alimentation : 3.3 à 6 V
- Dispose de 16 photodiodes avec différents filtres (4 rouges, 4 bleus, 4 verts et 4 sans filtre)
- Température de service : -40 à +85 °C

![L-33162](/img/L-33162.jpg)

# Installation des fichiers dans IDE Arduino:
<div style="text-align: justify">Créer un nouveau répertoire nommé "Pierron..." dans le dossier "libraries" de votre dossier Arduino.
Y placer tous les fichiers.</div>
Ou
<div style="text-align: justify">télécharger le dépôt en ZIP et dans l'IDE Arduino : Croquis / inclure bibliothèque / ajouter la bibliothèque ZIP.</div>

<div style="text-align: justify">Pour utiliser la librairie dans votre propre projet, importez-la avec  Sketch > Import Library.</div>

# Usage :
Pour l’utilisation de ce module, référez-vous aux indications présentes sur le circuit imprimé GROVE.

# Schémas :

![SCH-33162](/img/SCH-33162.jpg)
![BRD-33162](/img/BRD-33162.jpg)

# RESSOURCES À TÉLÉCHARGER :

Ressource utilisation : [TCS3472](https://github.com/pierron-asco-celda/33162-Capteur_Couleur_GROVE/blob/main/src/Datasheet_TCS3472.pdf)

# Exemple :
### Arduino / C++
```cpp
/*
    ** Mesure valeurs couleur RVB avec filtre module Grove **
       PIN I2C module shield GROVE
       Moniteur série -> Baud rate 9600.*
       La valeur du capteur de lumière ne reflète que la tendance approximative de l’intensité de la lumière, 
       elle ne représente PAS le lumen exact ainsi que la valeur de clarté.
*/

#include <Wire.h>
#include "Adafruit_TCS34725.h"

int rouge = 0;
int vert = 0;
int bleu = 0;
int clarte = 0;
int temperature = 0;
int lux = 0;

Adafruit_TCS34725 capteur = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_700MS, TCS34725_GAIN_1X);

void setup() {
  Serial.begin(9600);
  capteur.begin();
}

void loop() {
  capteur.getRawData(&rouge, &vert, &bleu, &clarte);
  temperature = capteur.calculateColorTemperature(rouge, vert, bleu);
  lux = capteur.calculateLux(rouge, vert, bleu);
  
  Serial.print("Rouge : ");
  Serial.print(rouge, DEC);
  Serial.print("; ");
  Serial.print("Vert : ");
  Serial.print(vert, DEC);
  Serial.print("; ");
  Serial.print("Bleu : ");
  Serial.print(bleu, DEC);
  Serial.println(" ");
  Serial.print("Clarté: ");
  Serial.print(clarte, DEC);
  Serial.println(" ");
  Serial.print("Température : ");
  Serial.print(temperature, DEC);
  Serial.println("° Kelvin");
  Serial.print("Flux couleur : ");
  Serial.print(lux, DEC);
  Serial.print(" lux");
  Serial.println(" ");
  Serial.println("---------------------------------------");
  delay(1000);
}
```
## À propos :
<div style="text-align: justify">*Le débit en bauds est un taux de transfert de données en unités de bits par seconde (bps). Si le débit en bauds est de 9600, cela signifie que la possibilité d’envoyer des données est de 9600 bits en une seconde. 1 caractère est identique à 1 octet.</div>
<br>
PIERRON ASCO-CELDA (https://www.pierron.fr).
