#pragma once

#include <QMainWindow>
#include <QTabWidget>
#include <QLineEdit>
#include <QComboBox>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private:
    QWidget* createTab(const QStringList& units,
                       const QString& topEditName,
                       const QString& topComboName,
                       const QString& bottomEditName,
                       const QString& bottomComboName);

    QTabWidget* tabWidget;
};
