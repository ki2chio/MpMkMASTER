#define LCHCLK 4
#define STFCLK 7
#define SDI 8

int numbers[] = {192, 249, 164, 176, 153, 146, 130,248, 128, 144};//вывод символов от 0 до 9 согластно масиву
void setup()
{
    pinMode(LCHCLK, OUTPUT);
    pinMode(STFCLK, OUTPUT);
    pinMode(SDI,OUTPUT);

    digitalWrite(STFCLK,LOW);

    Serial.begin(9600);
}

void printLed(unsigned char num , unsigned char digit){
	digitalWrite(LCHCLK,LOW);
	if(num==4)num=8;
	if(num==3)num=4;		

    for (int i = 7; i >= 0; --i)
    {
    	digitalWrite(SDI, (digit>>i)&1);
    	digitalWrite(STFCLK,HIGH);
    	delayMicroseconds(2);
    	digitalWrite(STFCLK,LOW);
    }

    for (int i = 7; i >= 0; --i)
    {
    	digitalWrite(SDI, (num>>i)&1);
    	digitalWrite(STFCLK,HIGH);
    	delayMicroseconds(2);
    	digitalWrite(STFCLK,LOW);
    }

	digitalWrite(LCHCLK,HIGH);
}

void loop()
{  
	    for (int k = 9; k >= 0; --k){
			printLed(1,numbers[k]);
			delay(1000);
		}
}