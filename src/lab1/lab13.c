#include "conio.h"

#define PA_PORT 0x600
#define PB_PORT 0x602
#define PC_PORT 0x604
#define CTRL_PORT 0x606

#define DATA_A 0x80
#define DATA_B 0x01

void delay(void);

int main(void) {
  int data;
  int status;
  outportb(0x606, 0x87); // A 工作在方式 0 并作为输出口，端口 B 工作在方式 1
                         // 并作为输入口，C 的 PC 2 输出

  while (1) {
    // 查询方式查询端口B，输出到端口A
    do {
      // 读取C口的状态
      status = inportb(PC_PORT);

      status = status & 0x02;
    } while (status != 0x02);

    // 读取B口的数据
    data = inportb(PB_PORT);

    // 输出到A口
    outportb(PA_PORT, data);
  }

  return 0;
}

// 手动延时程序
void delay(void) {
  int i, j;
  for (i = 0; i < 1000; i++)
    for (j = 0; j < 100; j++)
      ;
}