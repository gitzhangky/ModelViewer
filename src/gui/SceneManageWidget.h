#include<qtreewidget.h>
#include<QDockWidget>
#pragma execution_character_set("utf-8")

class SceneManageWidget : public QDockWidget
{
public:
	SceneManageWidget(QWidget* parent = nullptr);


private:
	QTreeWidget* treeWidget;
};




