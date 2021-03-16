#include "gamewindow.h"

GameWindow::GameWindow(QWidget *parent)
    : QStackedWidget(parent)
{
    setFixedSize(500, 400);

    setWindowTitle("Tic Tac Toe");
    setWindowIcon(QIcon(":/res/tic-tac-toe.png"));
    QFontDatabase::addApplicationFont(":/res/GROBOLD.ttf");
    setStyleSheet("QStackedWidget { background-image : url(:/res/background/1.png); }");
    _currentFrame = 0;

    _splashScreen = new SplashScreen(this);
    addWidget(_splashScreen);

    _gameView = new GameView(this);
    addWidget(_gameView);

    QObject::connect(_splashScreen, &SplashScreen::displayGame, this, &GameWindow::displayGame);
    QObject::connect(_gameView, &GameView::displaySplashScreen, this, &GameWindow::displaySplashScreen);

    setCurrentWidget(_splashScreen);

    _timer = new QElapsedTimer();
    _timer->start();
    startTimer(10);
}

GameWindow::~GameWindow()
{
}

void GameWindow::timerEvent(QTimerEvent *event)
{
    Q_UNUSED(event);
    if(_timer->elapsed() > 40)
    {
        _timer->restart();
        _currentFrame = (_currentFrame + 1) % 17;
        setStyleSheet("QStackedWidget { background-image : url(:/res/background/" + QString::asprintf("%d", _currentFrame + 1) + ".png); }");
    }
}

void GameWindow::displaySplashScreen()
{
    setCurrentWidget(_splashScreen);
}

void GameWindow::displayGame()
{
    _gameView->initialize();
    setCurrentWidget(_gameView);
}
