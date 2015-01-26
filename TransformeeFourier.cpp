 
#include "TransformeeFourier.hpp"
#include <bitset>

TransformeeFourier::TransformeeFourier(const std::vector<std::complex<double>> & contour){
	tabComplex = FFT(contour);
}

TransformeeFourier::TransformeeFourier(const Contour & contour){
	tabComplex = FFT(contour.getTabComplex());
}

void TransformeeFourier::fourier(const Signal & contour){
	
	Signal returnTransfoFourier;
	double N = contour.size();
	tabComplex.resize((int)(N)); 
	
	for(double j = -N/2; j < N/2; j++){
		tabComplex[(j+(N/2))] = 0;
		for(double i = 0; i < N; i ++){	
			std::complex<double> c(0.0, ((j+(N/2)))*i*M_PI*2.0/N);
			tabComplex[(j+(N/2))] += contour[i] * exp(-c);
		}
		tabComplex[(j+(N/2))] /= N;		
	}
	
}

TransformeeFourier::Signal TransformeeFourier::inverse(){
	return inverse(tabComplex);	
}

TransformeeFourier::Signal TransformeeFourier::inverse(const Signal & signal){
	Signal returnRecompoTransfoFourier;
	double N = signal.size();
	returnRecompoTransfoFourier.resize((int)(N));
	
	for(double j = -N/2; j < N/2; j++){
		returnRecompoTransfoFourier[(j+(N/2))] = 0;
		for(double i = 0; i < N; i ++){	
			std::complex<double> c(0.0, ((j+(N/2)))*i*M_PI*2.0/N);
			returnRecompoTransfoFourier[(j+(N/2))] += signal[i] * exp(c);
		}	
	}
	return returnRecompoTransfoFourier;
}


bool power_of_two(int a)
{
    if(a%2 != 0) return false;
    else if(a == 2) return true;
    else return power_of_two(a/2);
}

unsigned int nb_bits_utile(int v){
	if(v)
		return 1+ nb_bits_utile(v/2);
	else
		return 0;
}

unsigned int inverseBinaire(int nombre, int nbBits){
	
	int res = 0;
	for (int i = 0; i < nbBits; i++){
		res |= (nombre&1);
		if(i < nbBits-1){
			res <<=1;
			nombre >>=1;
		}
	}
	
	return res;
}

TransformeeFourier::Signal TransformeeFourier::FFT(const Signal & contour){
	Signal tempComplex;
	int taille = contour.size();
	if(!power_of_two(taille))
		taille = (1 << (nb_bits_utile(taille) + 1));
		
	tempComplex.resize(taille, 0);
	
	int nbBits = nb_bits_utile(contour.size()-1);
	for(unsigned int i = 0; i < contour.size(); i++){
		tempComplex[inverseBinaire(i, nbBits)] = contour[i];
	}
	int power = 1;
	std::complex<double> t1, t2;
	for(int s = 1; s <= std::log2(taille); s++){
		power = power << 1;
		for(int k = 0; k < taille; k += power){
			for(int l = k; l < k + power/2; l++){
				std::complex<double> c(0.0, -M_PI*(l - k)/(power/2));
				t1 = tempComplex[l];
				t2 = std::exp(c) * tempComplex[l+power/2];
				tempComplex[l] = 0.5*(t1 + t2);
				tempComplex[l + power/2] = 0.5*(t1 - t2);
			}
		}
	}
	return tempComplex;
}

const std::complex<double>& TransformeeFourier::getValue(int indice)const{
	return tabComplex[indice];
}

void TransformeeFourier::setValue(int indice, std::complex<double> value ){
	tabComplex[indice] = value;
}	

const TransformeeFourier::Signal& TransformeeFourier::getSignal()const{
	return tabComplex;
}

TransformeeFourier::Signal& TransformeeFourier::getSignal(){
	return tabComplex;
}

void TransformeeFourier::affichage()const{
	for(auto i : tabComplex){
		std::cout << "Valeur : "<< i <<std::endl;
	}
	for(auto i : tabComplex){
		std::cout << "Valeur Normée: "<< std::norm(i) <<std::endl;
	}
}

	
