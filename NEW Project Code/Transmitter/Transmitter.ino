// ECE 597 SD Project

String charToBin(int number)
{
  String binNum = "";
  for (int bit = 6; bit >= 0; bit--)
  {
    binNum += bitRead(number, bit);
  }
  return binNum;
}

int zeroLength = 8;  // 50  // 10
int oneLength = zeroLength*3;

void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  char ch;
  if(Serial.available()){
    ch = Serial.read();
    flashLaser(charToBin(ch));
    delay(zeroLength*2);
  }
}

void flashLaser(String BinaryChar)
{
  for (int i=0; i<7; i++){
    if(BinaryChar[i] == '0'){
      zero();
    } else if (BinaryChar[i] == '1'){
      one();
    }
  }
}

void zero()
{
  digitalWrite(13, HIGH);
  delay(zeroLength);
  digitalWrite(13, LOW);
  delay(zeroLength);
}

void one()
{
  digitalWrite(13, HIGH);
  delay(oneLength);
  digitalWrite(13, LOW);
  delay(zeroLength);
} 
