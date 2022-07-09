#include <Adafruit_SSD1306.h>
#include <SoftwareSerial.h>
String inData;

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

void setup() {
  Serial.begin(9600);       
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

    display.display(); 
    delay(2000);
    display.clearDisplay();
}
void loop() {
 int i=0;
  char aloda[100];

  if(Serial.available()){
     delay(100);
     while( Serial.available() && i< 99) {
        aloda[i++] = Serial.read();
     }
     aloda[i++]='\0';
  }

  if(i>0)
{
  Serial.println((char*)aloda);
}
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(4);
  display.setCursor(0,0);
  display.println((char*)aloda);
  display.display();
  delay(1000);

}
