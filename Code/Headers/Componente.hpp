/**
@Author: Jorge Cantero Morueco.
@version 1.1.
@fecha:21/06/2022.
**/
#pragma once
namespace engine {
	class Entity;
	/**
	@brief Esta clase sirve para definir la base de los componentes.
	Esta clase es una definicion, aqui solamente decimos a los componentes a que entidad pertenecen.
	Para ello creamos una clase de encabezado, poniendo class entity, de esta forma nos permite crear un puntero que apunta a Entity que en este caso se llama owner.
	**/
	class Componente {
	protected:

	public:
		/**
		@brief destructor virtual por defecto, para despues destruir los componentes.
		
		**/
		virtual  ~Componente() = default;
		/**
		@brief puntero a entity para saber a que entidad pertenece.
		**/
		Entity* owner;
		/**
		@brief constructor de componente donde incializamos el puntero a entity.
		**/
		Componente() {
			this->owner = owner;
		}
		
	};
}