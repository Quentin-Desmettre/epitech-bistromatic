#include "bistromatic.h"
#include "ui_bistromatic.h"
#include <QLabel>
#include <QPushButton>
#include <QFile>
#include <iostream>
#include <QTextEdit>
#include <unistd.h>
#include <fcntl.h>
#include <QFile>
#include <QTime>
#include <QMessageBox>
#include <QScreen>

QString get_last_line(QTextEdit *edit)
{
    QString line = "";
    QString text = edit->toPlainText();

    for (int i = 0, n = text.size(); i < n; i++) {
        line += text[i];
        if (text[i] == '\n')
            line = "";
    }
    return line;
}

void delay(int ms)
{
    QTime dieTime= QTime::currentTime().addMSecs(ms);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

bistromatic::bistromatic(QWidget *parent) :
    QWidget(parent),
    erasable(false),
    m_is_computing(false),
    is_resize(false),
    ui(new Ui::bistromatic)
{
    ui->setupUi(this);
    setWindowTitle("Bistromatic");
    ui->results->setMaximumHeight(height() / 3);
    path = "./calc";
    adapt_graphics();
    m_cursor = ui->results->textCursor();
    if (system("make -s easy"))
        exit(84);
}

void bistromatic::adapt_graphics()
{
    QFont font;
    ui->results->setMaximumHeight(height() / 3);
    for (int i = 0; i < 24; i++) {
        font = ui->gridLayout->itemAt(i)->widget()->font();
        font.setPixelSize(height() / 20);
        ui->gridLayout->itemAt(i)->widget()->setFont(font);
        ui->gridLayout->itemAt(i)->widget()->setMaximumHeight((height() - ui->results->height())/6);
    }
    font = ui->results->font();
    font.setPixelSize(height() / 25);
    ui->results->setFont(font);
}

void bistromatic::resizeEvent(QResizeEvent *event)
{
    if (!isVisible() || is_resize)
        return;
    adapt_graphics();
}

void bistromatic::do_action() {
    QPushButton *origin = qobject_cast<QPushButton*>(sender());
    QString text;
    QString tmp;

    if (!origin)
        return;
    text = origin->text();
    if (text == "Quit")
        qApp->exit(0);
    else if (text == "<-") {
        if (!erasable)
            return;
        text = ui->results->toPlainText();
        ui->results->setPlainText(text.remove(text.size() - 1, 1));
        erasable = (text.size() == 0 || text.back() == '\n') ? true : false;
    }
    else if (text == "???") {
        QMessageBox msg(QMessageBox::Question, "Bonus", "Please give us a medal :(", QMessageBox::Yes | QMessageBox::No);
        QFont font = msg.font();
        font.setPixelSize(height() / 20);
        msg.setFont(font);
        while (msg.exec() == QMessageBox::No);
        QMessageBox thx(QMessageBox::Information, "Bonus", "Thank you :)");
        thx.setFont(font);
        thx.exec();
    }
    else if (text == "Clear") {
        ui->results->setPlainText("");
        erasable = false;
    }
    else if (text == "=") {
        m_is_computing = true;
        compute(m_expr);
        erasable = false;
        m_expr = "";
        m_is_computing = false;
    }
    else {
        tmp = ui->results->toPlainText();
        tmp += text;
        ui->results->setPlainText(tmp);
        erasable = true;
    }

}

void bistromatic::compute(QString expr){
    if (expr.size() == 0)
        return;
    if (expr == "0+0") {
        toto();
        expr = ui->results->toPlainText();
        expr += "\n";
        ui->results->setPlainText(expr);
        m_expr = "";
        return;
    }
    QString final_expr = " \'" + expr + "\' ";
    system((path + final_expr + " > output").toStdString().c_str());
    QFile output("output");
    if (output.open(QIODevice::ReadOnly | QIODevice::Text)){
        expr = ui->results->toPlainText();
        expr += "\n" + output.readAll();
        ui->results->setPlainText(expr);        
        m_expr = "";

    }
    else
        ui->results->setPlainText("ERROR : " + output.errorString());
}

void bistromatic::on_results_cursorPositionChanged()
{
    if (ui->results->textCursor().position() < global_text.size() - m_expr.size()) {
        ui->results->setTextCursor(m_cursor);
    }
    else
        m_cursor = ui->results->textCursor();
}

void bistromatic::on_results_textChanged()
{
    QString text = ui->results->toPlainText();

    if (text.size() > 0 && text.back() == '\n' && !m_is_computing) {
        m_is_computing = true;
        text.chop(1);
        ui->results->setPlainText(text);
        ui->pushButton_18->click();
    }
    m_expr = get_last_line(ui->results);
    global_text = ui->results->toPlainText();
}

void bistromatic::toto()
{

    QLabel *widget = new QLabel;
    QFile *totos = new QFile("bonus/Bistromatic_graphic/toto_1");
    if (!totos->open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QString toto_1 = totos->readAll();
    totos->close();
    delete totos;
    totos = new QFile("bonus/Bistromatic_graphic/toto_2");
    if (!totos->open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QString toto_2 = totos->readAll();
    totos->close();
    delete totos;
    totos = new QFile("bonus/Bistromatic_graphic/toto_3");
    if (!totos->open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QString toto_3 = totos->readAll();
    totos->close();
    delete totos;
    totos = new QFile("bonus/Bistromatic_graphic/toto_4");
    if (!totos->open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QString toto_4 = totos->readAll();
    totos->close();
    delete totos;
    totos = new QFile("bonus/Bistromatic_graphic/toto_5");
    if (!totos->open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QString toto_5 = totos->readAll();
    totos->close();
    delete totos;

    widget->setFont({ "Courier" });
    QFont font = widget->font();
    font.setBold(true);
    widget->setFont(font);
    QRect rec = QGuiApplication::primaryScreen()->geometry();
    int height = rec.height();
    int width = rec.width();
    widget->resize(width / 4.35, height / 2.15);
    widget->show();
    delay(300);
    widget->setText(toto_1);
    delay(300);
    widget->setText(toto_2);
    delay(300);
    widget->setText(toto_3);
    delay(300);
    widget->setText(toto_4);
    delay(300);
    widget->setText(toto_5);
    delay(1000);
    delete widget;
}
bistromatic::~bistromatic()
{
    delete ui;
}
