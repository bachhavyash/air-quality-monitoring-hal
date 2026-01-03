/*
 Air Quality Monitoring and Pollution Control System
 ESP32 Based
 Presented at HAL Technical Exhibition
 Author: Yash Bachhav
*/

#define AIR_SENSOR_PIN 34   // ADC pin
#define LED_PIN 2
#define BUZZER_PIN 15

int airValue = 0;
int threshold = 1800;   // ESP32 ADC range is higher than Arduino

void setup() {
  Serial.begin(115200);

  pinMode(AIR_SENSOR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  digitalWrite(LED_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);
}

void loop() {
  airValue = analogRead(AIR_SENSOR_PIN);

  Serial.print("Air Quality Sensor Value: ");
  Serial.println(airValue);

  // Check pollution level
  if (airValue > threshold) {
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(BUZZER_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);
  }

  delay(1000);
}
