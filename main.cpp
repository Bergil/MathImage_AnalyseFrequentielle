#include <iostream>
#include "Contour.hpp"
#include "TransformeeFourier.hpp"

int main(int argc, char * argv[])
{
	Contour cont;
	
	for(unsigned int i =0; i < 8; i++)
	{
		std::complex<double> c(i, i*2);
		cont.insertPointEnd(c);
	}
	
	cont.affichage();
	TransformeeFourier transfoFourier;
	transfoFourier.transformeeFourier(cont.getTabComplex());
	std::cout<<"Transfo Fourier"<<std::endl;
	transfoFourier.affichage();
	
	Contour recompo(transfoFourier.inverse());
	std::cout<<"Recompo Fourier"<<std::endl;
	recompo.affichage();
	
	transfoFourier.FFT(cont.getTabComplex());
	std::cout<<"FFT"<<std::endl;
	transfoFourier.affichage();
	
	Contour recompoFFT(transfoFourier.inverse());
	std::cout<<"RecompoFFT"<<std::endl;
	recompoFFT.affichage();
    return 0;
}

