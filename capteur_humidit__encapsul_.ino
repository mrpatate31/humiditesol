// Déclaration de la classe
class SoilHumiditySensor {
  private:
    const int sensorPin; // Pin du capteur
    int sensorValue; // Valeur lue par le capteur

  public:
    // Constructeur pour initialiser le pin du capteur
    SoilHumiditySensor(int pin) : sensorPin(pin) {
      pinMode(sensorPin, INPUT); // Configuration du pin en entrée
    }

    // Méthode pour lire la valeur d'humidité du sol
    int readHumidity() {
      sensorValue = analogRead(sensorPin); // Lecture de la valeur analogique
      return sensorValue;
    }

    // Méthode pour afficher la valeur d'humidité du sol
    void printHumidity() {
      Serial.print("Humidité du sol : ");
      Serial.println(readHumidity()); // Affichage de la valeur
    }
};

// Utilisation de la classe
SoilHumiditySensor sensor(14); // Création d'un objet pour le capteur sur le pin 14

void setup() {
  Serial.begin(115200); // Initialisation de la communication série
}

void loop() {
  sensor.printHumidity(); // Affichage de la valeur d'humidité du sol
  delay(1000); // Attendre 1 seconde avant la prochaine lecture
}
