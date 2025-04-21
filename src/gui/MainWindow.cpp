#include "MainWindow.h"
#include "ui_Mainwindow.h"
#include <QSplitter>


MainWindow::MainWindow(QWidget* parent) :QMainWindow(parent)
{
	ui = new Ui::MainWindow;
	ui->setupUi(this);
	resize(QSize(2300, 1300));
	osgWidget = new OsgWidget;
	outputMessageWidget = new OutputMessageWidget;
	sceneManageWidget = new SceneManageWidget;
	detailDataWidget = new DetailDataWidget;
	propertyWidget = new PropertyWidget;
	setWindowTitle("ModelViewer");
	initLayout();
}

void MainWindow::initLayout()
{
	this->addDockWidget(Qt::LeftDockWidgetArea, sceneManageWidget, Qt::Vertical);
	this->addDockWidget(Qt::LeftDockWidgetArea, detailDataWidget, Qt::Horizontal);

	this->addDockWidget(Qt::RightDockWidgetArea, propertyWidget);
	this->addDockWidget(Qt::BottomDockWidgetArea, outputMessageWidget);





	this->setCentralWidget(osgWidget);

}
