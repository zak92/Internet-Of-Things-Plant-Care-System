/* 
Read the temperature and humidity values from the DHT11 sensor
*/
void read_temperature_humidity(){
  
   // Read temperature as Celsius (the default)
    float newTemperature = dht.readTemperature();
 
    // if temperature read failed, don't change temp value
    if (isnan(newTemperature)) {
      Serial.println("Failed to read emperature!");
    }
    else {
      temperature = newTemperature;
      Serial.print("Temperature: ");
      Serial.println(temperature);
    }
    // Read Humidity
    float newHumidity = dht.readHumidity();
    // if humidity read failed, don't change humidity value 
     if (isnan(newHumidity)) {
      Serial.println("Failed to read humidity!");
    }
    else {
      humidity = newHumidity;
      Serial.print("Humidity: ");
      Serial.println(humidity);
    }
  
}
