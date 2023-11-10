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

  outportb(CTRL_PORT, 0x36);


  outportb(C0_PORT, data_C0_low);
  outportb(C0_PORT, data_C0_high);


  outportb(CTRL_PORT, 0x76);

  outportb(C1_PORT, data_C1_low);
  outportb(C1_PORT, data_C1_high);

  while (1) {
  }

  return 0;
}