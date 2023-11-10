/*正向锯齿波*/
#include "conio.h"

#define PORT 0x600

//======基本延时程序======
void delay(int x) {
  int i, j;
  for (i = 0; i < x; i++) {
    for (j = 0; j < 0x5000; j++)
      ;
  }
}

int main() {
  int data;

  while (1) {
    while (!Kbhit()) {
      for (data = 0; data < 256; data++) {
        outportb(PORT, data);
        delay(100);
      }
    }
  }

  return 0;
}