#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Vector{
  int n1,n2,n3;
} vec1 = {12,3,6},vec2 = {2,8,4}, vec3, *v11,*v22;

int k = 0;

void write(struct Vector *v);
struct Vector *escalar(struct Vector *v);
void suma(struct Vector *v1,struct Vector *v2);
struct Vector *productoCruz(struct Vector *v1,struct Vector *v2);
void productoMixto(struct Vector *v1,struct Vector *v2);
void modulo(struct Vector *v1,struct Vector *v2);
int productoPunto(struct Vector *v1,struct Vector *v2);

int main(){
  /*struct Vector v1 = {12,3,6},*v11,*v22;
  struct Vector v2 = {2,8,4};*/
  int k = 0;

  printf("Vector 1 \n");
  write(&vec1);
  printf("Vector 2: \n ");
  write(&vec2);

  k = productoPunto(&vec1,&vec2);
  printf("\nProducto punto: %d \n\n",k);

  printf("Escalar: \n");
  v11 = escalar(&vec1);
  write(v11);

  v22 = escalar(&vec2);
  write(v22);

  printf("\nProducto Cruz: ");
  v11 = productoCruz(&vec1,&vec2);
  write(v11);

  printf("\nProducto mixto: ");
  productoMixto(&vec1,&vec2);

  modulo(&vec1,&vec2);

  printf("Suma: ");
  suma(&vec1,&vec2);

  return 0;
}

void write(struct Vector *v){
    printf("(%d , %d, %d ) \n", v -> n1, v -> n2, v -> n3);
}

int productoPunto(struct Vector *v1,struct Vector *v2){
  k = (v1 -> n1) * (v2 -> n1) + (v1 -> n2) * (v2 -> n2) + (v2 -> n3) * (v2 -> n3);
  return k;
}

struct Vector *escalar(struct Vector *v){
  int esc = k;
  struct Vector *v3;
  v3 = &vec3;
  //printf("%d",v3 -> n1);
  v3 -> n1 = (v -> n1) * esc;
  v3 -> n2 = (v -> n2) * esc;
  v3 -> n3 = (v -> n3) * esc;

  return v3;
}

void suma(struct Vector *v1,struct Vector *v2){
  struct Vector *v3;
  v3 = &vec3;
  v3 -> n1 = v1 -> n1 + v2 -> n1 ;
  v3 -> n2 = v1 -> n2 + v2 -> n2;
  v3 -> n3 = v1 -> n3 + v2 -> n3;
  write(v3);
}

struct Vector *productoCruz(struct Vector *v1,struct Vector *v2){
  struct Vector *v3;
  v3 = &vec3;
  v3 -> n1 = ((v1 -> n2) * ( v2 -> n3)) - ((v1 -> n3) * (v2 -> n2)) ;
  v3 -> n2 = ((v1 -> n3) * ( v2 -> n1)) - ((v1 -> n1) * (v2 -> n3));
  v3 -> n2 = ((v1 -> n1) * (v2 -> n2)) - ((v1 -> n2) *  (v2 -> n1));

  return v3;
}

void productoMixto(struct Vector *v1,struct Vector *v2){ //producto escalar del primer vector por el producto vectorial de los otros dos
  struct Vector *v5;
  v5 = &vec3;
  v5 -> n1 = (escalar(v1) -> n1) * (productoCruz(v1,v2) -> n1);
  v5 -> n2 = (escalar(v1) -> n2) * (productoCruz(v1,v2) -> n2);
  v5 -> n3 = ((escalar(v1) -> n3) * (productoCruz(v1,v2) -> n3));
  write(v5);
}

void modulo(struct Vector *v1,struct Vector *v2){// |v| = sqrt( pow(v1) + pow(v2) )
  int num;
  num = sqrt(pow(((v1 -> n2) - (v1 -> n1)),2) + pow (((v2 -> n2) - (v1 -> n1)),2));
  printf("\nEl modulo de los vectores es: %d \n\n",num );
}
