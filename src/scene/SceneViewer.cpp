#include "SceneViewer.h"
#include <osg/Material>
#include <osgGA/TrackballManipulator>
#include"AssimpLoader.h"
#include <filesystem>



SceneViewer::SceneViewer(osg::ArgumentParser& arguments) :osgViewer::Viewer(arguments)
{
	rootScene = new RootScene;
	setSceneData(rootScene);
}

SceneViewer::SceneViewer(const osgViewer::Viewer& viewer, const osg::CopyOp& copyop) :osgViewer::Viewer(viewer, copyop)
{
	rootScene = new RootScene;
	setSceneData(rootScene);
}

SceneViewer::SceneViewer()
{
	rootScene = new RootScene;
	setSceneData(rootScene);
	initExample();
}

void SceneViewer::initExample()
{
	AssimpLoader loader;

	std::filesystem::path currentPath = std::filesystem::current_path();
	std::string path = currentPath.string() + "\\..\\models\\models\\OBJ\\spider.obj";

	auto sceneData = loader.loadFile(path, aiProcess_Triangulate | aiProcess_GenSmoothNormals | aiProcess_JoinIdenticalVertices);



	if (!sceneData || !sceneData->mRootNode) {
		return;
	}


	processNode(sceneData->mRootNode, sceneData, rootScene);

	setSceneData(rootScene);
	this->getCamera()->setClearColor(osg::Vec4(0.7f, 0.7f, 0.9f, 1.0f));
	////std::cout << " �������ڵ㴴���ɹ�\n";

	//// ===== 2. ������������������� =====
	//osg::ref_ptr<osg::Box> box = new osg::Box(osg::Vec3(), 2.0f); // �߳�2.0
	//osg::ref_ptr<osg::ShapeDrawable> boxDrawable = new osg::ShapeDrawable(box);
	//boxDrawable->setColor(osg::Vec4(1, 0, 0, 1)); // ������ɫ

	//osg::ref_ptr<osg::Geode> baseGeode = new osg::Geode();
	//baseGeode->addDrawable(boxDrawable);
	////std::cout << " ���������崴���ɹ�\n";

	//// ===== 3. ���������任�ڵ� =====
	//// ԭʼλ�ã���ɫ��
	//osg::ref_ptr<osg::MatrixTransform> originalNode = new osg::MatrixTransform();
	//originalNode->addChild(baseGeode);

	//// Z+5����ɫ��
	//osg::ref_ptr<osg::MatrixTransform> zPos5Node = new osg::MatrixTransform();
	//zPos5Node->setMatrix(osg::Matrix::translate(0, 0, 5));
	//osg::ref_ptr<osg::Geode> zPos5Geode = dynamic_cast<osg::Geode*>(baseGeode->clone(osg::CopyOp::DEEP_COPY_ALL));
	//zPos5Node->addChild(zPos5Geode);

	//// Z-5����ɫ��
	//osg::ref_ptr<osg::MatrixTransform> zNeg5Node = new osg::MatrixTransform();
	//zNeg5Node->setMatrix(osg::Matrix::translate(0, 0, -5));
	//osg::ref_ptr<osg::Geode> zNeg5Geode = dynamic_cast<osg::Geode*>(baseGeode->clone(osg::CopyOp::DEEP_COPY_ALL));
	//zNeg5Node->addChild(zNeg5Geode);
	////std::cout << " �任�ڵ㴴���ɹ�\n";

	//// ===== 4. ���ò�ͬ��ɫ���� =====
	//// ��ɫ����
	//osg::ref_ptr<osg::Material> greenMat = new osg::Material();
	//greenMat->setDiffuse(osg::Material::FRONT, osg::Vec4(0, 1, 0, 1));
	//zPos5Geode->getOrCreateStateSet()->setAttributeAndModes(greenMat);

	//// ��ɫ����
	//osg::ref_ptr<osg::Material> blueMat = new osg::Material();
	//blueMat->setDiffuse(osg::Material::FRONT, osg::Vec4(0, 0, 1, 1));
	//zNeg5Geode->getOrCreateStateSet()->setAttributeAndModes(blueMat);
	////std::cout << " �������óɹ�\n";

	//// ===== 5. �������� =====
	//rootScene->addChild(originalNode);
	//rootScene->addChild(zPos5Node);
	//rootScene->addChild(zNeg5Node);
	////std::cout << " �����������\n";

	//// ===== 6. ���ò鿴�� =====
	//this->setCameraManipulator(new osgGA::TrackballManipulator());

	//// ��������ӽ�
	//this->getCamera()->setViewMatrixAsLookAt(
	//	osg::Vec3d(0, 15, 0),  // ���λ�ã�Y=15�߶ȣ�
	//	osg::Vec3d(0, 0, 0),   // �۲����ĵ�
	//	osg::Vec3d(0, 0, 1)    // �Ϸ���Z�ᣩ
	//);
	//this->getCamera()->setClearColor(osg::Vec4(0.7f, 0.7f, 0.9f, 1.0f));
	////std::cout << " �鿴���������\n";


}

void SceneViewer::processNode(const aiNode* node, const aiScene* scene, osg::Group* parent)
{
	osg::ref_ptr<osg::MatrixTransform> transform = new osg::MatrixTransform;
	transform->setMatrix(aiMatrixToOsg(node->mTransformation));
	parent->addChild(transform);

	for (unsigned i = 0; i < node->mNumMeshes; ++i) {
		const aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
		osg::ref_ptr<osg::Geode> geode = new osg::Geode;
		geode->addDrawable(convertMesh(mesh));
		transform->addChild(geode);
	}

	for (unsigned i = 0; i < node->mNumChildren; ++i) {
		processNode(node->mChildren[i], scene, transform);
	}
}

osg::Matrix SceneViewer::aiMatrixToOsg(const aiMatrix4x4& m)
{
	return osg::Matrix(
		m.a1, m.b1, m.c1, m.d1,
		m.a2, m.b2, m.c2, m.d2,
		m.a3, m.b3, m.c3, m.d3,
		m.a4, m.b4, m.c4, m.d4
	);
}

osg::ref_ptr<osg::Geometry> SceneViewer::convertMesh(const aiMesh* mesh)
{
	auto geometry = new osg::Geometry;
	auto vertices = new osg::Vec3Array;
	auto normals = new osg::Vec3Array;

	for (unsigned i = 0; i < mesh->mNumVertices; ++i) {
		vertices->push_back(osg::Vec3(
			mesh->mVertices[i].x,
			mesh->mVertices[i].y,
			mesh->mVertices[i].z
		));

		if (mesh->HasNormals()) {
			normals->push_back(osg::Vec3(
				mesh->mNormals[i].x,
				mesh->mNormals[i].y,
				mesh->mNormals[i].z
			));
		}
	}

	geometry->setVertexArray(vertices);
	if (mesh->HasNormals()) geometry->setNormalArray(normals, osg::Array::BIND_PER_VERTEX);

	for (unsigned i = 0; i < mesh->mNumFaces; ++i) {
		const aiFace& face = mesh->mFaces[i];
		if (face.mNumIndices == 3) {
			geometry->addPrimitiveSet(new osg::DrawElementsUInt(
				osg::PrimitiveSet::TRIANGLES, 3, face.mIndices));
		}
	}

	return geometry;
}
