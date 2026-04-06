#include "../Image.h"

float G(float x, float y, float cx, float cy, float s){
	float dx = x - cx;
	float dy = y - cy;
	return 100*exp(-(dx*dx + dy*dy)/(s*s));
}

float F(float x, float y){
	return 50 
		- G(x, y, 300, 550, 55)  //cabeça
		- G(x, y, 300, 380, 100) //corpo
		- G(x, y, 300, 300, 50)  //cintura
        - G(x, y, 300, 250, 50)
        - G(x, y, 410, 390, 20)  //braço direito
        - G(x, y, 430, 390, 20)  
        - G(x, y, 450, 390, 20)  
        - G(x, y, 470, 390, 20)  
        - G(x, y, 490, 390, 20) 
        - G(x, y, 190, 390, 20)  //braço esquerdo
        - G(x, y, 180, 360, 20)  
        - G(x, y, 170, 330, 20)
        - G(x, y, 170, 300, 20)
        - G(x, y, 170, 270, 20)
        - G(x, y, 250, 210, 30)  // perna esquerda
        - G(x, y, 250, 170, 30)
        - G(x, y, 250, 130, 30)
        - G(x, y, 250, 90, 30)
        - G(x, y, 350, 210, 30)  // perna direita
        - G(x, y, 350, 170, 30)
        - G(x, y, 350, 130, 30)
        - G(x, y, 350, 90, 30);
}

int main(){
	ImageRGB img(600, 600);
	img.fill(white);
	for(int y = 0; y < img.height(); y++)
		for(int x = 0; x < img.width(); x++)
			if(F(x,y) <= 0)
				img(x,y) = gray;
		

	img.save("boneco.png");
}
