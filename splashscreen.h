#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include <QWidget>

class SplashScreen : public QWidget
{
    Q_OBJECT

public:
    SplashScreen(QWidget *parent = nullptr);
    ~SplashScreen();

signals:
    void displayGame();
};

#endif // SPLASHSCREEN_H
