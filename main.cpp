#include <QApplication>
#include <QPushButton>

#include "MyApp.h"


int main(int argc, char **argv)
{
    QApplication app (argc, argv);

    MyApp lol;
    lol.show();

    return app.exec();
}
