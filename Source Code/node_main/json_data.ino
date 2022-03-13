/* 
  This file creates a JSON object of the sensor data
*/

//Utility function to send JSON data
String get_json(){
  // Create JSON data
  jsonData();
  // Make JSON data ready for the http request
  String jsonStr;
  serializeJsonPretty(doc, jsonStr);

  return jsonStr;
}


void jsonData(){

  // Add JSON request data
  doc["Content-Type"] = "application/json";
  doc["Status"] = 200;
  
  // Add distance sensor JSON object data
  JsonObject sensor_data  = doc.createNestedObject("Current Sensor Data");
  // Add distance sonsor JSON data to the object
  sensor_data["Current Soil Moisture Value"] = soil_moisture_value;
  sensor_data["Current Temperature Value"] = temperature;
  sensor_data["Current Humidity Value"] = humidity;
  
  JsonObject notifications  = doc.createNestedObject("Notifications");
  
  notifications["Water Pump Status"] = water_pump_status;
  notifications["Reservoir Level Status"] = reservoir_level_status;
  notifications["Temperature Status"] = temperature_status;
  notifications["Humidity Status"] = humidity_status;
  
  JsonObject plant_requirements  = doc.createNestedObject("Plant Requirements  Set by User");
  
  plant_requirements["Minimum Soil Moisture Level"] = soil_moisture_threshold;
  plant_requirements["Minimum Temperature"] = temperature_threshold;
  plant_requirements["Minimum Humidity"] = humidity_threshold;
  plant_requirements["Maximum Distance"] = distance_threshold;

}
