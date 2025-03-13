#include <PCF8574_VGA.h>

// Define I2C address for PCF8574
#define PCF8574_ADDRESS 0x20

// Create PCF8574_VGA object
PCF8574_VGA vga(PCF8574_ADDRESS);

void setup() {
    Serial.begin(9600);
    vga.initial();             // Initialize VGA
    vga.resolution(640, 480);  // Set resolution
    vga.rotation(0);           // No rotation
    vga.displayRefreshRate(60); // Set refresh rate
}

void loop() {
    if (vga.detect()) {
        Serial.println("VGA device detected.");
        Serial.println("Identified as: " + vga.identify());
        vga.display();
        delay(5000);
        vga.sleepMode(true);
        delay(2000);
        vga.sleepMode(false);
    } else {
        Serial.println("No VGA device detected.");
    }
    delay(10000);
}