

// librerias 
#include <iostream>
#include <stdlib.h>
#include <string.h>

// ADMINISTRADOR
#define sueldo1 850.00
#define sueldo2 950.00

//DOCENTE POR CONTRATO//
#define sueldoc1 2200.00 //TIEMPO COMPLETO
#define sueldoc2 1100.00 // MEDIO TIEMPO

//DOCENTE POR NOMBRAMIENTO//

//TIEMPO COMPLETO
#define sueldon1a 2200.00 
#define sueldona1 3500.00
#define sueldom1 5100.00

//MEDIO TIEMPO
#define sueldon2a 1100.00 
#define sueldona2 1750.00
#define sueldom2 2550.00

// estructuras 
struct administrativo{
	    int horario;
	};

struct docente{
        int horario, modalidad, nombramiento;
	};
		
struct empleado{

float cedula, telefono, sueldo;
int hFalt,horasfalta,edad;
struct administrativo A;
struct docente B; 
char nombrec[40], direccion[40], correo[25], genero[20],nacionalidad[40];
}dato;

//Funciones propias del programador
void MENU(void);
void DATOS_EMPLEADO(void);
void ADMINISTRATIVO(void);
void DOCENTE(void);
float SUELDO(float a, float b, int c, int d, int e);
void RESULTADOS(void);
void SALIR(void);
void MENUCARGO (void);


main(){
    MENU();
}

void MENU(void)
{
// menu principal	
    int op= 0;
    system("cls");
    do{
    printf("SOLO PUEDE INGRESAR VALORES DEL 1 AL 2 CASO CONTRARIO NO AVANZARA EN EL PROGRAMA\n\n");
    printf("\n\t ** MENU DE OPCIONES **\n");
    printf("\n [1] INGRESO AL FORMULARIO");
	printf("\n [2] SALIR \n");
    scanf("%d",&op);fflush(stdin);
  }while (op!=1 && op!=2);
    system("cls");
    switch(op){
case 1:
    DATOS_EMPLEADO();
    break;
case 2:
    SALIR();
    break;
}
    return;

}

void DATOS_EMPLEADO(void)
{	
// menu ingreso de datos personales 
	do{
	printf("    ** INGRESO DE DATOS PERSONALES **\n\n");
    printf("\n CEDULA: "); 					
    scanf("%f",&dato.cedula); fflush(stdin);
	}while(dato.cedula < 0);
	printf("\n INGRESE NOMBRES Y APELLIDOS: "); 
    gets(dato.nombrec); fflush(stdin);
    printf("\n INGRESE DIRECCION: "); 			
    gets(dato.direccion);   fflush(stdin);
    printf("\n INGRESE NUMERO DE TELEFONO: "); 	
    scanf("%f",&dato.telefono); fflush(stdin);
    printf("\n INGRESE CORREO: "); 	
    gets(dato.correo); fflush(stdin);
    printf("\n DIJITE SU SEXO: ");
  	gets(dato.genero); fflush(stdin);
  	printf("\n DIJITE SU EDAD:");
    scanf("%d",&dato.edad); fflush(stdin);
    printf("\n DIJITE SU NACIONALIDAD:");
    scanf("%s",&dato.nacionalidad);
    
    MENUCARGO();
}
void MENUCARGO (void){
int opcciones=0;
    system("cls");
    printf("\n\n      ** SELECCIONE CARGO **");
    printf("\n [1] PROFESOR");
    printf("\n [2] ADMINISTRATIVO\n");
    scanf("%d",&opcciones); fflush(stdin);
    switch(opcciones){
    
    case 1:
            DOCENTE();
            break;
    case 2:
            ADMINISTRATIVO();
            break;   
			default:
    printf("\n*** DIGITE UN VALOR CORRECTO ***\n");
    printf("APLASTE CUALQUIER TECLA PARA REGRESAR\n");
    system("pause");
    MENUCARGO();     
}
}

