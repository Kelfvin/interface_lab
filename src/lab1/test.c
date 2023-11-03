#include "conio.h"

#define PA_PORT 0x600
#define PB_PORT 0x602
#define PC_PORT 0x604
#define CTRL_PORT 0x606

#define DATA_A 0x80
#define DATA_B 0x01

void delay(void);

void main(void) {
  int i, j;

  outportb(0x606, 0x80); // 将AB口均设置成0方式都是输出

  //   依次左移
  while (1) {
    int data_B = DATA_B;
    int data_A = DATA_A;
    // 先输出到A口
    for (i = 0; i < 8; i++) {
      outportb(PA_PORT, data_A);
      outportb(PB_PORT, data_B);
      data_A = data_A >> 1;
      data_B = data_B << 1;
      delay();
    }
  }
}

// 手动延时程序
void delay(void) {
  int i, j;
  for (i = 0; i < 1000; i++)
    for (j = 0; j < 100; j++)
      ;
}