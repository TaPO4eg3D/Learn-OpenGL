#include <GLFW/glfw3.h>

#include <stdio.h>

int main(int argc, char* argv[]) {
   if (glfwInit()) {
      printf("InitGL: got GLFW initialized! :D\n");
      glfwTerminate();
   } else {
      printf("InitGL: unable to initialize GLFW :(\n");
   }

   return 0;
}
