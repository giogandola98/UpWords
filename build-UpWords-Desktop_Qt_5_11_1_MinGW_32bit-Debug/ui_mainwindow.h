/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAggiungi_Giocatore;
    QAction *actionInformazioni;
    QAction *actionAvvia_Gioco;
    QWidget *centralWidget;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QLabel *label_3;
    QTableWidget *tableWidget;
    QLabel *label_4;
    QTableWidget *giocatori_table;
    QTableWidget *lettere_table;
    QLabel *label_5;
    QLabel *points_txt;
    QLabel *turno_giocatore;
    QLabel *label_6;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(914, 604);
        MainWindow->setUnifiedTitleAndToolBarOnMac(true);
        actionAggiungi_Giocatore = new QAction(MainWindow);
        actionAggiungi_Giocatore->setObjectName(QStringLiteral("actionAggiungi_Giocatore"));
        actionInformazioni = new QAction(MainWindow);
        actionInformazioni->setObjectName(QStringLiteral("actionInformazioni"));
        actionAvvia_Gioco = new QAction(MainWindow);
        actionAvvia_Gioco->setObjectName(QStringLiteral("actionAvvia_Gioco"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 100, 51, 16));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 350, 47, 13));
        label_2->setFont(font);
        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(270, 200, 161, 51));
        pushButton_7 = new QPushButton(centralWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(270, 270, 161, 61));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 10, 61, 16));
        label_3->setFont(font);
        tableWidget = new QTableWidget(centralWidget);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(450, 40, 453, 453));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        tableWidget->setFont(font1);
        tableWidget->setLayoutDirection(Qt::LeftToRight);
        tableWidget->setColumnCount(0);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(30, 370, 301, 31));
        QFont font2;
        font2.setBold(false);
        font2.setWeight(50);
        label_4->setFont(font2);
        giocatori_table = new QTableWidget(centralWidget);
        giocatori_table->setObjectName(QStringLiteral("giocatori_table"));
        giocatori_table->setGeometry(QRect(10, 30, 421, 61));
        giocatori_table->setMaximumSize(QSize(421, 61));
        lettere_table = new QTableWidget(centralWidget);
        lettere_table->setObjectName(QStringLiteral("lettere_table"));
        lettere_table->setGeometry(QRect(10, 120, 420, 61));
        sizePolicy.setHeightForWidth(lettere_table->sizePolicy().hasHeightForWidth());
        lettere_table->setSizePolicy(sizePolicy);
        lettere_table->setFont(font);
        lettere_table->setLayoutDirection(Qt::LeftToRight);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 206, 71, 20));
        label_5->setFont(font);
        points_txt = new QLabel(centralWidget);
        points_txt->setObjectName(QStringLiteral("points_txt"));
        points_txt->setGeometry(QRect(150, 206, 47, 20));
        points_txt->setFont(font);
        turno_giocatore = new QLabel(centralWidget);
        turno_giocatore->setObjectName(QStringLiteral("turno_giocatore"));
        turno_giocatore->setGeometry(QRect(150, 230, 47, 20));
        turno_giocatore->setFont(font);
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 230, 111, 20));
        label_6->setFont(font);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 914, 26));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menu->menuAction());
        menuFile->addAction(actionAggiungi_Giocatore);
        menuFile->addAction(actionAvvia_Gioco);
        menu->addAction(actionInformazioni);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionAggiungi_Giocatore->setText(QApplication::translate("MainWindow", "Aggiungi Giocatore", nullptr));
        actionInformazioni->setText(QApplication::translate("MainWindow", "Informazioni", nullptr));
        actionAvvia_Gioco->setText(QApplication::translate("MainWindow", "Avvia Gioco", nullptr));
        label->setText(QApplication::translate("MainWindow", "Lettere", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Parola", nullptr));
        pushButton_6->setText(QApplication::translate("MainWindow", "Passa il Turno", nullptr));
        pushButton_7->setText(QApplication::translate("MainWindow", "Suggerimento", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Giocatori", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "Punteggio", nullptr));
        points_txt->setText(QApplication::translate("MainWindow", "0", nullptr));
        turno_giocatore->setText(QApplication::translate("MainWindow", "0", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "Turno giocatore", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", nullptr));
        menu->setTitle(QApplication::translate("MainWindow", "?", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
