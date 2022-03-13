
/* 

 This is the main implementation file with only two functions - setup() and loop()

*/

#include "Arduino.h"
#include <ESP8266WiFi.h>

#ifdef ESP8266
#include "Hash.h"
#include <ESPAsyncTCP.h>
#else
#include <AsyncTCP.h>
#endif

#include <ESPAsyncWebServer.h>

#include <AsyncElegantOTA.h>

#include <EMailSender.h>

#include <ArduinoJson.h>

#include <Adafruit_Sensor.h>
#include <DHT.h>

#include <LiquidCrystal_I2C.h>



// Replace with your network credentials
const char* ssid = "AA";
const char* password = "0823971796";

AsyncWebServer server(80);

// input parameters to form elements on dashboard
String inputMessage;
String inputParam;
const char* PARAM_SOIL_MOISTURE = "soil_moisture";
const char* PARAM_TEMPERATURE = "temperature";
const char* PARAM_HUMIDITY = "humidity";
const char* PARAM_DISTANCE = "distance";

// Allocate the JSON document
// Allows to allocated memory to the document dinamically.
DynamicJsonDocument doc(1024);

// soil moisture sensor variables
int soil_sensor_pin = A0; 
int soil_moisture_value;

// digital pin where the relay is plugged in
const int pump = 16;      

// ultrasonic sensor variables:
#define SOUND_VELOCITY 0.034
#define CM_TO_INCH 0.393701
long duration;
int distance;
// Initialise ultrasonic sensor pins
const int trigPin = D7;
const int echoPin = D5; 


// Initialise the DHT11 Temperature and Humidity pin
const int temp_hum_pin = D6;
// Initialise variables to store the temperature and humidity values
float temperature = 0.0;
float humidity = 0.0;

// Initialise the DHT11 component
#define DHTTYPE  DHT11
DHT dht(temp_hum_pin, DHT11);

// thresholds
int soil_moisture_threshold = 10;
int temperature_threshold = 40;
int humidity_threshold = 60;
int distance_threshold = 9;

// status
String water_pump_status;
String reservoir_level_status;
String temperature_status;
String humidity_status;

// set email credentials
const char* email_address = "iotplantcare8266@gmail.com";
const char* email_password = "plantcareIOT8266";
// Initialize emailsender
EMailSender emailSend(email_address ,email_password);

// set the LCD number of columns and rows
int lcdColumns = 16;
int lcdRows = 2;

// set LCD address, number of columns and rows
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);  

// time intervals for DHT11 readings
unsigned long previousMillis = 0;
const long interval = 10000;  


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  
  WiFi.mode(WIFI_STA);
  
  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
 

  // Print ESP Local IP Address
  Serial.println(WiFi.localIP());

  // initialize pins
  pinMode(soil_sensor_pin, INPUT);  
  pinMode(pump, OUTPUT);

  // Start the dht component reading
  dht.begin();
  
  // initialize LCD
  lcd.begin(lcdColumns, lcdRows);
  lcd.init();
  // turn on LCD backlight                      
  lcd.backlight();

  // Start ElegantOTA
  AsyncElegantOTA.begin(&server);

  // see asynchronous_we_server tab
  async_web_server();
  server.begin();

   
}

void loop() {
  // put your main code here, to run repeatedly:

  // OTA
  AsyncElegantOTA.loop();

  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    // save the last time you updated the DHT values
    previousMillis = currentMillis;
    // read temperature and humidity readings - see read_temperature_humidity tab
    read_temperature_humidity();
  }

  // get distance from ultrasonic sensor - see get_distance tab
  get_distance();

  // if the distance reading is less than the threshold
  if (distance < distance_threshold) {
    reservoir_level_status = "Water reservoir is sufficient";
    Serial.println(reservoir_level_status);
  }
  else {
    reservoir_level_status = "Water in reservoir is not sufficient. Please fill water into the reservoir";
    Serial.println(reservoir_level_status);
    //send email to user - see send_email tab
    send_email();
  }

  // if the temp reading is less than the threshold
  if(temperature < temperature_threshold) {
    temperature_status = "The air temperature surrounding the plant is too low. Please move the plant to a warmer area";
  }
  else {
     temperature_status = "The air temperature surrounding the plant is sufficient";
  }

  // if the humidity reading is less than the threshold
   if(humidity < humidity_threshold) {
     humidity_status = "The air humidity is too low. Place a humidity tray next to the plant ";
  }
  else {
     humidity_status = "The air humidity surrounding the plant is sufficient";
  }

  // get soil moisture - see read_current_soil_moisture tab
  read_current_soil_moisture_value();

  // if the soil moisture reading is less than the threshold
  if (soil_moisture_value < soil_moisture_threshold) {
    // see water_pump_control tab
    turn_on_water_pump();
  }
  else {
    turn_off_water_pump();
  }
 
  // show data on lcd screen - see lcd_screen tab
  display_data_lcd();

  // Readings will be captured every hour - Enable in production; disable for testing
  //delay(3600000); 

}







 
