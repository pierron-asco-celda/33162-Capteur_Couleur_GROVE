/*
    ** Mesure valeurs couleur RVB avec filtre module Grove **
       PIN I2C Module shield GROVE
       Moniteur série -> Baud rate 9600.
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
