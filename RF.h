
void resetBuffer(unsigned int*, unsigned char);
void resetBufferChar(unsigned char*, unsigned char);
void send_rf(unsigned char, unsigned char*);
void zero(unsigned char);
void one(unsigned char);
void f(unsigned char);
unsigned char ArrayCompare(unsigned int*, unsigned int*, int, unsigned char);
unsigned char ArrayCompareChar(unsigned char*, unsigned char*, int, unsigned char);
void ArrayCopy(unsigned int*, unsigned int*, unsigned char);
void ArrayCopyChar(unsigned char*, unsigned char*, unsigned char);
unsigned char readSwitch_P2(unsigned char);
unsigned char readSwitch_P1(unsigned char);
void BlinkLED_P2(unsigned char);
void Blink2LED_P2(unsigned char, unsigned char);
