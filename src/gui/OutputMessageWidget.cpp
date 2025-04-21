#include "OutputMessageWidget.h"

OutputMessageWidget::OutputMessageWidget(QWidget* parent) :QDockWidget(parent)
{
	setWindowTitle(QString("ĞÅÏ¢Êä³öÀ¸"));
	tableWidget = new QTableWidget;
	setWidget(tableWidget);
}