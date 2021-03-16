#include "splashscreen.h"

SplashScreen::SplashScreen(QWidget *parent)
    : QWidget(parent)
{
    QPushButton *button = new QPushButton(this);
    button->setIcon(QIcon(":/res/play.png"));
    button->setIconSize(QSize(50, 50));
    button->setMaximumSize(150, 150);
    button->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Expanding);

    QLabel *title = new QLabel("Tic Tac Toe", this);
    title->setAlignment(Qt::AlignCenter);
    title->setFont(QFont("GROBOLD"));

    QVBoxLayout *vLayout = new QVBoxLayout();
    vLayout->addStretch();
    vLayout->addWidget(title);
    vLayout->addStretch();
    vLayout->addWidget(button);
    vLayout->addStretch();

    QHBoxLayout *mainlayout = new QHBoxLayout();
    mainlayout->addLayout(vLayout);
    setLayout(mainlayout);

    QObject::connect(button, &QPushButton::clicked, this, &SplashScreen::displayGame);
}

SplashScreen::~SplashScreen()
{

}
