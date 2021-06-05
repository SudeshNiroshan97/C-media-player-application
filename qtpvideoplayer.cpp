#include "qtpvideoplayer.h"
#include "ui_qtpvideoplayer.h"
#include <sstream>
#include <string>
#include <QKeyEvent>
#include <QMediaPlaylist>
//#include <QDebug>

QTPVideoPlayer::QTPVideoPlayer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QTPVideoPlayer)
{
    ui->setupUi(this);
    ui->actionunMuteVol->setVisible(0);
   // ui->actionSpeakeVol->setDisabled(1);
    ui->actionSpeakeVol->setVisible(0);

    player = new QMediaPlayer(this);
    vw = new QVideoWidget(this);
    vw->setFixedSize(590,265);
    vw->setStyleSheet("margin");



    player->setVideoOutput(vw);
    ui->statusBar->setStyleSheet(" background-color: black; color:white;");
    ui->mainToolBar->setStyleSheet(" background-color: #999966; color: red; height:40px; align:center; border: 2px ");


    slider = new QSlider(this);

      sliderVol = new QSlider(this);
      slider->setGeometry(15,275,540,25);
      slider->setOrientation(Qt::Horizontal);
      sliderVol->setOrientation(Qt::Horizontal);
      sliderVol->setStyleSheet("max-width: 150px; height:15px; ");
      slider->setStyleSheet("max-width: 540px; height:10px; padding-top: 150; background-color: black; border: 2px solid red; border-radius: 10px; ");


      ui->actionPause->setVisible(0);
      ui->mainToolBar->setMovable(0);
      ui->mainToolBar->addWidget(sliderVol);
      ui->mainToolBar->adjustSize();
      sliderVol->setRange(0, 100);
      sliderVol->setValue(player->volume());
      
      
      
      
      connect(sliderVol, &QSlider::valueChanged, player, &QMediaPlayer::setVolume);
      connect(sliderVol,&QSlider::sliderMoved,player,&QMediaPlayer::setVolume);
      connect(player,&QMediaPlayer::durationChanged,slider,&QSlider::setMaximum);
      connect(player,&QMediaPlayer::positionChanged,slider,&QSlider::setValue);
      connect(slider,&QSlider::sliderMoved,player,&QMediaPlayer::setPosition);


  }





QTPVideoPlayer::~QTPVideoPlayer()
{
    delete ui;
}

void QTPVideoPlayer::on_actionOpen_triggered()
{

    QString filename = QFileDialog::getOpenFileName(this,"Open a File","","Video File(*.*)");
    on_actionStop_triggered();

    player->setMedia(QUrl::fromLocalFile(filename));

   on_actionPlay_triggered();
}

void QTPVideoPlayer::on_actionPause_triggered()
{

    player->pause();
    ui->statusBar->showMessage("Paused");
    ui->actionPlay->setVisible(1);
    ui->actionPause->setVisible(0);

}

void QTPVideoPlayer::on_actionPlay_triggered()
{

    player->play();
    ui->actionPlay->setVisible(0);
    ui->actionPause->setVisible(1);
    ui->statusBar->showMessage("Playing..");

}

void QTPVideoPlayer::on_actionNext_triggered()
{

    playlist->next();
    on_actionPlay_triggered();
    ui->statusBar->showMessage("Playing Next file..");
}

void QTPVideoPlayer::on_actionBack_triggered()
{

    playlist->previous();
    on_actionPlay_triggered();
    ui->statusBar->showMessage("Playing Previous file..");
}

void QTPVideoPlayer::on_actionMute_triggered()
{

    player->setVolume(0);
    ui->statusBar->showMessage("Audio Muted..");
    sliderVol->setValue(0);
    ui->actionMute->setVisible(0);
    ui->actionunMuteVol->setVisible(1);
}

void QTPVideoPlayer::on_actionStop_triggered()
{

    player->stop();
    ui->statusBar->showMessage("Stoped");
    ui->actionPlay->setVisible(1);
    ui->actionPause->setVisible(0);
}

void QTPVideoPlayer::on_actionPlaylist_triggered()
{

    playlist = new QMediaPlaylist(player);
    QStringList filenames = QFileDialog::getOpenFileNames(this, "Open a File","","Video File(*.*)");
    for(const QString & filename: filenames){
        playlist->addMedia(QMediaContent(QUrl::fromLocalFile(filename)));
    }

        player->setPlaylist(playlist);
        player->setPlaylist(playlist);
        on_actionPlay_triggered();

}

void QTPVideoPlayer::on_actionunMuteVol_triggered()
{
    ui->actionunMuteVol->setVisible(0);
    ui->actionMute->setVisible(1);
    player->setVolume(45);
    sliderVol->setValue(45);
    ui->statusBar->showMessage("Volume unmuted.. Volue set to 45");
}

void QTPVideoPlayer::on_actionFullScreen_triggered()
{
    vw->setFullScreen(1);


    //cant't return from full screen


}




