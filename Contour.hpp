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
	Contour(int nbPoints);
	Contour(const Contour & contour);
	Contour(const std::string& nomFichier);
	~Contour();
	
	void insertPointEnd(std::complex<double> & point);
	void deletePointEnd();
	std::complex<double> getPoint(int indice);
	std::vector<std::complex<double>> getTabComplex();
	void affichageContour();
	
private :
	std::vector<std::complex<double>> tabComplex;	
};
