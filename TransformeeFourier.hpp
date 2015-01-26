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

	using Signal = std::vector<std::complex<double>>;
	TransformeeFourier() =default;
	TransformeeFourier(const Contour & contour);
	TransformeeFourier(const Signal & contour);
	
	void fourier(const Signal & contour);
	static Signal FFT(const Signal & contour);
	
	Signal inverse();
	static Signal inverse(const Signal & signal);
	
	const std::complex<double> & getValue(int indice)const;
	void setValue(int indice, std::complex<double> value);
	const Signal& getSignal()const;
	Signal& getSignal();
	void setSignal(const Signal &s) {tabComplex = s;}
	void affichage()const;
	
private :
	Signal tabComplex;
	
};

