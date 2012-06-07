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

//------------------------------------------------------------------------------
// Helper Function Declarations
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Global Varible Declarations
//------------------------------------------------------------------------------
NMEAGPS gps(2,3);

//------------------------------------------------------------------------------
// Setup Function - Initializes Arduino
//------------------------------------------------------------------------------
void setup() {
    Serial.begin(9600);
}

//------------------------------------------------------------------------------
// Loop Function - Arduino Program Loop
//------------------------------------------------------------------------------
void loop() {
    gps.update();
    
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

    delay(200);
}

//------------------------------------------------------------------------------
// Helper Functions
//------------------------------------------------------------------------------


//Serial.print("Time: ");
//Serial.print(_timeHour); Serial.print(":");
//Serial.print(_timeMin); Serial.print(":");
//Serial.println(_timeSec);
//
//Serial.print("Lat: ");
//Serial.println(_lat,6);
//
//Serial.print("Lon: ");
//Serial.println(_lon,6);
//
//Serial.print("# Sats: ");
//Serial.println(_nSats);
//
//Serial.print("HDOP: ");
//Serial.println(_hdop);    
//
//Serial.print("Alt: ");
//Serial.print(_alt); Serial.print(" "); Serial.println(_altUnits);
//
//Serial.print("Geoid: ");
//Serial.print(_geoid); Serial.print(" "); Serial.println(_geoidUnits);
//
//Serial.print("Check Sum: "); Serial.print(_checkSum1); Serial.println(_checkSum2);
