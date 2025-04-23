#include<qmainwindow.h>
#include"OsgWidget.h"
#include"OutputMessageWidget.h"
#include"DetailDataWidget.h"
#include"SceneManageWidget.h"
#include"PropertyWidget.h"
#include"StatusMonitorWidget.h"
#include<qtoolbutton.h>
namespace Ui
{
	class MainWindow;
}

class MainWindow : public QMainWindow
{
public:
	MainWindow(QWidget* parent = nullptr);

	void initLayout();

	void initToolBarIcon();
private:
	Ui::MainWindow* ui;
	OsgWidget* osgWidget;
	OutputMessageWidget* outputMessageWidget;
	DetailDataWidget* detailDataWidget;
	SceneManageWidget* sceneManageWidget;
	PropertyWidget* propertyWidget;
	StatusMonitorWidget* statusMonitorWidget;

	QToolBar* rightToolBar;

	QAction* act_bk;        //±≥æ∞…Ë÷√∞¥≈•
};
