#ifndef MAJ_H
#define MAJ_H

#include <QWidget>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>
#include <QFile>
#include <QDesktopServices>
#include <QDir>
#include <QUrl>
#include <QFormLayout>
#include <QProgressBar>
#include <QLabel>
#include <QDebug>
#include <QSettings>
#include <QMessageBox>
#include <windows.h>
#include <QTimer>
#include <QTextCodec>

namespace Ui {
class MAJ;
}

class MAJ : public QWidget
{
    Q_OBJECT

public:
    explicit MAJ(QString version, QString vAPI, QString vFTP, QString RA = 0, QWidget *parent = 0);
    ~MAJ();

private slots:
void valeur(qint64 readBytes, qint64 totalBytes);
void Erreur();
void redemarrer();

private:
    Ui::MAJ *ui;
    QString ftp;
    QString API;
};

#endif // MAJ_H
