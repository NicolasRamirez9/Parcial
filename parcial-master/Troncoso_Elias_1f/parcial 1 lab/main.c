#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define A 3
#define VACIO -1
#define LLENO 1
typedef struct
{
    int dia;
    int mes;
    int anio;
} sFecha;

typedef struct
{
    int codigoDeJuego;
    char descripcion[52];
    float importe;
    int isEmpty;
} sJuegos;

typedef struct
{
    int codigoDeCliente;
    char apellido[52];
    char nombre[52];
    char domicilio[52];
    char telefono[22];
    int isEmpty;
} sClientes;

typedef struct
{
    int codigoDeAlquiler;
    int codigoDeJuego;
    int codigoDeCliente;
    sFecha miFecha;
} sAlquileres;


int main()
{
    sJuegos arrayJuegos[A];
    sClientes arrayClientes[A];


    inicializarArrayJuegos(arrayJuegos,A);
    inicializarArrayClientes(arrayClientes,A);
    funcionMenu(arrayJuegos,arrayClientes);


    return 0;
}
void funcionMenu(sJuegos arrayJuegos[],sClientes arrayClientes[])
{

    int opcion;
    char seguir;
    int indice;
    int indice1;
    int flag=0;
    int flag1=0;


    do
    {

        printf(":::::::::::::::::::::::::::::::::::::::\n");
        printf(":            MENU DE JUEGOS           :\n");
        printf(":       1) ALTAS    2)MODIFICAR       :\n");
        printf(":       3) BAJA     4)INFORMAR        :\n");
        printf(":            MENU DE CLIENTES         :\n");
        printf(":       5) ALTAS    6)MODIFICAR       :\n");
        printf(":       7) BAJA     8)INFORMAR        :\n");
        printf(":::::::::::::::::::::::::::::::::::::::\n");

        printf("elija una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            flag=1;
            indice=buscarEspacioEnElArray(arrayJuegos,A);
            if( indice!=VACIO)
            {
                altaJuego(arrayJuegos,A,indice);
            }
            else
            {
                printf("no hay espacio en el array\n");
            }
            break;

        case 2:
            if(flag==0)
            {
                printf("debe cargar al juego primero");
            }
            else
            {

                modificacionJuegos(arrayJuegos,A);

            }
            break;

        case 3 :
            if(flag==0)
            {

                printf("debe cargar el juego primero");

            }
            else
            {
                bajaJuego(arrayJuegos,A);
            }
            break;

        case 4:
            if(flag==0)
            {

                printf("debe cargar al juego primero");

            }
            else
            {
                funcionListar(arrayJuegos,A);


            }


            break;

        case 5:

            flag1=1;

            indice1=buscarEspacioEnElArrayCliente(arrayClientes,A);

            if( indice1!=VACIO)
            {
                altaCliente(arrayClientes,A,indice1);
            }
            else
            {
                printf("no hay espacio en el array\n");
            }
            break;

        case 6:
            if(flag1==0)
            {
                printf("debe cargar al cliente primero");
            }
            else
            {

             modificacionClientes(arrayClientes,A);

            }
            break;

        case 7 :
            if(flag1==0)
            {

                printf("debe cargar el juego primero");

            }
            else
            {
            bajaCliente(arrayClientes,A);
            }
            break;

        case 8:
            if(flag1==0)
            {

                printf("debe cargar al juego primero");

            }
            else
            {



            }


            break;
        }
        printf("\nQuiere volver al menu?\ns/Para continuar n/Para salir\n");
        seguir=getch();
        system("cls");
    }
    while(seguir =='s');

}
int funcionIdJuego(sJuegos arrayJuegos[],int cant)
{
    int i ;
    for( i=0; i<cant; i++)
    {
        if(arrayJuegos[i].isEmpty==VACIO)
        {
            arrayJuegos[i].codigoDeJuego=i+1;
            break;
        }

    }
    return i;
}

