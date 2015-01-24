 
#include "TransformeeFourier.hpp"
#include <bitset>

TransformeeFourier::TransformeeFourier(const std::vector<std::complex<double>> & contour){
	FFT(contour);
}

TransformeeFourier::TransformeeFourier(const Contour & contour){
	FFT(contour.getTabComplex());
}

void TransformeeFourier::transformeeFourier(const std::vector<std::complex<double>> & contour){
	
	std::vector<std::complex<double>> returnTransfoFourier;
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

std::vector<std::complex<double>> TransformeeFourier::inverse(){
	
	std::vector<std::complex<double>> returnRecompoTransfoFourier;
	double N = tabComplex.size();
	returnRecompoTransfoFourier.resize((int)(N));
	
	for(double j = -N/2; j < N/2; j++){
		returnRecompoTransfoFourier[(j+(N/2))] = 0;
		for(double i = 0; i < N; i ++){	
			std::complex<double> c(0.0, ((j+(N/2)))*i*M_PI*2.0/N);
			returnRecompoTransfoFourier[(j+(N/2))] += tabComplex[i] * exp(c);
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

void TransformeeFourier::FFT(const std::vector<std::complex<double>> & contour){
	int taille = contour.size();
	if(!power_of_two(taille))
		taille = (1 << (nb_bits_utile(taille) + 1));
		
	tabComplex.resize(taille, 0);
	
	int nbBits = nb_bits_utile(contour.size()-1);
	for(unsigned int i = 0; i < contour.size(); i++){
		tabComplex[inverseBinaire(i, nbBits)] = contour[i];
	}
	int power = 1;
	std::complex<double> t1, t2;
	for(int s = 1; s <= std::log2(taille); s++){
		power = power << 1;
		for(int k = 0; k < taille; k += power){
			for(int l = k; l < k + power/2; l++){
				std::complex<double> c(0.0, -M_PI*(l - k)/(power/2));
				t1 = tabComplex[l];
				t2 = std::exp(c) * tabComplex[l+power/2];
				tabComplex[l] = 0.5*(t1 + t2);
				tabComplex[l + power/2] = 0.5*(t1 - t2);
			}
		}
	}
		
}
	

const std::complex<double>& TransformeeFourier::getValue(int indice)const{
	return tabComplex[indice];
}

const std::vector<std::complex<double>>& TransformeeFourier::getTabComplex()const{
	return tabComplex;
}

void TransformeeFourier::affichage()const{
	
	for(auto i : tabComplex){
		std::cout << "Valeur : "<< i <<"\n";
	}
}


	
