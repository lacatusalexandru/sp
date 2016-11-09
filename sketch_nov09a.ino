#include <SoftwareSerial.h>
#include <Servo.h>


int sensorPinRight = 0; // Senzorul din dreapta
int sensorPinCenter = 1; // Senzorul din centru
int sensorPinLeft = 2; // Senzorul din stanga

int lightTolerance = 1000;

int lightReadingRight;
int lightReadingCenter;
int lightReadingLeft;
// Variabile pentru citirea intensitatii luminoase

int readingDelay = 100;
// Delay-ul pus intre citiri

int Motor1A = 8; // Declar pinii in care au fost plasati motoarele
int Motor1B = 9;
int Motor2A = 10;
int Motor2B = 11;

void setup()
{
// Se stocheaza intensitatea citita in variabila respectiva
lightReadingRight = analogRead(sensorPinRight);
lightReadingCenter = analogRead(sensorPinCenter);
lightReadingLeft = analogRead(sensorPinLeft);

  pinMode( Motor1A, OUTPUT );  // Motorul din dreapta
  pinMode( Motor1B, OUTPUT );
  pinMode( Motor2A, OUTPUT );  // Motorul din stanga
  pinMode( Motor2B, OUTPUT );
  
  digitalWrite( Motor1A, LOW );
  digitalWrite( Motor1B, LOW );
  digitalWrite( Motor2A, LOW );
  digitalWrite( Motor2B, LOW );
}

void loop()
{
      if(lightReadingRight < lightTolerance ||
      lightReadingCenter < lightTolerance ||
      lightReadingLeft < lightTolerance )
      {
        digitalWrite( Motor1A, LOW );
        analogWrite( Motor1B, LOW );
        
        digitalWrite( Motor2A, LOW );
        analogWrite( Motor2B, LOW );
      }
        if(lightReadingCenter > lightTolerance)
        {
          digitalWrite( Motor1A, HIGH );
          analogWrite( Motor1B, 50 );

          digitalWrite( Motor2A, HIGH );
          analogWrite( Motor2B, 50 );
        }

        if(lightReadingLeft > lightTolerance)
        {
          digitalWrite( Motor2B, HIGH );
          analogWrite( Motor2A, 50 );
        }
        
        if(lightReadingLeft > lightTolerance)
        {
          digitalWrite( Motor1B, HIGH );
          analogWrite( Motor1A, 50 );
        }

}

