// Third party libraries
#include <glad/gl.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <cglm/struct.h>

// Standard library
#include <stdio.h>
#include <stdlib.h>

// Custom libraries
// Exclude the boolean macro from the types library
#define NO_BOOL
#include "util/types.h"
#include "util/time.h"

//------------------------------------------------------------------------------
// Purpose: OpenGL Viewport size callback function for GLFW
//------------------------------------------------------------------------------
static void s_SizeCallback(GLFWwindow *pWindow, int iWidth, int iHeight) {
	glViewport(0, 0, iWidth, iHeight);
}

// The actuall function is at the bottom of the file, this is here because C doesn't like it when you declare functions after you called them.
// TODO: Make an actuall GLFW key callback function to properly utilize the input functions
static void s_ProcessInput(GLFWwindow *pWindow);

int main(int argc, char **argv) {
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
	GLFWwindow *pWindow = glfwCreateWindow(640, 480, "OpenSource Beta 0.1",
		NULL, NULL);
	if(pWindow == NULL) {
		fprintf(stderr, "ERROR: Failed to create a GLFW window!\n");
		glfwTerminate();
		return 1;
	}
	printf("Created Window!\n");
	glfwMakeContextCurrent(pWindow);

	// TODO: Add more callback functions in the future!
	glfwSetFramebufferSizeCallback(pWindow, s_SizeCallback);

	// This is the most EVIL way to initialize GLAD, I am sorry for whoever has to read this...
	int iGlVersion = gladLoadGL(glfwGetProcAddress);
	if(iGlVersion == 0) {
		fprintf(stderr, "ERROR: Failed to load GLAD!\n");
		glfwDestroyWindow(pWindow);
		glfwTerminate();
		return 1;
	}
	printf("Loaded OpenGL version %d.%d!\n",
		GLAD_VERSION_MAJOR(iGlVersion),
		GLAD_VERSION_MINOR(iGlVersion));

	// Pre-startup functions to enable different OpenGL extensions
	// TODO: Add a default option of window size and then add the ability to start from a different resolution in the command line.
	glViewport(0, 0, 640, 480);
	glEnable(GL_DEPTH_TEST);
	//--------------------------------------------------------------------------
	// Purpose: Main Loop
	//--------------------------------------------------------------------------
	while(!glfwWindowShouldClose(pWindow)) {
		// Makes sure the window doesn't appear as unresponding on some systems
		glfwPollEvents();

		s_ProcessInput(pWindow);

		// Prepare for rendering step
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Swap the buffers
		glfwSwapBuffers(pWindow);
	}
	//--------------------------------------------------------------------------
	// Purpose: Cleanup
	//--------------------------------------------------------------------------
	glfwDestroyWindow(pWindow);
	glfwTerminate();
	return 0;
	//--------------------------------------------------------------------------
}

//------------------------------------------------------------------------------
// Purpose: Input processing code
//------------------------------------------------------------------------------
// TODO: Move this to another file later...
static void s_ProcessInput(GLFWwindow *pWindow) {
	// This one is a little weird with the functions
	if(glfwGetKey(pWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		printf("Pressed Escape, exiting program!\n");
		glfwSetWindowShouldClose(pWindow, GLFW_TRUE);
	}
}