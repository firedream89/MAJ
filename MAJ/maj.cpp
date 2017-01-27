#include "maj.h"
#include "ui_maj.h"


MAJ::MAJ(QString version, QString vAPI, QString vFTP, QString RA, QString name, QString icon, QWidget *parent) :
    QWidget(parent), API(vAPI), ftp(vFTP),
    ui(new Ui::MAJ)
{
    ui->setupUi(this);

    if(name != "")
        this->setWindowTitle(name + " - Mise à jour");
    if(icon != "")
        this->setWindowIcon(QIcon(icon));
    if(QCoreApplication::arguments().last().split("=").at(0) == "webSite")
        m_WebSite = QCoreApplication::arguments().last().split("=").at(1);

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
        QTimer timer;
        ui->bRedemarrer->hide();

        QNetworkAccessManager manager;
        QNetworkReply *reply;
        QEventLoop loop;
        QString maj = version;

    ///Vérification de la version
        ui->eFichier->setText("Vérification version...");
        reply = manager.get(QNetworkRequest(QUrl(ftp + maj + "/" + maj + ".txt"))); // Url vers le fichier version.txt
        qDebug() << reply->errorString() << ftp + maj + "/" + maj + ".txt";
        QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
        QObject::connect(reply, SIGNAL(error(QNetworkReply::NetworkError)),&loop,SLOT(quit()));
        timer.start(10000);
        loop.exec();
        timer.stop();
        QString retour = QString::fromUtf8(reply->readAll());
        ui->quoiDeNeuf->setText(retour);

    ///Téléchargement de la liste de fichiers
        ui->eFichier->setText("Récupération de la liste de fichiers...");
        reply->close();
        reply = manager.get(QNetworkRequest(QUrl(ftp + maj + "/fichiers.txt")));
        QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
        QObject::connect(reply, SIGNAL(error(QNetworkReply::NetworkError)),&loop,SLOT(quit()));
        timer.start(10000);
        loop.exec();
        timer.stop();

        QString fichier1 = reply->readAll();
        QStringList fichier = fichier1.split("\n");
        QString nb = fichier.at(0);
        ui->nbfichier->setText("0 / " + nb);
        int nb2 = 0;
        for(int cpt=1;cpt<fichier.count();cpt++)
        {
            ui->Chargement->setMinimum(0);
            ui->nbfichier->setText(QString::number(nb2) + " / " + nb);
            ui->eFichier->setText("Téléchargement du fichier " + fichier.at(cpt));

    ///Vérification dossier
            qDebug() << fichier.at(cpt).split("/");
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
            qDebug() << ftp + maj + "/" + fichier.at(cpt);
            reply->close();
            reply = manager.get(QNetworkRequest(QUrl(ftp + maj + "/" + fichier.at(cpt))));
            QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
            QObject::connect(reply, SIGNAL(error(QNetworkReply::NetworkError)),&loop,SLOT(quit()));
            connect(reply, SIGNAL(downloadProgress(qint64,qint64)), this, SLOT(valeur(qint64,qint64)));
            timer.start(60000);
            QObject::connect(reply,SIGNAL(downloadProgress()), &timer, SLOT(stop()));
            loop.exec();
            timer.stop();

            if(!reply->canReadLine())
            {
                QMessageBox::warning(this, "Erreur", "Une Erreur s'est produite dans le téléchargement d'un fichier."
                                                     "Si l'application ne redémarre pas, veuillez la télécharger manuellement");
                QDesktopServices::openUrl(QUrl(m_WebSite));
                return;
            }
            QString chantier2 = fichier.at(cpt);
            QFile fichier2(chantier2);
            fichier2.open(QIODevice::WriteOnly);
            fichier2.write(reply->readAll());
            nb2++;
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

void MAJ::WebSite(QString site)
{
    m_WebSite = site;
    qDebug() << "Ajout webSite";
}
