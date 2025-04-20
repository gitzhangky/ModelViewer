#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>


class AssimpLoader
{
public:
	AssimpLoader();

	const aiScene* loadFile(std::string fileName, unsigned int flags);
private:

	struct aiMesh {};         //��ȡ�����񼸺�����

	Assimp::Importer importer;


};


