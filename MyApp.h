#ifndef MYAPP_H
#define MYAPP_H

#include <QApplication>
#include <QFont>
#include <QPushButton>
#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QFileDialog>
#include <QRgb>
#include <QMessageBox>
#include <QSpinBox>


#include <string>
#include <complex>
#include "TransformeeFourier2D.hpp"
#include "TransformeeFourier.hpp"

class MyApp : public QWidget{

    //autorise le public slots
    Q_OBJECT

    public :
        //elements
        QPushButton *charger;
        QPushButton * sauver;
        bool addPointEnable;

        QString pathImg;
        QLabel * zoneImage;
        QImage * img;
        TransformeeFourier2D::MatrixComplex imgFourier;

        QLabel * zoneResultat;
        QImage * resultat;

        QPushButton * filtreBas;
        QPushButton * filtreHaut;
        QSpinBox * ValFrequence;


        TransformeeFourier::Signal pts;

        MyApp(QWidget * parent = 0);


        void QImage2ImageFourier();
        void ImageFourier2Resultat();


    public slots :
        void loadImage();
        void saveImage();
        void setFiltreBas();
        void setFiltreHaut();

};

#endif // MYAPP_H
