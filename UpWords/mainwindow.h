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
    void on_tableWidget_cellClicked(int row, int column);
    void start_game();
    void add_player();

private:
    Ui::MainWindow *ui;
    void update_game_points();
    void update_terrain();
    void UpdateTerrain(Terreno *terrain);
    void terrainWidgetInit();
    void onTurnSwitched();
    void fillGamerHand(giocatore &g);
    void setPlayerLabel();
    void setLettersTable();
    sacchetto *s;
    Terreno *terrain;
    dizionario *d;
    unsigned short int turno_giocatore;
    std::vector<giocatore> giocatori;
    bool game_started;


};

#endif // MAINWINDOW_H
