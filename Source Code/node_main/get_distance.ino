/* 
  get distance value in cm from the ultrasonic distance sensor 
*/

void get_distance(){
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculate the distance
  distance = duration * SOUND_VELOCITY/2; 
  
  // Prints the distance on the Serial Monitor
  Serial.print("Distance(cm): ");
  Serial.println(distance);

  delay(1000);
  
}
