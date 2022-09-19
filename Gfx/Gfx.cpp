#include <iostream>
#include "src/core/Display.h"
#include "src/core/Mesh.h"
#include "src/core/Shader.h"
#include "src/core/Texture.h"
#include "src/core/Camera.h"
#include <map>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include "src/utils/Log.h"

using namespace Gfx;

static const int DISPLAY_WIDTH = 1280;
static const int DISPLAY_HEIGHT = 720;

int main(int argc, char** argv)
{
	Gfx::Log::Init();

	Display display(DISPLAY_WIDTH, DISPLAY_HEIGHT, "OpenGL");
	
	Mesh monkey("./res/monkey3.obj");
	Shader shader("./res/solidRed");
	Texture texture("./res/bricks.jpg");
	Transform transform;
	Camera camera(glm::vec3(0.0f, 0.0f, -5.0f), 70.0f, (float)DISPLAY_WIDTH / (float)DISPLAY_HEIGHT, 0.1f, 100.0f);

	SDL_Event e;
	bool isRunning = true;
	float counter = 0.0f;
	while (isRunning)
	{
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
				isRunning = false;
		}

		display.Clear(0.1f, 0.1f, 0.2f, 1.0f);

		float sinCounter = sinf(counter);
		float absSinCounter = abs(sinCounter);

		//transform.GetPos()->x = sinCounter;
		transform.GetRot()->y = counter * 100;
		//transform.GetRot()->z = counter * 100;
		//transform.GetScale()->x = absSinCounter;
		//transform.GetScale()->y = absSinCounter;

		shader.Bind();
		texture.Bind();
		shader.Update(transform, camera);
		monkey.DrawWire();
		//mesh.Draw();

		display.SwapBuffers();
		SDL_Delay(1);
		counter += 0.0001f;
	}

	return 0;
}
