#include <stdio.h>
#include <math.h>
#define FREQ 5
#define width 60
#define chr "*"

void plot(int x , float y);

int main() {
  int x;
  float y,
        pi = 3.14159265359;

  for(x = 0; x < 360; x++) {
    y = 0.5*sin(FREQ*x*pi/180)+0.5;
    plot(x, y);
}
  printf("0.0|");
    for (int i=0; i<width+1; i++){
      printf("-");
}
  printf("|1.0 \n");
  return 0;
}
void plot(int x, float y) {
  int q = (width*y)+1;
  int r = (width-q)+6;

  if (y == 0) {
    printf("%03d %s %*.3f\n", x, chr, r, y);
  }
  else if (y == 1) {
    printf("%03d %*s %.3f\n", x, q, chr, y);
  }
  else {
    printf("%03d %*s %*.3f\n", x, q, chr, r, y);
  }
  return;
}
