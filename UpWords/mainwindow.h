#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <sacchetto.h>
#include <combinatore.h>
#include <terreno.h>
#include <costanti.h>
#include <giocatore.h>
#include <cella.h>
#include <referee.h>
#include <thread>

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
    void on_pushButton_7_clicked();
    void on_tableWidget_cellClicked(int row, int column);
    void start_game();
    void add_player();
    void on_lettere_table_cellClicked(int row, int column);
    void on_abort_btn_clicked();
    void on_cambia_btn_clicked();
    void on_conferma_btn_clicked();
    void on_passaturno_btn_clicked();

private:
    Ui::MainWindow *ui;
    void update_game_points();
    void reset_insert_data();
    void loadRack();
    void set_gamer_points();
    void update_terrain();
    void UpdateTerrain(Terreno *terrain);
    void terrainWidgetInit();
    void onTurnSwitched();
    void fillGamerHand(giocatore &g);
    void setPlayerLabel();
    void setLettersTable();
    void enable_rack_click();
    void disable_grid(std::size_t x,std::size_t y);
    void disable_grid();
    void enable_grid();
    void error_message(std::string title,std::string body);
    void enable_row(std::size_t y,std::size_t x);
    void enable_column(std::size_t x,std::size_t y);
    void init_suggerimento();
    referee *arbitro;
    sacchetto *s;
    Terreno *terrain;
    dizionario *d;
    Combinatore *c;
    unsigned short int turno_giocatore;
    std::vector<giocatore> giocatori;
    bool game_started;
    char selected_letter;
    std::vector<cella> to_insert;
    std::thread *t1;
    std::string th1_result;


};

#endif // MAINWINDOW_H
