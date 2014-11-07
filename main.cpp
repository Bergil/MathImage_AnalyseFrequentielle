#include <iostream>
#include "FourierContour.hpp"

int main(int argc, char * argv[])
{
	Contour cont(5);
	for(unsigned int i =0; i < cont.tabComplex.size(); i++){
		std::complex<double> c(i, i*2);
		cont.insertPointEnd(c);
	}
	FourierContour fcont(cont.getTabComplex().size());
	fcont.transformeeFourier(0.5, cont.getTabComplex());
	
	fcont.affichageContour();
    return 0;
}

