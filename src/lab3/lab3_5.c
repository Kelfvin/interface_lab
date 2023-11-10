/*梯形波*/
#include "conio.h"

#define PORT 0x600
// 1/0.02 = 50
#define MIN = 50
#define MID = 150
#define MIDH = 200
#define MAX = 250

//======基本延时程序======
void delay(int x) {
  int i, j;
  for (i = 0; i < x; i++) {
  }
}

int main() {
  int data[4] = {MID, MAX, MIDH, MIN};

  while (1) {
    for (int i = 0; i < 4; i++) {
      outportb(PORT, data[i]);
      delay(500);
    }
  }

  return 0;
}