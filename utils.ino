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