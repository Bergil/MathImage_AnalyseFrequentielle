#pragma once

#include <string>
#include <vector>
#include <stdlib.h>
#include <complex>
#include <fstream>
#include <sstream>
#include <iostream>
#include <math.h>
#include "Filtre.hpp"
#include "TransformeeFourier.hpp"

class TransformeeFourier2D{
	
public:
	using MatrixComplex = std::vector<std::vector<std::complex<double>>>; //utile pour la transpo (que sur des complex pas forcément
																		  //fourier)(et puis ça ajoute sémantique alors ...)
	TransformeeFourier2D() =default;
	TransformeeFourier2D(const MatrixComplex & image); 
	
	void fourier2D(const MatrixComplex & image);
	MatrixComplex inverse(); //retourne l'image
	void filtre(const Filtre& f);
	static MatrixComplex transpose(const MatrixComplex& tf);
	
private:
	MatrixComplex tabComplex2D;
	
};
