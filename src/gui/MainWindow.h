#include<qmainwindow.h>
#include"OsgWidget.h"


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
};
