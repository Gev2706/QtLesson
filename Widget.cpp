#include "Widget.h"
#include <QLayout>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QRadioButton>
#include <QLabel>
#include <QLineEdit>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , m_firstName ("Poghos")
    , m_secondName("Poghosyan")
    , m_thirdName ("Poghosi")
{
    createMembers();
    setupMembers();
    makeConnections();
}

Widget::~Widget()
{
}

void Widget::createMembers()
{
    m_mainLayout = new QVBoxLayout();
    m_topLayout  = new QHBoxLayout();

    m_buttonsLayout = new QVBoxLayout();

    m_setFirstNameButton  = new QPushButton("Reset First Name" );
    m_setSecondNameButton = new QPushButton("Reset Second Name");
    m_setThirdNameButton  = new QPushButton("Reset Third Name" );

    m_lineEditsLayout    = new QVBoxLayout();
    m_firstNameLineEdit  = new QLineEdit  ();
    m_secondNameLineEdit = new QLineEdit  ();
    m_thirdNameLineEdit  = new QLineEdit  ();

    m_bottomTxt = new QLabel();
}




void Widget::setupMembers()
{


    m_buttonsLayout->addWidget(m_setFirstNameButton);
    m_buttonsLayout->addWidget(m_setSecondNameButton     );
    m_buttonsLayout->addWidget(m_setThirdNameButton      );


    m_lineEditsLayout->addWidget(m_firstNameLineEdit );
    m_lineEditsLayout->addWidget(m_secondNameLineEdit);
    m_lineEditsLayout->addWidget(m_thirdNameLineEdit );

    m_topLayout->addLayout(m_lineEditsLayout);
    m_topLayout->addLayout(m_buttonsLayout);


    m_mainLayout->addLayout(m_topLayout);
    m_mainLayout->addWidget(m_bottomTxt);

    m_firstNameLineEdit ->setText(m_firstName );
    m_secondNameLineEdit->setText(m_secondName);
    m_thirdNameLineEdit ->setText(m_thirdName);

    setLayout(m_mainLayout);
    setBottomText();
}

void Widget::makeConnections()
{
    QObject::connect(m_setFirstNameButton, &QPushButton::clicked,
                     this, &Widget::clearFirstNameLineEditSlot);
    QObject::connect(m_setSecondNameButton, &QPushButton::clicked,
                     this, &Widget::clearSecondNameLineEditSlot);
    QObject::connect(m_setThirdNameButton, &QPushButton::clicked,
                     this, &Widget::clearThirdNameLineEditSlot);

    QObject::connect(m_firstNameLineEdit, &QLineEdit::textChanged,
                     this, &Widget::setFirstNameSlot);
    QObject::connect(m_secondNameLineEdit, &QLineEdit::textChanged,
                     this, &Widget::setSecondNameSlot);
    QObject::connect(m_thirdNameLineEdit, &QLineEdit::textChanged,
                     this, &Widget::setThirdNameSlot);
}

void Widget::setBottomText()
{
    QString msg = "Hello dear " + m_firstName
                  + " "         + m_secondName
                  + " "         + m_thirdName ;
    m_bottomTxt->setText(msg);
}

void Widget::clearFirstNameLineEditSlot ()
{
    m_firstNameLineEdit->setText(m_firstName = "Poghos");
    setBottomText();
}

void Widget::clearSecondNameLineEditSlot()
{
    m_secondNameLineEdit->setText(m_secondName = "Poghosyan");
    setBottomText();
}

void Widget::clearThirdNameLineEditSlot ()
{

    m_thirdNameLineEdit->setText(m_thirdName = "Poghosi");
    setBottomText();
}

void Widget::setFirstNameSlot (const QString& str)
{
    m_firstName = str;
    setBottomText();
}
void Widget::setSecondNameSlot(const QString& str)
{
    m_secondName = str;
    setBottomText();
}
void Widget::setThirdNameSlot (const QString& str)
{
    m_thirdName = str;
    setBottomText();
}

