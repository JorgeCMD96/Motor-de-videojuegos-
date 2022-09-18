
// Code released into the public domain
// in January 2019
// by Ángel

#include <Window.hpp>
#include <Scene.hpp>

using namespace engine;

int main()
{
    // Se crea una ventana:

    Window window("TEST", 1280, 720/*, true*/);

    window.enable_vsync();

   

    
    Scene scene (&window);

 

   

   

    scene.ejecutar();
    

    return 0;
}
