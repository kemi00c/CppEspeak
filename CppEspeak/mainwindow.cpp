#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>

#include "espeakvoice.h"
#include "espeakvoices.h"
#include "espeaker.h"
#include "espeaksaver.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setVoices();

    setDefault();

    espeakProcess = NULL;


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::setVoices()
{
    EspeakVoices espeakVoices = EspeakVoices();

    voices = espeakVoices.getVoices();

    for (EspeakVoice* voice : *voices)
    {
        ui->comboBoxLanguage->addItem(voice->name());
    }
}

void MainWindow::setDefault()
{
    ui->comboBoxLanguage->setCurrentIndex(ui->comboBoxLanguage->findText("English_(America)"));
    ui->sliderAmplitude->setValue(100);
    ui->sliderPitch->setValue(50);
}

EspeakVoice* MainWindow::getCurrentVoice()
{
    for (EspeakVoice* voice : *voices)
    {
        if (voice->name() == ui->comboBoxLanguage->currentText())
        {
            return voice;
        }
    }

    return NULL;
}

void MainWindow::on_buttonPlay_pressed()
{
    EspeakVoice* selectedVoice = getCurrentVoice();

    if ((selectedVoice != NULL))
    {
        if (espeakProcess == NULL)
        {
            Espeaker espeaker = Espeaker();
            espeakProcess = espeaker.speak(ui->textEdit->toPlainText(), selectedVoice, ui->sliderAmplitude->value(), ui->sliderPitch->value());
            ui->buttonPlay->setText("Stop");
            connect(espeakProcess, SIGNAL(finished(int,QProcess::ExitStatus)), this, SLOT(on_espeakProcess_finished()));
        }
        else
        {
            espeakProcess->kill();
        }
    }
}

void MainWindow::on_espeakProcess_finished()
{
    ui->buttonPlay->setText("Play");
    espeakProcess = NULL;
}


void MainWindow::on_buttonSave_pressed()
{
    QString filename = QFileDialog::getSaveFileName(this, "Save as WAV...", NULL, "WAV files (*.wav);;All files (*)", NULL);
    if (!filename.isNull() || filename.isEmpty())
    {
        EspeakVoice* voice = getCurrentVoice();
        EspeakSaver saver = EspeakSaver();
        saver.save(ui->textEdit->toPlainText(), voice, ui->sliderAmplitude->value(), ui->sliderPitch->value(), filename);
    }
}

