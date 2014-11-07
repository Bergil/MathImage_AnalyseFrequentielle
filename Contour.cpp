#include "Contour.hpp"

Contour::Contour(int nbPoints){
	tabComplex.resize(nbPoints);
}

Contour::Contour(const Contour & contour){
	tabComplex = contour.tabComplex;
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
	
	for(std::vector<std::complex<double>>::iterator i = tabComplex.begin(); i != tabComplex.end();){
		std::cout << "Point : "<< *i <<"\n";
	}
}


	
