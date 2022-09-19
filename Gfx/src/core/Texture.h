#pragma once

#include <string>
#include <glew.h>
#include "../utils/stb_image.h"
#include <iostream>


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

