#include "Render2D_v1.h"
#include "bezier.h"
#include "polygon_triangulation.h"

int main(){
	std::vector<vec2> CP = loadCurve("coracao.txt");
	std::vector<vec2> P = sample_bezier_spline<3>(CP, 30);

	LineStrip L{P.size()};
	
   ImageRGB G(600, 600);
   G.fill(white);
   render2d(P, L, red, G);
   G.save("coracao.png");
}
