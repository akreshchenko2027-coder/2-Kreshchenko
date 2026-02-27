#include "mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Converter");
    resize(500, 200);

    tabWidget = new QTabWidget(this);
    tabWidget->setObjectName("tabWidget");

    tabWidget->addTab(
        createTab(
            {"m", "km", "in", "ft", "mi"},
            "editTopLength", "comboTopLength",
            "editBottomLength", "comboBottomLength"
            ),
        "Length"
        );

    tabWidget->addTab(
        createTab(
            {"kg", "lb", "oz"},
            "editTopMass", "comboTopMass",
            "editBottomMass", "comboBottomMass"
            ),
        "Mass"
        );

    tabWidget->addTab(
        createTab(
            {"°C", "°F", "K"},
            "editTopTemp", "comboTopTemp",
            "editBottomTemp", "comboBottomTemp"
            ),
        "Temperature"
        );

    setCentralWidget(tabWidget);
}

QWidget* MainWindow::createTab(const QStringList& units,
                               const QString& topEditName,
                               const QString& topComboName,
                               const QString& bottomEditName,
                               const QString& bottomComboName)
{
    QWidget* tab = new QWidget;

    auto* mainLayout = new QVBoxLayout(tab);

    auto* topLayout = new QHBoxLayout;
    QLineEdit* editTop = new QLineEdit;
    QComboBox* comboTop = new QComboBox;

    editTop->setObjectName(topEditName);
    comboTop->setObjectName(topComboName);
    comboTop->addItems(units);

    editTop->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    comboTop->setMinimumWidth(80);

    topLayout->addWidget(editTop);
    topLayout->addWidget(comboTop);

    auto* bottomLayout = new QHBoxLayout;
    QLineEdit* editBottom = new QLineEdit;
    QComboBox* comboBottom = new QComboBox;

    editBottom->setObjectName(bottomEditName);
    comboBottom->setObjectName(bottomComboName);
    comboBottom->addItems(units);

    editBottom->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    comboBottom->setMinimumWidth(80);

    bottomLayout->addWidget(editBottom);
    bottomLayout->addWidget(comboBottom);

    mainLayout->addLayout(topLayout);
    mainLayout->addLayout(bottomLayout);
    mainLayout->addStretch();

    return tab;
}
