/*负向锯齿波*/
#include "conio.h"

#define PORT 0x600

//======基本延时程序======
void delay(int x) {
  int i, j;
  for (i = 0; i < x; i++) {
  }
}

int main() {
  int data;

  while (1) {
    for (data = 255; data >= 0; data--) {
      outportb(PORT, data);
      delay(500);
    }
  }

  return 0;
}