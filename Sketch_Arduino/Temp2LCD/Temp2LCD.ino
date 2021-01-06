/*
 * Este sketch recibe la temperatura del CPU y GPU de la aplicación Temp2LCD hecha en Gambas
 * y la despliega en un display LCD (16x2) con interfaz I2C conectado en A5(SCL) y A4(SDA).
 * También hay conectado un LED en el pin 13 que se enciende al recibir información del puerto serie
 * Para descargar la aplicación y obtener mas información visita el blog: 
 * https://thenerdyapprentice.blogspot.com/ y deja un comentario!
 * 
 */

// Incluimos las librerías necesarias para el LCD
#include <Wire.h>  
#include <LiquidCrystal_I2C.h>

const int LED = 13;

//Seteamos la dirección del LCD -> En mi caso 0x27
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

void setup() {
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
  Serial.begin(9600); // Iniciamos el puerto serie
  Serial.println("- Hola desde el Arduino!"); // Enviamos el mensaje a la PC
  
  lcd.begin(16,2); // Inicializamos el LCD 16x2
  lcd.backlight(); // Encendemos la luz de fondo
  
  // Escribimos la primer línea del LCD
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("CPU / GPU Temp.");
  
}

void loop() {
/* Si el puerto serie está disponible, encendemos el LED y guardamos en la variable 
 * data la información recibida, ubicamos el cursor del LCD en la segunda línea
 * y mostramos la información.  
 */
 
  if (Serial.available()) {
    digitalWrite(LED, HIGH); 
    String data = Serial.readStringUntil('\n'); //Deja de leer cuando llega la cadena '\n'
    lcd.setCursor(0,2);
    lcd.print(data);
    Serial.println(data); // Devuelve la información recibida a la PC.
    delay(350);
  }

digitalWrite(LED, LOW);

}
