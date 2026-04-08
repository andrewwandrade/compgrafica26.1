#include "Image.h"
#define W 600
#define H 600

int main(){
   ImageRGB I(W, H);
   vec3 A = red, B = blue, C = green, D = yellow;
   for (int y = 0; y < H; y++){
       for (int x = 0; x < W; x++){
           float u = x/(W-1.0f);
           float v = y/(H-1.0f);
           I(x,y) = bilerp(u, v, A, B, C, D);
       }
   }
   I.save("output.png");
}
