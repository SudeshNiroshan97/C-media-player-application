#ifndef QTPVIDEOPLAYER_H
#define QTPVIDEOPLAYER_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QFileDialog>
#include <QProgressBar>
#include <QSlider>
#include <QKeyEvent>



namespace Ui {
class QTPVideoPlayer;
}

class QTPVideoPlayer : public QMainWindow
{
    Q_OBJECT

public:
    explicit QTPVideoPlayer(QWidget *parent = nullptr);
    ~QTPVideoPlayer();

private slots:
    void on_actionOpen_triggered();

    void on_actionPause_triggered();

    void on_actionPlay_triggered();

    void on_actionNext_triggered();

    void on_actionBack_triggered();

    void on_actionMute_triggered();

    void on_actionStop_triggered();

    void on_actionPlaylist_triggered();

    void on_actionunMuteVol_triggered();

    void on_actionFullScreen_triggered();







private:
    Ui::QTPVideoPlayer *ui;
    QMediaPlayer *player;
    QVideoWidget *vw;
    QProgressBar *bar;
    QSlider *slider;
    QSlider *sliderVol;
    QToolBar *toolbar1;

    QMediaPlaylist *playlist;
    QMediaContent *contents;
   // void keyPressEvent (QKeyEvent *event);

};

#endif // QTPVIDEOPLAYER_H
