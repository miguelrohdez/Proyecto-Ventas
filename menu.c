#include <stdio.h>
#include <stdlib.h>
#include "titulo.h"

void menu(void);
char op;
char res;
int main(){
	do{
	titulo();
	menu();
	printf("\n\n\tEscoger otra opcion,Presione (S/N): ");
	fflush(stdin);
	scanf("%c",&res);
	}while (res=='s' || res =='S');
	return 0;
}

void menu(){	
	printf("\n\n\tBienvenido, selecciona una opciOn y presiona ENTER: \n\n");
	printf("\tR. Registro Empleados\n");
	printf("\tV. Ventass\n");
	printf("\tC. Consultar Datos\n");
	printf("\tS. Salir\n");
	fflush(stdin);
	scanf("%c",&op);


	switch(op){
		case 'R': 
			printf("\t\t***Registro***\n\n");	//Llamada a Registro
			system("start registro.exe");
			break;
		case 'r': 
			printf("\t\t***Registro***\n\n");
			system("start registro.exe");
			break;
		case 'V': 
			printf("\t\t***Ventas***\n\n");		//Llamada a Ventas
			system("start fventa.exe");
			break;
		case 'v': 
			printf("\t\t***Ventas***\n\n");
			system("start fventa.exe");
			break;
		case 'C': 
			printf("\t\t***Consultas***\n\n");		//Llamada a Consultas
			system("start consulta.exe");
			break;
		case 'c': 
			printf("\t\t***Consultas***\n\n");
			system("start consulta.exe");
			break;
		case 'S': 
			printf("\t\t***Programa finalizado con exito***\a");
			break;
		case 's': 
			printf("\t\t***Programa finalizado con exito***\a");
			break;
		default:
			printf("\n\t\tNo es una opcion valida!!\n\a");
			printf("\tPresione una tecla para continuar...\n");
			getchar();
			
			//poner alguna pausa aqui
			break;
		}

	return;   
}
