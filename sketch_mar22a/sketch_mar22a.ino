//SCREMIN LEONARDO 4^BI

#include <LiquidCrystal.h>
int meta = 30;
bool start;
int sommanumeri = 0;
int punteggioG1 = 0;
int punteggioG2 = 0;
bool terminato = false;
int buttonblue = 10; //bottone per diminuire il numero da scegliere
int buttonwhite = 9; // bottone per confermare il numero scelto
int buttongreen = 8; // bottone per aumentare il numero da scegliere
bool soddisfaCondizioni = false;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  start = false;
  terminato = false;
  pinMode(buttonblue, INPUT_PULLUP);
  pinMode(buttonwhite, INPUT_PULLUP);
  pinMode(buttongreen, INPUT_PULLUP);
  lcd.begin(16, 2);
 
}


void loop() {
  // put your main code here, to run repeatedly:


  
 while(!start)
  {
    Meta();
  }
  while(true)
  {
    turnoG1();
    GeneralCheck("G1");
    turnoG2();
    GeneralCheck("G2");
  }

}


void Meta()
{
  lcd.setCursor(0,0);
  lcd.print("Inserisci meta");
  lcd.setCursor(7,1);
  lcd.print(String(meta));
  
  while (digitalRead(buttonwhite) == HIGH) {
    if (digitalRead(buttongreen) == LOW) {
      if(meta < 90){
        meta++;
          lcd.setCursor(7,1);
        lcd.print(meta);      
      }
      else {
        lcd.setCursor(0,0);
        lcd.print("                ");
        lcd.setCursor(0,0);
        lcd.print("Non barare!");
      }
      delay(100);
    }
    if (digitalRead(buttonblue) == LOW) {
      if (meta > 30){
        meta--;
          lcd.setCursor(7,1);
        lcd.print(meta);       
      }
      else {
        lcd.setCursor(0,0);
        lcd.print("                ");
        lcd.setCursor(0,0);
        lcd.print("Non barare!");
      }
      delay(100);
    }
   } 
  start = true;
  lcd.clear(); lcd.setCursor(0,0);
  lcd.print("Meta:" + String(meta));
  delay(1000);
}



void turnoG1(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("G1 scegliera:");
  lcd.setCursor(7,1); lcd.print(String(punteggioG1));
while(!soddisfaCondizioni){ 
  while(digitalRead(buttonwhite) == HIGH){
    if(digitalRead(buttongreen) == LOW && punteggioG1<6){
      punteggioG1++;
      lcd.setCursor(7,1); lcd.print(String(punteggioG1));
      delay(250);
    }
    if(digitalRead(buttonblue) == LOW && punteggioG1>0){
      punteggioG1--;
      lcd.setCursor(7,1); lcd.print(String(punteggioG1));
      delay(250);
    }
   } 
   Checknumbers1();    
 }

sommanumeri += punteggioG1; // sommanumeri = sommanumeri + punteggioG1
lcd.setCursor(14,1); lcd.print(String(sommanumeri));
delay(500);
soddisfaCondizioni = false;
}


void turnoG2(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("G2 scegliera:");
  lcd.setCursor(7,1); lcd.print(String(punteggioG2));
while(!soddisfaCondizioni){ 
  while(digitalRead(buttonwhite) == HIGH){
    if(digitalRead(buttongreen) == LOW && punteggioG2<6){
      punteggioG2++;
      lcd.setCursor(7,1); lcd.print(String(punteggioG2));
      delay(250);
    }
    if(digitalRead(buttonblue) == LOW && punteggioG2>0){
      punteggioG2--;
      lcd.setCursor(7,1); lcd.print(String(punteggioG2));
      delay(250);
    }
   } 
   Checknumbers2();    
 }

sommanumeri += punteggioG2; // sommanumeri = sommanumeri + punteggioG1
lcd.setCursor(14,1); lcd.print(String(sommanumeri));
delay(500);
soddisfaCondizioni = false;
}


void Checknumbers1() //controlla i numeri che vengono inseriti dall'utente, rispettando il regolamento
{
  if(punteggioG1 == 1 && punteggioG2 != 1 && punteggioG2 != 6){
    soddisfaCondizioni = true;
  }
  else if(punteggioG1 == 2 && punteggioG2 != 2 && punteggioG2 != 5){
    soddisfaCondizioni = true;
    }
  else if(punteggioG1 == 3 && punteggioG2 != 3 && punteggioG2 != 4){
    soddisfaCondizioni = true;
    }
  else if(punteggioG1 == 4  && punteggioG2 != 3 && punteggioG2 != 4){
    soddisfaCondizioni = true;
  }
  else if(punteggioG1 == 5  && punteggioG2 != 2 && punteggioG2 != 5){
    soddisfaCondizioni = true;
  }
  else if(punteggioG1 == 6  && punteggioG2 != 1 && punteggioG2 != 6){
    soddisfaCondizioni = true;
  }
}

 void Checknumbers2()
 { 
  //faccio 6 if
 if(punteggioG2 == 1  && punteggioG1 != 1 && punteggioG1 != 6){
    soddisfaCondizioni = true;
  }
  else if(punteggioG2 == 2 && punteggioG1 != 2 && punteggioG1 != 5){
    soddisfaCondizioni = true;
    }
  else if(punteggioG2 == 3 && punteggioG1 != 3 && punteggioG1 != 4){
    soddisfaCondizioni = true;
    }
  else if(punteggioG2 == 4  && punteggioG1 != 3 && punteggioG1 != 4){
    soddisfaCondizioni = true;
  }
  else if(punteggioG2 == 5  && punteggioG1 != 2 && punteggioG1 != 5){
    soddisfaCondizioni = true;
  }
  else if(punteggioG2 == 6  && punteggioG1 != 1 && punteggioG1 != 6){
    soddisfaCondizioni = true;
  }
 }
 





void GeneralCheck(String nome)
{
  if (sommanumeri == meta)
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Vince giocatore ");
    lcd.setCursor(7,1);  
    lcd.print(nome);
    while(true){}
  }
  else if (sommanumeri > meta)
  {
    lcd.clear();
    lcd.setCursor(0,0); 
    lcd.print("Perde giocatore ");
    lcd.setCursor(7,1);
    lcd.print(nome);
    while(true){}
  }
}



/*void somma()
{
  sommanumeri = punteggioG1 + punteggioG2;
  lcd.print(sommanumeri.toInt());
}
*/

