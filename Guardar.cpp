#include "Estudiante.cpp"
#include <iostream>
#include <stdio.h>  
#include <string.h> 
#include <stdlib.h>
#include <locale.h>
#define Eliminado -1

using namespace std;

const char *nombre_archivo ="archivos.dat";
const char *temp_archivo ="temporal.dat";


class Guardar : Estudiante {

	// atributos
	public : string curso;
				
	// 
	public : Guardar(string nombres,string apellidos,int codigo,string direccion,int telefono) : Estudiante(nombres,apellidos,codigo,direccion,telefono){}
									
	void setCodigo(int codigo){cod = codigo;}
	void setNombres(string nombres){nom = nombres;}
	void setApellidos(string apellidos){ape = apellidos;}
	void setDireccion(string direccion){direccion = dir;}
	void setTelefono(int telefono){telefono = tel;}
	
	int getCodigo(){return cod;}
	string getNombres(){return nom;}
	string getApellidos(){return ape;}
	string getDireccion(){return dir;}
	int getTelefono(){return tel;}
	
	void mostrar(){
	FILE* archivo = fopen(nombre_archivo,"ab");
	cout<<"\n_______________\n"<<endl;
	cout<<"Codigo:"<<cod<<endl;
	cout<<"Nombres:"<<nom<<endl;
	cout<<"Apellidos:"<<ape<<endl;
	cout<<"Direccion:"<<dir<<endl;
	cout<<"Telefono:"<<tel<<endl;
	fwrite(&cod,sizeof(int),1,archivo);
	fwrite(&nom,sizeof(string),1,archivo);
	fwrite(&ape,sizeof(string),1,archivo);
	fwrite(&dir,sizeof(string),1,archivo);
	fwrite(&tel,sizeof(int),1,archivo);
	fclose(archivo);
	}
	
	void actualizar(){
	FILE* archivo = fopen(nombre_archivo,"r+b");;
	cout<<"\n_______________\n"<<endl;
	cout<<"Codigo:"<<cod<<endl;
	cout<<"Nombres:"<<nom<<endl;
	cout<<"Apellidos:"<<ape<<endl;
	cout<<"Direccion:"<<dir<<endl;
	cout<<"Telefono:"<<tel<<endl;
	fwrite(&cod,sizeof(int),1,archivo);
	fwrite(&nom,sizeof(string),1,archivo);
	fwrite(&ape,sizeof(string),1,archivo);
	fwrite(&dir,sizeof(string),1,archivo);
	fwrite(&tel,sizeof(int),1,archivo);
	fclose(archivo);
	}
	
	void eliminar(){
	FILE* archivo = fopen(nombre_archivo,"r+b");
	FILE* archivo1 = fopen(temp_archivo,"w+b");
	char continuar;
	char elimina;
	int id,codigo;
	char repite = 1;
	char respuesta[50];
	cout<<"Ingrese el ID a eliminar:";
	cin>>id;
	fseek(archivo,id * sizeof(cod),SEEK_SET);
	
	if (archivo == NULL) {
		elimina = 0;
 
	} else {
		elimina = 0;
		fread(&cod,sizeof(int),1,archivo);
		fread(&nom,sizeof(string),1,archivo);
		fread(&ape,sizeof(string),1,archivo);
		fread(&dir,sizeof(string),1,archivo);
		fread(&tel,sizeof(int),1,archivo);
		while (!feof(archivo)) {
			if (codigo == id) {
				fseek(archivo, ftell(archivo) - sizeof(id), SEEK_SET);
				codigo = Eliminado;
					fwrite(&cod,sizeof(int),1,archivo);
					fwrite(&nom,sizeof(string),1,archivo);
					fwrite(&ape,sizeof(string),1,archivo);
					fwrite(&dir,sizeof(string),1,archivo);
					fwrite(&tel,sizeof(int),1,archivo);
				elimina = 1;
				break;
			}
				fread(&cod,sizeof(int),1,archivo);
				fread(&nom,sizeof(string),1,archivo);
				fread(&ape,sizeof(string),1,archivo);
				fread(&dir,sizeof(string),1,archivo);
				fread(&tel,sizeof(int),1,archivo);
		}
	}
	
	do {
	
	if (!(strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0)) {
			repite = 0;
		}
	
	} while (repite);	
	fclose(archivo);
}

void eliminarfisico(){
	
	FILE *archivo;
	FILE *archivo1;
	char elimina = 0;
	int codigo;
 
	archivo = fopen("archivos.dat", "r+b");
	archivo1 = fopen("temporal.dat", "w+b");
 
	if (archivo == NULL || archivo1 == NULL) {
		elimina = 0;
	} else {

		fread(&cod,sizeof(int),1,archivo);
		fread(&nom,sizeof(string),1,archivo);
		fread(&ape,sizeof(string),1,archivo);
		fread(&dir,sizeof(string),1,archivo);
		fread(&tel,sizeof(int),1,archivo);
		while (!feof(archivo)) {
			if (codigo != Eliminado) {
				fwrite(&cod,sizeof(int),1,archivo);
				fwrite(&nom,sizeof(string),1,archivo);
				fwrite(&ape,sizeof(string),1,archivo);
				fwrite(&dir,sizeof(string),1,archivo);
				fwrite(&tel,sizeof(int),1,archivo);
			}
			fread(&cod,sizeof(int),1,archivo);
			fread(&nom,sizeof(string),1,archivo);
			fread(&ape,sizeof(string),1,archivo);
			fread(&dir,sizeof(string),1,archivo);
			fread(&tel,sizeof(int),1,archivo);
		}
		fclose(archivo);
		fclose(archivo1);
 
		remove("archivos.dat");
		rename("temporal.dat", "archivos.dat");
		rename("archivos.dat", "temporal.dat");
 
		elimina = 1;
	}
}
};
