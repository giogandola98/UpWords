#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dizionario.h"
#include "costanti.h"
#include "terreno.h"
#include <QMessageBox>
#include "functional"
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    d = new dizionario("C:\\Users\\giorgio\\Documents\\GitHub\\UpWords\\dizionario\\it_IT.txt");
    terrain=new(Terreno);
    /*
     * qui il dizionario funziona, ritorna 1
    std::string test = "CIAO";
    std::cerr<<d->exist(test);*/
    s = new(sacchetto);
    arbitro=new referee(d,terrain);
    terrainWidgetInit();
    UpdateTerrain(terrain);
    game_started=false;
    selected_letter=costanti::EMPITY_FIELD;
    c=nullptr;
}
MainWindow::~MainWindow()
{
    delete ui;
    delete d;
    delete terrain;
}

//FUNZIONI DI CORREDO
void MainWindow::threadStart(std::string hand,dizionario *d,char letters[costanti::TERRAIN_SIZE_X][costanti::TERRAIN_SIZE_Y])
{

}
void MainWindow::fillGamerHand(giocatore &g)
{

    while(!g.hand_full()&&(!s->this_is_empty()))
    {
        g.add_letter(s->convert_to_char(s->extract_letter()));
    }
}
void MainWindow::onTurnSwitched()
{
  //riempio la mano del nuovo giocatore
  fillGamerHand(giocatori.at(turno_giocatore));
  //cambio il punteggio a video con quello del nuovo giocatore
  set_gamer_points();
  //cambio le lettere a video con quelle del nuovo giocatore
  loadRack();
  //qui devo fare lo switch del giocatore nell'array giocatori
  ui->turno_giocatore->setText(QString::number(turno_giocatore+1));
  init_suggerimento();
  //riabilito il bottone di cambio lettera
  ui->cambia_btn->show();


}
//QUI CI SONO PROBLEMI
void MainWindow::init_suggerimento()
{
    if(game_started)
    {
        char letters[costanti::TERRAIN_SIZE_X][costanti::TERRAIN_SIZE_Y];
        for(std::size_t x=0;x<costanti::TERRAIN_SIZE_X;x++)
            for(std::size_t y=0;y<costanti::TERRAIN_SIZE_Y;y++)
                letters[y][x]=terrain->getElement(y,x);
        std::string hand="";
        for(std::size_t i =0;i<costanti::MAX_LETTERS_HAND;i++)
            hand+=(giocatori.at(turno_giocatore).get_letter(i));
        //qui il thread start
    }
}
//______FINE PROBLEMI
void MainWindow::start_game()
{
    if(!game_started)
    {
    if(giocatori.size()>=costanti::MIN_PLAYERS)
    {
        game_started=true;
        turno_giocatore=0;
        setLettersTable();
        setPlayerLabel();
        onTurnSwitched();
    }
    else
        error_message("ERROR","Giocatori non sufficenti");
    }
    else
        error_message("ERROR","Gioco già iniziato");

}
void MainWindow::add_player()
{
  //aprire la finestra per inserimento giocatore (se possibile)
    if(giocatori.size()<costanti::MAX_PLAYERS&&!game_started)
    {
        QString s =QInputDialog::getText(this,"AGGIUNGI GIOCATORE","Inserisci nome giocatore");
        giocatore g(s.toStdString());
        giocatori.push_back(g);
        std::cerr<<giocatori.size();
    }else
        error_message("ERROR","Giocatori al Completo");
}
void MainWindow::error_message(std::string title,std::string body)
{
    QMessageBox::information(this,QString::fromStdString(title),QString::fromStdString(body));
}
void MainWindow::launch_win()
{
    short int max_points=0;
    std::string max_name;
    foreach (giocatore g, giocatori)
    {
        if(g.get_points()>=max_points)
        {
            max_points=g.get_points();
            max_name  =g.get_name();
        }
    }
    std::cerr<<max_name;
    error_message("VITTORIA","Vince il giocatore "+max_name);
    game_started=false;
    reset_insert_data();
    giocatori.clear();
}
//FUNZIONI GUI
void MainWindow::terrainWidgetInit()
{
    ui->tableWidget->setRowCount(costanti::DIM_CAMPOGIOCO);
    ui->tableWidget->setColumnCount(costanti::DIM_CAMPOGIOCO);
    ui->tableWidget->verticalHeader()->setVisible(false);
    ui->tableWidget->horizontalHeader()->setOffset(0);
    ui->tableWidget->horizontalHeader()->setDefaultSectionSize(45);
    ui->tableWidget->verticalHeader()->setDefaultSectionSize(45);
    ui->tableWidget->verticalHeader()->setOffset(0);
    ui->tableWidget->horizontalHeader()->setVisible(false);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);


}
void MainWindow::loadRack()
{
    ui->lettere_table->clear();
    for(std::size_t i = 0; i< costanti::MAX_LETTERS_HAND;i++)
    {
      QString item;
      item.append(giocatori.at(turno_giocatore).get_letter(i));
      ui->lettere_table->setItem(0,i,new QTableWidgetItem(item));
    }
}
void MainWindow::set_gamer_points()
{
     ui->points_txt->setText(QString::number(giocatori.at(turno_giocatore).get_points()));
}
void MainWindow::UpdateTerrain(Terreno *terrain)
{
    for(std::size_t x = 0;x<costanti::DIM_CAMPOGIOCO;x++)
        for(std::size_t y =0;y<costanti::DIM_CAMPOGIOCO;y++)
        {
            QString item;
            item.append(terrain->getElement(x,y));
            ui->tableWidget->setItem(y,x,new QTableWidgetItem(item));
            item.clear();
        }
    ui->tableWidget->update();
    ui->tableWidget->show();

}
void MainWindow::setPlayerLabel()
{
   ui->giocatori_table->setRowCount(1);
   ui->giocatori_table->setColumnCount(giocatori.size());
   ui->giocatori_table->verticalHeader()->setVisible(false);
   ui->giocatori_table->horizontalHeader()->setOffset(0);
   ui->giocatori_table->horizontalHeader()->setDefaultSectionSize((ui->giocatori_table->maximumWidth()/giocatori.size())-ui->giocatori_table->maximumWidth()%giocatori.size());
   ui->giocatori_table->verticalHeader()->setDefaultSectionSize(ui->giocatori_table->maximumHeight());
   ui->giocatori_table->verticalHeader()->setOffset(0);
   ui->giocatori_table->horizontalHeader()->setVisible(false);
   ui->giocatori_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
   for(std::size_t i = 0;i<giocatori.size();i++)
   {
        giocatore g = giocatori.at(i);
        ui->giocatori_table->setItem(0,i,new QTableWidgetItem(QString::fromStdString(g.get_name())));
    }
}
void MainWindow::setLettersTable()
{
    ui->lettere_table->setRowCount(1);
    ui->lettere_table->setColumnCount(costanti::MAX_LETTERS_HAND);
    ui->lettere_table->verticalHeader()->setVisible(false);
    ui->lettere_table->horizontalHeader()->setOffset(0);
    ui->lettere_table->horizontalHeader()->setDefaultSectionSize((ui->lettere_table->width()/costanti::MAX_LETTERS_HAND)-(ui->giocatori_table->width()%costanti::MAX_LETTERS_HAND));
    ui->lettere_table->verticalHeader()->setDefaultSectionSize(ui->lettere_table->height());
    ui->lettere_table->verticalHeader()->setOffset(0);
    ui->lettere_table->horizontalHeader()->setVisible(false);
    ui->lettere_table->setEditTriggers(QAbstractItemView::NoEditTriggers);

}
void MainWindow::reset_insert_data()
{
    UpdateTerrain(terrain);
    to_insert.clear();
    selected_letter=costanti::EMPITY_FIELD;
    enable_grid();
    ui->passaturno_btn->show();
    enable_rack_click();
}
void MainWindow::disable_grid()
{
    for(std::size_t x = 0;x<costanti::DIM_CAMPOGIOCO;x++)
        for(std::size_t y =0;y<costanti::DIM_CAMPOGIOCO;y++)
            ui->tableWidget->item(y,x)->setFlags(Qt::ItemFlag::NoItemFlags);
}
void MainWindow::enable_grid()
{
    for(std::size_t j=0;j<costanti::DIM_CAMPOGIOCO;j++)
        for(std::size_t k=0;k<costanti::DIM_CAMPOGIOCO;k++)
            ui->tableWidget->item(j,k)->setFlags(Qt::ItemIsEnabled|Qt::ItemIsSelectable);

}
void MainWindow::enable_column(std::size_t x,std::size_t y)
{
    for(std::size_t j=x;j<costanti::DIM_CAMPOGIOCO;j++)
            ui->tableWidget->item(y,j)->setFlags(Qt::ItemIsEnabled|Qt::ItemIsSelectable);
}
void MainWindow::enable_row(std::size_t y,std::size_t x)
{
    for(std::size_t j=y;j<costanti::DIM_CAMPOGIOCO;j++)
            ui->tableWidget->item(j,x)->setFlags(Qt::ItemIsEnabled|Qt::ItemIsSelectable);
}
void MainWindow::disable_grid(std::size_t x,std::size_t y)
{
    disable_grid();
    if(to_insert.size()>1)
    {
        if(to_insert.at(0).getY()!=y)
            enable_row(y,x);
        else
            enable_column(x,y);
    }
    else
    {
        enable_column(x,y);
        enable_row(y,x);
    }


}
void MainWindow::enable_rack_click()
{
    for(std::size_t i =0;i<costanti::MAX_LETTERS_HAND;i++)
      ui->lettere_table->item(0,i)->setFlags(Qt::ItemIsEnabled|Qt::ItemIsSelectable);
}//EVENTI GUI
void MainWindow::on_conferma_btn_clicked() //se confermo l'inserimento
{
    if(game_started)
    {
        if(to_insert.size()>0)
        {

            short int point = arbitro->insWord(to_insert);
            std::cerr<<"PUNTI : "<<point<<std::endl;
            std::cerr<<"RACK  : "<<to_insert.size()<<std::endl;
            if(point>0)//se sono valide le lettere inserite e tutto va bene
            {
                giocatori.at(turno_giocatore).update_points(point);
                set_gamer_points();
                UpdateTerrain(terrain);
                foreach (cella c, to_insert)
                {
                    giocatori.at(turno_giocatore).remove_letter(c.getCharacter());
                }
                loadRack();

            }
            MainWindow::on_passaturno_btn_clicked(); //cambia turno
        }
        reset_insert_data();
    }
}
void MainWindow::on_cambia_btn_clicked() //cambia lettere nel rack
{
    if(game_started)
    {
        if(selected_letter!=costanti::EMPITY_FIELD)
        {
          giocatori.at(turno_giocatore).remove_letter(selected_letter);
          giocatori.at(turno_giocatore).add_letter(s->change_letter(selected_letter));
          loadRack();
          ui->passaturno_btn->show();  //può sempre cambiare turno in questo caso
          ui->cambia_btn->hide();
        }
        else
            error_message("ERRORE ","\n Prima devi selezionare una lettera\n");
    }
}
void MainWindow::on_passaturno_btn_clicked()
{
    if(game_started)
    {
        if(MainWindow::turno_giocatore<giocatori.size()-1)
            MainWindow::turno_giocatore++;
        else
            MainWindow::turno_giocatore=0;
        onTurnSwitched();
    }
}
void MainWindow::on_abort_btn_clicked() //annulla inserimento
{
    reset_insert_data();
    ui->cambia_btn->show();
}
void MainWindow::on_lettere_table_cellClicked(int row, int column) //click rack lettere
{
    if(game_started&&giocatori.at(turno_giocatore).get_letter(static_cast<unsigned int>(column))!=costanti::EMPITY_FIELD)
    {
      if(ui->lettere_table->item(row,column)->flags()!=Qt::ItemFlag::NoItemFlags)
      {
        selected_letter=giocatori.at(turno_giocatore).get_letter(static_cast<unsigned int>(column));
        ui->passaturno_btn->hide();
        ui->lettere_table->item(row,column)->setFlags(Qt::ItemFlag::NoItemFlags);
      }
    }
    else
        selected_letter=costanti::EMPITY_FIELD;

}
void MainWindow::on_tableWidget_cellClicked(int row, int column) //click campo gioco
{
    if(game_started)
    {
        if(selected_letter!=costanti::EMPITY_FIELD)
        {
            if(ui->tableWidget->item(row,column)->flags()!=Qt::ItemFlag::NoItemFlags)
            {
                ui->cambia_btn->hide();
                to_insert.push_back(cella(static_cast<std::size_t>(column),static_cast<std::size_t>(row),selected_letter));
                QString s;
                s+=selected_letter;
                ui->tableWidget->setItem(row,column,new QTableWidgetItem(s));
                disable_grid(static_cast<std::size_t>(column),static_cast<std::size_t>(row));
                selected_letter=costanti::EMPITY_FIELD;
            }
            else
                error_message("ERRORE INPUT","\n Seleziona un area del campo valida \n");

        }
        else
            error_message("ERRORE INPUT","\n Prima devi selezionare una lettera \n");

    }
}
void MainWindow::on_pushButton_7_clicked()  //suggerimento
{
    if(game_started)
    {

    }
}
void MainWindow::on_conferma_btn_3_clicked()
{
    start_game();
}
void MainWindow::on_conferma_btn_2_clicked()
{
    add_player();
    setPlayerLabel();
}
void MainWindow::on_end_btn_clicked()
{
    launch_win();
}
