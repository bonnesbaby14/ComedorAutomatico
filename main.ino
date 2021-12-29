

#include <Servo.h>
#include <virtuabotixRTC.h> //Libreria

// CLK -> 6, DAT -> 7, RST -> 8
// SCLK -> 6, I/O -> 7, CE -> 8 

virtuabotixRTC myRTC(6, 7, 8); // Si cambiamos los PIN de conexión, debemos cambiar aquí tambien


Servo apuntador, boquilla;
int tServir=800;

void setup() {
  pinMode(31,INPUT);
  //Iniciamos el monitor serie para mostrar el resultado
  Serial.begin(9600);

 //Iniciamos el servo para que empiece a trabajar con el pin 9
  apuntador.attach(52);
  boquilla.attach(50);
   apuntador.write(20);
 boquilla.write(90);  

delay(2000);

//apuntamos 1
movimiento(20,apuntador);

delay(1000);

//apuntamos 2
movimiento(62,apuntador);
delay(1000);

//apuntamos 
movimiento(110,apuntador);
delay(1000);






  
 apuntador.write(15);
 boquilla.write(90);  
 delay(3000);

}




void loop() {

 myRTC.updateTime();
if((myRTC.hours==7 && myRTC.minutes ==0 &&  myRTC.seconds==0)|| (digitalRead(31)==HIGH)){

  servir();
  }


 


}




void servir(){

//apuntamos 1
movimiento(20,apuntador);
delay(200);
//abrimos boquilla
boquilla.write(15);
delay(tServir);

boquilla.write(90);
sacudir(apuntador);
delay(1000);

//apuntamos 2
movimiento(62,apuntador);
delay(200);
//abrimos boquilla
boquilla.write(15);
delay(tServir);
boquilla.write(90);
sacudir(apuntador);
delay(1000);

//apuntamos 
movimiento(110,apuntador);
delay(200);
//abrimos boquilla
boquilla.write(15);
delay(tServir);

boquilla.write(90);
sacudir(apuntador);
delay(2000);



apuntador.write(15);

  
}



void movimiento(int destino, Servo motor){

  for(int x=motor.read(); x<destino;x++){
    motor.write(x);
    
    delay(9);
   
  }
  
}



void sacudir(Servo motor){

int data=motor.read();

for(int x=0;x<200;x++){
  motor.write(data-5);
  delay(15);
  motor.write(data+5);
  delay(15);

  
}
motor.write(data);



}
