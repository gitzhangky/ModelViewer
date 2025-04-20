
#include <osgViewer/Viewer>
#include "RootScene.h"
#include <osgViewer/GraphicsWindow>
#include <osg/ShapeDrawable>
#include <osg/MatrixTransform>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
class SceneViewer : public osgViewer::Viewer
{
public:
	SceneViewer(osg::ArgumentParser& arguments);

	SceneViewer(const osgViewer::Viewer& viewer, const osg::CopyOp& copyop = osg::CopyOp::SHALLOW_COPY);

	SceneViewer();

	void initExample();

	void processNode(const aiNode* node, const aiScene* scene, osg::Group* parent);

	osg::Matrix aiMatrixToOsg(const aiMatrix4x4& m);

	osg::ref_ptr<osg::Geometry> convertMesh(const aiMesh* mesh);
private:
	RootScene* rootScene;;

};

