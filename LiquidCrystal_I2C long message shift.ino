/*
TR :LiquidCrystal_I2C ile uzun mesaj kaydırmalı ekrana  yazma
ENG: Long message shift write with LiquidCrystal_I2C

Samed ÇALIK tarafından üretilmiş bir koddur.

*/
#include <LiquidCrystal_I2C.h>

/*
uno modelinde SDA : A4
              SCL : A5

modole gore farklılık gosterir
*/
LiquidCrystal_I2C lcd(0x27,16,2);            // 0x3F yada 0x27 konulacak hata yazmaz ise tekrarla

#define sure 500

void kaydirmali(String msg )
{
  int size_msg = msg.length();
  int i =15;              // sutun sayisi
  String sub_S;           // bole islemi icin gerekli string
  int k = 1;              // 
  int loop_size = size_msg+10;
  
  while(loop_size--)
  {
    lcd.setCursor(i,0);
    if(i>0)
     { 
        i--;
        sub_S  = msg.substring(0,16);   // direk msg yazidirsaydik 2. satirda çıkıyordu bu sebeble bolumledim.
        lcd.print(sub_S);
     }
     else
     {
        sub_S  = msg.substring(k, size_msg);
        lcd.print(sub_S);
        k++;
     }


    delay(sure);
    lcd.clear();
  }
  
}

void setup() {
  
lcd.init(); // begin();
lcd.backlight(); // arka isigi acar 

lcd.setCursor(0,0); // satır ,sutun
lcd.print("selam ");
lcd.setCursor(0,1);
lcd.print("ben Samed");
delay(3000);
lcd.clear();

kaydirmali( "samed ile yazilim ogrenmeceler de :)" );


}


void loop() {

}


  




