#include <stdio.h>
#include <kipr/wombat.h>

int main() {
  while(1) {
    int ir = analog(1);
    printf("%d\n", ir);
    if(ir>1600) {
      motor(0, 50);
      motor(3, 10);
    } else {
      motor(0, 10);
      motor(3, 50);
    }
  }
  alloff();
  return 0;
}
