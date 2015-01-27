#include "MyApp.h"

extern QString imgPath;

MyApp :: MyApp (QWidget * parent) : QWidget(parent){

    addPointEnable = false;
    setFixedSize(1280, 630);
    setWindowTitle("ouh ouh");

   // bouton charger
    charger = new QPushButton("Charger", this);
    charger->setGeometry(10,10,150,30);

    //lie le bouton charger avec l'ouverture de fichier
    QObject :: connect(charger, SIGNAL(clicked()), this, SLOT(loadImage()));

    //bouton selction de contour
    sauver = new QPushButton("Sauvegarder", this);
    sauver->setGeometry(10,45,150,30);
    QObject :: connect(sauver, SIGNAL(clicked()), this, SLOT(saveImage()));

    //image (zone visuel)
    zoneImage = new QLabel(this);

    zoneImage->setGeometry(10, 100, 512, 512);
    zoneImage->setScaledContents(true);

    //image (donnée)
    img = new QImage();

    zoneResultat = new QLabel(this);
    zoneResultat->setGeometry(530,100,512,512);
    zoneResultat->setScaledContents(true);


    QLabel * frequence = new QLabel(this);
    frequence->setText("Fréquence");
    frequence->setAlignment(Qt :: AlignRight);
    frequence->setGeometry(300,50,150,30);

    ValFrequence = new QSpinBox(this);
    ValFrequence->setGeometry(480,45,50,30);

    filtreBas = new QPushButton("Filtre bas", this);
    filtreBas->setGeometry(550,10,150,30);
    QObject :: connect(filtreBas, SIGNAL(clicked()), this, SLOT(setFiltreBas()));

    filtreHaut = new QPushButton("Filtre bas", this);
    filtreHaut->setGeometry(550,45,150,30);
    QObject :: connect(filtreHaut, SIGNAL(clicked()), this, SLOT(setFiltreHaut()));


}

void MyApp :: loadImage(){
    pathImg = QFileDialog :: getOpenFileName(this, "Chager une image.");

    img = new QImage(pathImg);

    QImage2ImageFourier();
    ImageFourier2Resultat();

    QPixmap tmp;
    tmp.convertFromImage(*img);
    zoneImage->setPixmap(tmp);

     QPixmap tmp2;
    tmp2.convertFromImage(*resultat);
    zoneResultat->setPixmap(tmp2);

}

void MyApp :: QImage2ImageFourier(){
    imgFourier.clear();
    imgFourier.resize(img->height());
    for(int i = 0; i < img->height(); i++){
        imgFourier.at(i).resize(img->width());
        for(int j = 0; j < img->width(); j++){
            QRgb tmp= img->pixel(j,i);
            int red = qRed(tmp);
            int blue = qBlue(tmp);
            int green = qGreen(tmp);
            imgFourier.at(i).at(j) = std :: complex<double>(0.2126*red + 0.0722*blue + 0.7152*green,0);
        }

    }
}

void MyApp :: ImageFourier2Resultat(){
    resultat = new QImage(img->width(), img->height(), QImage :: Format_ARGB32);
    for (int i = 0; i < img->height(); i++){
        for(int j = 0; j < img->width(); j++){
            int tmp = abs(imgFourier.at(i).at(j));
            resultat->setPixel(j,i, qRgb(tmp, tmp, tmp));

        }

    }

}

void MyApp :: saveImage(){
    QString fileName = QFileDialog::getSaveFileName(this,"Ou enegistrer?", ".jpg");
    if(!fileName.isEmpty()){
       resultat->save(fileName);

    }
}

void MyApp :: setFiltreBas(){
   //fBas.setAmplitude(ValAmp->value());
   //fBas.setFrequence( ValFrequence->value());

}

void MyApp :: setFiltreHaut(){
    //fHaut.setAmplitude(ValAmp->value());
    //fHaut.setFrequence( ValFrequence->value());
}
