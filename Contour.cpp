#include "Contour.hpp"
#include <bitset>

Contour::Contour(int nbPoints) : 
	tabComplex(nbPoints, 0)
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
	

void Contour::insertPointEnd(std::complex<double> & point){
	tabComplex.push_back(point);
}

void Contour::deletePointEnd(){
	tabComplex.pop_back();
}

const std::complex<double>& Contour::getPoint(int indice)const{
	return tabComplex[indice];
}

const std::vector<std::complex<double>>& Contour::getTabComplex() const{
	return tabComplex;
}

void Contour::setTabComplex(const std::vector<std::complex<double>>& newtab){
	tabComplex = newtab;
}

void Contour::affichage()const{
	
	for(auto i : tabComplex){
		std::cout << "Point : "<< i <<std::endl;
	}
}


	
