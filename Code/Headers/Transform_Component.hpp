/**
@Author: Jorge Cantero Morueco.
@version 1.1.
@fecha:21/06/2022.
**/
#pragma once
#include<glad\glad.h>
#include<glm\glm.hpp>
#include<Componente.hpp>
namespace engine {
	/**
	@brief esta clase hereda de Componente y sirve para poner los vectores de posicion, rotacion y escala de los componentes.
	**/
	class Transform_Component :public Componente {
	private:



	public:
		/**
		@brief creamos un vector tres para la escala.
		**/
		glm::vec3 scale;
		/**
		@brief creamos un vector tres para la rotacion.
		**/
		glm::vec3 rotation;
		/**
		@brief creamos un vector tres para la posicion.
		**/
		glm::vec3 position;




	};


};