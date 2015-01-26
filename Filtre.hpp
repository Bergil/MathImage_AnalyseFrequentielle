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

class Filtre {
	public :
		virtual void operator()(TransformeeFourier::Signal & tf)const =0;
	
};


class FiltreHaut : public Filtre{
	public : 
		virtual void operator()(TransformeeFourier::Signal  & tf)const override;
		
		FiltreHaut(double f) : frequence(f){}
		
	private :
		double frequence;
};

class FiltreBas : public Filtre{
	public : 
		virtual void operator()(TransformeeFourier::Signal  & tf)const override;
		
		FiltreBas(double f) : frequence(f){}
		
	private :
		double frequence;
};

class FiltreGaussien : public Filtre{
	public : 
		virtual void operator()(TransformeeFourier::Signal  & tf)const override;
		
		FiltreGaussien(double e, double et, double c) : esperance(e), ecarttype(et), centreF(c){}
		
	private : 
		double esperance;
		double ecarttype;
		double centreF;
};
