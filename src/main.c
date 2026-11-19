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
	if(!glfwInit()) {
		fprintf(stderr, "ERROR: Failed to load GLFW!\n");
		return 1;
	}
	glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow *window = glfwCreateWindow(640, 480, "OpenSource Beta 0.1", NULL, NULL);
	if(window == NULL) {
		fprintf(stderr, "ERROR: Failed to create a GLFW window!\n");
		glfwTerminate();
		return 1;
	}
	printf("Created Window!\n");
	glfwMakeContextCurrent(window);

	glfwSetFramebufferSizeCallback(window, s_sizeCallback);

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

	glViewport(0, 0, 640, 480);
	glEnable(GL_DEPTH_TEST);

	while(!glfwWindowShouldClose(window)) {
		glfwPollEvents();

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glfwSwapBuffers(window);
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}