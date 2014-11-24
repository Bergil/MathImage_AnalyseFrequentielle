#pragma once

#include <string>
#include <vector>
#include <stdlib.h>
#include <complex>
#include <fstream>
#include <sstream>
#include <iostream>
#include <math.h>


class Contour{

public :
	Contour() =default;
	Contour(int nbPoints);
	Contour(const Contour & contour) = default;
	Contour(const std::vector<std::complex<double>> & contour);
	Contour(const std::string& nomFichier);
	~Contour();
	
	void insertPointEnd(std::complex<double> & point);
	void deletePointEnd();
	std::vector<std::complex<double>> transformeeFourier();
	std::vector<std::complex<double>> recompoTransformeeFourier();
	std::complex<double> getPoint(int indice);
	std::vector<std::complex<double>> getTabComplex();
	std::vector<std::complex<double>> FFT();
	void affichageContour();
	
private :
	std::vector<std::complex<double>> tabComplex;	
};

