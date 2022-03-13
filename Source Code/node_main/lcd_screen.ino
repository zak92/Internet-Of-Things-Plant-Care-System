/* 
this file contains functions to display the sensor data on the lcd screen 
*/
void display_data_lcd(){
  String sensorReadings = "Moisture: " + String(soil_moisture_value) + "% ";
  
  sensorReadings += "Temp: " + String(temperature) + " ";
  sensorReadings += "Hum: " + String(humidity) + "% ";
 
  scroll_text(0, sensorReadings, 250, lcdColumns);
  scroll_text(1, reservoir_level_status, 250, lcdColumns);
}

// enables scrolling on lcd screen
void scroll_text(int row, String message, int delayTime, int lcdColumns) {
  
  for (int i=0; i < lcdColumns; i++) {
    message = " " + message;  
  } 
  
  message = message + " "; 
  for (int pos = 0; pos < message.length(); pos++) {
    lcd.setCursor(0, row);
    lcd.print(message.substring(pos, pos + lcdColumns));
    delay(delayTime);
  }
}
