#include "IRButtons.h"
#include "password.h"
#include <IRremote.hpp>
#define IR_RECEIVE_PIN 7

const byte code_length = PC_PASSWORD_LEN;
const byte pc_password[code_length]={PC_PASSWORD};

byte index = 0;
byte code[code_length];

void setup(){

  Serial.begin(9600);
    while (!Serial)
        ; 

    Serial.flush();
    Serial.println(F("START " __FILE__ " from " __DATE__ ));
    IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK); // Start the receiver
}


void printArray(byte* arr,byte size){

  for(int i = 0; i < size; i++)
  {
    Serial.print(arr[i]);
    Serial.print(", ");
  }
  Serial.println();
}

bool cmp(byte* code, byte* password, byte size){

  bool equal = true;

  for(int i = 0; i < size; i++){
    equal = equal && (code[i] == password[i]);
  }

  return(equal);
}

void startPC(){
  Serial.println("start!");

}

void loop(){

   
    if (IrReceiver.decode()) {

      if(!IrReceiver.decodedIRData.flags & IRDATA_FLAGS_IS_REPEAT){
        IRData data = IrReceiver.decodedIRData;

        Serial.println(data.command);

        code[index++] = byte(data.command);

        if(index == code_length){
          Serial.println("code");
          printArray(code,code_length);

          if(cmp(code, pc_password, code_length)){
            startPC();
          }
          index = 0;
        }
        
      
      }
     

  
  
    IrReceiver.resume();
  }


}