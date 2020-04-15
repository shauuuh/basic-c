#include <stdio.h>
#include <stdlib.h>
#define MAX 5

struct Monedas{
  int valor; //valor de la moneda
  int cont; //numero de veces que se usa una moneda
};

typedef struct Monedas Moneda;
Moneda m[MAX]; //arreglo de 5 monedas

void solucion(int monto);
void imprimir();

int main(){
  int monto = 0;
  printf("\nSus monedas son: \n| ");
  for(int i = 0; i < MAX; i++){
    m[i].cont = 0; //se inicializan los contadores de monedas en 0
    m[i].valor = 5 * (i + 1);   //se asignan valores a las monedas
    printf("  %d  |",m[i].valor);
  }
  printf("\nIngrese el monto a cubrir: ");
  scanf("%d",&monto);
  solucion(monto);
  imprimir();

 return 0;
}

void solucion(int monto){
  int i = 0;
  int cambio = 0; //contador de monedas

  while(cambio != monto){
    i = MAX - 1; //indice en ultima posicion
    while (i >= 0) {
      if((cambio + m[i].valor) <= monto){//obtiene la solucion de monedas
        cambio+= m[i].valor;
        m[i].cont++;
      }else{
           i--;
      }
   }
  }
 }

void imprimir(){//imprime solucion
  for(int i = 0; i < MAX; i++){
      if(m[i].cont != 0){
        printf("\n %d moneda(s) de %d ",m[i].cont, m[i].valor);
      }
  }

}
