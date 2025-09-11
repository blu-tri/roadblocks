#include "../include/glad/glad.h"
#include <GLFW/glfw3.h>
#include <string>
#include <iostream>

void  prinfo(std::string info);
void prerror(std::string error);
void prwarn(std::string warning);

int main()
{
	prinfo("test info");
	prerror("test error");
	prwarn("test warning");
	
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(800, 480, "roadblocks", NULL, NULL);
	if (window == NULL)
	{
		prerror("Failed to create GLFW window");
    glfwTerminate();
    return -1;
	}
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
    prerror("Failed to start GLAD");
    return -1;
	}

	prinfo("Successfully started base libraries. Moving onto GL set up");

	glViewport(0, 0, 800, 480);
}

/* FUNCTIONS */

void  prinfo(std::string info)
{
	std::cout << "\x1b[38;2;0;255;0m[INFO] \x1b[0m" << info << "\n";
}

void prerror(std::string error)
{
	std::cout << "\x1b[38;2;255;0;0m[ERROR] \x1b[0m" << error << "\n";
}

void prwarn(std::string warning)
{
	std::cout << "\x1b[38;2;255;255;0m[WARNING] \x1b[0m" << warning << "\n";
}
