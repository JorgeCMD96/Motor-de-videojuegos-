/**
@Author: Jorge Cantero Morueco.
@version 1.1.
@fecha:21/06/2022.
**/
#pragma once
namespace engine
{
    class Scene;
    /**
    @brief esta clase sirve como "base" para las tareas.
    **/
    class Task
    {
    protected:
        /**
        @brief puntero a scene, para saber a que clase pertenece.
        **/
        Scene* scene;    

    public:

        /**
         @brief constructor de la clase Task.
         @param le pasamos la escena, a la cual la tarea ha sido creada.
        **/
        Task(Scene* given_scene)
        {
            scene = given_scene;
        }

        /**
        @brief Virtual run, y tiene que ser implementada en todas las clases que hereden de task.
        **/
        virtual void run(float) = 0;
    };

}
