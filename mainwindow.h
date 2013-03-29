#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "iir/Bessel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
  void updateFilter();
  void updateGain(double samplerate);

private:
  Ui::MainWindow *ui;
  Iir::Bessel::LowPass<1> m_filter;
};

#endif // MAINWINDOW_H
