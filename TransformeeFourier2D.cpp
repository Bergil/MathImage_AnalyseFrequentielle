#include "TransformeeFourier2D.hpp"


TransformeeFourier2D::TransformeeFourier2D(const MatrixComplex & image){
	fourier2D(image);
}

void TransformeeFourier2D::fourier2D(const MatrixComplex & image){
	MatrixComplex temp;
	for (auto i : image){
		temp.push_back(TransformeeFourier::FFT(i));
	}
	temp = transpose(temp);
	for (auto t : temp){
		tabComplex2D.push_back(TransformeeFourier::FFT(t));
	}
}

TransformeeFourier2D::MatrixComplex TransformeeFourier2D::inverse(){ //retourne l'image 
	MatrixComplex temp;
	for (auto i : tabComplex2D){
		temp.push_back(TransformeeFourier::inverse(i));
	}
	temp = transpose(temp);
	for (auto &t : temp){
		t = TransformeeFourier::inverse(t);
	}
	return temp;
}

void TransformeeFourier2D::filtre (const Filtre& f){
	for (auto i : tabComplex2D){
		f(i);
	}
	tabComplex2D = transpose(tabComplex2D);
	for (auto i : tabComplex2D){
		f(i);
	}
	tabComplex2D = transpose(tabComplex2D);
}

TransformeeFourier2D::MatrixComplex TransformeeFourier2D::transpose(const MatrixComplex& tf){
	MatrixComplex temp;
	temp.resize(tf[0].size());
	for(unsigned int i =0; i < temp.size(); i++){
		temp[i].resize(tf.size());
		for(unsigned int j = 0; temp[i].size(); j++){
			temp[i][j] = tf[j][i];
		}
	}
	return temp;
}
	
