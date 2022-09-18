/**
@Author: Jorge Cantero Morueco.
@version 1.1.
@fecha:21/06/2022.
**/
#pragma once
#include<map>
#include<string>
#include<iostream>
#include<Kernel.hpp>
#include"Render_Task.hpp"
#include<Componente.hpp>
#include<Entity.hpp>



namespace engine {
	class Window;
	class Control_Task;
	class Render_Task;

	/**
	@brief esta clase es la de la escena, la cual tiene entidades, y es basicamente donde se van a dibujar los modelos, mediante la llamada al kernel.
	**/
	class Scene {
	
	
		
		/**
		@brief tarea del render.
		**/
		Render_Task* render_task;       
		/**
		@brief kernel.
		**/
		Kernel  kernel;           
		/**
	
		@brief vector de entidades para ir agregando a este, las entidades que se hayan sido creadas y renderizadas.
		**/
		std::vector < Entity*> entities;
		/**
		@brief puntero a Ventana.
		**/
		Window* window;

	public:
		
		/**
		@brief este metodo sirve para ejecutar las tareas.
		**/

		void ejecutar();

		/**
		@brief constructor de la escena.
		@param le pasamos una referencia a la ventana.
		
		**/
		Scene(Window * given_window);
		/**
		@brief metodo para cargar la entidad1.
		**/
		void loadentity1();
		
		/**
		@brief metodo para cargar la entidad2.
		**/
		void loadentity2();

	};
}