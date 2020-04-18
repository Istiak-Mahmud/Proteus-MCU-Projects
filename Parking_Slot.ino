#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

void setup() 
{
  Serial.begin(9600); // Starts the serial communication   
  lcd.init();
  lcd.backlight(); 
  pinMode(8,INPUT); 
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT); }

  void loop()   {
    int pirState = digitalRead(8);  
    lcd.setCursor(0, 0);
    lcd.print("Detecting-");   
    if (pirState == LOW)    
    {
      digitalWrite(2, HIGH);
      digitalWrite(3, LOW);
      lcd.setCursor(0, 1);
      lcd.print("All Clear");
      Serial.println("All Clear");
      delay(500);
      lcd.clear();
    }    
    else if (pirState == HIGH)     
    {
      lcd.setCursor(0, 1);  
      digitalWrite(3, HIGH);
      digitalWrite(2,LOW);    
      lcd.print("Not clear");    
      Serial.println("Not Clear"); 
      delay(500);        
      lcd.clear();     
      } 
 
    } 
 
 
