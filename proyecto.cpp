// proyecto.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;
#include"Archivos.h"
#include"conio.h"

int Menu()
{
	int opc;
	cout<<"---------------MENU DE OPCIONES------------------"<<endl;
	cout<<"1-.GENERAR LOS ARCHIVOS"<<endl;
	cout<<"---------------GENERAR REPORTES:-----------------"<<endl;
	cout<<"2-.DELITOS COMETIDOS"<<endl;
	cout<<"3-.DELITOS COMETIDOS CON GRAVEDAD 1"<<endl;
	cout<<"4-.DETENIDOS CON NO MAS DE DOS DELITOS Y GRAVEDAD ENTRE 3 Y 4"<<endl;
	cout<<"5-.ESTADISTICAS"<<endl;
	cout<<"6-.MONTO PAGADO POR CADA CIUDADANO"<<endl;
	cout<<"7-.DELICUENTE MAS DETENIDO"<<endl;
	cout<<"8-.REPORTE DE DELITOS"<<endl;
	cout<<"9-.SALIR"<<endl;
	cin>>opc;
	return opc;
}


int _tmain(int argc, _TCHAR* argv[])
{


	Archivo arch;
	int n;
	n = Menu();

	while(n!=9){

		switch (n)
		{
		case 1: system("cls");
			arch.Generar_Archivos();
			arch.Dar_Memoria();
			arch.Cargar();
			getch();
			break;
		case 2:
			system("cls");
			arch.Delitos_Cometidos();
			getch();
			break;
		case 3:
			system("cls");
			arch.Delitos_cometidos_por_gravedad_1();
			getch();
			break;
		case 4:
			system("cls");
			arch.Insercion();
			arch.DelitosCometido();
			getch();
			break;
		case 5:
			system("cls");

			arch.Estadisticas();
			getch();
			break;
		case 6:
			system("cls");
			arch.Pago();
			getch();
			break;
		case 7:
			system("cls");
			arch.Mayor_delicuente();
			getch();
			break;
		case 8:
			system("cls");
			arch.Insercion2();
			arch.Insercion3();
			arch.Reporte();
			getch();
			break;
		default: cout<<"Opcion incorrecta"<<endl;
		}
		system("cls");
		n = Menu();
	}
	system("pause");
	return 0;
}

