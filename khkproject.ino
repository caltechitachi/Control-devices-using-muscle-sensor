int giatri;
int sensorPin = A0;
int LED1 = 13;
int LED2 = 9;
int LED3 = 8;
#include<LiquidCrystal.h>
#include<Servo.h>
#define SERVO_PIN 7
Servo SERVO_1;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup() {
  Serial.begin(9600);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  SERVO_1.attach(SERVO_PIN);
  lcd.begin(16, 2);
  lcd.print("hehe to la Khang day");

}

void loop() {
  giatri = analogRead(sensorPin);
  lcd.setCursor(0,1);
  Serial.print("muscle=");
  Serial.println(giatri);
  giatri = map(giatri,0,1024,0,100);

  if((giatri >=0) && (giatri <10))
    {
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      lcd.print("DZE VUI QUA");
      SERVO_1.write(170);
    }
   if ((giatri >= 10) && (giatri < 20))
       {
        digitalWrite(LED1, LOW);
        digitalWrite(LED2, HIGH);
        digitalWrite(LED3, LOW);
        lcd.print("   fine nha");
        SERVO_1.write(10);
       }
 
    if ((giatri >= 20) && (giatri < 30))
       {
        digitalWrite(LED1, LOW);
        digitalWrite(LED2, LOW);
        digitalWrite(LED3, HIGH);
        lcd.print("no problem");
        SERVO_1.write(30);
       }
           
    Serial.println(giatri);
}
