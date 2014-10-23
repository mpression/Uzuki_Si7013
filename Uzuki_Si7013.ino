/**************************************************************************
Copyright (c) 2014, Macnica Inc.,
All rights reserved.

This is a library for the Si7013 Temperature and Related Humidity Sensor on Uzuki IoT Sensor Shield
http://www.m-pression.com/ja/solutions/boards/uzuki-shield

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met: 

1. Redistributions of source code must retain the above copyright notice,
   this list of conditions and the following disclaimer. 
2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution. 

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

The views and conclusions contained in the software and documentation are those
of the authors and should not be interpreted as representing official policies, 
either expressed or implied, of the FreeBSD Project.
******************************************************************************/

#include <si7013.h>
#include <Wire.h>

SI7013 si7013(0x40, 1);

// Print a centi-unit in "float"
void print_float(int tmp)
{
   Serial.print(tmp / 100);
   Serial.print(".");
   Serial.println(tmp - (tmp / 100) * 100);
}

void setup()
{
   Serial.begin(9600);
   Wire.begin();
   si7013.begin();
   Serial.println("si7013 Library Example");
}
   
void loop()
{
   int tmp;
   Serial.print("Humidity = ");
   print_float(si7013.readHumidity());
   Serial.print("Temperature From Humidity Reading = ");
   print_float(si7013.getTempFromHumidity());
   Serial.print("Temperature = ");
   print_float(si7013.readTemperature());
   Serial.println();
   delay(1000);
}

