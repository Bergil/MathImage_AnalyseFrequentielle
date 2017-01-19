#include "Filtre.hpp"

void FiltreHaut::operator()(TransformeeFourier::Signal  & tf)const {
	for(unsigned int i = 0; i < tf.size() && i < frequence; i++)
		tf[i] =  std::complex<double>(0,0);
}

void FiltreBas::operator()(TransformeeFourier::Signal  & tf)const {
	for(unsigned int i = frequence + 1; i < tf.size(); i++)
		tf[i] = std::complex<double>(0,0);
}

void FiltreGaussien::operator()(TransformeeFourier::Signal  & tf)const {
	for(unsigned int i = 0; i < tf.size(); i++) {
		double fGauss = exp(-((i -centreF -esperance)*(i -centreF -esperance)/(2*ecarttype*ecarttype))) ;
		tf[i] *= fGauss;
	}
}

