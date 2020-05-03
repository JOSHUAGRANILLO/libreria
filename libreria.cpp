/*
DATOS QUE DEBE DE LLEVAR LE PROGRAMA DE LIBRERIA
	 Modelo#1 – Q10.00
	 Modelo#2 – Q15.00
	 Modelo#3 – Q18.50
	 Modelo#4 – Q25.00
	 	
		 *ORDEN QUE DEBE DE LLEVAR EL PROGRAMA
		 	 DIA1,MOD,CANT
		 	 
		 	 VARIABLES QUE SE DEBEN DE UTILIZAR EN EL PROGRAMA
		 	 	DIA
		 	 	MOD
		 	 	CANT
		 	 	
		 	 		ACCIONES QUE DEBE DE REALIZAR EL PROGRAMA EN LA EJECUCION
		 	 		
		 	 			Modificar el número de unidades vendidas, solicitando al usuario el día y código de articulo
						(modificación del archivo)
						Eliminación de un día especifico de venta (modificación del archivo)
						Calcular el total recaudado por modelo en los 30 días.
							Calcular cuál fue el modelo que se vendió mas en los 30 días*/
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
using namespace std;

struct libreria{
	int dia,cant,mod,opc;
	string s;
	float precio,total;
	bool encontrado;
	};
	
	void escribir();
	void modificaciones();
	void eliminaciones();
	void lecturaarchivo();
	
int main(){
	int opc, mod, modelo, dia, cant;
	string opcion;
	bool encontrado;
	do{
	
	cout<<"Bienvenido al programa contable de la libreria Dios es amor"<<endl;
	cout<<"************************************************************"<<endl;
	cout<<"Elija una opcion a realizar: "<<endl;
	cout<<"----------------------------"<<endl;
	cout<<"1.	Ingreso de nuevos registros "<<endl;
	cout<<"2.	Busqueda de registros "<<endl;
	cout<<"3.	Modificacion de los registros "<<endl;
	cout<<"4.	Eliminacion de registros"<<endl;
	cout<<"5.	Total de ventas generadas en los ultimos 30 dias"<<endl;
	cout<<"6.	Reporte de modelo con mayor frecuencia de ventas en los ultimos 30 dias"<<endl;
	cout<<"7.	Salir"<<endl;
	cin>>opc;
	ifstream leer;
		
	string buscarRegistro;
	switch(opc){
		case 1:
			{
				ofstream libreria;
	string nombrearchivo;
	fflush(stdin);//accion borra el buffer
	cout<<"Ingrese el nombre del archivo: ";
	getline(cin,nombrearchivo);
		if(libreria.fail()){
			cout<<"No se pudo abrir el archivo";
			exit(1);
		}
		system("CLS");
			int dia,cant;
			string s;
			float precio4=25,precio3=18.50,precio2=15,precio1=10,total;
			//Ingreso de datos
				do{
				cout<<"Ingrese el dia en el que se realizo la venta:\t ";
				cin>>dia;
				cout<<"Elija modelo de la venta realizada:"<<endl;
				cout<<"1 ---> Modelo#1 el costo es de: Q. 10.00"<<endl;
				cout<<"2 ---> Modelo#2 el costo es de: Q. 15.00"<<endl;
				cout<<"3 ---> Modelo#3 el costo es de: Q. 18.50"<<endl;
				cout<<"4 ---> Modelo#4 el costo es de: Q. 25.00"<<endl;
				cin>>mod;
					if(mod==1){
						precio1=10.00;
						cout<<"El precio del producto es de Q. 10.00"<<endl;
					}if(mod==2){
						//precio=15.00;
						cout<<"El precio del producto es de Q. 15.00"<<endl;
					}if(mod==3){
						//precio=18.50;
						cout<<"El precio del producto es de Q. 18.50"<<endl;
					}if(mod==4){
						//precio=25.00;
						cout<<"El precio del producto es de Q. 25.00"<<endl;
							}
					
					
				cout<<"Cuantas unidades desea llevar del producto deseado?:"<<endl;
				cin>>cant;
					total=precio1*cant;
					total=precio2*cant;
					total=precio3*cant;
					total=precio4*cant;
				
				cout<<"El total del(os) producto(s) es: "<<total<<endl;
				
				cout<<"Desea seguir efectuando compras?: "<<endl;
				cin>>opcion;
					}while(opcion==s);
			libreria.open("libreria.txt", ios::app);
			libreria<<dia<<"\t"<<"\t"<<"\t"<<mod<<"\t"<<"\t"<<"\t"<<cant<<endl;
			libreria.close();
			
			break;
			}
		case 2:{
			system("cls");
			leer.open("libreria.txt");
			leer>>mod>>cant>>dia;
			bool encontrado=false;
			cout<<"Ingrese el numero de modelo que desea buscar"<<endl;
			cin>>mod;
			while(!leer.eof())
			{
				leer>>modelo;
				if(modelo==mod)
				{
					encontrado=true;
					cout<<"----------------------------------"<<endl;
					cout<<"Modelo No.             "<<mod<<endl;
					cout<<"Cantidad comprada:     "<<cant<<endl;
					cout<<"Fecha de compra:		  "<<dia<<endl;
					cout<<"----------------------------------"<<endl;
					cout<<endl;
				}
				leer>>mod>>cant>>dia;
				
			}
			if(encontrado==false)
			{
				cout<<"Modelo no encontrado"<<endl;
			}
		leer.close();
		break;
	}
		case 3:{
			modificaciones();
			break;
		}
		case 4:{
			eliminaciones();
			break;
		}	
		}	
		}
	while(opc ==7);
getch();
return 0;
}

