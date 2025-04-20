#include "AssimpLoader.h"
#include <filesystem>


AssimpLoader::AssimpLoader()
{



}

const aiScene* AssimpLoader::loadFile(std::string fileName, unsigned int flags)
{
	const aiScene* sceneData = importer.ReadFile(fileName, aiProcess_Triangulate | aiProcess_GenNormals | aiProcess_JoinIdenticalVertices |
		aiProcess_ImproveCacheLocality | aiProcess_RemoveRedundantMaterials);

	return sceneData;
}




