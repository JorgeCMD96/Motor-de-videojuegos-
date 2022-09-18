/**
@Author: Jorge Cantero Morueco.
@version 1.1.
@fecha:21/06/2022.
**/
#include<Scene.hpp>
#include<Window.hpp>
#include<Kernel.hpp>

#pragma once

using namespace engine;
	//al constructor le pasamos como parametro la ventana.
	Scene::Scene(Window * window) {

		window = window; 
		//inicializamos la tarea del render.
		render_task = new Render_Task(window, this);
		
		//agregamos al kernel la tarea.
		kernel.add_task(render_task);
		
		//cargamos la entidad.
		
		loadentity1();
	};
	
	
	/**
	*@brief este metodo sirve para ejecutar las tareas del kernel.
	
	**/
	void Scene::ejecutar() {
		
		kernel.execute();
		
	}
	/*
	@brief este metodo sirve para cargar entidad1.
	*/
	void Scene:: loadentity1() {
		//creo un transform component para después pasarselo a la entity.
		Transform_Component transform;
		

		//creo una entidad y le paso la escena.
		Entity  entity1(this);
		//añado el componente con la posicion a la entidad.
		entity1.add_component(std::make_shared< Componente >(transform));
		//le pongo la posicion y la escala de la entidad.
		entity1.setposition(glm::vec3(0, 0, 0));
		entity1.setscale(glm::vec3(1.f, 1.f,1.f));
		//añado a la entidad el componente con el objeto y una id.
		entity1.add_component(render_task->agregar("1", "../assets/sphere.obj"));
		
		//añado al vector la entidades.
		entities.push_back(&entity1);
		

		
	}
	/*
	@brief este metodo sirve para cargar entidad2
	*/
	//void Scene::loadentity2() {
	//	//creo un transform component para después pasarselo a la entity
	//	Transform_Component transform;


	//	//creo una entidad y le paso la escena
	//	Entity  entity2(this, transform);
	//	//añado un el componente con la posicion a la entidad 
	//	entity2.add_component(std::make_shared< Componente >(transform));
	//	//le pongo la posicion y la escala de la entidad
	//	entity2.setposition(glm::vec3(0, 0, 0));
	//	entity2.setscale(glm::vec3(1.f, 1.f, 1.f));
	//	//añado a la entidad el componente con el objeto y una id
	//	entity2.add_component(render_task->agregar("2", "../assets/stanford-bunny.obj"));

	//	//añado al vector la entidades
	//	entities.push_back(&entity2);



	//}


	

