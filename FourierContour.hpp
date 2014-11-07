#pragma once

#include "Contour.hpp"

class FourierContour : public Contour {
	
public : 
	void transformeeFourier(double pas, std::vector<std::complex<double>> tabComplexContour);
		
};