void ADMINISTRATIVO(void)
{   
	
	struct administrativo A, *a=NULL;
	a=&A;
	
// cargo en la universidad 
    system("cls");
    printf("\n   ** ADMINISTRACION **\n");
    printf("\n ELIJA SU JORNADA \n");
    printf("\n [1] MATUTINO");
	printf("\n [2] NOCTURNO\n");  
    scanf ("%d",&a->horario); fflush(stdin);
    if (a->horario>=3){
    printf("\n*** DIGITE UN VALOR CORRECTO ***\n");
    printf("APLASTE CUALQUIER TECLA PARA REGRESAR\n");
    system("pause");
    ADMINISTRATIVO();
    
	}
	
    //menu de horas faltas 
    system("cls");
	printf("\n     ** ¿TIENE HORAS FALTA? **");
	printf("\n[1] SI");
	printf("\n[2] NO\n"); 
	scanf("%d",&dato.horasfalta); fflush(stdin);
	if(dato.horasfalta==1){
		
// dijitar horas de falta
    do{
    system("cls");
    printf("\n*** DIGITE HORAS FALTAS ***\n");     
	scanf("%d",&dato.hFalt); fflush(stdin);
    }while(dato.hFalt < 0);
    
// calculos en caso de atraso
    if(a->horario == 1)
    dato.sueldo =SUELDO(sueldo1,sueldo1,30,8,dato.hFalt);
    else if(a->horario == 2)
    dato.sueldo =SUELDO(sueldo2,sueldo2,30,8,dato.hFalt);
    RESULTADOS();
    return;
    
// caso de no tener atrasos 
    }else if (dato.horasfalta==2){
    if(a->horario == 1)
    dato.sueldo =sueldo1;
    else if(a->horario == 2)
    dato.sueldo =sueldo2;
    RESULTADOS();
    return;
	}
}

void DOCENTE(void)
{
	
	struct docente B, *z=NULL;
	z=&B;
	
// menu en caso de ser docente 

    system("cls");
    printf("\n*** PROFESOR ***\n");
    
   // menu de la modalidad de trabajo 
    printf("\n ELIJA MODALIDAD \n");
    printf("\n [1] CONTRATO");
	printf("\n [2] NOMBRAMIENTO\n");      
	scanf("\n %d",&z->modalidad); fflush(stdin);
	if (z->modalidad>=3){
    printf("\n*** DIGITE UN VALOR CORRECTO ***\n");
    printf("APLASTE CUALQUIER TECLA PARA REGRESAR\n");
    system("pause");
    DOCENTE();
	}

do{
	
    // menu de la jornada
    system("cls");
    printf("\n ELIJA JORNADA \n");
    printf("\n [1] TIEMPO COMPLETO");
	printf("\n [2] MEDIO TIEMPO\n");
	scanf("%d",&z->horario); fflush(stdin);
}while(z->horario!=1&& z->horario!=2);
    switch(z->modalidad){
    case 1:
    	
    do{
	
//menu de horas faltas 
    system("cls");
	printf("\n     ** ¿TIENE HORAS FALTA? **");
	printf("\n[1] SI");
	printf("\n[2] NO\n");
	scanf("%d",&dato.horasfalta); fflush(stdin);
	}while(dato.horasfalta!=1&&dato.horasfalta!=2);
	if(dato.horasfalta==1){
    do{
    
// dijitar horas faltas
    system("cls");
    printf("\n DIGITE HORAS FALTAS: ");     
	scanf("%d",&dato.hFalt); fflush(stdin);
    }while(dato.hFalt < 0);
    
// calculos en caso de horas falta 
    if(z->modalidad == 1 && z-> horario== 1)
    dato.sueldo = SUELDO(sueldoc1, sueldoc1, 30, 8, dato.hFalt);
    else if(z->modalidad == 1 && z->horario== 2)
    dato.sueldo = SUELDO(sueldoc2, sueldoc2, 30, 4, dato.hFalt);
            
 // calculos en caso de no tener horas falta  
    }else if (dato.horasfalta==2)
    if(z->modalidad == 1 && z->horario== 1)
    dato.sueldo =sueldoc1;
    else if(z->modalidad == 1 && z->horario== 2)
    dato.sueldo =sueldoc2;
    break;
    case 2:
    if(z->modalidad == 2){
    system("cls");
    printf("\n ELIJA NOMBRAMIENTO ");
    printf("\n [1] AUXILIAR");
	printf("\n [2] AGREGADO");
	printf("\n [3] PRINCIPAL\n");    
	scanf("%d",&z->nombramiento);
  
            //menu de horas faltas 
    system("cls");
	printf("\n     ** ¿TIENE HORAS FALTA? **");
	printf("\n[1] SI");
	printf("\n[2] NO\n");
	scanf("%d",&dato.horasfalta); fflush(stdin);
	if(dato.horasfalta==1){
    do{
    
// dijitar horas faltas
    system("cls");
    printf("\n DIGITE HORAS FALTAS: ");     
	scanf("%d",&dato.hFalt); fflush(stdin);
    }while(dato.hFalt < 0);
            	
// calculo horas falta 
    if(z->nombramiento && z->horario== 1){
    dato.sueldo = SUELDO (sueldon1a, sueldon1a, 30, 8, dato.hFalt);
    }else if(z->nombramiento && z->horario== 2){
    dato.sueldo =  SUELDO(sueldon2a, sueldon2a, 30, 4, dato.hFalt);
    }

    if(z->nombramiento && z->horario== 1){
    dato.sueldo = SUELDO (sueldona1,sueldona1, 30, 8, dato.hFalt);
    }else if(z->nombramiento && z->horario== 2){
    dato.sueldo = SUELDO  (sueldona2, sueldona2, 30, 4, dato.hFalt);
    }

    if(z->nombramiento && z->horario== 1){
    dato.sueldo = SUELDO (sueldom1,sueldom1, 30, 8, dato.hFalt);
    }else if(z->nombramiento && z->horario== 2){
    dato.sueldo =  SUELDO (sueldom2,sueldom2, 30, 4, dato.hFalt);
    }

//calculos en caso de no tener horas de atraso 
    }else if (dato.horasfalta==2){
    if(z->nombramiento && z->horario== 1){
    dato.sueldo =sueldon1a;
    }else if(z->nombramiento && z->horario== 2){
    dato.sueldo =sueldon2a;
    }

    if(z->nombramiento && z->horario== 1){
    dato.sueldo =sueldona1;
    }else if(z->nombramiento && z->horario== 2){
    dato.sueldo =sueldona2;
    }

    if(z->nombramiento &&z-> horario== 1){
    dato.sueldo =sueldom1;
    }else if(z->nombramiento && z->horario== 2){
    dato.sueldo =sueldom2;
    }
	}
	break;
        
    }

    }
    RESULTADOS();
    return;
}
int op=0;
	
