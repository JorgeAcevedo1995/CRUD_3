#include "Guardar.cpp"
#include <iostream>

using namespace std;

int main(){
	
	string nombres,apellidos,direccion;
	int cod,tel,num,i;

	cout<<"Ingrese la cantidad de estudiantes a evaluar: ";
	cin>>num;
	
	for(int i=1; i<=num; i++){
	
	cout<<"\nIngrese Codigo:";
	cin>>cod;
	cout<<"Ingrese Nombres:";
	cin>>nombres;
	cout<<"Ingrese Apellidos:";
	cin>>apellidos;
	cout<<"Ingrese Direccion:";
	cin>>direccion;
	cout<<"Ingrese Telefono:";
	cin>>tel;
	
	
	Guardar obj = Guardar(nombres,apellidos,cod,direccion,tel);
	obj.mostrar();
	
	}
}

