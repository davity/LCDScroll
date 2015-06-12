#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>
#include <string.h>

LiquidCrystal_I2C	lcd(0x27,2,1,0,4,5,6,7);

#define SCROLLSPEED 230
#define STRENDDELAY 800
#define LINELENGTH 16

char line[LINELENGTH + 1] = "";
int pos = 0;
char msg[] = "Riega el mar y la pradera.";
char msg2[] = "POLEPOLEPOLE";

void setup()
{
  Serial.begin(9600);
  lcd.begin (16,2); // for 16 x 2 LCD module
  lcd.setBacklightPin(3,POSITIVE);
  lcd.setBacklight(HIGH);
  lcd.home(); // set cursor to 0,0
  
}
 
void loop()
{
  
  lcd.home();
  scrollText(line, msg, &pos);
  
  delay(SCROLLSPEED);
}

void scrollText(char *line, char *msg, int *pos) {
  strncpy(line, msg + *pos, LINELENGTH);
  lcd.print(line);
  //line[17]="\0";
  if (*pos == 0) {
    delay(STRENDDELAY);
  }
  (*pos)++;
  Serial.println(strlen(msg));
  if (*pos > (strlen(msg) - strlen(line))) {
    (*pos) = 0;
    delay(STRENDDELAY);
  } else {
    lcd.print(line);
  }
}

//void copyString(char dest[], char source[]) {
//  strncpy(dest, source + pos, 17);
//}
