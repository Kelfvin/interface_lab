#include "conio.h"

#define PA_PORT 0x600
#define PB_PORT 0x602
#define PC_PORT 0x604
#define CTRL_PORT 0x606

// 手动延时程序
void delay(void) {
  int i, j;
  for (i = 0; i < 1000; i++)
    for (j = 0; j < 1000; j++)
      ;
}

void main(void) {
  outportb(0x606, 0x80); // 将AB口均设置成0方式都是输出
  //   循环
  int data = 0x01;
  //   依次左移
  while (1) {
    // 先输出到A口
    outportb(PA_PORT, data);
    delay();
    for (int i = 0; i < 7; i++) {
      data = data << 1;
      outportb(PA_PORT, data);
      delay();
    }

    data = 0x01;

    // 输出到B口
    outportb(PB_PORT, data);
    delay();
    for (int i = 0; i < 7; i++) {
      data = data << 1;
      outportb(PB_PORT, data);
      delay();
    }

    data = 0x01;
  }
}