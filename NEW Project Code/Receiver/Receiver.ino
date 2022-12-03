// ECE 597 SD Project

int val = 0;
int ctrHigh = 0;
int ctrLow = 0;
int zeroLen = 4;  // 400 // 80 // 64  // 32 // 8  // 4
String toPrint = "";

void setup()
{
  Serial.begin(115200);
  Serial.println("Starting...");
}

void loop()
{
  val = analogRead(A4);

  if (val >= 30) {
    ctrHigh++;
    ctrLow = 0;
  }
  else {
    ctrLow++;
    if ((ctrHigh >= zeroLen) && (ctrHigh < zeroLen*2)) {
      // Serial.print("0");
      toPrint += "0";
    } 
    else if (ctrHigh >= zeroLen * 2) {
      // Serial.print("1");
      toPrint += "1";
    } 
    else {
      if(ctrLow == zeroLen*3){
        long dec = strtol(toPrint.c_str(), NULL, 2);
        Serial.print(char(dec));
        toPrint = "";
      }
    }
    ctrHigh = 0;
  }
}
