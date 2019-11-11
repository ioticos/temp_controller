//CODIGO
//se incluyen las librerias
#include <OneWire.h>
#include <DallasTemperature.h>

//se define el pin que vamos a usar con one wire
#define ONE_WIRE_BUS 2
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensor (&oneWire);

int led = 6;
int boton = 3;
int ventilador = 5;
float temperatura;
bool ventilador_activado = false;
int temperatura_limite = 29;


void setup() {

  //TCCR0B = TCCR0B & B11111000 | B00000101;    // for PWM frequency of 30.64 Hz
  Serial.begin(9600);
  Serial.println("Iniciando Sistema Control Temperatura");
  pinMode (ventilador,OUTPUT);

}

void loop() {

  sensor.requestTemperatures();
  temperatura = sensor.getTempCByIndex(0);
  //Serial.println("La temperatura es: " + String(temperatura));

  if (temperatura > temperatura_limite){
    digitalWrite(ventilador,HIGH);
    ventilador_activado = true;
    Serial.println("VENTILADOR ACTIVADO -> " + String (temperatura));
  }else{
    digitalWrite(ventilador,LOW);
    ventilador_activado = false;
    Serial.println("VENTILADOR DESACTIVADO -> " +  String (temperatura));
  }

}
