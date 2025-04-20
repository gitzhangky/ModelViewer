#include<iostream>
#include"MainWindow.h"
#include<qapplication.h>
#include"AssimpLoader.h"
int main(int argc, char** argv)
{
	QApplication App(argc, argv);

	MainWindow* window = new MainWindow;
	window->showNormal();
	return App.exec();
}
