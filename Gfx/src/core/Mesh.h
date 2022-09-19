#pragma once

#include <glew.h>
#include <glm.hpp>
#include <string>
#include <vector>
#include "../utils/ObjLoader.h"
#include "../utils/utils.h"
#include <map>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <stdlib.h>

namespace Gfx
{
	struct Vertex
	{
	public:
		Vertex(const glm::vec3& pos, const glm::vec2& texCoord, const glm::vec3& normal)
		{
			this->pos = pos;
			this->texCoord = texCoord;
			this->normal = normal;
		}

		glm::vec3* GetPos() { return &pos; }
		glm::vec2* GetTexCoord() { return &texCoord; }
		glm::vec3* GetNormal() { return &normal; }

	private:
		glm::vec3 pos;
		glm::vec2 texCoord;
		glm::vec3 normal;
	};

	enum MeshBufferPositions
	{
		POSITION_VB,
		TEXCOORD_VB,
		NORMAL_VB,
		INDEX_VB
	};

	class Mesh
	{
	public:
		Mesh(const std::string& fileName);
		Mesh(Vertex* vertices, unsigned int numVertices, unsigned int* indices, unsigned int numIndices);

		void Draw();
		void DrawWire();

		virtual ~Mesh();
	protected:
	private:
		static const unsigned int NUM_BUFFERS = 4;
		void operator=(const Mesh& mesh) {}
		Mesh(const Mesh& mesh) { m_numIndices = 0; m_vertexArrayObject = 0; m_vertexArrayBuffers[0] = 0; }

		void InitMesh(const IndexedModel& model);

		GLuint m_vertexArrayObject;
		GLuint m_vertexArrayBuffers[NUM_BUFFERS];
		unsigned int m_numIndices;
	};
}
