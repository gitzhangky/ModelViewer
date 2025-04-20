#include<qopenglwidget.h>
#include"SceneViewer.h"
#include <osgViewer/GraphicsWindow>
#include <osgGA/TrackballManipulator>
#include <QInputEvent>
class OsgWidget :public QOpenGLWidget
{
public:
	OsgWidget(QWidget* parent = nullptr);

protected:

	void initializeGL()override;

	void paintGL()override;

	void resizeGL(int w, int h)override;

	void mouseDoubleClickEvent(QMouseEvent* event)override;
	void mouseMoveEvent(QMouseEvent* event)override;
	void mousePressEvent(QMouseEvent* event)override;
	void mouseReleaseEvent(QMouseEvent* event)override;
	void wheelEvent(QWheelEvent* event)override;
	void keyPressEvent(QKeyEvent* event)override;
	void keyReleaseEvent(QKeyEvent* event)override;

	bool event(QEvent* event) override;

	void setKeyboardModifiers(QInputEvent* event);

	osgGA::EventQueue* getEventQueue()const;
private:
	SceneViewer* sceneViewer;

	osg::ref_ptr<osgViewer::GraphicsWindowEmbedded> gw_;
};