#include "Contour.hpp"

Contour::Contour(int nbPoints) : 
	tabComplex(5, 0)
{
}

Contour::Contour(const std::vector<std::complex<double>> & contour) : tabComplex(contour){

}

Contour::Contour(const std::string& nomFichier){
	std::ifstream fichier;
    fichier.open(nomFichier, std::ifstream::in);
    if(fichier){
		double imag, real;
		
		while(fichier.good()){
			fichier >> real;
			fichier >> imag;
			std::complex<double> myComplex(real, imag);
			tabComplex.push_back(myComplex);
		}
		fichier.close();		  
     }
     else  
         std::cerr << "Impossible d'ouvrir le fichier !" << std::endl;
	
}

Contour::~Contour(){
	tabComplex.clear();
}

std::vector<std::complex<double>> Contour::transformeeFourier(){
	
	std::vector<std::complex<double>> returnTransfoFourier;
	double N = tabComplex.size();
	returnTransfoFourier.resize((int)(N)); 
	
	for(double j = -N/2; j < N/2; j++){
		returnTransfoFourier[(j+(N/2))] = 0;
		for(double i = 0; i < N; i ++){	
			std::complex<double> c(0.0, ((j+(N/2)))*i*M_PI*2.0/N);
			returnTransfoFourier[(j+(N/2))] += tabComplex[i] * exp(-c);
		}
		returnTransfoFourier[(j+(N/2))] /= N;		
	}
	
	return returnTransfoFourier;
}

std::vector<std::complex<double>> Contour::recompoTransformeeFourier(){
	
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

unsigned int inverseBinaire(int i){
	int nbBits = nb_bits_utile(i);
	return (~(i << (sizeof(int) - nbBits)))>>(sizeof(int) - nbBits);
}

std::vector<std::complex<double>> Contour::FFT(){
	std::vector<std::complex<double>> signalRetour;
	int taille = tabComplex.size();
	if(!power_of_two(taille))
		taille = (1 << (nb_bits_utile(taille) + 1));
		
	signalRetour.resize(taille, 0);
	
	for(int i = 0; i < tabComplex.size(); i++){
		signalRetour[inverseBinaire(i)] = tabComplex[i];
	}
	int power = 1;
	
	std::complex<double> t1, t2;
	for(int s = 1; s <= std::log2(taille); s++){
		power = power << 1;
		for(int k = 0; k < taille; k += power){
			for(int l = k; l < k + power/2; l++){
				std::complex<double> c(0.0, -M_PI*(l - k)/(power / 2));
				t1 = signalRetour[l];
				t2 = std::pow(std::exp(c), k) * signalRetour[l+power/2];
				signalRetour[l] = t1 + t2;
				signalRetour[l + power/2] = t1 - t2;
			}
		}
	}
	return signalRetour;
		
}
	

void Contour::insertPointEnd(std::complex<double> & point){
	tabComplex.push_back(point);
}

void Contour::deletePointEnd(){
	tabComplex.pop_back();
}

std::complex<double> Contour::getPoint(int indice){
	return tabComplex[indice];
}

std::vector<std::complex<double>> Contour::getTabComplex(){
	return tabComplex;
}

void Contour::affichageContour(){
	
	for(std::vector<std::complex<double>>::iterator i = tabComplex.begin(); i != tabComplex.end(); ++i){
		std::cout << "Point : "<< *i <<"\n";
	}
}


	
