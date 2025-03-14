
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
int main() {
  //Inicializamos la libreria GLFW
  glfwInit();
  //Le indicamos a GLFW con que version de OpenGL queremos trabajar. En este caso estamos usando OpenGL 3.7
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  //Le indicamos GLFW que estamos usando solo funciones modernas
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  //Establecemos el nombre que deseamos aparezca en pantalla
  GLFWwindow* window = glfwCreateWindow(800, 800, "Primitivas Graficas",
  NULL, NULL);
  //En caso que la ventana no se pueda crear entonces enviamos un error.
  if (window == NULL) {
    std::cout << "Fallo al tratar de crear la ventana usando GLFW" <<
    std::endl;
    glfwTerminate();
    return -1;
  }
  //Ponemos la ventana en el contexto actual de lo que queremos presentar en pantalla
  glfwMakeContextCurrent(window);
  //Cargamos GLAD para configurar OpenGL
  gladLoadGL();
  //Especificamos el puerto de vision de OpenGL en la ventana. En este casotiene las coordenadas desde x = 0, y = 0, hasta x = 800, y = 800
  glViewport(0, 0, 800, 800);
  //Especificamos el color de fondo
  glClearColor(0.07f, 0.13f, 0.17f, 1.0f); //Podemos jugar con los parametrosdel color para obtener diferentes tonos del fondo en la ventana.
  //Limpiamos el buffer de memoria con el valor que tiene y asignamos unnuevo color si acaso es necesario
  glClear(GL_COLOR_BUFFER_BIT);
  //Realizamos un intercambio entre el buffer trasero con el bufferdelantero, es decir, entre el registro viejo de memoria con el nuevo registro dememoria
  glfwSwapBuffers(window);
  while (!glfwWindowShouldClose(window))
  {
    //Tomamos en consideracion todos los eventos que le puedan ser indicados a GLFW
    glfwPollEvents();
  }
  //Eliminamos la ventana antes de que termine el programa
  glfwDestroyWindow(window);
  //Terminamos de ejecutar GLFW antes de que termine el programa
  glfwTerminate();
  return 0;
}