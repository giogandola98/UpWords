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
    QPushButton *cambia_btn;
    QPushButton *pushButton_7;
    QLabel *label_3;
    QTableWidget *tableWidget;
    QTableWidget *giocatori_table;
    QTableWidget *lettere_table;
    QLabel *label_5;
    QLabel *points_txt;
    QLabel *turno_giocatore;
    QLabel *label_6;
    QPushButton *conferma_btn;
    QPushButton *abort_btn;
    QPushButton *passaturno_btn;
    QPushButton *conferma_btn_2;
    QPushButton *conferma_btn_3;
    QPushButton *end_btn;
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
        label->setGeometry(QRect(10, 120, 51, 16));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        cambia_btn = new QPushButton(centralWidget);
        cambia_btn->setObjectName(QStringLiteral("cambia_btn"));
        cambia_btn->setGeometry(QRect(270, 390, 161, 51));
        pushButton_7 = new QPushButton(centralWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(270, 450, 161, 61));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 70, 61, 16));
        label_3->setFont(font);
        tableWidget = new QTableWidget(centralWidget);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(450, 100, 453, 453));
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
        giocatori_table = new QTableWidget(centralWidget);
        giocatori_table->setObjectName(QStringLiteral("giocatori_table"));
        giocatori_table->setGeometry(QRect(10, 100, 421, 61));
        giocatori_table->setMaximumSize(QSize(421, 61));
        lettere_table = new QTableWidget(centralWidget);
        lettere_table->setObjectName(QStringLiteral("lettere_table"));
        lettere_table->setGeometry(QRect(10, 190, 420, 61));
        sizePolicy.setHeightForWidth(lettere_table->sizePolicy().hasHeightForWidth());
        lettere_table->setSizePolicy(sizePolicy);
        lettere_table->setFont(font);
        lettere_table->setLayoutDirection(Qt::LeftToRight);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 376, 71, 20));
        label_5->setFont(font);
        points_txt = new QLabel(centralWidget);
        points_txt->setObjectName(QStringLiteral("points_txt"));
        points_txt->setGeometry(QRect(150, 376, 47, 20));
        points_txt->setFont(font);
        turno_giocatore = new QLabel(centralWidget);
        turno_giocatore->setObjectName(QStringLiteral("turno_giocatore"));
        turno_giocatore->setGeometry(QRect(150, 400, 111, 20));
        turno_giocatore->setFont(font);
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 400, 111, 20));
        label_6->setFont(font);
        conferma_btn = new QPushButton(centralWidget);
        conferma_btn->setObjectName(QStringLiteral("conferma_btn"));
        conferma_btn->setGeometry(QRect(270, 270, 161, 51));
        abort_btn = new QPushButton(centralWidget);
        abort_btn->setObjectName(QStringLiteral("abort_btn"));
        abort_btn->setGeometry(QRect(10, 270, 161, 51));
        passaturno_btn = new QPushButton(centralWidget);
        passaturno_btn->setObjectName(QStringLiteral("passaturno_btn"));
        passaturno_btn->setGeometry(QRect(270, 330, 161, 51));
        conferma_btn_2 = new QPushButton(centralWidget);
        conferma_btn_2->setObjectName(QStringLiteral("conferma_btn_2"));
        conferma_btn_2->setGeometry(QRect(10, 10, 161, 51));
        conferma_btn_3 = new QPushButton(centralWidget);
        conferma_btn_3->setObjectName(QStringLiteral("conferma_btn_3"));
        conferma_btn_3->setGeometry(QRect(270, 10, 161, 51));
        end_btn = new QPushButton(centralWidget);
        end_btn->setObjectName(QStringLiteral("end_btn"));
        end_btn->setGeometry(QRect(740, 10, 161, 51));
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

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
        cambia_btn->setText(QApplication::translate("MainWindow", "Cambia Lettera", nullptr));
        pushButton_7->setText(QApplication::translate("MainWindow", "Suggerimento", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Giocatori", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "Punteggio", nullptr));
        points_txt->setText(QApplication::translate("MainWindow", "0", nullptr));
        turno_giocatore->setText(QApplication::translate("MainWindow", "0", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "Turno giocatore", nullptr));
        conferma_btn->setText(QApplication::translate("MainWindow", "Conferma Inserimento", nullptr));
        abort_btn->setText(QApplication::translate("MainWindow", "Annulla Inserimento", nullptr));
        passaturno_btn->setText(QApplication::translate("MainWindow", "Passa il Turno", nullptr));
        conferma_btn_2->setText(QApplication::translate("MainWindow", "Aggiungi giocatore", nullptr));
        conferma_btn_3->setText(QApplication::translate("MainWindow", "avvia gioco", nullptr));
        end_btn->setText(QApplication::translate("MainWindow", "Termina Partita", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
