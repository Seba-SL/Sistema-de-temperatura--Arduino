//La libreria Wire.h permite usar distintos dispositivos a traves del mismo puerto I2C 
//La libreria LiquidCrystal_I2C.h permite trabajar el display con un controlador de comunicacion I2C
// La ultima libreria Adafruit_MLX90614.h es para manipular el sensor de temperatura tambien de interfaz de comunicación digital SMBus/I2C
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Adafruit_MLX90614.h>

//Se declara un led de alarma para exceso de temperatura
#define LEDALARM 12


//Inicializa el lcd de 16x2 y se declara un objeto del tipo Adafruit_MLX90614 , mlx 
LiquidCrystal_I2C lcd(0x27,16,2);  //
Adafruit_MLX90614 mlx = Adafruit_MLX90614();

void setup()
 {
  //El led en el pin 12 sera una salida
  pinMode(LEDALARM,OUTPUT);
  
 //Se inicializan los puertos el I2C y el serial 
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
  

}
