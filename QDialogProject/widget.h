#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QPlainTextEdit>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    QPlainTextEdit *plainTextEdit;

private:
    Ui::Widget *ui;

protected:
    void onPressBtnOpenSingleFile();
    void onPressBtnOpenMutipleFiles();
    void onPressBtnOpenDirectory();
    void onPressBtnSaveFile();

    void onPressBtnInputString();
    void onPressBtnInputInteger();
    void onPressBtnInputFloat();
    void onPressBtnInputItem();

    void onClickBtnQuestion();
    void onClickBtnInformation();
    void onClickBtnWarning();
    void onClickBtnCritical();
    void onClickBtnAbout();
    void onClickBtnAboutQt();

    void onClickBtnClearText();
};

#endif // WIDGET_H
