#include "gamewindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyleSheet("\
                    QLabel { background-color: rgba(0,0,0,0); color : white; font-size : 24px; } \
                    QPushButton { color: white; background-color: #6f2232; border-radius: 4px; border: 2px solid #c3073f; font-size : 40px; }\
                    QPushButton:hover { border: 3px solid white; }\
                    ");

    GameWindow w;
    w.show();
    return a.exec();
}
