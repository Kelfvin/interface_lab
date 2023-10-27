
#include "conio.h"

void main(void) {
  int data;
  outportb(0x606, 0x90);
  while (1) {
    data = inportb(0x600);
    outportb(0x602, data);
  }
}