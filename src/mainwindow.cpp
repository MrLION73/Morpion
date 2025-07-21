#include "mainwindow.h"
#include <QMessageBox>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), xTurn(true)
{
    QWidget *central = new QWidget(this);
    QGridLayout *layout = new QGridLayout;

    for (int i = 0; i < 9; ++i) {
        QPushButton *btn = new QPushButton("");
        btn->setFixedSize(100, 100);
        btn->setFont(QFont("Arial", 24, QFont::Bold));
        connect(btn, &QPushButton::clicked, this, &MainWindow::handleButtonClick);
        buttons.append(btn);
        layout->addWidget(btn, i / 3, i % 3);
    }

    central->setLayout(layout);
    setCentralWidget(central);
    setWindowTitle("Morpion");
    setFixedSize(320, 340);
}

MainWindow::~MainWindow() {}

void MainWindow::handleButtonClick() {
    QPushButton *clicked = qobject_cast<QPushButton*>(sender());
    if (!clicked || !clicked->text().isEmpty())
        return;

    clicked->setText(xTurn ? "X" : "O");
    xTurn = !xTurn;

    checkWinner();
}

void MainWindow::checkWinner() {
    const int winCombos[8][3] = {
        {0,1,2}, {3,4,5}, {6,7,8}, // Rows
        {0,3,6}, {1,4,7}, {2,5,8}, // Columns
        {0,4,8}, {2,4,6}           // Diagonals
    };

    for (auto &combo : winCombos) {
        QString t1 = buttons[combo[0]]->text();
        QString t2 = buttons[combo[1]]->text();
        QString t3 = buttons[combo[2]]->text();
        if (!t1.isEmpty() && t1 == t2 && t2 == t3) {
            QMessageBox::information(this, "Fin de partie", QString("Le joueur %1 a gagné !").arg(t1));
            resetGame();
            return;
        }
    }

    bool draw = std::all_of(buttons.begin(), buttons.end(), [](QPushButton *b){ return !b->text().isEmpty(); });
    if (draw) {
        QMessageBox::information(this, "Fin de partie", "Match nul !");
        resetGame();
    }
}

void MainWindow::resetGame() {
    for (QPushButton *btn : buttons) {
        btn->setText("");
    }
    xTurn = true;
}
