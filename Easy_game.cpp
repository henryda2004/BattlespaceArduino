//
// Created by mrr on 24/03/23.
//

#include "Easy_game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>

Easy_game::Easy_game(QWidget *parent){
    //Escena
    QGraphicsScene *scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    int width = 800;
    int height = 600;

    //Item en la escena
    Player *player = new Player();
    player->setPixmap(QPixmap("/home/mrr/Desktop/Battle-Space/myship.png").scaled(50,50));

    //Agregado de el item a la escena
    scene->addItem(player);

    //Hacer rectangulo focusiable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    //Mostrar scena
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    player->setPos(0,150);
    int bullet_speed = 600;

    //Timer de las balas
    QTimer *timer_bullets = new QTimer;
    QObject::connect(timer_bullets,SIGNAL(timeout()),player,SLOT(bullets()));
    timer_bullets->start(bullet_speed);

    //Timer de los enemigos
    QTimer *timer_enemies = new QTimer;
    QObject::connect(timer_enemies,SIGNAL(timeout()),player,SLOT(spawn_enemies()));
    timer_enemies->start(3000);

    show();
}
