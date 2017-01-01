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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MAJ
{
public:
    QGridLayout *gridLayout;
    QLabel *nbfichier;
    QPushButton *bRedemarrer;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *eFichier;
    QProgressBar *Chargement;
    QLabel *label_2;
    QTextBrowser *quoiDeNeuf;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *MAJ)
    {
        if (MAJ->objectName().isEmpty())
            MAJ->setObjectName(QStringLiteral("MAJ"));
        MAJ->resize(449, 481);
        QIcon icon;
        icon.addFile(QStringLiteral("../../../Archives KGestion/Logoapi.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MAJ->setWindowIcon(icon);
        gridLayout = new QGridLayout(MAJ);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        nbfichier = new QLabel(MAJ);
        nbfichier->setObjectName(QStringLiteral("nbfichier"));

        gridLayout->addWidget(nbfichier, 3, 0, 1, 1);

        bRedemarrer = new QPushButton(MAJ);
        bRedemarrer->setObjectName(QStringLiteral("bRedemarrer"));

        gridLayout->addWidget(bRedemarrer, 4, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 4, 2, 1, 1);

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


        gridLayout->addLayout(verticalLayout, 1, 0, 1, 3);

        label_2 = new QLabel(MAJ);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setLayoutDirection(Qt::LeftToRight);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 3, 2, 1, 1);

        quoiDeNeuf = new QTextBrowser(MAJ);
        quoiDeNeuf->setObjectName(QStringLiteral("quoiDeNeuf"));

        gridLayout->addWidget(quoiDeNeuf, 0, 0, 1, 3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 4, 0, 1, 1);


        retranslateUi(MAJ);

        QMetaObject::connectSlotsByName(MAJ);
    } // setupUi

    void retranslateUi(QWidget *MAJ)
    {
        MAJ->setWindowTitle(QApplication::translate("MAJ", "Mise \303\240 jour", 0));
        nbfichier->setText(QApplication::translate("MAJ", "0 / 0", 0));
        bRedemarrer->setText(QApplication::translate("MAJ", "Red\303\251marrer", 0));
        label->setText(QApplication::translate("MAJ", "Mise \303\240 jour en cours...", 0));
        eFichier->setText(QString());
        label_2->setText(QApplication::translate("MAJ", "0 / 0", 0));
    } // retranslateUi

};

namespace Ui {
    class MAJ: public Ui_MAJ {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAJ_H
