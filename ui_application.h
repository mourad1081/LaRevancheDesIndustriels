/********************************************************************************
** Form generated from reading UI file 'application.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPLICATION_H
#define UI_APPLICATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Application
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *titre;
    QLabel *gif;
    QVBoxLayout *verticalLayout;
    QPushButton *btnNouvellePartie;
    QPushButton *btnContinuer;
    QPushButton *btnOptions;
    QPushButton *btnHackNASA;
    QPushButton *btnMusique;
    QPushButton *btnQuitter;

    void setupUi(QMainWindow *Application)
    {
        if (Application->objectName().isEmpty())
            Application->setObjectName(QStringLiteral("Application"));
        Application->resize(681, 392);
        centralwidget = new QWidget(Application);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        centralwidget->setStyleSheet(QLatin1String("\n"
"#centralwidget\n"
"{\n"
"border-image: url(:/img/SuperMarioBrosWallpaper.png) 0 0 0 0 stretch stretch;\n"
"}\n"
"\n"
"#titre\n"
"{\n"
"border-image: url(:/img/titre.png) 0 0 0 0 stretch stretch;\n"
"}\n"
"\n"
"QPushButton\n"
"{\n"
"color:white;\n"
"border-radius:1px;\n"
"}\n"
"\n"
"QPushButton::hover\n"
"{\n"
"color:salmon;\n"
"}"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        titre = new QLabel(centralwidget);
        titre->setObjectName(QStringLiteral("titre"));
        titre->setMinimumSize(QSize(500, 300));
        titre->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout_2->addWidget(titre);

        gif = new QLabel(centralwidget);
        gif->setObjectName(QStringLiteral("gif"));

        verticalLayout_2->addWidget(gif);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        btnNouvellePartie = new QPushButton(centralwidget);
        btnNouvellePartie->setObjectName(QStringLiteral("btnNouvellePartie"));
        btnNouvellePartie->setMinimumSize(QSize(0, 0));
        QFont font;
        font.setPointSize(14);
        font.setBold(false);
        font.setUnderline(false);
        font.setWeight(50);
        font.setStyleStrategy(QFont::PreferAntialias);
        btnNouvellePartie->setFont(font);
        btnNouvellePartie->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout->addWidget(btnNouvellePartie, 0, Qt::AlignRight);

        btnContinuer = new QPushButton(centralwidget);
        btnContinuer->setObjectName(QStringLiteral("btnContinuer"));
        QFont font1;
        font1.setPointSize(14);
        font1.setStyleStrategy(QFont::PreferAntialias);
        btnContinuer->setFont(font1);
        btnContinuer->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout->addWidget(btnContinuer, 0, Qt::AlignRight);

        btnOptions = new QPushButton(centralwidget);
        btnOptions->setObjectName(QStringLiteral("btnOptions"));
        btnOptions->setMinimumSize(QSize(0, 0));
        btnOptions->setFont(font);
        btnOptions->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout->addWidget(btnOptions, 0, Qt::AlignRight);

        btnHackNASA = new QPushButton(centralwidget);
        btnHackNASA->setObjectName(QStringLiteral("btnHackNASA"));
        btnHackNASA->setMinimumSize(QSize(0, 0));
        btnHackNASA->setFont(font);
        btnHackNASA->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout->addWidget(btnHackNASA, 0, Qt::AlignRight);

        btnMusique = new QPushButton(centralwidget);
        btnMusique->setObjectName(QStringLiteral("btnMusique"));
        btnMusique->setFont(font1);
        btnMusique->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout->addWidget(btnMusique, 0, Qt::AlignRight);

        btnQuitter = new QPushButton(centralwidget);
        btnQuitter->setObjectName(QStringLiteral("btnQuitter"));
        btnQuitter->setMinimumSize(QSize(0, 0));
        btnQuitter->setFont(font);
        btnQuitter->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout->addWidget(btnQuitter, 0, Qt::AlignRight);


        horizontalLayout->addLayout(verticalLayout);

        Application->setCentralWidget(centralwidget);

        retranslateUi(Application);

        QMetaObject::connectSlotsByName(Application);
    } // setupUi

    void retranslateUi(QMainWindow *Application)
    {
        Application->setWindowTitle(QApplication::translate("Application", "MainWindow", 0));
        titre->setText(QString());
        gif->setText(QString());
        btnNouvellePartie->setText(QApplication::translate("Application", "NOUVELLE PARTIE", 0));
        btnContinuer->setText(QApplication::translate("Application", "CONTINUER", 0));
        btnOptions->setText(QApplication::translate("Application", "PARAM\303\210TRES", 0));
        btnHackNASA->setText(QApplication::translate("Application", "HACKER LA NSA", 0));
        btnMusique->setText(QApplication::translate("Application", "MUSIQUE", 0));
        btnQuitter->setText(QApplication::translate("Application", "QUITTER", 0));
    } // retranslateUi

};

namespace Ui {
    class Application: public Ui_Application {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPLICATION_H
