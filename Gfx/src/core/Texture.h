#pragma once

#include <string>
#include <glew.h>
#include <iostream>

#include "../utils/stb_image.h"
#include "../utils/Log.h"

namespace Gfx
{

	class Texture
	{
	public:
		Texture(const std::string& fileName);

		void Bind();

		virtual ~Texture();
	protected:
	private:
		Texture(const Texture& texture) { m_texture = 0; }
		void operator=(const Texture& texture) {}

		GLuint m_texture;
	};

}

