#include<qtreewidget.h>
#include<QDockWidget>
#pragma execution_character_set("utf-8")

class DetailDataWidget : public QDockWidget
{
public:
	DetailDataWidget(QWidget* parent = nullptr);

private:
	QTreeWidget* treeWidget;


};











