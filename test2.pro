    TEMPLATE = app
    TARGET = name_of_the_app
    CONFIG += c++11

    QT = core gui

    greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    main.cpp \
    MyApp.cpp \
    Contour.cpp \
    Filtre.cpp \
    TransformeeFourier.cpp \
    TransformeeFourier2D.cpp

HEADERS += \
    MyApp.h \
    Contour.hpp \
    Filtre.hpp \
    TransformeeFourier.hpp \
    TransformeeFourier2D.hpp
