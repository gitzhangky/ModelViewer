#include "MainWindow.h"
#include "ui_Mainwindow.h"
#include <QSplitter>
#include"qdebug.h"

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
	rightToolBar = new QToolBar("属性工具栏");
	setWindowTitle("ModelViewer");
	initLayout();
}

void MainWindow::initLayout()
{
	this->setCorner(Qt::BottomLeftCorner, Qt::LeftDockWidgetArea);
	this->addDockWidget(Qt::LeftDockWidgetArea, sceneManageWidget, Qt::Vertical);     //左侧
	this->addDockWidget(Qt::LeftDockWidgetArea, detailDataWidget, Qt::Horizontal);    //左侧
	this->addDockWidget(Qt::LeftDockWidgetArea, outputMessageWidget);				  //左下
	this->addDockWidget(Qt::RightDockWidgetArea, propertyWidget);					  //右侧
	this->addDockWidget(Qt::BottomDockWidgetArea, statusMonitorWidget);				  //底部
	this->setCentralWidget(osgWidget);												  //中间

	this->resizeDocks(QList<QDockWidget*>{sceneManageWidget, outputMessageWidget}, QList<int>{3, 1}, Qt::Vertical);   //设置比例

	this->addToolBar(Qt::RightToolBarArea, rightToolBar);
	initToolBarIcon();

}

void MainWindow::initToolBarIcon()
{
	act_bk = new QAction;
	QIcon icon(":/new/prefix1/Resource/aclogo.icon");
	if (icon.isNull())
	{
		qDebug() << icon.isNull();
	}
	act_bk->setIcon(QIcon(":/new/prefix1/Resource/aclogo.icon"));
	act_bk->setStatusTip("设置背景颜色");
	rightToolBar->addAction(act_bk);

}
