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
// #include <NMEAGPS.h>

#include <SoftwareSerial.h>

//------------------------------------------------------------------------------
// Helper Function Declarations
//------------------------------------------------------------------------------
int stoi(const String &str);

//------------------------------------------------------------------------------
// Global Varible Declarations
//------------------------------------------------------------------------------
SoftwareSerial gpsSerial(2,3);
String buffer;

int Ts = 250; // Sampling time

//------------------------------------------------------------------------------
// Setup Function - Initializes Arduino
//------------------------------------------------------------------------------
void setup() {
	Serial.begin(9600);
    gpsSerial.begin(4800);
    
    Serial.println("Ready to print data received\n");
}

//------------------------------------------------------------------------------
// Loop Function - Arduino Program Loop
//------------------------------------------------------------------------------
void loop() {
    String msgID;
    int msgStartInd, msgEndInd, dollarInd;
    String msg;
    
    int numOfMsg, msgNum;
    
    // Receive data stream from GPS unit
    if (gpsSerial.overflow()) {
        Serial.println("Overflow!");
        buffer = "";
    }
    
	while (gpsSerial.available()) {
        buffer += (char)gpsSerial.read();
    }
    
    
    Serial.println(buffer);
    
    // Parse string
    while (buffer.length() > 1) {
        msgStartInd = buffer.indexOf('$');
        if (msgStartInd == -1) {
            buffer = "";
            break;
        }        
        
        msgEndInd = buffer.indexOf('\n',msgStartInd);
        if (msgEndInd == -1) {
            break;
        }
        
        dollarInd = buffer.indexOf('$',msgStartInd);
        if (dollarInd != -1 && dollarInd < msgEndInd) {
            buffer = buffer.substring(dollarInd);
            msgStartInd = 0;
            msgEndInd = msgEndInd - dollarInd;
        }
        
        msgID = buffer.substring(msgStartInd+1, msgStartInd+6);
        msg = buffer.substring(msgStartInd+7,msgEndInd);
        
        Serial.println("%%%% Message %%%%");
        if (msgID == String("GPGGA")) {
            Serial.println("GPGGA");
        } else if (msgID == String("GPGSA")) {
            Serial.println("GPGSA");
        } else if (msgID == String("GPRMC")) {
            Serial.println("GPRMC");
        } else if (msgID == String("GPGSV")) {
            Serial.println("GPGSV");
        }
        Serial.println(msg);
        Serial.println();
        
        Serial.println("---- Before trim ----");
        Serial.println(buffer.length());
        Serial.print(buffer);
        
        // Trim off found message
        Serial.print("msgStartInd: "); Serial.println(msgStartInd);
        Serial.print("msgEndInd: "); Serial.println(msgEndInd);
        buffer = buffer.substring(msgEndInd+1);
        
        Serial.println("**** After trim ****");
        Serial.println(buffer.length());
        Serial.print(buffer);
        Serial.println("\n\n\n");
    }
    
    Serial.println("\n\n\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
    
    delay(Ts);
}

//------------------------------------------------------------------------------
// Helper Functions
//------------------------------------------------------------------------------
int stoi(const String &str) {
    char charBuffer[50];
    str.toCharArray(charBuffer, 50);
    return (atoi(charBuffer));
}