void RESULTADOS(void)
{
// salidas
    system("cls");
    printf("\n HORAS FALTAS: %d",dato.hFalt); 
    printf("\n CEDULA: %.0f",dato.cedula);
    printf("\n NOMBRE Y APELLIDO: %s",dato.nombrec);
    printf("\n TELEFONO: %.0f",dato.telefono);
    printf("\n DIRECCION: %s",dato.direccion);
    printf("\n CORREO: %s",dato.correo);
    printf("\n SUELDO: $ %.2f",dato.sueldo);
    printf("\n SU EDAD ES: %d",dato.edad);
    printf("\n SU NACIONALIDAD ES: %s",dato.nacionalidad);
    printf("\n SU GENERO ES: %s\n\n",dato.genero);
    system("\n pause");
    printf("\n");

// menu de reinicio
system("cls");
    printf("** DESEA REINICIAR EL FORMULARIO **\n");
    printf("\n[1] SI\n");
    printf("[2] NO\n");
    scanf("%d",&op);
if(op==1){
        MENU();
}
if (op==2){
        SALIR();
    }
}

float SUELDO(float a, float b, int c, int d, int e)
{
    float sueldo = 0;
    sueldo = a-((b/c)/d)*e;
    return(sueldo);
}

void SALIR(void)
{
// confirmacion de salida
	do{
	system("cls");
    printf("\n*** SALIDA ***");
    printf("\nSEGURA QUE QUIERE SALIR?\n");
    printf("\n[1] SI");
    printf("\n[2] NO\n");
    scanf("%d",&op);
if (op==2){
    	MENU();
	}else if(op==1){
		op=2;
	}
	}while (op!=2);
}
