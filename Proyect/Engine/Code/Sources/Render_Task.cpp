/**
@Author: Jorge Cantero Morueco.
@version 1.1.
@fecha:21/06/2022.
**/
#include <Cube.hpp>
#include <Model.hpp>
#include <Model_Obj.hpp>
#include <Light.hpp>
#include <Render_Node.hpp>
#include <Render_Task.hpp>
#include <Window.hpp>
#include<iostream>

#pragma once


using namespace std;
using namespace glt;

namespace engine
{
	/**
	@brief constructor de la clase Render_Task.
	@param _window la ventana que esta activa.
	@param la escena a la que pertenece.
	@param la escena en donde se ha creado la tarea.
	**/
	Render_Task::Render_Task(Window* given_window, Scene* scene) :Task(scene)
	{
		//incializamos el puntero de ventana.
		this->_window = given_window;
		/**
		@brief creamos la camara y la luz con la ayuda de opengl toolkit.
		**/
		std::shared_ptr< glt::Camera > camera(new glt::Camera(20.f, 1.f, 50.f, 1.f));
		std::shared_ptr< glt::Light  > light(new glt::Light);

		renderer.add("camera", camera);
		renderer.add("light", light);

		renderer.get("camera")->translate(glm::vec3(0.f, 0.f, 5.f));
		renderer.get("light")->translate(glm::vec3(10.f, 10.f, 10.f));
	}
	/**
	@brief esta funcion sirve para agregar componentes.
	@param el id del componente.
	@param la ruta del archivo obj.
	**/
	shared_ptr<Componente> Render_Task::agregar(const string id, const string path) {
		//hacemos un auto a model, para que c++ sepa como transformalos y lo igualamos a un puntero de Model_Obj junto con la ruta que le pasaremos.
		auto model = std::make_shared< glt::Model_Obj >(path);
		//hacemos lo mismo pero con componente, pero en este caso a Render_Component y esta vez sin ruta.
		auto component = std::make_shared< Render_Component >();
		//accedemos al atributo model de component y lo igualamos a model.
		component->model = model;
		//renderizamos con un id y un modelo.
		renderer.add(id, model);
		//retornamos el componente.
		return component;



	}
	//llamamos a la funcion run de task.hpp y hacemos que ejecute el render.
	void Render_Task::run(float time) {


		//hacemos un bucle for para los componentes.
		for (auto componente : _componentes) {
			//declaramos un puntero a la entidad y lo igualamos al puntero que declaramos en la clase componente.
			Entity* entity = componente->owner;
			//creamos una matriz unidad.
			glm::mat4 matriz(1);
			//obtenemos la posicion, rotacion y la escala, accediendo a los metodos que tiene la clase entity, a traves del puntero.
			matriz = glm::translate(matriz, entity->getposition());
			matriz = glm::rotate(matriz, entity->getrotation().x, glm::vec3(0, 0, 0));
			matriz = glm::scale(matriz, entity->getscale());
			componente->model->set_transformation(matriz);
		}




		/**
		@brief con esto obtenemos el ancho y alto de la ventana.
		**/
		GLsizei width = GLsizei(_window->get_width());
		GLsizei height = GLsizei(_window->get_height());



		/**
		@brief utilizamos el metodo clear para "limpiar la ventana", renderizamos e intercambios los buffers para que se vea en la ventana.
		**/
		_window->clear();
		renderer.render();
		_window->swap_buffers();

	}




	//declaramos el destructor de render_task para que la clase pueda destruir el render.
	Render_Task::~Render_Task()
	{

	}
	

}