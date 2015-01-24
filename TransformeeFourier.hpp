#pragma once

#include <string>
#include <vector>
#include <stdlib.h>
#include <complex>
#include <fstream>
#include <sstream>
#include <iostream>
#include <math.h>
#include "Contour.hpp"

class TransformeeFourier{

public :
	TransformeeFourier() =default;
	TransformeeFourier(const Contour & contour);
	TransformeeFourier(const std::vector<std::complex<double>> & contour);
	
	void transformeeFourier(const std::vector<std::complex<double>> & contour);
	void FFT(const std::vector<std::complex<double>> & contour);
	std::vector<std::complex<double>> inverse();
	
	const std::complex<double> & getValue(int indice)const;
	const std::vector<std::complex<double>>& getTabComplex()const;
	void affichage()const;
	
private :
	std::vector<std::complex<double>> tabComplex;
		
};

