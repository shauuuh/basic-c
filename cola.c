#include <stdio.h>

int menu();

int colaNum[10];
int indice=0;

int estaLlena();
void insercion();
void elimina();
void muestra();

int main()
   {
    char opc; 


    opc=menu();
    while(opc!=4)
     {
      switch(opc)
        {
         case 1: 
                 insercion();
                 printf("%d\n",indice);
                 break;
         case 2: elimina();
                 printf("%d\n",indice);
                 break;
         case 3: muestra();
                 break;
         default: printf("Error...\n");
                  break;
        }
      opc=menu();
     }
    return 1;
   }

int menu()
   {
    int num;

    printf("COLA DE ENTEROS\n");
    printf("[1] Insertar un dato en la cola\n");
    printf("[2] Borrar un dato de la cola\n");
    printf("[3] Mostrar el primer dato de la cola\n");
    printf("[4] Salir\n");
    printf("OPCION:_");
    scanf("%d",&num);
    return num;
   }


int estaLlena()
   {
    if(indice==10)
      return 1;
    else return 0;
   }


void insercion()
   {
    int numero;
    if (estaLlena())
       printf("COLA LLENA...\n Imposible encolar el dato...\n");
    else {
          printf("Dame el dato a encolar: ");
          scanf("%d",&numero);
          colaNum[indice]=numero;
          printf("Dato encolado...\n");
          indice++;
         }
   }

void elimina()
   {
    int valor,i;
    if (indice==0)
       printf("COLA VACIA...\n Imposible DESENCOLAR dato...\n");
    else {
          valor=colaNum[0];
          printf("El valor %d se ha eliminado de la cola...\n", valor);
          indice--;
          for(i=1;i<=indice;i++)
              colaNum[i-1]=colaNum[i];
         }
   }

void muestra()
   {
    if (indice==0)
       printf("COLA VACIA...\n Nada que mostrar...\n");
    else 
       printf("El proximo elemento a salir de la cola es el numero %d ...\n", colaNum[0]); 
   }

