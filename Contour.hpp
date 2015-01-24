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
	
	void insertPointEnd(std::complex<double> & point);
	void deletePointEnd();
	
	const std::complex<double>& getPoint(int indice)const;
	const std::vector<std::complex<double>>& getTabComplex() const;
	void setTabComplex(const std::vector<std::complex<double>>& newtab);

	void affichage()const;
	
private :
	std::vector<std::complex<double>> tabComplex;	
};

