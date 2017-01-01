/********************************************************************************
** Form generated from reading UI file 'maj.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAJ_H
#define UI_MAJ_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MAJ
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *eFichier;
    QProgressBar *Chargement;
    QLabel *nbfichier;
    QLabel *label_2;

    void setupUi(QWidget *MAJ)
    {
        if (MAJ->objectName().isEmpty())
            MAJ->setObjectName(QStringLiteral("MAJ"));
        MAJ->resize(400, 97);
        QIcon icon;
        icon.addFile(QStringLiteral("../../../Archives KGestion/Logoapi.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MAJ->setWindowIcon(icon);
        gridLayout = new QGridLayout(MAJ);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(MAJ);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        eFichier = new QLabel(MAJ);
        eFichier->setObjectName(QStringLiteral("eFichier"));

        verticalLayout->addWidget(eFichier);

        Chargement = new QProgressBar(MAJ);
        Chargement->setObjectName(QStringLiteral("Chargement"));
        Chargement->setValue(0);

        verticalLayout->addWidget(Chargement);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 2);

        nbfichier = new QLabel(MAJ);
        nbfichier->setObjectName(QStringLiteral("nbfichier"));

        gridLayout->addWidget(nbfichier, 1, 0, 1, 1);

        label_2 = new QLabel(MAJ);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setLayoutDirection(Qt::LeftToRight);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 1, 1, 1, 1);


        retranslateUi(MAJ);

        QMetaObject::connectSlotsByName(MAJ);
    } // setupUi

    void retranslateUi(QWidget *MAJ)
    {
        MAJ->setWindowTitle(QApplication::translate("MAJ", "KGestion - Mise \303\240 jour", 0));
        label->setText(QApplication::translate("MAJ", "Mise \303\240 jour en cours...", 0));
        eFichier->setText(QString());
        nbfichier->setText(QApplication::translate("MAJ", "0 / 0", 0));
        label_2->setText(QApplication::translate("MAJ", "0 / 0", 0));
    } // retranslateUi

};

namespace Ui {
    class MAJ: public Ui_MAJ {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAJ_H
