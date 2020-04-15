#include <stdio.h>
#include <stdlib.h>

struct Nodo{
  int num;
  struct nodo *sig;
};

struct Nodo *cabeza = NULL; //Lista ligada vacia
int tam = 0;

void insertarInicio(int numero);
void insertarFinal(int numero);
int insertar(int numero,int pos);
void recorreLista();

int menu(){
  int opc;
  printf("---LISTAS LIGADAS----");
  printf("\n 1)Insertar al inicio \n2)Insertar al final \n3)Insertar \n4)Recorrer lista \n5)Tamanio de la lista");
  printf("\n6)Salir \n\nOPCION_:");
  scanf("%d",&opc);

  return opc;
}

int main(){
  int opcion, numero, pos;

  do{
    opcion = menu();
    switch (opcion){
      case 1:
        printf("\nDame el numero a insertar al inicio de la lista:");
        scanf("%d",&numero);
        insertarInicio(numero);
        break;
      case 2:
        printf("\nDame el numero a insertar al final de la lista:");
        scanf("%d",&numero);
        insertarFinal(numero);
          break;
      case 3:
        printf("\nDame el numero a insertar en la lista:");
        scanf("%d",&numero);
        printf("\nDame la posicion en la que deseas insertarlo:");
        scanf("%d",&pos);
        insertar(numero,pos);
          break;
      case 4:
        recorreLista();
          break;
      case 5:
      printf("\nActualmente hay %d en la lista...",tam);
          break;
    }

  }while(opcion != 6);
  return 1;
}

void insertarInicio(int numero){
  struct Nodo *nodo;   //Se crea el nodo
  nodo = malloc(sizeof(struct Nodo));//se asigna tam de struct
  nodo -> num = numero;   //El apuntador nodo apunta a los datos de su estructura y le asigna datos
  nodo -> sig = NULL;
  if (cabeza == NULL){
    cabeza = nodo; //La lista esta vacia y cabeza ahora apunta al nodo creado
  }else{
    nodo -> sig = cabeza;
    cabeza =nodo;
  }
printf("El dato %d se ha insertado al inicio de la Lista...",numero);
}

void insertarFinal(int numero){
  struct Nodo *nodo;   //Se crea el nodo
  nodo = malloc(sizeof(struct Nodo));//se asigna tam de struct
  nodo -> num = numero;   //El apuntador nodo apunta a los datos de su estructura y le asigna datos
  nodo -> sig = NULL;
  if(cabeza == NULL){
    nodo -> sig = cabeza;
  }else{
    Struct Nodo *aux = cabeza;
    while (aux -> sig != NULL){
      aux = aux -> sig;
  }
  aux -> sig = nodo;
  printf("Dato %d insertado al final de la lista...",nodo -> num);
  tam+=1;
}

void insertar(int numero,int pos){
  struct Nodo *nodo;   //Se crea el nodo
  nodo = malloc(sizeof(struct Nodo));//se asigna tam de struct
  nodo -> num = numero;   //El apuntador nodo apunta a los datos de su estructura y le asigna datos
  nodo -> sig = NULL;
  if ((pos <= 0) || (cabeza == NULL)){
    cabeza = nodo;
  }else{
    if(pos > tam){
      Struct Nodo *aux = cabeza;
      while (aux -> sig != NULL){
        aux = aux -> sig;
    }
    aux -> sig = nodo;
    }else{
      int indice = 1;
      while( indice < pos){
        aux = aux -> sig;
        indice++;
      }
      nodo->sig = aux -> sig;
      aux -> sig = nodo;
    }

  }

  printf("Dato %d se ha asignado en la posicion %d\n",numero,pos);
}

void recorreLista(){
  Struct Nodo *aux = cabeza;
  while (aux != NULL){
    printf("--> %d", aux -> num);
    aux = aux -> sig;
}

}
