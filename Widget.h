#pragma once

#include <QWidget>
class QLayout;
class QPushButton;
class QVBoxLayout;
class QHBoxLayout;
class QRadioButton;
class QLabel;
class QLineEdit;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    void createMembers();
    void setupMembers();
    void makeConnections();

    void setBottomText();
private slots:
    void clearFirstNameLineEditSlot ();
    void clearSecondNameLineEditSlot();
    void clearThirdNameLineEditSlot ();

    void setFirstNameSlot (const QString& str);
    void setSecondNameSlot(const QString& str);
    void setThirdNameSlot (const QString& str);

private:
    QVBoxLayout *m_mainLayout = nullptr;

    QHBoxLayout *m_topLayout = nullptr;

    QVBoxLayout *m_buttonsLayout = nullptr;

    QPushButton *m_setFirstNameButton   = nullptr;
    QPushButton *m_setSecondNameButton        = nullptr;
    QPushButton *m_setThirdNameButton         = nullptr;

    QVBoxLayout *m_lineEditsLayout      = nullptr;
    QLineEdit   *m_firstNameLineEdit    = nullptr;
    QLineEdit   *m_secondNameLineEdit   = nullptr;
    QLineEdit   *m_thirdNameLineEdit    = nullptr;

    QLabel      *m_bottomTxt = nullptr;

    QString m_firstName;
    QString m_secondName;
    QString m_thirdName;
};
