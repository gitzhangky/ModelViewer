#include "OutputMessageWidget.h"

OutputMessageWidget::OutputMessageWidget(QWidget* parent) :QDockWidget(parent)
{
	setWindowTitle(QString("��Ϣ�����"));
	tableWidget = new QTableWidget;
	setWidget(tableWidget);
}