#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QtWidgets>

class GameView : public QWidget
{
    Q_OBJECT

public:
    GameView(QWidget *parent = nullptr);
    ~GameView();
    void initialize();
    bool checkWin();
    void restart();

public slots:
    void cross();

signals:
    void displaySplashScreen();

private:
    QPushButton *_buttonsTab[3][3];
    QLabel *_title;
    bool _player;
    int _turn;
};
#endif // GAMEVIEW_H
