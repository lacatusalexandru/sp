#include <SoftwareSerial.h>
#include <Servo.h>

int bluetoothTx = 1;
int bluetoothRx = 0;

SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

int Motor1A = 8;
int Motor1B = 9;
int Motor2A = 10;
int Motor2B = 11;

void setup()
{
  bluetooth.begin(115200);
  bluetooth.print("$$$");
  delay(100);
  bluetooth.println("U,9600,N");
  bluetooth.begin(9600);
  
  
  pinMode( Motor1A, OUTPUT );
  pinMode( Motor1B, OUTPUT );
  pinMode( Motor2A, OUTPUT );
  pinMode( Motor2B, OUTPUT );
  
  digitalWrite( Motor1A, LOW );
  digitalWrite( Motor1B, LOW );
  digitalWrite( Motor2A, LOW );
  digitalWrite( Motor2B, LOW );
}
int flag1 = -1;
int flag2 = -1;

void loop()
{
  if(bluetooth.available())
  {
    char toSend = (char)bluetooth.read();
    if(toSend == 'S')
    {
        flag1 = 0;
        flag2 = 0;
        digitalWrite( Motor1A, LOW );
        analogWrite( Motor1B, LOW );
        
        digitalWrite( Motor2A, LOW );
        analogWrite( Motor2B, LOW );
    }
    if(toSend == 'F' || toSend == 'G' || toSend == 'I')
    {
        if(flag1 != 1)
        {
          flag1 = 1;
          digitalWrite( Motor1A, HIGH );
          analogWrite( Motor1B, 50 );   // edit 21.12.2016 am substituit 50 cu 250, apoi cu 450
                                        // acelasi bazait scos de motoare, insa de data asta se misa haotic cateva secunde, indiferent de ce comanda ii dadeam
        }         //note to self : de masurat tensiunea ce iese din motor driver si pica pe motoare;
                  // de incercat lipirea cate unui condesator 5...45pF in paralel cu fiecare motor pentru diminuarea bazaitului
                  //Captain's log : modulul drive are condensatoare incorporate pe iesiri, consuma intre 4.5 si 5.6 V, iar pe motoare cade o tensiune prea mica
                  //                therefore, problema bazaitului a fost descoperita si partial rezolvata
                  //                din fisa tehnica : L298N trebuie alimentat la o ten de aprox 7V http://pdf1.alldatasheet.com/datasheet-pdf/view/22440/STMICROELECTRONICS/L298N.html
    }
    if(toSend == 'B' || toSend == 'H' || toSend == 'J')
    {
        if(flag1 != 2)
        {
          flag1 = 2;
          digitalWrite( Motor1B, HIGH );
          analogWrite( Motor1A, 50 );
        }
    }

    if(toSend == 'L' || toSend == 'G' || toSend == 'H')
    {
        if(flag2 != 1)
        {
          flag2 = 1;
          digitalWrite( Motor2B, HIGH );
          analogWrite( Motor2A, 50 );
        }
    }
    else
    if(toSend == 'R' || toSend == 'I' || toSend == 'J')
    {
        if(flag2 != 2)
        {
          flag2 = 2;
          digitalWrite( Motor2A, HIGH );
          analogWrite( Motor2B, 50 );
        }
    }
    else
    {
        if(flag2 != 3)
        {
          flag2 = 3;
          digitalWrite( Motor2A, LOW );
          analogWrite( Motor2B, LOW );
        }
    }
  }
}

