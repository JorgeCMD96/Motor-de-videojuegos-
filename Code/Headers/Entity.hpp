/**
@Author: Jorge Cantero Morueco.
@version 1.1.
@fecha:21/06/2022.
**/
#pragma once
#include<map>
#include<string>
#include<iostream>
#include<glm/glm.hpp>
#include<Transform_Component.hpp>
#include<Componente.hpp>
#include<vector>

using namespace std;
using namespace glm;

namespace engine {
	
	class Scene;
	/**
	@brief esta clase sirve para crear entidades, para posteriormente anadirlas a la escena,
	para ello le pasamos una escena al constructor.
	**/
	class Entity {
	private:

		/**
		@brief lista de componentes.
		
		**/
		std::list<std::shared_ptr< Componente > > componentes;    
		/*
		@brief posicion,rotacion y escala del componente.
		*/
		Transform_Component  Transform;
	public:
		Scene* scene;
		/**
		@brief constructor de entity, le pasamos a que escena pertenece.
		**/
		Entity(Scene* _owner) {
			this->scene = _owner;
			

		
		}
		/**
		@brief add_component este metodo sirve para anadir componentes a las entidades.
		@param component es un shared_ptr a la clase Componente, en el que le pasamos los componentes que va a tener esa entidad. 
		@return  metemos en la lista components, el componente que hemos creado.
		**/
		void add_component(shared_ptr< Componente >component) {

			componentes.push_back(component);


		}
		/**
		@brief _transform este metodo sirve para obtener el trasnform de transform_componente y, poder acceder a los vectores posicion, escala y rotacion de Transform_Component.
		@return nos devuelve la variable Transform.
		**/
		Transform_Component& _transform() {
			return Transform;

		}
		/**
		@brief este metodo sirve para obtener el vector posicion, de Transform_Component y, nos permite acceder a el.
		@return retornamos la posicion, haciendo un Tranform.position.
		
		**/
		glm::vec3& getposition() {
			return Transform.position;


		
		}
		/**
		@brief este metodo sirve para igualar el vector de position de Transform_Component, a la variable que recibe como parametro y nos permite acceder a el.
		@param recibe una variable de vec3 llamado position.
		
		**/
		void setposition(glm::vec3 position) {
			Transform.position = position;

		}
		/**
		@brief este metodo sirve para obtener el vector rotacion, de Transform_Component y, nos permite acceder a el.
		@return retornamos la rotacion, haciendo un Tranform.rotation.
		**/
		glm::vec3& getrotation() {

			return Transform.rotation;

		}
		/**
		@brief este metodo sirve para igualar el vector de rotation de Transform_Component, a la variable que recibe como parametro y nos permite acceder a el.
		@param recibe una variable vec3 rotation.
		**/
		void setrotation(glm::vec3 rotation) {

			Transform.rotation = rotation;
		}
		/**
		@brief este metodo sirve para obtener el vector scale, de Transform_Component y, nos permite acceder a el.
		@return retornamos la escala, haciendo un Tranform.scale.
		**/
		
		glm::vec3& getscale() {

			return Transform.scale;
		}
		/**
		@brief este metodo sirve para igualar la escala por nuestro vector scale, que tiene Transform_component.
		@param recibe un variable vec3 scale.
		**/
		void setscale(glm::vec3 scale) {
			Transform.scale = scale;

		}




	};


}









































