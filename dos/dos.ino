#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Adafruit_MLX90614.h>

LiquidCrystal_I2C lcd(0x27,16,2);  //
Adafruit_MLX90614 mlx = Adafruit_MLX90614();

void setup()
 {

   pinMode(12,OUTPUT);

  Wire.begin();

  Serial.begin(9600);

  mlx.begin();  

  lcd.init();
  
  //Encender la luz de fondo.
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(1, 0);
  
  // Escribimos el Mensaje en el LCD.
 // lcd.print("");
  // put your setup code here, to run once:

}


void loop() {

float ambiente , obj ;

  Wire.beginTransmission(1);

  ambiente =mlx.readAmbientTempC();
  obj = mlx.readObjectTempC();

  if(obj > 35)
  {
    digitalWrite(12, HIGH);
  }else digitalWrite(12, LOW);

  Wire.endTransmission();
    
   Wire.beginTransmission(2);

   lcd.setCursor(0, 0);
  
   lcd.print("Ambiente:");
   lcd.print(ambiente);
   lcd.print("C");
   lcd.print((char)223);
   delay(500);   
   
   lcd.setCursor(0,1);

   lcd.print("Objeto: ");
   lcd.print(obj);
   lcd.print("C");
   lcd.print((char)223);
   delay(500);
   Wire.endTransmission();
      delay(500);
  // put your main code here, to run repeatedly:

}