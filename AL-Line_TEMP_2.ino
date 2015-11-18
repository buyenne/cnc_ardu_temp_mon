#include <UTFT.h>
#include <OneWire.h>
#include <DallasTemperature.h>
//#include <Inconsola.c>

// Data wire is plugged into port 2 on the Arduino
#define ONE_WIRE_BUS 8
// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS); 
// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);
// Declare which fonts we will be using
extern uint8_t SmallFont[];
extern uint8_t Inconsola[];
UTFT myGLCD(ITDB32S,38,39,40,41);
// Testeintrag. Weitere Möglichkeit die Sensoren anzusprechen. Müssen vorher mit einem andere Skript ausgelesen werden.
DeviceAddress Sensor1 = {0x28, 0x2C, 0x3D, 0x74, 0x06, 0x00, 0x00, 0xCA};
// min / max Werte Setzten
float tempA_min = 100;
float tempA_max = 0;
float tempB_min = 100;
float tempB_max = 0;
float tempC_min = 100;
float tempC_max = 0;
float tempD_min = 100;
float tempD_max = 0;
float tempE_min = 100;
float tempE_max = 0;
float tempF_min = 100;
float tempF_max = 0;

void setup(void)
{

// Setup the LCD
  myGLCD.InitLCD();
  myGLCD.setFont(SmallFont);
  //myGLCD.setFont(BigFont);
  myGLCD.clrScr();
  
// start serial port
  Serial.begin(9600);
 
// Start up the library
  sensors.begin();

 }
  
  void loop(void)
{
  // request to all devices on the bus
  Serial.print("Requesting temperatures...");
  sensors.requestTemperatures(); // Send the command to get temperatures
  Serial.println("DONE");  
  Serial.print("Temperature for the device 1 (index 0) is: ");
  Serial.println(sensors.getTempCByIndex(0));
  Serial.println(sensors.getTempCByIndex(1));
  Serial.println(sensors.getTempCByIndex(2));
  Serial.println(sensors.getTempCByIndex(3));
  Serial.println(sensors.getTempCByIndex(4));
  Serial.println(sensors.getTempCByIndex(5));
  // alternative zum Temp holen
  Serial.println(sensors.getTempC(Sensor1));
  
  float tempA = sensors.getTempCByIndex(0);
  float tempB = sensors.getTempCByIndex(1);
  float tempC = sensors.getTempCByIndex(2);
  float tempD = sensors.getTempCByIndex(3); 
  float tempE = sensors.getTempCByIndex(4); 
  float tempF = sensors.getTempCByIndex(5); 
  // alternative
  float tempC1 = sensors.getTempC(Sensor1);
  
{
  if (tempA_min > tempA )
      {tempA_min = tempA;
      }
      else { Serial.println("keine Änderung");
      }
}
{
   if (tempA_max < tempA )
       {tempA_max = tempA;
       }
       else { Serial.println("keine Änderung");
      }
}


      {
  if (tempB_min > tempB )
      {tempB_min = tempB;
      }
      else { Serial.println("keine Änderung");
      }
}
{
   if (tempB_max < tempB )
       {tempB_max = tempB;
       }
       else { Serial.println("keine Änderung");
      }
}


{
  if (tempC_min > tempC )
      {tempC_min = tempC;
      }
      else { Serial.println("keine Änderung");
      }
}
{
   if (tempC_max < tempC )
       {tempC_max = tempC;
       }
       else { Serial.println("keine Änderung");
      }
}

// min / max Sensor D
{
  if (tempD_min > tempD )
      {tempD_min = tempD;
      }
      else { Serial.println("keine Änderung");
      }
}
{
   if (tempD_max < tempD )
       {tempD_max = tempD;
       }
       else { Serial.println("keine Änderung");
      }
}

// min / max Sensor E
{
  if (tempE_min > tempE )
      {tempE_min = tempE;
      }
      else { Serial.println("keine Änderung");
      }
}
{
   if (tempE_max < tempE )
       {tempE_max = tempE;
       }
       else { Serial.println("keine Änderung");
      }
}

// min / max Sensor F
{
  if (tempF_min > tempF )
      {tempF_min = tempF;
      }
      else { Serial.println("keine Änderung");
      }
}
{
   if (tempF_max < tempF )
       {tempF_max = tempF;
       }
       else { Serial.println("keine Änderung");
      }
}


//Kopf und Fußzeile

  myGLCD.setColor(255, 0, 0);
  myGLCD.fillRect(0, 0, 319, 13);
  myGLCD.setColor(255, 255, 255);
  myGLCD.fillRect(0, 226, 319, 239);
  myGLCD.setColor(255, 255, 255);
  myGLCD.setBackColor(255, 0, 0);
  myGLCD.print("* Temp Monitor AL-Line TEST *", CENTER, 1);
  myGLCD.setBackColor(255, 2552, 255);
  myGLCD.setColor(0,0,0);
  myGLCD.print("<http://blog.buyenne.com>", CENTER, 227);

//Temperaturen

  myGLCD.setBackColor(0, 0, 0);
  myGLCD.drawRect(0, 14, 319, 225);
  myGLCD.setColor(255,255,255);
  myGLCD.print("Temp Motor  -  Temp Stepper", CENTER, 20);
  
  myGLCD.print("X-Achse", LEFT, 30);
  myGLCD.print("Y-Achse", LEFT, 70);
  myGLCD.print("Z-Achse", LEFT, 110);
  myGLCD.print("4-Achse", LEFT, 150);  
  
 // Test Groß klein Temp

  myGLCD.setColor(0,0,255);
  myGLCD.printNumF(tempA_min ,2,15,43);
  myGLCD.setColor(255,0,0);
  myGLCD.printNumF(tempA_max ,2,15,55);
  myGLCD.setColor(255,255,255);
  myGLCD.setFont(Inconsola);
  myGLCD.printNumF(tempA ,1, 55, 43);
  myGLCD.setFont(SmallFont);
  
  myGLCD.setColor(0,0,255);
  myGLCD.printNumF(tempB_min ,2,15,83);
  myGLCD.setColor(255,0,0);
  myGLCD.printNumF(tempB_max ,2,15,95);
  myGLCD.setColor(255,255,255);
  myGLCD.setFont(Inconsola);
  myGLCD.printNumF(tempB ,1, 55, 83);
  myGLCD.setFont(SmallFont);
  
  myGLCD.setColor(0,0,255);
  myGLCD.printNumF(tempC_min ,2,15,123);
  myGLCD.setColor(255,0,0);
  myGLCD.printNumF(tempC_max ,2,15,135);
  myGLCD.setColor(255,255,255);
  myGLCD.setFont(Inconsola);
  myGLCD.printNumF(tempC ,1, 55, 123);
  myGLCD.setFont(SmallFont);
  
  myGLCD.setColor(0,0,255);
  myGLCD.printNumF(tempD_min ,2,175,43);
  myGLCD.setColor(255,0,0);
  myGLCD.printNumF(tempD_max ,2,175,55);
  myGLCD.setColor(255,255,255);
  myGLCD.setFont(Inconsola);
  myGLCD.printNumF(tempD ,1, 215, 43);
  myGLCD.setFont(SmallFont);
  
  myGLCD.setColor(0,0,255);
  myGLCD.printNumF(tempE_min ,2,175,83);
  myGLCD.setColor(255,0,0);
  myGLCD.printNumF(tempE_max ,2,175,95);
  myGLCD.setColor(255,255,255);
  myGLCD.setFont(Inconsola);
  myGLCD.printNumF(tempE ,1, 215, 83);
  myGLCD.setFont(SmallFont);
  
  myGLCD.setColor(0,0,255);
  myGLCD.printNumF(tempF_min ,2,175,123);
  myGLCD.setColor(255,0,0);
  myGLCD.printNumF(tempF_max ,2,175,135);
  myGLCD.setColor(255,255,255);
  myGLCD.setFont(Inconsola);
  myGLCD.printNumF(tempF ,1, 215, 123);
  myGLCD.setFont(SmallFont);

// Trafos

  myGLCD.setColor(255,255,255);
  myGLCD.print("Spannung Trafos 5V 12V 24V 48V", CENTER, 190);
  
  
  delay(2000);
  }
  
 
