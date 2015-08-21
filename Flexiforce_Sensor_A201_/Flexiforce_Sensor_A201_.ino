#include <LiquidCrystal.h>
LiquidCrystal lcd (8, 9, 4, 5, 6, 7);
const int analogPin = A0;
const int LED1 = A2;
const int LED2 = A3;
const int LED3 = A4;
const int LED4 = A5;
unsigned char voltage;

void setup()
{
  lcd.begin(8, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Voltage:");
  pinMode(analogPin, INPUT);
}

void loop()
{
  voltage = obtain_volt();
  LED_Light(voltage);
  lcd.setCursor(0,1);
  lcd.print(voltage/10,DEC);         // Print the value in decimal 
  lcd.print('.');
  lcd.print(voltage%10,DEC);
  delay(100);
}

void LED_Light(unsigned int k)
{
 if(k >= 10 && k < 20)
    {
        digitalWrite(LED1, HIGH);
    }
    else if (k >= 20 && k < 30)
    {
        digitalWrite(LED1, HIGH);
        digitalWrite(LED2, HIGH);
    }
    else if(k >= 30 && k< 40)
    {
        digitalWrite(LED1, HIGH);
        digitalWrite(LED2, HIGH);
        digitalWrite(LED3, HIGH);
    }
    else if(k >= 40 && k < 48)
    {
        digitalWrite(LED1, HIGH);
        digitalWrite(LED2, HIGH);
        digitalWrite(LED3, HIGH);
        digitalWrite(LED4, HIGH);
    }
    else if (k >= 48)
    {
        digitalWrite(LED1, HIGH);
        delay(10);
        digitalWrite(LED1, LOW);
        
        digitalWrite(LED2, HIGH);
        delay(10);
        digitalWrite(LED2, LOW);
        
        digitalWrite(LED3, HIGH);
        delay(10);
        digitalWrite(LED3, LOW);
        
        digitalWrite(LED4, HIGH);
        delay(10);
        digitalWrite(LED4, LOW);
    }
    else
    {
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, LOW);
    }
}

int obtain_volt()
{
  float adc = 0;
  float total = 0;
  int average = 0;
  for (int i = 0; i<100; i++);
  {
    adc = analogRead(analogPin);    // Read the value from analog pin for 1000 time
    total += adc * (5.0/1024)*1000; 
  }
  average = int(total/100);         // Get the average value
  return average;
}

