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
	statusMonitorWidget = new StatusMonitorWidget;
	setWindowTitle("ModelViewer");
	initLayout();
}

void MainWindow::initLayout()
{
	this->setCorner(Qt::BottomLeftCorner, Qt::LeftDockWidgetArea);
	this->addDockWidget(Qt::LeftDockWidgetArea, sceneManageWidget, Qt::Vertical);     //���
	this->addDockWidget(Qt::LeftDockWidgetArea, detailDataWidget, Qt::Horizontal);    //���
	this->addDockWidget(Qt::LeftDockWidgetArea, outputMessageWidget);				  //����
	this->addDockWidget(Qt::RightDockWidgetArea, propertyWidget);					  //�Ҳ�
	this->addDockWidget(Qt::BottomDockWidgetArea, statusMonitorWidget);				  //�ײ�
	this->setCentralWidget(osgWidget);												  //�м�

	this->resizeDocks(QList<QDockWidget*>{sceneManageWidget, outputMessageWidget}, QList<int>{3, 1}, Qt::Vertical);   //���ñ���




}
