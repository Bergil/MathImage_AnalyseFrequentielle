#include "FourierContour.hpp"


void FourierContour::transformeeFourier(double pas, std::vector<std::complex<double>> tabComplexContour){
	
	double N = tabComplexContour.size();
	tabComplex.resize((int)(N/pas)); //nombre de points en fonction du pas
	
	for(double j = -N/2; j < N/2; j+= pas){
		tabComplex[(j+(N/2))/pas] = 0;
		for(double i = 0; i < N; i ++){	
			std::complex<double> c(0.0, ((j+(N/2))/pas)*i*M_PI*2.0/N);
			tabComplex[(j+(N/2))/pas] += tabComplexContour[i] * exp(-c);
		}
		tabComplex[(j+(N/2))/pas] /= N;		
	}
}
