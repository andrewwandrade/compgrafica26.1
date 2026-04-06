#include "../Image.h"

void over(ImageRGB& bg, ImageRGBA& img, int x0, int y0){
  int x1 = x0 + img.width();
  int y1 = y0 + img.height();  

  for(int y = std::max(y0, 0); y < y1 && y < bg.height(); y++)
     for(int x = std::max(x0, 0); x < x1 && x < bg.width(); x++){
          RGB& Bg = bg(x, y);
          vec4 C = img(x-x0, y-y0);
          float alpha = C[3];
          Bg = lerp(alpha, (vec3)Bg, toVec3(C));
     }
}

int main(){
 ImageRGB boneco{"boneco.png"};
 ImageRGBA olho{"../assets/olho.png"};
 ImageRGBA boca{"../assets/boca.png"};
 ImageRGBA insignia{"../assets/insignia.png"};
 ImageRGBA nariz{"../assets/nariz.png"};
 ImageRGBA espada{"../assets/adaga.png"};
 ImageRGBA cueca{"../assets/cueca.png"};

 // desenha o boneco no cenário
 over(boneco, olho, 250, 540);
 over(boneco, olho, 300, 540);
 over(boneco, espada, 425, 390);
 over(boneco, nariz, 280, 510);
 over(boneco, boca, 265, 450);
 over(boneco, insignia, 300, 350);
 over(boneco, cueca, 200, 120);

 boneco.save("output.png");
}