#include "DetailDataWidget.h"

DetailDataWidget::DetailDataWidget(QWidget* parent) :QDockWidget(parent)
{
	setWindowTitle("��ϸ��Ϣ");
	setMinimumWidth(350);

	treeWidget = new QTreeWidget;
	setWidget(treeWidget);

}
