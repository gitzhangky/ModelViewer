#include"SceneManageWidget.h"

SceneManageWidget::SceneManageWidget(QWidget* parent) : QDockWidget(parent)
{
	setWindowTitle("����������");
	setMinimumWidth(350);

	treeWidget = new QTreeWidget;
	setWidget(treeWidget);
}


