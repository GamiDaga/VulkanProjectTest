//#define GLFW_INCLUDE_VULKAN
//#include <GLFW/glfw3.h>
//
//#define GLM_FORCE_RADIANS
//#define GLM_FORCE_DEPTH_ZERO_TO_ONE
//#include <glm/vec4.hpp>
//#include <glm/mat4x4.hpp>
//
//#include <iostream>
//
////codigo mio
////#include "stdafx.h"
////
//
//int main() {
//	glfwInit();
//
//	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
//	GLFWwindow* window = glfwCreateWindow(800, 600, "Vulkan window", nullptr, nullptr);
//
//	uint32_t extensionCount = 0;
//	vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
//
//	std::cout << extensionCount << " extensions supported" << std::endl;
//
//	glm::mat4 matrix;
//	glm::vec4 vec;
//	auto test = matrix * vec;
//
//	while (!glfwWindowShouldClose(window)) {
//		glfwPollEvents();
//	}
//
//	glfwDestroyWindow(window);
//
//	glfwTerminate();
//
//	return 0;
//}

#define GLFW_INCLUDE_VULKAN		//GLFW es una biblioteca de utilidad ligera para uso con OpenGL. 
#include <GLFW/glfw3.h>			//Proporciona la capacidad de crear y dirigir ventanas y aplicaciones OpenGL, así como recibir la entrada de joystick, teclado y ratón.
								

#include <iostream>		//se incluyen para informar y propagar errores
#include <stdexcept>	//se incluyen para informar y propagar errores
#include <functional>	//se incluye para la administracion de recursos
#include <cstdlib>		//se incluye porque proporciona las macros EXIT_SUCCESS y EXIT_FAILURE

class HelloTriangleApplication {
	/* El programa en sí mismo está envuelto en una clase donde almacenaremos los objetos Vulkan como miembros de clase privados y
	agregaremos funciones para iniciar cada uno de ellos, que se llamarán desde la función initVulkan */
public:

	const int WIDTH = 800;
	const int HEIGHT = 600;
	GLFWwindow* window;

	//vida de la aplicacion
	void run() {
		initWindow();
		initVulkan();
		mainLoop();
		cleanup();
	}

private:
	//funcion para administracion de ventanas e inicializacion de GLFW
	void initWindow() {
		glfwInit();		//inicializa las librerias de glfw
		
		//glfw crea un contexto para OpenGL, por eso para evitar eso se usan las siguientes function 
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

		window = glfwCreateWindow(WIDTH, HEIGHT, "VulkanProjectTest_Title", nullptr, nullptr); // (zize,zize,title, monitor, solo relevante para OpenGl)
	}
	//funcion para hacer los llamados a funciones que inicializan objetos Vulkan
	void initVulkan() {

	}

	//función para incluir un bucle que se repita hasta que la ventana se cierre en un momento
	void mainLoop() {
		while (!glfwWindowShouldClose(window)) {
			glfwPollEvents();
		}
	}

	//funcion para desasignar los recursos utilizados, se ejecuta cuando mainLoop() retorna
	void cleanup() {
		glfwDestroyWindow(window);

		glfwTerminate();
	}
};

int main() {
	HelloTriangleApplication app;

	try {
		app.run();
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}