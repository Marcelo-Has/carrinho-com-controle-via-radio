#include <IRremote.h>
  
int sinal = 13;  
float armazenavalor;  
int IN1 = 4;
int IN2 = 5;
int IN3 = 6;
int IN4 = 7;
int ledver = 12;
int ledama1 = 2;
int ledama2 = 8;
int buzzer = 3;



  
IRrecv irrecv(sinal); 
decode_results results;

  
void setup()  
{  
  Serial.begin(9600);  
  irrecv.enableIRIn(); // Inicializa o receptor IR
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT); 
  pinMode(ledver, OUTPUT);
  pinMode(ledama1, OUTPUT);
  pinMode(ledama2, OUTPUT);
  pinMode(buzzer, OUTPUT);
  digitalWrite(ledama1, HIGH);
  digitalWrite(ledama2, HIGH);
  digitalWrite(ledver, HIGH);
  digitalWrite(buzzer, HIGH);
  
}  
   
void loop()  
{  
  if (irrecv.decode(&results))  
  {  
    Serial.print("Valor lido : ");  
    Serial.println(results.value, HEX);  
    armazenavalor = (results.value);  

    irrecv.resume(); //Le o próximo valor  
    
    if (armazenavalor == 0xFF18E7) // IR PARA FRENTE
    {  
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      digitalWrite(ledver, HIGH);
    }  
    
    if (armazenavalor == 0xFF4AB5) // IR PARA ATRAS
     {  
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);      
      digitalWrite(ledver, LOW);
      digitalWrite(buzzer, LOW);
      delay(500);
      digitalWrite(buzzer, HIGH);
      delay(500);
     }
     
     if (armazenavalor == 0xFF5AA5) // IR PARA ESQ FRENTE
     {  
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      digitalWrite(ledver, HIGH);
     }

     if (armazenavalor == 0xFF6897) // IR PARA ESQ ATRAS
     {  
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      digitalWrite(ledver, LOW);
      digitalWrite(buzzer, LOW);
      delay(500);
      digitalWrite(buzzer, HIGH);
      delay(500);
     }
     
     if (armazenavalor == 0xFF10EF) // IR PARA DIR FRENTE
     {  
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, HIGH);
      digitalWrite(ledver, HIGH);
     }

     if (armazenavalor == 0xFFB04F) // IR PARA DIR ATRAS
     {  
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      digitalWrite(ledver, LOW);
      digitalWrite(buzzer, LOW);
      delay(500);
      digitalWrite(buzzer, HIGH);
      delay(500);
     }
     
     if (armazenavalor == 0xFF38C7) // TODOS PARADOS
     {  
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, HIGH);
      digitalWrite(ledver, HIGH);
     }


     if (armazenavalor == 0xFFE21D) //LED FAROL LIGA
     {
      digitalWrite(ledama1, LOW);
     }
     if (armazenavalor == 0xFFC23D) //LED FAROL DESLIGA
     {
      digitalWrite(ledama1, HIGH);
     }

     if (armazenavalor == 0xFF9867) //CANHÂO
     {
      digitalWrite(ledama2, LOW);
      delay(500);
      digitalWrite(ledama2, HIGH);
     }

     if (armazenavalor == 0xFFE01F) //CANHÂO
     {
      digitalWrite(ledama2, LOW);
      delay(500);
      digitalWrite(ledama2, HIGH);
      delay(500);      
     }

     if (armazenavalor == 0xFF629D) //Buzina
     {
      digitalWrite(buzzer, LOW);
      delay(400);
      digitalWrite(buzzer, HIGH);      
     }    
  }  
}  