void modificaciones(){
		ofstream aux;
		int mod, dia, cant;
		ifstream lectura;
		bool encontrado;
		encontrado=false;
		int auxmod=0, auxcant, auxdia;
		float auxprecio;
		aux.open("auxiliar.txt", ios::out);
		lectura.open("libreria.txt", ios::in);
		if(aux.is_open() && lectura.is_open()){
			cout<<"Ingrese el codigo el dia de la compra que deseas modificar: ";
			cin>>auxmod;
			lectura>>mod;
			while(!lectura.eof()){
				lectura>>dia>>cant;
				if(auxmod==mod){
					encontrado=true;
					cout<<"--------------------------------------"<<endl;
					cout<<"Modelo#:          "<<dia<<endl;
					cout<<"Dia de compra:    "<<mod<<endl; 
					cout<<"Cantidad     :    "<<cant<<endl;
					cout<<"--------------------------------------"<<endl;
					cout<<"Ingrese la nueva cantidad comprada del producto elegido con No. de modelo "<<mod<<": ";
					cin>>auxcant;
					aux<<mod<<" "<<auxcant<<" "<<dia<<endl;
					cout<<"Registro modificado"<<endl;
				} else{
					aux<<mod<<" "<<cant<<" "<<dia<<endl;
				}
				lectura>>mod;
			}
		} else{
			cout<<"No se pudo abrir el archivo o aun no ha sido creado"<<endl;
		}
		if(encontrado==false){
			cout<<"No se encontro ningun registro con los parametros representados"<<endl;
		}
		aux.close();
		lectura.close();
		remove("libreria.txt");
		rename("auxiliar.txt","libreria.txt");

	}
	
	void eliminaciones()
	{
			ofstream aux;
		int mod, dia, cant;
		ifstream lectura;
		bool encontrado;
		encontrado=false;
		int auxmod=0, auxcant, auxdia;
		float auxprecio;
		aux.open("auxiliar.txt", ios::out);
		lectura.open("libreria.txt", ios::in);
		if(aux.is_open() && lectura.is_open()){
			cout<<"Ingrese el codigo el dia de la compra que deseas eliminar: ";
			cin>>auxmod;
			lectura>>mod;
			while(!lectura.eof()){
				lectura>>dia>>cant;
				if(auxmod==mod){
					encontrado=true;
					cout<<"Registro eliminado"<<endl;
				} else{
					aux<<mod<<" "<<cant<<" "<<dia<<endl;
				}
				lectura>>mod;
			}
		} else{
			cout<<"No se pudo abrir el archivo o aun no ha sido creado"<<endl;
		}
		if(encontrado==false){
			cout<<"No se encontro ningun registro con los parametros representados"<<endl;
		}
		aux.close();
		lectura.close();
		remove("libreria.txt");
		rename("auxiliar.txt","libreria.txt");		
	}

	void lecturaarchivo(){
		ifstream lecarch;
		//lec
	}


