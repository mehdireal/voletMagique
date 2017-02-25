/**
 * @authors Imane ZEROUALI
 *          Narimane BENHELLAL
 *          Mohamed El-Mehdi TIOUITCHI
 *          Abdousamad MOUSA ELMI
 **/

/**Scénario d'un simple test photo-cellulaire.
  *Connection d'une extrémité de la photoresistance à 5V, l'autre extrémité à l'Analogique 0.
  * Ensuite, la connection d'une extrémité d'une résistance 10K de l'analogique 0 à la masse.
  **/

int photocellulePin = A0; // La photoresistance et resistance 10Kohm sont connectés à A0.
int photocelluleLecture; // La lecture analogique.

// Fonction setup(), appelée au démarrage de la carte Arduino.
void setup(void) {
    Serial.begin(9600); // L'envoi des informations de débogage via le moniteur Serial.
}

// Fonction loop(), appelée en boucle tant que la carte Arduino est alimentée.
void loop(void) {
  photocelluleLecture = analogRead(photocellulePin);  // Mesure de la tension sur la broche A0
  //Serial.print("Lecture analogique = ");
  
  // Envoi la mesure au PC pour affichage et attends 5000ms
  Serial.print(photocelluleLecture);
  
  // Conditions d'affichage selon la mesure de la tension en déterminant qualitativement quelques seuils.
  if (photocelluleLecture < 10) {
    Serial.println(" - Noir");
  } else if (photocelluleLecture < 200) {
    Serial.println(" - Sombre");
  } else if (photocelluleLecture < 500) {
    Serial.println(" - Faiblement lumineux");
  } else if (photocelluleLecture < 800) {
    Serial.println(" - Lumineux");
  } else {
    Serial.println(" - Tres lumineux");
  }
  delay(5000); //delai de 5000ms
}
