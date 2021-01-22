/*
Arduino_GB231_library
函数：
    getfont(<字符串>, <长度>, <回传（unsigned char xxx [32]）>);

*/



#include <Arduino_GB231_library.h>
void setup() {

  Serial.begin(115200);
  Serial.println("\r\n");
  
  unsigned char  names1[] = "小";
  unsigned char  names2[] = "可";
  unsigned char  names3[] = "爱";
  dps( names1);
  dps( names2);
  dps( names3);
  }

void loop() {
  // put your main code here, to run repeatedly:

}



void dps (unsigned char*names){
  unsigned char buffs[32];
  //建立缓存空间
  getfont(names, sizeof(names), buffs);
  //获取当前字符串数组
  unsigned char zwbuff[256];
  //建立缓存空间
  int kj = 0;
  for (int i = 0; i < 32; i++) {
    for (int s = 7 ; s > 0 ; s--)
    {
      if (buffs[i] & (0x01 << s))
      {
         zwbuff[kj++] =  1;
         Serial.print(" 0 ");
      }
      else {
       zwbuff[kj++]  = 0;
       Serial.print("   ");
      }
    }
    if ((i + 1) % 2 == 0)Serial.println("");
  }

  Serial.println("");
  }
