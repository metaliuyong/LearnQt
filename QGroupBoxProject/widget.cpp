#include "widget.h"
#include "ui_widget.h"
#include <QRadioButton>
#include <QToolButton>
#include <QPushButton>
#include <QCheckBox>
#include <QMenu>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    gridLayout = new QGridLayout(this);
    gridLayout->addWidget(createFirstExclusiveGroup(),0,0);
    gridLayout->addWidget(createSecondExclusiveGroup(),0,1);
    gridLayout->addWidget(createNonExclusiveGroup(),1,0);
    gridLayout->addWidget(createPushButtonGroup(),1,1);
}

Widget::~Widget()
{
    delete ui;
}

QGroupBox *Widget::createFirstExclusiveGroup(){
    QGroupBox *groupBox = new QGroupBox(tr("Exclusive Radio Buttons"));
    QRadioButton *radio1 = new QRadioButton(tr("&Radio button 1"));
    QRadioButton *radio2 = new QRadioButton(tr("R&adio button 2"));
    QRadioButton *radio3 = new QRadioButton(tr("Ra&dio button 3"));

    radio1->setChecked(true);

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(radio1);
    vbox->addWidget(radio2);
    vbox->addWidget(radio3);
//    vbox->addStretch(1);
    groupBox->setLayout(vbox);

    return groupBox;
}


QGroupBox *Widget::createSecondExclusiveGroup()
{
    QGroupBox *groupBox = new QGroupBox(tr("E&xclusive Radio Buttons"));
    groupBox->setCheckable(true);
    groupBox->setChecked(true);

    QRadioButton *radio1 = new QRadioButton(tr("Rad&io button1"));
    QRadioButton *radio2 = new QRadioButton(tr("Radi&o buttoon2"));
    QRadioButton *radio3 = new QRadioButton(tr("Radio &button3"));
    radio1->setChecked(true);
    QCheckBox *checkBox = new QCheckBox(tr("Ind&ependent checkbox"));
    checkBox->setChecked(true);

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(radio1);
    vbox->addWidget(radio2);
    vbox->addWidget(radio3);
    vbox->addWidget(checkBox);
    groupBox->setLayout(vbox);

    return groupBox;
}

QGroupBox *Widget::createNonExclusiveGroup()
{
    QGroupBox *groupBox = new QGroupBox(tr("No-Exclusive Checkboxes"));
    groupBox->setFlat(true);

    QCheckBox *checkBox1 = new QCheckBox(tr("&Checkbox 1"));
    QCheckBox *checkBox2 = new QCheckBox(tr("C&heckbox 2"));
    checkBox2->setChecked(true);
    QCheckBox *tristateBox = new QCheckBox(tr("Tri-&state buttton"));
    tristateBox->setTristate(true);//是否启用三种状态切换
    tristateBox->setCheckState(Qt::PartiallyChecked);//介于Qt::Unchecked和Qt::Checked之间

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(checkBox1);
    vbox->addWidget(checkBox2);
    vbox->addWidget(tristateBox);
    vbox->addStretch(1);
    groupBox->setLayout(vbox);
    return groupBox;
}


QGroupBox *Widget::createPushButtonGroup()
{
    QGroupBox *groupBox = new QGroupBox(tr("&Push Button"));
    groupBox->setCheckable(true);
    groupBox->setChecked(true);

    QPushButton *pushButton = new QPushButton(tr("&Normal Button"));
    QPushButton *toggleButton = new QPushButton(tr("&Toggle Button"));
    toggleButton->setCheckable(true);
    toggleButton->setChecked(true);

    QPushButton *flatButton = new QPushButton(tr("&Flat Button"));
    flatButton->setFlat(true);

    QPushButton *popupButton = new QPushButton(tr("Pop&up Button"));
    QMenu *menu = new QMenu(this);
    menu->addAction((tr("&First Item")));
    menu->addAction((tr("&Second Item")));
    menu->addAction((tr("Third Item")));
    menu->addAction(tr("F&ourth Item"));
    popupButton->setMenu(menu);

    QAction *newAction = menu->addAction(tr("Submenu"));
    QMenu *subMenu = new QMenu(tr("Popup Submenu"));
    subMenu->addAction(tr("Item 1"));
    subMenu->addAction(tr("Item 2"));
    subMenu->addAction(tr("Item 3"));
    newAction->setMenu(subMenu);

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(pushButton);
    vbox->addWidget(toggleButton);
    vbox->addWidget(flatButton);
    vbox->addWidget(popupButton);
    groupBox->setLayout(vbox);
    return groupBox;
}

