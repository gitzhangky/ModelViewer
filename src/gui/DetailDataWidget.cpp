#include "DetailDataWidget.h"

DetailDataWidget::DetailDataWidget(QWidget* parent) :QDockWidget(parent)
{
	setWindowTitle("ÏêÏ¸ĞÅÏ¢");
	setMinimumWidth(350);

	treeWidget = new QTreeWidget;
	setWidget(treeWidget);

}
