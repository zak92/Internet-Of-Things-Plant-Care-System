
/*
 get soil moisture from soil moisture sensor
*/

void read_current_soil_moisture_value() {
  
  soil_moisture_value= analogRead(soil_sensor_pin);
  // map soil moisture value to a percentage - for usability
  soil_moisture_value = map(soil_moisture_value,550,0,0,100);
  
  // display on serial monitor - for testing
  Serial.print("Moisture : ");
  Serial.print(soil_moisture_value);
  Serial.println("%");
  
}
