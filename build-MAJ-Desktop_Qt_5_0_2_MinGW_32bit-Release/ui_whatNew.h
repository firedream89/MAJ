/********************************************************************************
** Form generated from reading UI file 'whatNew.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WHATNEW_H
#define UI_WHATNEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_whatNew
{
public:
    QTextBrowser *textBrowser;

    void setupUi(QWidget *whatNew)
    {
        if (whatNew->objectName().isEmpty())
            whatNew->setObjectName(QStringLiteral("whatNew"));
        whatNew->resize(400, 300);
        textBrowser = new QTextBrowser(whatNew);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(0, 0, 401, 301));

        retranslateUi(whatNew);

        QMetaObject::connectSlotsByName(whatNew);
    } // setupUi

    void retranslateUi(QWidget *whatNew)
    {
        whatNew->setWindowTitle(QApplication::translate("whatNew", "Quoi de nouveau ?", 0));
    } // retranslateUi

};

namespace Ui {
    class whatNew: public Ui_whatNew {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WHATNEW_H
