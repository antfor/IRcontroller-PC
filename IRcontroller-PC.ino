#include "IRButtons.h"
#include "password.h"
#include <IRremote.hpp>
#define IR_RECEIVE_PIN 7 //Left, - middle, + right

const byte code_length = PC_PASSWORD_LEN;
const byte pc_password[code_length]={PC_PASSWORD};

byte index = 0;
byte code[code_length];

bool pressedStart = false;

void setup(){

  Serial.begin(9600);
    while (!Serial)
        ; 

    Serial.flush();
    Serial.println(F("START " __FILE__ " from " __DATE__ ));
    setupOnButton();
    setupLED();
    IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK); // Start the receiver

}


void startPC(){
  Serial.println("start!");
  press();
  Serial.println("Pc is running!");

}

void cheackCode(){

  if(index == code_length){
    Serial.println("code");
    printArray(code,code_length);

    if(cmp(code, pc_password, code_length)){
      startPC();
      blink();
    }
    index = 0;
    pressedStart = false;
  }

}

void loop(){
   
    if (IrReceiver.decode()) {

      if(!IrReceiver.decodedIRData.flags & IRDATA_FLAGS_IS_REPEAT){

        const IRData data = IrReceiver.decodedIRData;
        const byte command = byte(data.command);

        Serial.println(data.command);

        if(!pressedStart && command == B_CHP){
          Serial.println("give password");
          pressedStart = true;
          blink();
        }else if(pressedStart){
          blink();
          code[index++] = command;
          cheackCode();
        }
        
      }
     

  
  
    IrReceiver.resume();
  }


}