#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  connect(ui->filterType, SIGNAL(currentIndexChanged(int)), this, SLOT(updateFilter()));
  connect(ui->passType, SIGNAL(currentIndexChanged(int)), this, SLOT(updateFilter()));
  connect(ui->order, SIGNAL(valueChanged(int)), this, SLOT(updateFilter()));
  connect(ui->samplingRate, SIGNAL(valueChanged(double)), this, SLOT(updateFilter()));
  connect(ui->cutoffFrequency, SIGNAL(valueChanged(double)), this, SLOT(updateFilter()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateFilter()
{
  double sampleRate = ui->samplingRate->value();
  double cutoff1    = ui->cutoffFrequency->value();

  if ((cutoff1*2.0) > sampleRate)
  {
    ui->cutoffFrequency->setValue(sampleRate/2.0);
    cutoff1 = ui->cutoffFrequency->value();
  }

  m_filter.setup(1, sampleRate, cutoff1);
  m_filter.reset();

  // generate some data:
  int numSamples = (int)(sampleRate/cutoff1)*1.5;
  QVector<double> x(numSamples), y(numSamples); // initialize with entries 0..100

  // step response
  for (int i=0; i<numSamples; ++i)
  {
    x[i] = i;
    y[i] = m_filter.filter((i == 0) ? 0.0 : 1.0);
  }
  // create graph and assign data to it:
  ui->plot->addGraph();
  ui->plot->graph(0)->setData(x, y);

  m_filter.reset();
  // impulse response
  for (int i=0; i<numSamples; ++i)
  {
    x[i] = i;
    y[i] = m_filter.filter((i == 0) ? 1.0 : 0.0);
  }
  // create graph and assign data to it:
  ui->plot->addGraph();
  ui->plot->graph(1)->setData(x, y);

  // give the axes some labels:
  ui->plot->xAxis->setLabel("n");
  ui->plot->yAxis->setLabel("y[n]");
  // set axes ranges, so we see all data:
  ui->plot->xAxis->setRange(0, numSamples*1.05);
  ui->plot->yAxis->setRange(0, 1.03125);
  ui->plot->replot();

  updateGain(sampleRate);
}

void MainWindow::updateGain(double sampleRate)
{
  int numSamples = (int)(0.5*sampleRate);
  numSamples = std::min(numSamples, 2000);

  QVector<double> x(numSamples), y(numSamples); // initialize with entries 0..100
  for (int i=0; i<numSamples; ++i)
  {
    x[i] = i;
    Iir::complex_t test = m_filter[0].response(i/sampleRate);
    y[i] = test.real();
  }
  ui->plot2->addGraph();
  ui->plot2->graph(0)->setData(x, y);

  // give the axes some labels:
  ui->plot2->xAxis->setLabel("omega");
  ui->plot2->yAxis->setLabel("y[n]");
  // set axes ranges, so we see all data:
  ui->plot2->xAxis->setRange(0, numSamples*1.05);
  ui->plot2->yAxis->setRange(0, 1.03125);
  ui->plot2->replot();
}
