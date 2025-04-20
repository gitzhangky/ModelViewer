#include"SceneManageWidget.h"

SceneManageWidget::SceneManageWidget(QWidget* parent) : QDockWidget(parent)
{
	setWindowTitle("³¡¾°¹ÜÀíÆ÷");
	setMinimumWidth(350);

	treeWidget = new QTreeWidget;
	setWidget(treeWidget);
}


