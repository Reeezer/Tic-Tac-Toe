#include "gameview.h"

GameView::GameView(QWidget *parent)
    : QWidget(parent)
{
    _player = false;

    _title = new QLabel(this);
    _title->setAlignment(Qt::AlignCenter);
    _title->setFont(QFont("GROBOLD"));

    QGridLayout *gridLayout = new QGridLayout();
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            _buttonsTab[i][j] = new QPushButton(this);
            gridLayout->addWidget(_buttonsTab[i][j], i + 1, j);
            QObject::connect(_buttonsTab[i][j], &QPushButton::clicked, this, &GameView::cross);
            _buttonsTab[i][j]->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            _buttonsTab[i][j]->setFont(QFont("GROBOLD"));
        }
    }

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(_title);
    mainLayout->addLayout(gridLayout);
    setLayout(mainLayout);

    initialize();
}

GameView::~GameView()
{
}

void GameView::initialize()
{
    _turn = 0;
    if (!_player)
        _title->setText("Player 1's turn");
    else
        _title->setText("Player 2's turn");

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            _buttonsTab[i][j]->setText("");
            _buttonsTab[i][j]->setEnabled(true);
        }
    }
}

void GameView::cross()
{
    if (qobject_cast<QPushButton *>(QObject::sender())->text() == "") {
        QString str = "";
        if (_player) {
            str = "X";
            _title->setText("Player 1's turn");
        }
        else {
            str = "O";
            _title->setText("Player 2's turn");
        }
        qobject_cast<QPushButton *>(QObject::sender())->setText(str);
        _player = !_player;
        _turn++;

        if (checkWin()) {
            if (_player)
                _title->setText("Player 1 has won !");
            else
                _title->setText("Player 2 has won !");
            restart();
        }
        else if(_turn == 9) {
            _title->setText("It's a draw !");
            restart();
        }
    }
}

void GameView::restart()
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            _buttonsTab[i][j]->setEnabled(false);
    QTimer::singleShot(2000, this, &GameView::displaySplashScreen);
}

bool GameView::checkWin()
{
    // Columns and rows
    for (int i = 0; i < 3; i++)
        if ((_buttonsTab[i][0]->text() == _buttonsTab[i][1]->text() && _buttonsTab[i][0]->text() == _buttonsTab[i][2]->text() && _buttonsTab[i][0]->text() != "") || (_buttonsTab[0][i]->text() == _buttonsTab[1][i]->text() && _buttonsTab[0][i]->text() == _buttonsTab[2][i]->text() && _buttonsTab[0][i]->text() != ""))
            return true;

    // Diagonals
    if ((_buttonsTab[0][0]->text() == _buttonsTab[1][1]->text() && _buttonsTab[0][0]->text() == _buttonsTab[2][2]->text() && _buttonsTab[0][0]->text() != "") || (_buttonsTab[0][2]->text() == _buttonsTab[1][1]->text() && _buttonsTab[0][2]->text() == _buttonsTab[2][0]->text() && _buttonsTab[1][1]->text() != ""))
        return true;

    return false;
}

