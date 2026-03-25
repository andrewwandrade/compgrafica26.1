#include "Image.h"

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

    //Importa os elementos do cenário
    ImageRGB img{"assets/output.png"};
    ImageRGBA boy1{"assets/personagem2.png"};
    ImageRGBA boy2{"assets/personagem3.png"};
    ImageRGBA boy3{"assets/personagem4.png"};
    ImageRGBA monstro{"assets/personagem5.png"};
    ImageRGBA arbusto{"assets/arbusto.png"};
    ImageRGBA arbusto2{"assets/arbusto2.png"};
    ImageRGBA arvore{"assets/arvore2.png"};
    ImageRGBA arvore2{"assets/arvore3.png"};
    ImageRGBA chaopedra{"assets/chao_pedra.png"};
    ImageRGBA barradevida{"assets/redbar_02.png"};
    ImageRGBA expstress{"assets/expression_stress.png"};
    ImageRGBA nuvem{"assets/nuvem.png"};

    //Desenha os elementos no cenário
    over(img, boy1, 165, 94);
    over(img, boy2, 45, 78);
    over(img, boy3, 180, 28);
    over(img, monstro, 190, 94);
    over(img, arbusto, 210, 28);
    over(img, arbusto2, 4, 28);
    over(img, arvore, 7, 28);
    over(img, arvore2, 75, 28);
    over(img, barradevida, 198, 110);
    over(img, expstress, 64, 92);

    //Desenha o bloco de pedra no chão
    for(int i=0; i<240; i+=15){
     over(img, chaopedra, i, 0);
    }

    //Desenha as camadas de nuvens no cenário
    for(int i=-15; i<240; i+=45){
     over(img, nuvem, i, 140);
    }

    for(int i=10; i<240; i+=70){
     over(img, nuvem, i, 130);
    }

    img.save("trabalhofinal.png");
}