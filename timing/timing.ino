long speedtest[100];

void setup(){

  while(!Serial){
  }

  delay(3000);
  
  test();
}

void test(){  
  speedtest[0]=micros();
  speedtest[1]=micros();
  speedtest[2]=micros();
  speedtest[3]=micros();
  speedtest[4]=micros();
  speedtest[5]=micros();
  speedtest[6]=micros();
  speedtest[7]=micros();
  speedtest[8]=micros();
  speedtest[9]=micros();
  speedtest[10]=micros();
  speedtest[11]=micros();
  speedtest[12]=micros();
  speedtest[13]=micros();
  speedtest[14]=micros();
  speedtest[15]=micros();
  speedtest[16]=micros();
  speedtest[17]=micros();
  speedtest[18]=micros();
  speedtest[19]=micros();

  for(int i = 20; i < 40; i++)
    speedtest[i] = micros();
    
  for(int i = 0; i < 40; i++){
    if(i<10)
      Serial.print("0");
      
    Serial.print(i);
    Serial.print(": ");
    Serial.println(speedtest[i]);
  }

  Serial.println("\n============\n");
  
  speedtest[40]=micros();
  Serial.println(micros());

  Serial.print("40: ");
  Serial.println(speedtest[40]);
  Serial.println("\n============\n");

  speedtest[41]=micros();
  Serial.println(micros());
  Serial.print("41: ");
  Serial.println(speedtest[41]);
  
  
}

void loop(){
  
}

