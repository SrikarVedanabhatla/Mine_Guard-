#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SimpleDHT.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_HMC5883_U.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C
#define DO_PIN 3          // Pin for MQ2 gas sensor (Digital Output)
#define DHT11_PIN 2       // Pin for DHT11 sensor

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
SimpleDHT11 dht11(DHT11_PIN);
Adafruit_HMC5883_Unified mag = Adafruit_HMC5883_Unified(12345);

void setup() {
  Serial.begin(9600);

  // Initialize OLED display
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  display.display();
  delay(2000);  // Pause for 2 seconds
  display.clearDisplay();

  // Initialize HMC5883L magnetometer
  if(!mag.begin()) {
    Serial.println("HMC5883L not detected!");
    while(1);
  }

  // Setup pin mode for MQ2 sensor
  pinMode(DO_PIN, INPUT);

  // Warm up the MQ2 sensor
  Serial.println("Warming up the MQ2 sensor");
  delay(70000);  // 70 seconds warm-up time for MQ2 sensor
}

void loop() {
  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;

  // Read temperature and humidity
  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    Serial.print("DHT11 Read Error, err=");
    Serial.println(err);
    delay(1000);
    return;
  }

  // Read gas status from MQ2 sensor
  int gasState = digitalRead(DO_PIN);
  String gasStatus = (gasState == HIGH) ? "No gas detected" : "Gas detected";

  // Read direction from HMC5883L
  sensors_event_t event;
  mag.getEvent(&event);
  float heading = atan2(event.magnetic.y, event.magnetic.x);
  heading = heading * 180 / PI;
  if (heading < 0) heading += 360;

  // Display temperature on OLED
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.print("Temp: ");
  display.print((int)temperature);
  display.print(" C");
  display.display();
  delay(2000);

  // Display humidity on OLED
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("Humidity: ");
  display.print((int)humidity);
  display.print(" %");
  display.display();
  delay(2000);

  // Display gas status on OLED
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("Gas: ");
  display.println(gasStatus);
  display.display();
  delay(2000);

  // Display heading direction on OLED
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("Heading: ");
  display.print(heading);
  display.println(" deg");
  display.display();
  delay(5000);
}
