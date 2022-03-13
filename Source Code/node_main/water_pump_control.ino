/* 
  Controls the relay connected to a pump.
  The function turn_on_water_pump switches the relay on and thus the pump on
  The function turn_off_water_pump switches the relay on and thus the pump off
*/

void turn_on_water_pump() {
  digitalWrite(pump, HIGH);
  Serial.println("pump on");
  water_pump_status = "ON";
  delay(1000);  //run pump for 1 second
  delay(2000);//wait 2 seconds 
   
}

void turn_off_water_pump() {
  digitalWrite(pump, LOW);
  water_pump_status = "OFF";
  Serial.println("do not turn on pump");
  //delay(3600000); //wait 1 hour
  // wait 1 second. This is for testing, uncomment the line above when implementing
  delay(1000);
}
