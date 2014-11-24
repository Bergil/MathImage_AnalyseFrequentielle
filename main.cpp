#include <iostream>
#include "Contour.hpp"

int main(int argc, char * argv[])
{
	Contour cont;
	
	for(unsigned int i =0; i < 4; i++)
	{
		std::complex<double> c(i, i*2);
		cont.insertPointEnd(c);
	}
	cont.affichageContour();
	Contour transfoFourier(cont.transformeeFourier());
	transfoFourier.affichageContour();
	
	Contour recompoTransforFourier(transfoFourier.recompoTransformeeFourier());
	recompoTransforFourier.affichageContour();
	
	Contour FFTContour(cont.FFT());
	FFTContour.affichageContour();
    return 0;
}

