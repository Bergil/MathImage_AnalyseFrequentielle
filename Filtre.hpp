#pragma once

#include <string>
#include <vector>
#include <stdlib.h>
#include <complex>
#include <fstream>
#include <sstream>
#include <iostream>
#include <math.h>
#include "TransformeeFourier.hpp"

class Filtre{
	public :
		virtual void operator()(TransformeeFourier & tf) =0;
	
};


class FiltreHaut : public Filtre{
	public : 
		virtual void operator()(TransformeeFourier & tf) override;
		
		FiltreHaut(double a);
		
	private :
		double amplitude;
};

class FiltreBas : public Filtre{
	public : 
		virtual void operator()(TransformeeFourier & tf) override;
		
		FiltreBas(double a);
		
	private :
		double amplitude;
};

class FiltreGaussien : public Filtre{
	public : 
		virtual void operator()(TransformeeFourier & tf) override;
		
		
};
