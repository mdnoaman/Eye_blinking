/* Three PWM Outputs */

// ATtiny85 outputs
const int ledL = 0;
const int ledR = 1;

volatile uint8_t* Port[] = {&OCR0A, &OCR0B};
int Pin[] = {0, 1};

void setup() {
  pinMode(Pin[ledL], OUTPUT);
  pinMode(Pin[ledR], OUTPUT);
  // Configure counter/timer0 for fast PWM on PB0 and PB1
  TCCR0A = 3<<COM0A0 | 3<<COM0B0 | 3<<WGM00;
  TCCR0B = 0<<WGM02 | 3<<CS00; // Optional; already set
}

// Sets colour Red=0 Green=1 Blue=2 to specified intensity 0 (off) to 255 (max)
void Setled (byte led, byte amp) {
  *Port[led] = 255 - amp;
}

void loop()
{
//    upLR(1);
//    delay(1000);

    for (int j=500; j<2000; j++){

    if(j%71==0){
    dnL(4);
    upL(4);
    dnL(4);
    upL(4);
    dnL(4);
    upL(4);
    dnL(4);
    upL(4);
    delay(500+j);}

    if(j%73==0){
    dnR(4);
    upR(4);
    dnR(4);
    upR(4);
    dnR(4);
    upR(4);
    dnR(4);
    upR(4);
    delay(500+j);}
    
    if(j%31==0){
    dnL(4);
    delay(100);
    upL(4);
    delay(500+j);}

    if(j%37==0){
    dnR(4);
    delay(100);
    upR(4);
    delay(500+j);}
    
    if(j%19==0){
    dnLR(4);
    delay(200);
    upLR(4);
    delay(500+j);
    }
    if(j%23==0){
    dnLR(2);
    delay(500+j);
    upLR(2);
    delay(200);
    }    

    if(j%71==64){
    dnLR(4);
    upLR(4);
    dnLR(4);
    upLR(4);
    dnLR(4);
    upLR(4);
    dnLR(4);
    upLR(4);
    delay(500+j);}

    if(j%17==0){
    delay(500+j);
    }
    
    }
//    dnLR(1);
//    delay(1000);


}  

void upLR(byte stp) {
  for (int i = 0; i < 255; i = i + stp){
    Setled(0,i);
    Setled(1,i);
    delay(1);}
}

void dnLR(byte stp) {
  for (int i = 255; i >= 0; i = i - stp){
    Setled(0,i);
    Setled(1,i);
    delay(1);}
}

void upR(byte stp) {
  for (int i = 0; i < 255; i = i + stp){
    Setled(1,i);
    delay(1);}
}

void dnR(byte stp) {
  for (int i = 255; i >= 0; i = i - stp){
    Setled(1,i);
    delay(1);}
}

void upL(byte stp) {
  for (int i = 0; i < 255; i = i + stp){
    Setled(0,i);
    delay(1);}
}

void dnL(byte stp) {
  for (int i = 255; i >= 0; i = i - stp){
    Setled(0,i);
    delay(1);}
}

