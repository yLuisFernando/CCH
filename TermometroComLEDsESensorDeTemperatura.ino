//TERMÔMETRO COM LEDs E SENSOR DE TEMPERATURA
float Temperatura = 0;
const int TPM = 1;
const int Buzzer = 2;
const int LEDVERMELHO = 0;
const int LEDVERDE = 0;
const int LEDAMARELO = 0;
int ADClido = 0;

void setup()
{
  Serial.begin(9600);
  analogReference(INTERNAL);
 
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(3, OUTPUT);
  
}

void loop()
{
 

  ADClido = analogRead(TPM);

  Temperatura = ADClido * 0.1075268817204301;
  Serial.println(Temperatura);
  

  
  if (Temperatura >= 20 && Temperatura <= 23) {
    digitalWrite(11, HIGH);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
    delay(1000);
  } else {
    if ((Temperatura >= 16 && Temperatura <= 19) || (Temperatura >= 24 && Temperatura <= 27)) {
      digitalWrite(12, HIGH);
      digitalWrite(11, LOW);
      digitalWrite(13, LOW);
      delay(1000);
    } else {
      digitalWrite(11, LOW);
      digitalWrite(12, LOW);
      digitalWrite(13, HIGH);
      digitalWrite(3, HIGH);
      tone(3, 523, 1500);
      
    }
  }
  delay(1000);
}
