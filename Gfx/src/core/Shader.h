#pragma once

#include <string>
#include <glew.h>
#include <iostream>
#include <fstream>

#include "Transform.h"
#include "../utils/Log.h"

namespace Gfx
{

	class Shader
	{
	public:
		Shader(const std::string& fileName);

		void Bind();
		void Update(const Transform& transform, const Camera& camera);

		virtual ~Shader();
	protected:
	private:
		static const unsigned int NUM_SHADERS = 2;
		static const unsigned int NUM_UNIFORMS = 3;
		void operator=(const Shader& shader) {}
		Shader(const Shader& shader) { { m_program = 0; m_shaders[0] = 0; m_uniforms[0] = 0; } }

		std::string LoadShader(const std::string& fileName);
		void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);
		GLuint CreateShader(const std::string& text, unsigned int type);

		GLuint m_program;
		GLuint m_shaders[NUM_SHADERS];
		GLuint m_uniforms[NUM_UNIFORMS];
	};

}
