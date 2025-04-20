#include "OutputMessageWidget.h"

OutputMessageWidget::OutputMessageWidget(QWidget* parent) :QDockWidget(parent)
{
	setWindowTitle(QString("ĞÅÏ¢Êä³öÀ¸"));
	setMinimumHeight(350);
	tableWidget = new QTableWidget;
	setWidget(tableWidget);
}