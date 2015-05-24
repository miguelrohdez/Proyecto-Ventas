#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "titulo.h"

	
	struct datosUsuario{
	char usuario[50];
	char password[50];
	};
	
void menu(void);	
void venta(void);
int validacion(void);
int verificarPassword(char passUsuario[], char passGuardada[]);
int verificarUsuario();


int verificarPassword(char passUsuario[], char passGuardada[]){
    int i=0,j=0,k=0;
    i = strlen(passUsuario);
    j = strlen(passGuardada);
    if(i==j){
        for(k=0; k<i; k++){
            if(passUsuario[k] != passGuardada[k]){
                return 0;
            }
        }
        return 1;    
    }
    else{
        return 0;
    }
    
}

int verificarUsuario(){
	struct datosUsuario mUsuario;
	printf("Por favor introduce tu nombre de usuario: ");
	scanf("%s",mUsuario.usuario);
	printf("Introduce tu contrasenia: ");
	scanf("%s",mUsuario.password);

	FILE *mArchivo;
    	char pass[50];
	mArchivo = fopen(mUsuario.usuario,"r");
	if(mArchivo != NULL){
		fscanf(mArchivo,"%s",pass);
        	if(verificarPassword(mUsuario.password,pass)){
            		printf("Autenticacion correcta.\n");
            		fclose(mArchivo);
    
            		venta();
            		return 1;
        	}
        	else{
            		printf("Contrasenia incorrecta\n");
            		return 0;
       		 }
        
	}
	else{
		printf("El usuario no existe\n");
        return 0;
	}//Fin if/else
			
}

int validacion(){
	if(verificarUsuario()){
                   		 return 1;
                	}
return 0;
}

void menu(void){
	printf("\n\n\t\t\t*****Menu*****\n\n\n");
	printf("\t1. Hamburguesa sencilla \t --> \t $28.00  \n");
	printf("\t2. Hamburguesa doble \t\t --> \t $35.00 \n");
	printf("\t3. Refresco normal \t\t --> \t $15.00 \n");
	printf("\t4. Refresco grande \t\t --> \t $19.00 \n");
	printf("\t5. Papas a la francesa normal \t --> \t $16.00  \n");
	printf("\t6. Papas a la francesa grandes \t --> \t $20.00 \n");
	printf("\t7. Combo normal \t\t --> \t $45.00 \n");
	printf("\t8. Combo grande \t\t --> \t $63.00 \n");
	printf("\t9. Total\n");
	printf("\t10. Salir al Menu\n");
	printf("\n\tIngresa el la orden y ENTER tras cada una: \n");
	return;
}

	
void venta(void){

	int venta;
	float orden, pago, cambio;
	
	struct datosUsuario rUsuario;
	printf("\n\tReingrese su numero de usuario: ");
	scanf("%s",rUsuario.usuario);
	
	time_t tiempo = time(0);
    struct tm *tlocal = localtime(&tiempo);
    char output[128];
    strftime(output,128,"%d/%m/%y %H:%M:%S",tlocal);
	
	FILE *mArchivo;
	mArchivo = fopen(rUsuario.usuario,"a");
	if(mArchivo != NULL){
		fprintf(mArchivo,"\n\n\n*****************************************************************************\n");
		fprintf(mArchivo,"******************************%s******************************\n",output);
	menu();
do
{

	if (venta >=0 || venta <=9){

		scanf("%i",&venta);
	}else{
		printf("Opcion invalida!\n\a");
		fflush(stdin);
		scanf("%i",&venta);
	}

	switch(venta){
		case 1: 
			printf("HS $28.00\n");
			fprintf(mArchivo,"HS $28.00\n");
			orden+=28;
			break;
		case 2: 
			printf("HD $35.00\n");
			orden+=35;
			fprintf(mArchivo,"HD $35.00\n");
			break;
		case 3: 
			printf("RN $15.00\n");
			orden+=15;
			fprintf(mArchivo,"RN $15.00\n");
			break;
		case 4: 
			printf("RG $19.00\n");
			orden+=19;
			fprintf(mArchivo,"RG $19.00\n");
			break;
		case 5: 
			printf("PC $16.00\n");
			orden+=16;
			fprintf(mArchivo,"PC $16.00\n");
			break;
		case 6: 
			printf("PG $20.00\n");
			orden+=20;
			fprintf(mArchivo,"PG $20.00\n");
			break;
		case 7: 
			printf("CH $45.00\n");
			orden+=45;
			fprintf(mArchivo,"CH $45.00\n");
			break;
		case 8: 
			printf("CG $63.00\n");
			orden+=63;
			fprintf(mArchivo,"CG $63.00\n");
			break;
		case 9: 
			printf("Total= $ %.2f\n",orden);
			printf("Efectivo recibido: $ ");
			scanf("%f",&pago);
			cambio = pago - orden;
			printf("Cambio $%.2f\n",cambio);
			fprintf(mArchivo,"Total de la orden= $%.2f\n",orden);
			fprintf(mArchivo,"Dinero recibido= $%.2f\n",pago);
			fprintf(mArchivo,"Cambio= $%.2f\n",cambio);
			printf("\n\n\t*****Orden guardada*****\n\n\n\tPresione 10 para salir:  ");
			break;
		case 10: 
			printf("\n\n\t*****Transaccion finalizada correctamente*****\n\n\n");
			fprintf(mArchivo,"Transaccion finalizada");
			return;
			break;
		default:
			printf("¡Opcion Invalida!\a\n");
			break;
		}
}while (venta != 0 || venta != 9);

}else{
	printf("\nUsuario incorrecto");
}
return;
}


int main(){
	char res,rep;
	do{
	titulo();
	float orden=0;
	validacion();
	printf("\n\nDeseas registrar otra venta? Presiona (S/N):  ");
	fflush(stdin);
	scanf("%c",&res);
	}while (res=='s'||res=='S');
	
	printf("Regresar al Menu Principal Presione(S/N): ");
	fflush(stdin);
	scanf("%c",&rep);
	if (rep == 'S' || rep == 's'){
		system("start menu.exe");
		return 0;
	}else{
		printf("\n\n\t***** Programa finalizado *****");
	}
}
