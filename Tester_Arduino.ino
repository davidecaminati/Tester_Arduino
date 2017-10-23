/*
 
 OhmMeter project
 by Davide Caminati
 
 This example code is in the public domain.
 
 @-------------+--------  Vcc 5Volt
               |
               |
               R_nota
               |
               |
               +-------  Vx
               |
               |
               |
               R_incognita
               |
               |
 @-------------+-------  GND
               
 
 */
 // NOTA
 //vx sta a vcc come R_incognita sta a R_nota



// These constants won't change.  They're used to give names
// to the pins used:
const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to

int sensorValue = 0;        // value read from the pot

const float tensione = 5.0;
const float resistenza_nota = 10000.0;
float resistenza_incognita = 0.0;

float tensione_Vx = 0.0;
float tensione_Rnota = 0.0;
float corrente = 0.0;



void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600); 
}

void loop() {
  // read the analog input value:
  sensorValue = analogRead(analogInPin);
  
  tensione_Vx = (tensione /1024 ) * sensorValue;
  
  tensione_Rnota = tensione - tensione_Vx;
  
  corrente = tensione_Rnota / resistenza_nota;
  
  resistenza_incognita = tensione_Vx / corrente;
  
  
  
  // map it to the range of the analog out:
  //outputValue = map(sensorValue, 0, 1023, 0, 255);    

  // print the results to the serial monitor:
  Serial.print("resistenza = " );                       
  Serial.println(sensorValue);     
  Serial.print("tensione_Vx = " );                       
  Serial.println(tensione_Vx);     
  Serial.print("resistenza_incognita = " );                       
  Serial.println(resistenza_incognita);     
  delay(2000);
  // IMPORTANT
  // wait at least 2 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  delay(2);                     
}
