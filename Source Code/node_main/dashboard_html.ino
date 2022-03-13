/* 
 *  Displays dashboard html page and user confirmation html page
*/

String get_index() {

  String html ="<!DOCTYPE html> <html> ";
  html += "<head><meta http-equiv=\"refresh\" content=\"15\"><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\"></head>";
  html += "<style> h1 {color: green;} </style>";
  
  html += "<body> <h1>Plant Care Dashboard</h1>";
  
  html +="<div><h2> Current Sensor Readings </h2>";
  
  html += "<div><h3> <strong> Current Soil Moisture(%):</strong></h3>";
  html += soil_moisture_value;
  html +=" </div>";
  html += "<div> <h3> <strong> Current Temperature(degree Celsius):</strong></h3>";
  html += temperature;
  html +=" </div>";
  html += "<div> <h3> <strong> Current Humidity(%):</strong></h3>";
  html += humidity;
  html +=" </div>";
  
  html +=" </div>";
  
  html +=" <hr>";

  html +="<div><h2> Notifications</h2>";
  
  html += "<div> <h3> <strong> Water Pump:</strong></h3>";
  html += water_pump_status;
  html +=" </div>";
  html += "<div> <h3> <strong> Water Reservoir:</strong></h3>";
  html += reservoir_level_status;
  html +=" </div>";
  html += "<div> <h3> <strong>Temperature:</strong></h3>";
  html += temperature_status;
  html +=" </div>";
  html += "<div> <h3> <strong>Humidity:</strong></h3>";
  html += humidity_status;
  html +=" </div>";

  html +=" </div>";
  
  html +=" <hr>";
 
  html +="<div><h2>Requirements Set By User</h2>";
  
  html +="<h3>Soil moisture level set by user(%):</h3>";
  html +=soil_moisture_threshold;
  html +="<h3>Temperature set by user(degree Celsius):</h3>";
  html +=temperature_threshold;
  html +="<h3>Humidity set by user(%):</h3>";
  html += humidity_threshold;
  html +="<h3> Distance set by user between the top of the reservoir and the water level (cm):</h3>";
  html += distance_threshold;
  
  html +=" </div>";

  html +=" <hr>";
 
  html +="<div><h2>Enter Plant Requirements</h2>";
  
  html += "<div><h4>Set the minimum soil moisture level required by your plant</h4>";
  html += "<form action='/setRequirements'>";
  html += "<label for='soil_moisture' name='soil_moisture'>Soil Moisture Level:</label><br>";
  html += "<input type='number' name='soil_moisture'><br>";
  html += "<input type='submit' value='Submit'></form>";
  html +=" </div>";

  html += "<div><h4>Set the minimum temperature required by your plant</h4>";
  html += "<form action='/setRequirements'>";
  html += "<label for='temperature' name='temperature'>Temperature:</label><br>";
  html += "<input type='number' name='temperature'><br>";
  html += "<input type='submit' value='Submit'></form>";
  html +=" </div>";

  html += "<div><h4>Set the minimum humidity required by your plant</h4>";
  html += "<form action='/setRequirements'>";
  html += "<label for='humidity' name='humidity'>Humidity:</label><br>";
  html += "<input type='number' name='humidity'><br>";
  html += "<input type='submit' value='Submit'></form>";
  html +=" </div>";

  html += "<div><h4>Set the maximum distance(cm) between the top of the reservoir and the water level</h4>";
  html += "<form action='/setRequirements'>";
  html += "<label for='distance' name='distance'>Distance:</label><br>";
  html += "<input type='number' name='distance'><br>";
  html += "<input type='submit' value='Submit'></form>";
  html +=" </div>";
  
  html +=" </div>";
 
  html +="</body> </html>";
  
  return html;
  
}


// displays the user confirmation page after user inputs a value in the form
String user_input_confirmation() {

  String html ="<!DOCTYPE html> <html> ";
  html += "<head><meta http-equiv=\"refresh\" content=\"15\"><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\"></head>";
  html += "<style>  </style>";
  html += "You have set the "; 
  html += inputParam + " to be: " + inputMessage;
  html += "<br><a href=\"/\">Return to Home Page</a>";
  html +="</body> </html>";
  
  return html;
  
}
