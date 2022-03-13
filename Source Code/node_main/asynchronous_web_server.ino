/* 
  This file contains the code for the async web server and handles 
  HTTP GET requests and inputs from the user
*/


void async_web_server() {

  // get dashboard - see dashboard_html tab for get_index()
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "text/html", get_index());
  });

  // get json - see json_data tab for get_json()
  server.on("/json", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "application/json", get_json());
  });

  
  // Send a GET request 
  server.on("/setRequirements", HTTP_GET, [] (AsyncWebServerRequest *request) {
    // get input values from user
    if (request->hasParam(PARAM_SOIL_MOISTURE)) {
      inputMessage = request->getParam(PARAM_SOIL_MOISTURE)->value();
      inputParam = PARAM_SOIL_MOISTURE;
      soil_moisture_threshold = inputMessage.toInt();
    }
    else if (request->hasParam(PARAM_TEMPERATURE)) {
      inputMessage = request->getParam(PARAM_TEMPERATURE)->value();
      inputParam = PARAM_TEMPERATURE;
      temperature_threshold = inputMessage.toInt();
    }
    else if (request->hasParam(PARAM_HUMIDITY)) {
      inputMessage = request->getParam(PARAM_HUMIDITY)->value();
      inputParam = PARAM_HUMIDITY;
      humidity_threshold = inputMessage.toInt();
    
    }
    else if (request->hasParam(PARAM_DISTANCE)) {
      inputMessage = request->getParam(PARAM_DISTANCE)->value();
      inputParam = PARAM_DISTANCE;
      distance_threshold = inputMessage.toInt();
    }
    else {
      inputMessage = "No message sent";
      inputParam = "none";
    }
    
     // see dashboard_html tab for user_input_confirmation()
    request->send(200, "text/html", user_input_confirmation());
  });
}
