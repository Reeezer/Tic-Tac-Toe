#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QtWidgets>
#include "gameview.h"
#include "splashscreen.h"

class GameWindow : public QStackedWidget
{
    Q_OBJECT

public:
    GameWindow(QWidget *parent = nullptr);
    ~GameWindow();

public slots:
    void displaySplashScreen();
    void displayGame();

protected:
    void timerEvent(QTimerEvent *);

private:
    GameView *_gameView;
    SplashScreen *_splashScreen;
    int _currentFrame;
    QElapsedTimer *_timer;
};

#endif // GAMEWINDOW_H
