#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QVector>
#include <QGridLayout>
#include <QWidget>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void handleButtonClick();

private:
    QVector<QPushButton*> buttons;
    bool xTurn;
    void checkWinner();
    void resetGame();
};

#endif // MAINWINDOW_H
