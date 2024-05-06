
#include <SoftwareSerial.h>
#define HM10_RX_PIN 2 // Arduino RX pin connected to HM-10 TX pin
#define HM10_TX_PIN 3 // Arduino TX pin connected to HM-10 RX pin

SoftwareSerial hm10(3, 2);

void setup() {
    Serial.begin(19200); // Serial monitor for debugging
    hm10.begin(9600);   // HM-10 module communication
    // hm10.println("AT+NAMEBedroomLed");
}

void loop() {
    // Send AT command
    
    delay(500); // Wait for module to respond

    // Read response
    while (Serial.available()) {
      hm10.print(Serial.readString());
    }
    while (hm10.available()) {
        Serial.write(hm10.read()); // Print response to serial monitor
    }

    delay(1000); // Delay before sending next command
}