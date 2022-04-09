#include <iostream>
using namespace std;

class Estudiante{
	// atributos
	public : string nom,ape,dir;
				int cod,tel;
				
	// 
	public : Estudiante(string nombres,string apellidos,int codigo, string direccion, int telefono){
					nom = nombres;
					ape = apellidos;
					cod = codigo;
					dir = direccion;
					tel = telefono;
			}

	void mostrar();
	void agregar();
	void modificar();
	void eliminar();
	void eliminarfisico();
	
	
};
