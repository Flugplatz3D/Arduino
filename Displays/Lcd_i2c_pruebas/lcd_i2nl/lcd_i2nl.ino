/**
 * EJEMPLO:
 * FC-113 : Adaptador I2C/IIC para LCD 1602 
 * Tutorial por Daniel Cabrera  (github: dansrocks)
 * Web: http://microproyectos.net
 *
 * Requiere librería New-LiquidCrystal
 *   https://bitbucket.org/fmalpartida/new-liquidcrystal/downloads
 *
 * Esquema de conexiones:
 *    SCL = A5
 *    SDA = A4
 *    VCC = 5V
 *    GND = GND
 */
 #include <Wire.h>
 #include <LCD.h>
 #include <LiquidCrystal_I2C.h>

/**
 * Ojo, aquí se define LCD y los pines que se usan para controlarlo
 */
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7);   // 0x27 suele ser la dirección I2C

void setup()
{
   lcd.setBacklightPin(3, POSITIVE);  // POSITIVE = enum definido en LCD.h
   lcd.setBacklight(HIGH);            // Activamos el backlight
   lcd.begin(16, 2);                  // Configuramos un LCD 16x2
   lcd.clear();                       // limpiamos el LCD
}

void loop()
{
   lcd.setCursor(0,0);
   lcd.print("LCD-I2C Works!");
   lcd.setCursor(0,1);
   lcd.print("caca");
   delay(5000);
}
