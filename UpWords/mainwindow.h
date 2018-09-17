#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <sacchetto.h>
#include <combinatore.h>
#include <terreno.h>
#include <costanti.h>
#include <giocatore.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::MainWindow *ui;
    void update_game_points();
    void update_terrain();

    Terreno *terrain;
    dizionario *d;
    unsigned short int n_gamers;
    unsigned short int turn_g;
    Combinatore c;
    std::vector<giocatore> giocatori;

};

#endif // MAINWINDOW_H
