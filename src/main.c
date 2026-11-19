#include <glad/gl.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <cglm/struct.h>

#include <stdio.h>
#include <stdlib.h>

static void s_sizeCallback(GLFWwindow *window, int width, int height) {
	glViewport(0, 0, width, height);
}

int main(int argc, char* argv[]) {
	//--------------------------------------------------------------------------
	// Purpose: Initialization Code
	//--------------------------------------------------------------------------
	if(!glfwInit()) {
		fprintf(stderr, "ERROR: Failed to load GLFW!\n");
		return 1;
	}
	// These are just window hints so that GLFW can actually launch in the right configuration
	glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// I have no clue why is this one so messed up but I am too lazy to fix this)
	GLFWwindow *window = glfwCreateWindow(640, 480, "OpenSource Beta 0.1",
		NULL, NULL);
	if(window == NULL) {
		fprintf(stderr, "ERROR: Failed to create a GLFW window!\n");
		glfwTerminate();
		return 1;
	}
	printf("Created Window!\n");
	glfwMakeContextCurrent(window);

	// TODO: Add more callback functions in the future!
	glfwSetFramebufferSizeCallback(window, s_sizeCallback);

	// This is the most EVIL way to initialize GLAD, I am sorry for whoever has to read this...
	int version = gladLoadGL(glfwGetProcAddress);
	if(version == 0) {
		fprintf(stderr, "ERROR: Failed to load GLAD!\n");
		glfwDestroyWindow(window);
		glfwTerminate();
		return 1;
	}
	printf("Loaded OpenGL version %d.%d!\n",
		GLAD_VERSION_MAJOR(version),
		GLAD_VERSION_MINOR(version));

	// Pre-startup functions to enable different OpenGL extensions
	// TODO: Add a default option of window size and then add the ability to start from a different resolution in the command line.
	glViewport(0, 0, 640, 480);
	glEnable(GL_DEPTH_TEST);
	//--------------------------------------------------------------------------
	// Purpose: Main Loop
	//--------------------------------------------------------------------------
	while(!glfwWindowShouldClose(window)) {
		// Makes sure the window doesn't appear as unresponding on some systems
		glfwPollEvents();

		// Prepare for rendering step
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Swap the buffers
		glfwSwapBuffers(window);
	}
	//--------------------------------------------------------------------------
	// Purpose: Cleanup
	//--------------------------------------------------------------------------
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
	//--------------------------------------------------------------------------
}