void inicializarArrayJuegos(sJuegos arrayJuegos[], int cant)
{
    int i;
    for(i=0; i<cant; i++)
    {
        arrayJuegos[i].isEmpty=VACIO;
    }

}
int buscarEspacioEnElArray(sJuegos arrayJuegos[], int cant)
{
    int aux=VACIO;
    int i;

    for(i=0; i<cant; i++)
    {
        if(arrayJuegos[i].isEmpty==VACIO)
        {
            aux=i;
            break;
        }
    }

    return aux;
}
void altaJuego(sJuegos arrayJuegos[],int cant,int i)
{

    int j;

    printf("el codigo de juego es:%d",funcionIdJuego( arrayJuegos,A));

    printf("\ningrese descripcion: ");
    fflush(stdin);
    gets(arrayJuegos[i].descripcion);

    while(strlen (  arrayJuegos[i].descripcion)>51)
    {
        printf("reingrese legajo: ");
        scanf("%s", & arrayJuegos[i].descripcion);

    }



    printf("ingrese importe: ");
    scanf("%f", & arrayJuegos[i].importe);

    while(arrayJuegos[i].importe <0)
    {
        printf("reingrese importe: ");
        scanf("%f", & arrayJuegos[i].importe);
    }

    arrayJuegos[i].isEmpty=LLENO;


}
void modificacionJuegos(sJuegos arrayJuegos[],int cant)
{

    int aceptar2;
    int i;
    int auxId;
    int flag=0;
    char modificacion;
    int j;

    printf("\ningrese codigo de juego para modificar : ");
    scanf("%d",&auxId);

    for(i=0; i<cant; i++)
    {
        if(arrayJuegos[i].isEmpty!=VACIO && auxId==arrayJuegos[i].codigoDeJuego)
        {
            do
            {

                system("cls");
                printf("-----------------\n");
                printf("-5) DESCRIPCION -\n");
                printf("-6) IMPORTE     -\n");
                printf("-----------------\n");

                printf("ingrese el campo a modificar: ");
                scanf("%d",&aceptar2);
                system("cls");
                switch(aceptar2)
                {
                case 5:
                    printf("ingrese una nueva descripcion: ");
                    fflush(stdin);
                    gets(arrayJuegos[i].descripcion);

                    while(strlen(arrayJuegos[i].descripcion)>51)
                    {
                        printf("reingrese nueva descripcion: ");
                        scanf("%s", & arrayJuegos[i].descripcion);

                    }



                case 6:
                    printf("\ningrese nuevo importe: ");
                    scanf("%f", & arrayJuegos[i].importe);
                    while(arrayJuegos[i].importe <0)
                    {
                        printf("reingrese nuevo importe: ");
                        scanf("%f", & arrayJuegos[i].importe);

                    }
                    break;



                }
                printf("\nquiere modificar otro campo?\ns/para continuar n/para salir\n");
                modificacion=getch();
                system("cls");
            }
            while(modificacion=='s');


            flag=LLENO;
            break;
        }
    }
    if(flag==0)
    {
        printf("\nNo existe el codigo de juego vuelva a ingresarlo\n");
    }
}
void bajaJuego(sJuegos arrarJuegos[],int cant)
{

    int i;
    int flag=0;
    int aceptar1;
    int auxId2;
    printf("\nIngrese codigo de juego para dar de baja: ");
    scanf("%d", & auxId2);

    for( i=0; i<cant; i++)
    {
        if(arrarJuegos[i].isEmpty!=VACIO && auxId2==arrarJuegos[i].codigoDeJuego)
        {
            flag=1;
            printf("\ndesea dar de baja a este juego?\n s/para continuar n/para salir\n");
            aceptar1=getch();
            if(aceptar1 =='s')
            {
                printf("\nse ha dado de baja a este juego.\n");
                arrarJuegos[i].isEmpty=VACIO;
                break;
            }
            else if (aceptar1!='s')
            {
                printf("\nprecione s para volver al menu\n");
            }

        }

    }

    if(flag==0)
    {
        printf("\nNo existe el codigo de juego, vuelva a ingresarlo\n");
    }
}
void funcionListar( sJuegos arrayJuegos[], int cant)
{
    int i;
    int j;
    int a;
    sJuegos aux;
    sJuegos aux2;
    printf("  ordenado alfabeticamente por importe:\n");
    for(i=0; i< cant-1; i++)
    {
        for(j=i+1; j<cant; j++)
        {
            if(arrayJuegos[i].importe>arrayJuegos[j].importe)
            {
                aux2=arrayJuegos[i];
                arrayJuegos[i]=arrayJuegos[j];
                arrayJuegos[j]=aux2;

            }
        }
    }
    for (i=0; i<cant; i++)
    {
        if(arrayJuegos[i].isEmpty==LLENO)
        {
            printf("  importe:%.2f \n",arrayJuegos[i].importe);
        }

    }
    printf("  ordenado alfabeticamente por descripcion:\n");
    for(i=0; i< cant-1; i++)
    {
        for(j=i+1; j<cant; j++)
        {
            if(stricmp(arrayJuegos[i].descripcion,arrayJuegos[j].descripcion)>0)
            {
                aux=arrayJuegos[i];
                arrayJuegos[i]=arrayJuegos[j];
                arrayJuegos[j]=aux;

            }
        }
    }
    for (i=0; i<cant; i++)
    {
        if(arrayJuegos[i].isEmpty==LLENO)
        {
            printf("  descripcion:%s \n",arrayJuegos[i].descripcion);
        }

    }
}
int funcionIdclientes(sClientes arrayClientes[],int cant)
{
    int i ;
    for( i=0; i<cant; i++)
    {
        if(arrayClientes[i].isEmpty==VACIO)
        {
            arrayClientes[i].codigoDeCliente=i+1;
            break;
        }

    }
    return i;
}

