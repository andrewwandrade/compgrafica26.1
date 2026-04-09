#include "Render2D_v1.h"
#include "bezier.h"
#include "matrix.h"
#include "transforms2d.h"

int main(){
    std::vector<vec2> CP = loadCurve("coracao.txt"); //Importa o arquivo com os pontos de controle que definem o formato da curva.
    std::vector<vec2> P = sample_bezier_spline<3>(CP, 50); //Chama a função responsável pelo processo de poligonização de uma curva com os pontos de controle contidos no arquivo "coração.txt" e com 50 pequenos segmentos de reta para cada pedaço do coração.
    //Utilizada para transformar os pontos em uma curva suave.

    ImageRGB I(1200, 800);
    I.fill(black);

    mat3 S = scale(0.3, 0.3); //Diminui o tamanho original do coração
    mat3 W = window(0, 3, 0, 2); //Utilizada para respeitar a razão de aspecto, não deixando o desenho distorcido

    float espacamento = 0.335f; //Distância horizontal entre os corações

    //Cria a primeira camada de corações (de baixo para cima)
    for(int i=0; i<9; i++){
        //Faz a translação de cada coração para a direita
        mat3 T = translate(i*espacamento, 0.03); 

        //Combinação de transformações
        mat3 Total = W*T*S;

        //Renderiza os corações
        render2d(Total*P, LineStrip{P.size()}, red, I);
    }

    //Cria o desenho de círculo de corações
    float raio = 0.3f; //Define a distância do centro do círculo até o coração
    mat3 Traio = translate(raio, 0); //Afasta o coração do centro para criar o raio
    mat3 S2 = scale(0.2, 0.2); 
    mat3 W2 = window(-1.5, 1.5, -1, 1);

    int total_coracoes = 12; 

    for(int i=0; i<total_coracoes; i++){
        //Calcula o ângulo em radianos para cada um dos 12 corações.
        float angulo = i*2*M_PI/total_coracoes; 
        mat3 R = rotate_2d(angulo); //Matriz de rotação

        //Responsável pelo círculo central
        mat3 M_centro = W2*R*Traio*S2; 
        render2d(M_centro*P, LineStrip{P.size()}, green, I);

        //Responsável pelo meio círculo esquerdo (Centro movido para x=-1,5)
        mat3 T_esq = translate(-1.5f, 0.0f);
        mat3 M_esq = W2*T_esq*R*Traio*S2; 
        render2d(M_esq*P, LineStrip{P.size()}, blue, I);

        //Responsável pelo meio círculo direito (Centro movido para x=1,5)
        mat3 T_dir = translate(1.5f, 0.0f);
        mat3 M_dir = W2*T_dir*R*Traio*S2; 
        render2d(M_dir*P, LineStrip{P.size()}, blue, I);
    }

    //Cria a segunda camada de corações (topo)
    for(int i=0; i<9; i++){
        //Faz a translação de cada coração para a direita
        mat3 T = translate(i*espacamento, 1.7); 

        //Combinação de transformações
        mat3 Total = W*T*S;

        //Renderiza os corações
        render2d(Total*P, LineStrip{P.size()}, red, I);
    }

    I.save("output.png");
}
