#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>


class AssimpLoader
{
public:
	AssimpLoader();

	const aiScene* loadFile(std::string fileName, unsigned int flags);
private:

	struct aiMesh {};         //读取的网格几何数据

	Assimp::Importer importer;


};


