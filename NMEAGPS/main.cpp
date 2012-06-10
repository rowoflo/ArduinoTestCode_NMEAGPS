/*
 -------------------------------------------------------------------------------
 main.cpp
 NMEAGPS Project
 
 *** DESCRIPTION ***
 
 Initially created by Rowland O'Flaherty (rowlandoflaherty.com) on 5/28/12.
 
 Version 1.0
 -------------------------------------------------------------------------------
 */

//------------------------------------------------------------------------------
// Includes and Defines
//------------------------------------------------------------------------------
#include <Arduino.h>
#include <NMEAGPS.h>
#include <SoftwareSerial.h>

//------------------------------------------------------------------------------
// Helper Function Declarations
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Global Varible Declarations
//------------------------------------------------------------------------------
NMEAGPS gps(2,3);

SoftwareSerial ss(4,5);

//------------------------------------------------------------------------------
// Setup Function - Initializes Arduino
//------------------------------------------------------------------------------
void setup() {
    Serial.begin(115200);
    ss.begin(9600);
    gps.initialize();
}

//------------------------------------------------------------------------------
// Loop Function - Arduino Program Loop
//------------------------------------------------------------------------------
void loop() {
    gps.listen();
    delay(250);
    
    Serial.print("Overflow: ");
    Serial.println(gps.overflow());
    
    if (gps.update() && gps.valid()) {
        
        Serial.print("Valid: ");
        Serial.println(gps.valid());
        
        Serial.print("Time: ");
        Serial.print(gps.hour()); Serial.print(":");
        Serial.print(gps.minute()); Serial.print(":");
        Serial.println(gps.second());

        Serial.print("Lat: ");
        Serial.println(gps.latitude(),6);

        Serial.print("Lon: ");
        Serial.println(gps.longitude(),6);
        
        Serial.print("Alt: ");
        Serial.print(gps.altitude()); Serial.print(" "); Serial.println(gps.altUnits());
        
        Serial.print("Geoid: ");
        Serial.print(gps.geoid()); Serial.print(" "); Serial.println(gps.geoidUnits());
        
        Serial.print("Speed: ");
        Serial.println(gps.speed());
        
        Serial.print("Course: ");
        Serial.println(gps.course());

        Serial.print("# Sats: ");
        Serial.println(gps.numberOfSats());

        Serial.print("PDOP: ");
        Serial.println(gps.PDOP());
        
        Serial.print("HDOP: ");
        Serial.println(gps.HDOP());    

        Serial.print("VDOP: ");
        Serial.println(gps.VDOP());
        
        Serial.println();
        
    } else {
        Serial.println("No new valid GPS data ...");
    }
    
    ss.listen();
    delay(5);
    
}

//------------------------------------------------------------------------------
// Helper Functions
//------------------------------------------------------------------------------
