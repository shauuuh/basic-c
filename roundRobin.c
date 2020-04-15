
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

struct Lista{
  char nombre;
  int tmp; //tiempo de llegada
  int rafaga; //quantum
  int tmpFinal; //tiempo Final
};
typedef struct Lista Proceso;


int nProcess = 0;
Proceso p[MAX];
Proceso a[MAX];
int fin = 0, intervalos = 0;
double tmpProm = 0.0;//tiempo promedio

void crearLista();
int quantUM();
void RoundRobin();
void impresion();

int main(){
  printf("*******ALGORITMO ROUND ROBIN********\n");
  crearLista();
  printf("\nEl quantum es: %d ",quantUM());
  RoundRobin();
  impresion();

  return 0;
}

void crearLista(){

  char nom = 97;
  printf("\nIngrese el numero de procesos (Maximo 10): ");
  scanf("%d",&nProcess);
  printf("\n\n");
  for(int i = 0; i < nProcess; i++){
      printf("\nPROCESO [%c]\nTiempo de llegada: ",nom);
      scanf("%d",&a[i].tmp);
      printf("\nRafaga: ");
      scanf("%d",&a[i].rafaga);
      a[i].nombre = nom;
      nom++;
  }
}

int quantUM(){
  int rest = 0,j;
  for(j = 0; j < nProcess; j++){
    rest+= a[j].tmp;
  }
  rest /= nProcess;
  return rest;
}

void Ordenar(){
  int k,j;
  Proceso temp;
  for(int i = 0; i < nProcess ; i++){
    p[i] = a[i];
  }

  for(j = 0; j < nProcess; j++){
    for(k = 0; k < nProcess; k++){
      if(p[j].tmp < p[k].tmp){
            temp = p[j];
            p[j] = p[k];
            p[k] = temp;
      }
    }
  }
}

void RoundRobin(){
  Ordenar();
  int aux = 0, auxtmp = 0;
  while(fin == 0){
    fin  = 1;
    for(int i = 0; i < nProcess; i++){
      if(p[i].rafaga > 0){
        p[i].rafaga-= quantUM();
        intervalos++;
        printf("\n Intervalo[%d] proceso %c",intervalos, p[i].nombre);
        if(p[i].rafaga > 0){
          auxtmp+= quantUM();
          fin = 0;
        }else{
            auxtmp += quantUM() + p[i].rafaga;
            tmpProm+= intervalos * quantUM();
            p[i].tmpFinal = auxtmp;
            aux++;
        }
      }
    }
  }
  tmpProm = tmpProm /nProcess;
}

void impresion(){
  for(int i = 0; i < nProcess; i++){
    for(int j = 0; j < nProcess; j++){
        if(p[i].nombre == a[j].nombre){
            a[j].tmpFinal = p[i].tmpFinal;
        }
    }

  }
  printf("\n\n");
  for(int k = 0; k < nProcess; k++){
    printf("\nTiempo de proceso[%c] : %d mls",a[k].nombre,a[k].tmpFinal);
  }
  printf("\n\n\tTiempo promedio: %f\n\n ", tmpProm);
}
