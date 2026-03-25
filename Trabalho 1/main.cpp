#include "Color.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb/stb_image_write.h>

//Define as dimensões da imagem
#define W 240
#define H 160

int main(){
   RGB I[H][W];

   //Define a imagem toda como azul
   for(int y = 0; y < H; y++)
      for(int x = 0; x < W; x++)
         I[y][x] = RGB(0x09BAF0);

   //Gera o chão marrom escuro (2a camada de marrom)
   for(int y = 0; y < 17; y++)
      for(int x = 0; x < W; x++)
         I[y][x] = RGB(0x532B02);
   
   //Gera o chão marrom escuro (1ª camada de marrom / da mesma cor do bloco de pedra)
   for(int x = 0; x < W; x++)
      I[0][x] = RGB(0x231C19);

   //Gera o chão marrom claro (3a camada de marrom)
   for(int y = 17; y < 23; y++)
      for(int x = 0; x < W; x++)
         I[y][x] = RGB(0x964B00);
   
   //Gera o chão verde (ideia de "grama")
   for(int y = 23; y < 28; y++)
      for(int x = 0; x < W; x++)
         I[y][x] = green;

   //Construção do fundo mais claro ----------------------------------------
   for(int y = 28; y < 54; y++)
      for(int x = 0; x < W; x++)
         I[y][x] = RGB(0xB2956E);

   for(int y = 54; y < 64; y++)
      for(int x = 0; x < 21; x++)
         I[y][x] = RGB(0xB2956E);
      
   for(int y = 64; y < 66; y++)
      for(int x = 0; x < 21; x++)
         I[y][x] = RGB(0x4EA563); //verde

   for(int y = 54; y < 61; y++)
      for(int x = 21; x < 41; x++)
         I[y][x] = RGB(0xB2956E);

   for(int y = 59; y < 61; y++)
      for(int x = 21; x < 41; x++)
         I[y][x] = RGB(0x4EA563); //verde

   for(int y = 54; y < 64; y++)
      for(int x = 101; x < W; x++)
         I[y][x] = RGB(0xB2956E);
   
   for(int y = 59; y < 61; y++)
      for(int x = 81; x < 101; x++)
         I[y][x] = RGB(0x4EA563); //verde
   
   for(int y = 54; y < 59; y++)
      for(int x = 81; x < 101; x++)
         I[y][x] = RGB(0xB2956E);
   
   for(int y = 64; y < 66; y++)
      for(int x = 101; x < 200; x++)
         I[y][x] = RGB(0x4EA563); //verde
   
   for(int y = 57; y < 64; y++)
      for(int x = 200; x < W; x++)
         I[y][x] = RGB(0x09BAF0); 
   
   for(int y = 57; y < 59; y++)
      for(int x = 200; x < W; x++)
         I[y][x] = RGB(0x4EA563); //verde
   
   for(int y = 54; y < 56; y++)
      for(int x = 41; x < 81; x++)
         I[y][x] = RGB(0x4EA563); //verde
   
   //Construção da ilha flutuante 1 (esquerda) ----------------------------------------
   
   //Gera o marrom da ilha
   for(int y = 67; y < 76; y++)
      for(int x = 31; x < 74; x++)
         I[y][x] = RGB(0x964B00);

   //Gera a "grama" da ilha
   for(int y = 76; y < 81; y++)
      for(int x = 31; x < 74; x++)
         I[y][x] = green;

   //"Arrendoda" a ilha
   I[67][31] = RGB(0x09BAF0);
   I[67][32] = RGB(0x09BAF0);
   I[67][33] = RGB(0x09BAF0);
   I[68][31] = RGB(0x09BAF0);
   I[68][32] = RGB(0x09BAF0);
   I[69][31] = RGB(0x09BAF0);

   I[67][73] = RGB(0x09BAF0);
   I[67][72] = RGB(0x09BAF0);
   I[67][71] = RGB(0x09BAF0);
   I[68][73] = RGB(0x09BAF0);
   I[68][72] = RGB(0x09BAF0);
   I[69][73] = RGB(0x09BAF0);

   //Construção da ilha flutuante 2 (direita) ---------------------------------------
   
   //Gera o marrom da ilha
   for(int y = 80; y < 89; y++)
      for(int x = 166; x < 211; x++)
         I[y][x] = RGB(0x964B00);
   
   //Gera a "grama" da ilha
   for(int y = 89; y < 94; y++)
      for(int x = 166; x < 211; x++)
         I[y][x] = green;
   
   //"Arrendoda" a ilha
   I[80][166] = RGB(0x09BAF0);
   I[80][167] = RGB(0x09BAF0);
   I[80][168] = RGB(0x09BAF0);
   I[81][166] = RGB(0x09BAF0);
   I[81][167] = RGB(0x09BAF0);
   I[82][166] = RGB(0x09BAF0);

   I[80][210] = RGB(0x09BAF0);
   I[80][209] = RGB(0x09BAF0);
   I[80][208] = RGB(0x09BAF0);
   I[81][210] = RGB(0x09BAF0);
   I[81][209] = RGB(0x09BAF0);
   I[82][210] = RGB(0x09BAF0);

   stbi_flip_vertically_on_write(true);
   stbi_write_png("assets/output.png", W, H, 3, I, 0);
}
