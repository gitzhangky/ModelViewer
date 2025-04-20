#include<qtablewidget.h>
#include<qdockwidget.h>
#pragma execution_character_set("utf-8")
class OutputMessageWidget : public QDockWidget
{
public:
	OutputMessageWidget(QWidget* parent = nullptr);

private:
	QTableWidget* tableWidget;
};