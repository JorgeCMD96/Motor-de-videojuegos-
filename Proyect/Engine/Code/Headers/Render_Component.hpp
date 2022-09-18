/**
@Author: Jorge Cantero Morueco.
@version 1.1.
@fecha:21/06/2022.
**/
#pragma once
#include<Componente.hpp>
#include<memory>
#include<Model.hpp>
#include<glm/glm.hpp>
using namespace glt;
namespace engine {
	/**
	@brief Esta clase se va a encargar de definir el modelo de lo componentes, haciendo uso de la clase Model.
	**/
	class Render_Component : public Componente {

	public:
		/**
		@brief creamos un modelo a partir de la clase model de opengl-toolkit.
		**/
		std::shared_ptr<Model> model;






	};
}