#define SER		(2)
#define RCLK	(3)
#define SRCLK	(4)
#define NSR (2)
 
void setup() {
  pinMode( SER,  OUTPUT );
  pinMode( RCLK, OUTPUT );
  pinMode( SRCLK, OUTPUT );
}
void initShiftRegister(){
  digitalWrite(RCLK, LOW);
  for(int i = 0; i < NSR * 8;i++){
    digitalWrite(SER, LOW);
			
		digitalWrite(SRCLK, HIGH);
	  digitalWrite(SRCLK, LOW);
  }
  digitalWrite(RCLK, HIGH);
}
//RCLK 確定
//SER データを送ってシフト
//SRCLK 
void SetLED(int array[][8], int Rows){
  digitalWrite(RCLK, LOW);
  for(int Row = 0; Row < Rows; Row++){
    for(int Column = 0; Column < 8; Column++){
      if(array[Row][Column] == 1){
        digitalWrite(SER, HIGH);
		    digitalWrite(SRCLK, HIGH);
	      digitalWrite(SRCLK, LOW);
      }
      else {
        digitalWrite(SER, LOW);
		    digitalWrite(SRCLK, HIGH);
	      digitalWrite(SRCLK, LOW);
      }
    }
  }
  digitalWrite(RCLK, HIGH);
}

void loop() {
  initShiftRegister();
  int LEDPattern1[2][8] = {{1,0,1,0,1,0,1,0},{0,1,0,1,0,1,0,1}};
  int LEDPattern2[2][8] = {{0,1,0,1,0,1,0,1},{1,0,1,0,1,0,1,0}};
  for(;;){
    SetLED(LEDPattern1, 2);
    delay(500);
    SetLED(LEDPattern2, 2);
    delay(500);
  }
}