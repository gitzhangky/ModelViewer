#include "OsgWidget.h"

OsgWidget::OsgWidget(QWidget* parent) :QOpenGLWidget(parent)
{
	sceneViewer = new SceneViewer;

}

void OsgWidget::initializeGL()
{


	// 创建 GraphicsWindowEmbedded（传入像素坐标）
	osg::ref_ptr<osg::GraphicsContext::Traits> traits = new osg::GraphicsContext::Traits;
	traits->x = this->x();
	traits->y = this->y();
	traits->width = this->width();
	traits->height = this->height();
	traits->windowDecoration = false;
	traits->doubleBuffer = true;
	traits->inheritedWindowData = nullptr;

	// 创建嵌入式窗口
	gw_ = new osgViewer::GraphicsWindowEmbedded(traits.get());

	// 设置 Viewer
	sceneViewer->getCamera()->setGraphicsContext(gw_.get());
	sceneViewer->getCamera()->setViewport(0, 0, width(), height());
	sceneViewer->getCamera()->setProjectionMatrixAsPerspective(
		30.0f, static_cast<double>(width()) / height(), 1.0f, 10000.0f);

	// 设置相机控制器
	sceneViewer->setCameraManipulator(new osgGA::TrackballManipulator());

	// 设置单线程渲染器（在 Qt 中通常不使用 OSG 的多线程）
	sceneViewer->setThreadingModel(osgViewer::Viewer::SingleThreaded);
}

void OsgWidget::paintGL()
{
	sceneViewer->frame();



}

void OsgWidget::resizeGL(int w, int h)
{
	sceneViewer->getCamera()->setViewport(0, 0, w, h);

	double aspectRatio = static_cast<double>(w) / static_cast<double>(h);
	sceneViewer->getCamera()->setProjectionMatrixAsPerspective(30.0f, aspectRatio, 1.0f, 10000.0f);
}


void OsgWidget::mouseDoubleClickEvent(QMouseEvent* event) {
	setKeyboardModifiers(event);
	int button = 0;
	switch (event->button())
	{
	case Qt::LeftButton:
		button = 1;
		break;
	case Qt::MidButton:
		button = 2;
		break;
	case Qt::RightButton:
		button = 3;
		break;
	}
	getEventQueue()->mouseDoubleButtonPress(event->x(), event->y(), button);
	QOpenGLWidget::mouseDoubleClickEvent(event);
}
void OsgWidget::mouseMoveEvent(QMouseEvent* event) {
	setKeyboardModifiers(event);
	getEventQueue()->mouseMotion(event->x(), event->y());
	QOpenGLWidget::mouseMoveEvent(event);
}
void OsgWidget::mousePressEvent(QMouseEvent* event) {
	setKeyboardModifiers(event);
	int button = 0;
	switch (event->button())
	{
	case Qt::LeftButton:
		button = 1;
		break;
	case Qt::MidButton:
		button = 2;
		break;
	case Qt::RightButton:
		button = 3;
		break;
	}
	getEventQueue()->mouseButtonPress(event->x(), event->y(), button);
	QOpenGLWidget::mousePressEvent(event);
}
void OsgWidget::mouseReleaseEvent(QMouseEvent* event) {
	setKeyboardModifiers(event);
	int button = 0;
	switch (event->button())
	{
	case Qt::LeftButton:
		button = 1;
		break;
	case Qt::MidButton:
		button = 2;
		break;
	case Qt::RightButton:
		button = 3;
		break;
	}
	getEventQueue()->mouseButtonRelease(event->x(), event->y(), button);
	QOpenGLWidget::mouseReleaseEvent(event);
}
void OsgWidget::wheelEvent(QWheelEvent* event) {
	setKeyboardModifiers(event);
	getEventQueue()->mouseScroll(event->orientation() == Qt::Vertical ?
		(event->delta() > 0 ? osgGA::GUIEventAdapter::SCROLL_UP : osgGA::GUIEventAdapter::SCROLL_DOWN) :
		(event->delta() > 0 ? osgGA::GUIEventAdapter::SCROLL_LEFT : osgGA::GUIEventAdapter::SCROLL_RIGHT));
	//getEventQueue()->mouseButtonPress(event->x(), event->y(), 3);
	QOpenGLWidget::wheelEvent(event);
}
bool OsgWidget::event(QEvent* event) {
	bool handled = QOpenGLWidget::event(event);
	switch (event->type())
	{
	case QEvent::MouseButtonPress:
	case QEvent::MouseButtonRelease:
	case QEvent::MouseMove:
	case QEvent::Wheel:
	case QEvent::MouseButtonDblClick:
	case QEvent::KeyPress:
	case QEvent::KeyRelease:
		this->update();
		break;
	default:
		break;
	}
	return handled;
}
void OsgWidget::setKeyboardModifiers(QInputEvent* event) {
	int modkey = event->modifiers() & (Qt::ShiftModifier | Qt::AltModifier | Qt::ControlModifier);
	unsigned mask = 0;
	if (modkey & Qt::ShiftModifier) {
		mask |= osgGA::GUIEventAdapter::MODKEY_SHIFT;
	}
	if (modkey & Qt::AltModifier) {
		mask |= osgGA::GUIEventAdapter::MODKEY_ALT;
	}
	if (modkey & Qt::ControlModifier) {
		mask |= osgGA::GUIEventAdapter::MODKEY_CTRL;
	}
	getEventQueue()->getCurrentEventState()->setModKeyMask(mask);
}
osgGA::EventQueue* OsgWidget::getEventQueue() const
{
	return gw_->getEventQueue();
}
void OsgWidget::keyPressEvent(QKeyEvent* event) {
	setKeyboardModifiers(event);

	switch (event->key())
	{
	case Qt::Key_F:
	{
		//从观察者获取节点的方式
		osg::Geode* geode = dynamic_cast<osg::Geode*>(sceneViewer->getSceneData());
		int count = geode->getNumDrawables();
		for (int i = 0; i < count; ++i) {
			osg::ShapeDrawable* draw = dynamic_cast<osg::ShapeDrawable*> (geode->getDrawable(i));
			std::string name = draw->getName();
			if (name == "zidingyi1") {
				draw->setColor(osg::Vec4(0.0, 1.0, 0.0, 1.0));
			}
		}
	}
	break;
	case Qt::Key_D:
	{
		//从观察者获取节点的方式
		osg::Geode* geode = dynamic_cast<osg::Geode*>(sceneViewer->getSceneData());
		int count = geode->getNumDrawables();
		for (int i = 0; i < count; ++i) {
			osg::Drawable* draw = geode->getDrawable(i);
			std::string name = draw->getName();
			if (name == "zidingyi1") {
				geode->removeDrawable(draw);
			}
		}
	}
	break;
	case Qt::Key_S:
	{
		getEventQueue()->keyPress(osgGA::GUIEventAdapter::KEY_S);
	}
	break;
	case Qt::Key_L:
	{
		getEventQueue()->keyPress(osgGA::GUIEventAdapter::KEY_L);
	}
	break;
	case Qt::Key_W:
	{
		getEventQueue()->keyPress(osgGA::GUIEventAdapter::KEY_W);
	}
	break;
	case Qt::Key_Space:
	{
		//返回Home键，
		getEventQueue()->keyPress(osgGA::GUIEventAdapter::KEY_Space);
	}
	break;
	default:
		break;
	}
	QOpenGLWidget::keyPressEvent(event);
}
void OsgWidget::keyReleaseEvent(QKeyEvent* event) {
	setKeyboardModifiers(event);

	QOpenGLWidget::keyReleaseEvent(event);
}