void inicializarArrayClientes(sClientes arrayClientes[], int cant)
{
    int i;
    for(i=0; i<cant; i++)
    {
        arrayClientes[i].isEmpty=VACIO;
    }

}
int buscarEspacioEnElArrayCliente(sClientes arrayClientes[], int cant)
{
    int aux=VACIO;
    int i;

    for(i=0; i<cant; i++)
    {
        if(arrayClientes[i].isEmpty==VACIO)
        {
            aux=i;
            break;
        }
    }

    return aux;
}
void altaCliente(sClientes arrayClientes[],int cant,int i)
{


    printf("el codigo de cliente es:%d",funcionIdclientes( arrayClientes,A));


    printf("\ningrese nombre: ");
    fflush(stdin);
    gets(arrayClientes[i].nombre);

    while(strlen(arrayClientes[i].nombre)>51)
    {
        printf("reingrese nombre: ");
        scanf("%s", & arrayClientes[i].nombre);

    }


    printf("\ningrese apellido: ");
    fflush(stdin);
    gets(arrayClientes[i].apellido);

    while(strlen(arrayClientes[i].apellido)>51)
    {
        printf("reingrese apellido: ");
        scanf("%s", & arrayClientes[i].apellido);

    }


    printf("\ningrese domicilio: ");
    fflush(stdin);
    gets(arrayClientes[i].domicilio);

    while(strlen(arrayClientes[i].domicilio)>51)
    {
        printf("reingrese domicilio: ");
        scanf("%s", & arrayClientes[i].domicilio);

    }


    printf("\ningrese telefono: ");
    gets(arrayClientes[i].telefono);


    while(strlen(arrayClientes[i].telefono)>21)
    {
        printf("reingrese telefono: ");
        gets(arrayClientes[i].telefono);

    }





    arrayClientes[i].isEmpty=1;


}







void modificacionClientes(sClientes arrayClientes[],int cant)
{

    int aceptar2;
    int i;
    int auxId2;
    int flag2 =0;
    char modificacion;


    printf("\ningrese codigo de cliente para modificar : ");
    scanf("%d",&auxId2);

    for(i=0; i<cant; i++)
    {
        if(arrayClientes[i].isEmpty!=VACIO && auxId2==arrayClientes[i].codigoDeCliente)
        {
            do
            {
                system("cls");
                printf("-----------------\n");
                printf("-9) APELLIDO    -\n");
                printf("-10) NOMBRE     -\n");
                printf("-11) DOMICILIO  -\n");
                printf("-12) TELEFONO   -\n");
                printf("-----------------\n");

                printf("ingrese el campo a modificar: ");
                scanf("%d",&aceptar2);
                system("cls");
                switch(aceptar2)
                {
                case 9:
                    printf("\ningrese nuevo apellido: ");
                    fflush(stdin);
                    gets(arrayClientes[i].apellido);

                    while(strlen(arrayClientes[i].apellido)>51)
                    {
                        printf("reingrese nuevo apellido: ");
                        scanf("%s", & arrayClientes[i].apellido);

                    }


                    break;


                case 10:
                    printf("\ningrese nuevo nombre: ");
                    fflush(stdin);
                    gets(arrayClientes[i].nombre);

                    while(strlen(arrayClientes[i].nombre)>51)
                    {
                        printf("reingrese nuevo nombre: ");
                        scanf("%s", & arrayClientes[i].nombre);

                    }
                    break;

                case 11:
                    printf("\ningrese nuevo domicilio: ");
                    fflush(stdin);
                    gets(arrayClientes[i].domicilio);

                    while(strlen(arrayClientes[i].domicilio)>51)
                    {
                        printf("reingrese nuevo domicilio: ");
                        scanf("%s", & arrayClientes[i].domicilio);

                    }
                    break;

                case 12:

                    printf("\ningrese nuevo telefono: ");
                    gets(arrayClientes[i].telefono);


                        while(strlen(arrayClientes[i].telefono)>21)
                        {
                            printf("reingrese nuevo telefono: ");
                            gets(arrayClientes[i].telefono);

                        }




                }
                printf("\nquiere modificar otro campo?\ns/para continuar n/para salir\n");
                modificacion=getch();
                system("cls");
            }while(modificacion=='s');


            flag2=LLENO;
            break;
        }
    }
    if(flag2==0)
    {
        printf("\nNo existe el codigo de cliente, vuelva a ingresarlo\n");
    }
}
void bajaCliente(sClientes arrayClientes[],int cant)
{

    int i;
    int flag=0;
    int aceptar1;
    int auxId2;
    printf("\nIngrese codigo de cliente para dar de baja: ");
    scanf("%d", & auxId2);

    for( i=0; i<cant; i++)
    {
        if(arrayClientes[i].isEmpty!=VACIO && auxId2==arrayClientes[i].codigoDeCliente)
        {
            flag=1;
            printf("\ndesea dar de baja a este cliente?\n s/para continuar n/para salir\n");
            aceptar1=getch();
            if(aceptar1 =='s')
            {
                printf("\nse ha dado de baja a este cliente.\n");
                arrayClientes[i].isEmpty=VACIO;
                break;
            }
            else if (aceptar1!='s')
            {
                printf("\nprecione s para volver al menu\n");
            }

        }

    }

    if(flag==0)
    {
        printf("\nNo existe el codigo de juego, vuelva a ingresarlo\n");
    }
}










