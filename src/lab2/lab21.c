#include "conio.h"
#define C0_PORT 0x600
#define C1_PORT 0x602
#define C2_PORT 0x604
#define CTRL_PORT 0x606

int main() {

  int N0 = 62500; // 62500*16=10^6
  int N1 = 16;

  int data_C0_low = N0 % 256;
  int data_C0_high = N0 / 256;
  int data_C1_low = N1 % 256;
  int data_C1_high = N1 / 256;

  // 先写入计数器0的控制字
  outport(CTRL_PORT, 0x36);

  // 计数器0计数初始化
  outport(C0_PORT, data_C0_low);
  outport(C0_PORT, data_C0_high);

  // 写入计数器1的控制字
  outport(CTRL_PORT, 0x76);

  // 计数器1计数初始化
  outport(C1_PORT, data_C1_low);
  outport(C1_PORT, data_C1_high);

  while (1) {
  }

  return 0;
}