/********************************************************************************
** Form generated from reading UI file 'application.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Application
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *titre;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnNouvellePartie;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnQuitter;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btnOptions;
    QPushButton *btnActiverSon;

    void setupUi(QMainWindow *Application)
    {
        if (Application->objectName().isEmpty())
            Application->setObjectName(QStringLiteral("Application"));
        Application->resize(661, 405);
        centralwidget = new QWidget(Application);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        centralwidget->setStyleSheet(QLatin1String("#centralwidget\n"
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
"background-color:  qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:1, stop:0 rgba(255, 255, 255, 255), stop:1 rgba(0, 173, 0, 255));\n"
"border-radius:25px;\n"
"color:black;\n"
"}\n"
"\n"
"QPushButton::hover\n"
"{\n"
"background-color:qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:1, stop:0 rgba(0, 173, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"}"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        titre = new QLabel(centralwidget);
        titre->setObjectName(QStringLiteral("titre"));
        titre->setMinimumSize(QSize(661, 250));
        titre->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout->addWidget(titre);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btnNouvellePartie = new QPushButton(centralwidget);
        btnNouvellePartie->setObjectName(QStringLiteral("btnNouvellePartie"));
        btnNouvellePartie->setMinimumSize(QSize(150, 50));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        btnNouvellePartie->setFont(font);
        btnNouvellePartie->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout->addWidget(btnNouvellePartie);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnQuitter = new QPushButton(centralwidget);
        btnQuitter->setObjectName(QStringLiteral("btnQuitter"));
        btnQuitter->setMinimumSize(QSize(150, 50));
        btnQuitter->setFont(font);
        btnQuitter->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout->addWidget(btnQuitter);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        btnOptions = new QPushButton(centralwidget);
        btnOptions->setObjectName(QStringLiteral("btnOptions"));
        btnOptions->setMinimumSize(QSize(150, 50));
        btnOptions->setFont(font);
        btnOptions->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout->addWidget(btnOptions);

        btnActiverSon = new QPushButton(centralwidget);
        btnActiverSon->setObjectName(QStringLiteral("btnActiverSon"));
        btnActiverSon->setMinimumSize(QSize(50, 50));

        horizontalLayout->addWidget(btnActiverSon);


        verticalLayout->addLayout(horizontalLayout);

        Application->setCentralWidget(centralwidget);

        retranslateUi(Application);

        QMetaObject::connectSlotsByName(Application);
    } // setupUi

    void retranslateUi(QMainWindow *Application)
    {
        Application->setWindowTitle(QApplication::translate("Application", "MainWindow", 0));
        titre->setText(QString());
        btnNouvellePartie->setText(QApplication::translate("Application", "Nouvelle partie", 0));
        btnQuitter->setText(QApplication::translate("Application", "Quitter", 0));
        btnOptions->setText(QApplication::translate("Application", "Options", 0));
        btnActiverSon->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Application: public Ui_Application {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPLICATION_H
