#ifndef MY_BISTROMATIC_H
#define MY_BISTROMATIC_H

#include <QWidget>
#include <QTextCursor>

namespace Ui {
class bistromatic;
}

class bistromatic : public QWidget
{
    Q_OBJECT

public:
    explicit bistromatic(QWidget *parent = nullptr);
    ~bistromatic();
public slots:
    void do_action();
    void on_results_cursorPositionChanged();
    void on_results_textChanged();

private:
    void adapt_graphics();
    void resizeEvent(QResizeEvent *event) override;
    void compute(QString expr);
    void toto();
    QString m_expr;
    QString global_text;
    bool erasable;
    Ui::bistromatic *ui;
    QString path;
    QTextCursor m_cursor;
    bool m_is_computing;
    bool is_resize;
};

#endif // MY_BISTROMATIC_H
