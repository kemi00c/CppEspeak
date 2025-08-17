#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>

#include "espeakvoice.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:

    QProcess* espeakProcess;
    QList<EspeakVoice*>* voices;

    void setVoices();
    void setDefault();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_buttonPlay_pressed();
    void on_espeakProcess_finished();

    void on_buttonSave_pressed();

private:
    Ui::MainWindow *ui;
    EspeakVoice* getCurrentVoice();
};
#endif // MAINWINDOW_H
