/*T
his sketch is made by gada888 from LUOYANG.
Date:2021-28-01
The MP3 module is from DFRobot.it is a new replacement of DFPlayer mini.
Voice Module
SKU:DFR0534
*/

#include <SoftwareSerial.h>
SoftwareSerial Serial1(10, 11);
unsigned char order[4] = {0xAA,0x06,0x00,0xB0};
# define IR1 2
# define IR2 3                        // keys of piano
# define IR3 4
# define IR4 5
# define IR5 6
# define IR6 7
//******************************************
void setup() {
pinMode(IR1,INPUT);
pinMode(IR2,INPUT);
pinMode(IR3,INPUT);
pinMode(IR4,INPUT);
pinMode(IR5,INPUT);
pinMode(IR6,INPUT);
Serial1.begin(9600);
volume(0x1E);//音量设置0x00-0x1E
}

//*******************************************
void loop() {
int  status1 = digitalRead(IR1); 
if(status1 == 0){                                                     // simple if statements to give output to buzzer if input is low
play(0x01);//指定播放:0x01-文件0001
delay(1000);
}
int  status2 = digitalRead(IR2); 
if(status2 == 0){                                                     // simple if statements to give output to MP3 if input is low
play(0x03);//指定播放:0x02
delay(1000);
}
int  status3 = digitalRead(IR3); 
if(status3 == 0){                                                     // simple if statements to give output to MP3 if input is low
play(0x03);//指定播放:0x03
delay(1000);
}
int  status4 = digitalRead(IR4); 
if(status4 == 0){                                                     // simple if statements to give output to MP3 if input is low
play(0x04);//指定播放:0x04
delay(1000);
}
int  status5 = digitalRead(IR5); 
if(status5 == 0){                                                     // simple if statements to give output to MP3 if input is low
play(0x03);//指定播放:0x03
delay(1000);
}
int  status6 = digitalRead(IR6); 
if(status6 == 0){                                                     // simple if statements to give output to MP3 if input is low
play(0x06);//指定播放:0x04
delay(1000);
}
}

//****************************************
void play(unsigned char Track)
{
unsigned char play[6] = {0xAA,0x07,0x02,0x00,Track,Track+0xB3};//0xB3=0xAA+0x07+0x02+0x00,即最后一位为校验和
Serial1.write(play,6);
}
void volume( unsigned char vol)
{
unsigned char volume[5] = {0xAA,0x13,0x01,vol,vol+0xBE};//0xBE=0xAA+0x13+0x01,即最后一位为校验和
Serial1.write(volume,5);
}
