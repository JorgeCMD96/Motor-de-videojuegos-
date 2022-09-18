/**
@Author: Jorge Cantero Morueco.
@version 1.1.
@fecha:21/06/2022.
**/
#pragma once
#include<vector>
#include<map>
#include<string>
#include<Task.hpp>
namespace engine {
using namespace std;
		
/**
@brief esta clase se encarga de recibir todas las tareas que haya, y meterlos en un vector de tareas, para despues llamarlas y poder ejecutarlas.
Hereda de Task ya que es la clase que define tareas.
**/
class Kernel {
		
			
			
		vector<Task*> tasks;

		bool salir;
	public:
		/**
		@brief esta funcion se encarga de agregar tareas.
		@param recibe como parametro la tarea que va a agregar.
		@return despues agregamos al vector de tareas con un pushback la tarea que recibimos.
		**/
		void add_task(Task * task) {
			tasks.push_back(task);
		}
		/**
		@brief esta funcion hace que se ejecute todas las tareas que tengan el metodo run.
		el do while es para que lo ejecute mientras que la ventana este abierta.
		**/
		void execute() {

			salir = false;
			do {

				for (auto task : tasks) task->run(0);
			} while (!salir);



		}


	};
}