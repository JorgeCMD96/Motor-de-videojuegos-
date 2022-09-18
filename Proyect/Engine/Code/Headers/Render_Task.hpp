/**
@Author: Jorge Cantero Morueco.
@version 1.1.
@fecha:21/06/2022.
**/
#pragma once
#include <memory>
#include <string>
#include <internal/declarations.hpp>
#include<Task.hpp>
#include<list>
#include <Render_Node.hpp>
#include<Render_Component.hpp>
#include<Entity.hpp>
using namespace std;
namespace engine
{

	class Componente;
	class Window;
	/**
	@brief es la clase que se encarga de renderizar, es una tarea asi que hereda de Task.
	**/
	class Render_Task :public Task
	{

		/**
		@brief se crea un objeto de la clase de Render_Node de opengl-toolkit y lo llamamos renderer, esto hara que nos deje renderizar los componentes o elementos que le pasemos.
		en el metodo render.
		**/

		glt::Render_Node renderer;

		Window* _window;
		
	
		/**
		@brief lista de componentes.
		**/

		std::list<std::shared_ptr <Render_Component>>  _componentes;

	public:

		/**
		@brief destructor de render_task.
		**/
		~Render_Task();
		/**
		@brief al constructor le pasamos como parametro la ventana.
		@param given_window la ventana que esta activa en este momento.
		@param scene la escena que esta activa.
		**/
		Render_Task(Window* given_window, Scene* scene);

		
		/**
		@brief esta funcion para agregar componentes, y despues renderizarlos.
		@param el id del componente.
		@param la ruta del archivo obj.
		**/
		shared_ptr<Componente> agregar(const string id, const string path);
		/**
		@brief esta funcion es la herencia del run de task.
		@param se le pasa un tiempo.
		**/
		void run(float time)override;
		/**
		@brief funcion para renderizar.
		**/
	
		

	};

}
