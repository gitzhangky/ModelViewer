#include<qmainwindow.h>
#include"OsgWidget.h"
#include"OutputMessageWidget.h"
#include"DetailDataWidget.h"
#include"SceneManageWidget.h"
#include"PropertyWidget.h"
#include"StatusMonitorWidget.h"
namespace Ui
{
	class MainWindow;
}

class MainWindow : public QMainWindow
{
public:
	MainWindow(QWidget* parent = nullptr);

	void initLayout();

private:
	Ui::MainWindow* ui;
	OsgWidget* osgWidget;
	OutputMessageWidget* outputMessageWidget;
	DetailDataWidget* detailDataWidget;
	SceneManageWidget* sceneManageWidget;
	PropertyWidget* propertyWidget;
	StatusMonitorWidget* statusMonitorWidget;
};
