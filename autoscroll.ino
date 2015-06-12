#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>
#include <string.h>

LiquidCrystal_I2C	lcd(0x27,2,1,0,4,5,6,7);

#define LCDWIDTH 16
#define SCROLLSPEED 230
#define STRENDDELAY 800
#define LINELENGTH 10
// Alignment for text in LCD if LINELENGTH < LCDWIDTH
#define ALIGN_CENTER (LCDWIDTH-LINELENGTH)/2
#define ALIGN_LEFT 0
#define ALIGN_RIGHT LCDWIDTH-LINELENGTH

char line[LINELENGTH + 1] = "";
int pos = 0;
char msg[] = "Riega el mar y la pradera.";
char msg2[] = "POLEPOLEPOLE";

void setup()
{
  Serial.begin(9600);
  lcd.begin (LCDWIDTH,2); // for 16 x 2 LCD module
  lcd.setBacklightPin(3,POSITIVE);
  lcd.setBacklight(HIGH);
}
 
void loop()
{
  
  lcd.setCursor(ALIGN_CENTER, 0);
  scrollText(line, msg, &pos);
  Serial.println(line);
  delay(SCROLLSPEED);
}

void scrollText(char *line, char *msg, int *pos) {
  strncpy(line, msg + *pos, LINELENGTH);
  line[LINELENGTH] = '\0';
  lcd.print(line);
  if (*pos == 0) {
    delay(STRENDDELAY);
  }
  (*pos)++;
  if (*pos > (strlen(msg) - strlen(line))) {
    (*pos) = 0;
    delay(STRENDDELAY);
  }
  
}

