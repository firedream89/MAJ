#include "maj.h"
#include "ui_maj.h"


MAJ::MAJ(QString version, QString vAPI, QString vFTP, QString RA, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MAJ)
{
    ui->setupUi(this);

    API = vAPI;
    ftp = vFTP;
    bool arg = true;
    if(version.isEmpty() || vAPI.isEmpty() || vFTP.isEmpty())
    {
        arg = false;
        this->show();
        QMessageBox::critical(this,"Erreur","Arguments manquant, Arret de la mise à jour.");
        this->close();
    }
    if(arg)
    {
        this->show();
    QTimer *timer = new QTimer;
    ui->bRedemarrer->hide();

///Vérification de la version
    ui->eFichier->setText("Vérification version...");
    QString maj = version;
    QNetworkAccessManager manager;
    QNetworkReply *reply = manager.get(QNetworkRequest(QUrl(ftp + maj + "/" + maj + ".txt"))); // Url vers le fichier version.txt
    QEventLoop loop;
    QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    timer->start(10000);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(Erreur()));
    QObject::connect(timer,SIGNAL(timeout()), timer, SLOT(stop()));
    QObject::connect(timer, SIGNAL(timeout()), &loop, SLOT(quit()));
    loop.exec();
    timer->stop();
    QString retour = reply->readAll();
    qDebug() << retour;
    ui->quoiDeNeuf->setText(retour);

///Téléchargement de la liste de fichiers
    ui->eFichier->setText("Récupération de la liste de fichiers...");
    QNetworkAccessManager manager2;
    QNetworkReply *reply2 = manager2.get(QNetworkRequest(QUrl(ftp + maj + "/fichiers.txt")));
    QEventLoop loop2;
    timer->start(10000);
    QObject::connect(reply2, SIGNAL(finished()), &loop2, SLOT(quit()));
    loop2.exec();
    timer->stop();

    QString fichier1 = reply2->readAll();
    QStringList fichier = fichier1.split("\r\n");
    QString nb = fichier.at(0);
    ui->nbfichier->setText("0 / " + nb);
    int nb2 = 0;
    for(int cpt=1;cpt<fichier.count();cpt++)
    {
        ui->Chargement->setMinimum(0);
        nb2++;
        ui->nbfichier->setText(QString::number(nb2) + " / " + nb);
        ui->eFichier->setText("Téléchargement du fichier " + fichier.at(cpt));

///Vérification dossier

        QStringList listFichier = fichier.at(cpt).split("/");
        if(listFichier.count() > 1)
        {
            for(int cpt=0;cpt<listFichier.count()-1;cpt++)
            {
                QDir dossier;
                dossier.mkdir(listFichier.at(cpt));
            }
        }

///Téléchargement des fichiers
        QNetworkAccessManager manager3;

        QNetworkReply *reply3 = manager3.get(QNetworkRequest(QUrl(ftp + maj + "/" + fichier.at(cpt))));
        connect(reply3, SIGNAL(downloadProgress(qint64,qint64)), this, SLOT(valeur(qint64,qint64)));
        QEventLoop loop3;
        timer->start(10000);
        QObject::connect(reply3, SIGNAL(finished()), &loop3, SLOT(quit()));
        loop3.exec();
        timer->stop();

        if(!reply3->canReadLine())
        {
            QMessageBox::warning(this, "Erreur", "Une Erreur s'est produite dans le téléchargement d'un fichier.");
        }
        QString chantier2 = fichier.at(cpt);
        QFile fichier2(chantier2);
        fichier2.open(QIODevice::WriteOnly);
        fichier2.write(reply3->readAll());
    }
    ui->bRedemarrer->show();
    connect(ui->bRedemarrer, SIGNAL(clicked()), this, SLOT(redemarrer()));

    if(RA == "oui")
        redemarrer();
    }
    else
        qApp->exit(0);
}

MAJ::~MAJ()
{
    delete ui;
}

void MAJ::valeur(qint64 readBytes, qint64 totalBytes)
{
    QVariant val = totalBytes;
    QVariant val2 = readBytes;
    ui->Chargement->setMaximum(val.toInt());
    ui->Chargement->setValue(val2.toInt());
    int valM1 = val.toDouble() / 1000;
    int valM2 = val2.toDouble() / 1000;

    double total = valM1;
    double actuel = valM2;
    total = total / 1000;
    actuel = actuel / 1000;

    ui->label_2->setText(QString::number(actuel) + " / " + QString::number(total) + " Mb");
}

void MAJ::Erreur()
{
    QMessageBox::warning(this,"Erreur","Une erreur est survenue durant la mise à jour, retentez plus tard.");
    redemarrer();
}

void MAJ::redemarrer()
{
    QDesktopServices::openUrl(QUrl::fromLocalFile(API));

    this->close();
    exit(EXIT_SUCCESS);
}
