#include "maj.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString valeur,API,ftp,RA,name,icon;

    for(int cpt=0;QCoreApplication::arguments().count()>cpt;cpt++)
    {
        if(QCoreApplication::arguments().at(cpt).split("=").at(0) == "ver")
            valeur = QCoreApplication::arguments().at(cpt).split("=").at(1);
        if(QCoreApplication::arguments().at(cpt).split("=").at(0) == "API")
            API = QCoreApplication::arguments().at(cpt).split("=").at(1);
        if(QCoreApplication::arguments().at(cpt).split("=").at(0) == "ftp")
            ftp = QCoreApplication::arguments().at(cpt).split("=").at(1);
        if(QCoreApplication::arguments().at(cpt).split("=").at(0) == "RA")
            RA = QCoreApplication::arguments().at(cpt).split("=").at(1);
        if(QCoreApplication::arguments().at(cpt).split("=").at(0) == "name")
            name = QCoreApplication::arguments().at(cpt).split("=").at(1);
        if(QCoreApplication::arguments().at(cpt).split("=").at(0) == "icon")
            icon = QCoreApplication::arguments().at(cpt).split("=").at(1);
    }

    MAJ w(valeur,API,ftp,RA,name,icon);
    if(!valeur.isEmpty() || !API.isEmpty() || !ftp.isEmpty())
        return a.exec();
    else
        return 0;
}
