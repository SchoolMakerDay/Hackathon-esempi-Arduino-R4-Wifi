/*
Hackathon 2025
Secondaria II grado
TEST111: servo sweep
sweep di un servo collegato al pin 5
il servo si porta a 0°, fa una rotazione fino a 180° a passi di 1° poi torna a 0° a passi di 1°rileva l'accelerazione sui tre assi x,y,z e la mostra, espressa in g, sulla seriale.
*/
#include <Servo.h>  // Include the Servo library
Servo myservo;  // Create a servo object
int pos = 0;    // Variable to store the servo position

void setup() {
  myservo.attach(5);  // Attach the servo to digital pin 5
  Serial.begin(9600); // Start serial communication at 9600bps
}

void loop() {
    for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);    // tell servo to go to position in variable 'pos'
    delay(15);             // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);    // tell servo to go to position in variable 'pos'
    delay(15);             // waits 15ms for the servo to reach the position
  }
/*
  // Read the position value from the serial port
  if (Serial.available()) {
    pos = Serial.parseInt();  // Parse the integer value
  }
  // Set the servo angle to the position received
  myservo.write(pos);
  // Wait for the servo to get to the position
  delay(15); 
*/  
}
