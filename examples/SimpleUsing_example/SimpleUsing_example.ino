#include <Wire.h>
#include <SFE_BMP180.h>

BMP180 bmp;

void setup() {
  Serial.begin(115200);
  bmp.begin();
}

void loop() {
  bmp.tick();
	static uint32_t lastMillis = millis();
  if (millis() - lastMillis >= 1000) {
    lastMillis = millis();
    Serial.printf("Temperature: %.3f C, Pressure: %.3f mmHg\n", bmp.getTemperature(), bmp.getMmHg());
  }
}
