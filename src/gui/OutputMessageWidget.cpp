#include "OutputMessageWidget.h"

OutputMessageWidget::OutputMessageWidget(QWidget* parent) :QDockWidget(parent)
{
	setWindowTitle(QString("��Ϣ�����"));
	setMinimumHeight(350);
	tableWidget = new QTableWidget;
	setWidget(tableWidget);
}