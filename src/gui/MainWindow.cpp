#include "MainWindow.h"
#include "ui_Mainwindow.h"


MainWindow::MainWindow(QWidget* parent) :QMainWindow(parent)
{
	ui = new Ui::MainWindow;
	ui->setupUi(this);
	osgWidget = new OsgWidget;
	setWindowTitle("ModelViewer");
	initLayout();
}

void MainWindow::initLayout()
{
	this->setCentralWidget(osgWidget);

}
