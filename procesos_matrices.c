#include <stdio.h>
#include <unistd.h>
#include <wait.h>
#include <sys/types.h>
#include <errno.h>
#include <stdlib.h>

int process_fork(int nproc) {
	int i;
	for(i = 0 ; i <= nproc-1 ; i++)
    if(fork()==0)
      return(i);
return(0);
}

int pid;
int buf; FILE *fp;

int main(){
	int fd[2]; //argumento pipe
  int mat[3][2], mat2[2][3], mat3[3][3];
  int i,j;

	pipe(fd);

  for(i = 0; i < 3; i++){
    for(j = 0; j < 2; j++){
      mat[i][j] = rand()%10;
      mat2[j][i] = rand()%10
    }
  }

pid=process_fork(4);

switch (pid) {
  case 0:

      //printf("\n\n##########  escribiendo archivo ##########\n\n");
			close(fd[1]);
      for(i = 0; i < 4; i++){wait(&i);}

      fprintf(stdout,"\n Soy el proceso padre con ID = %d \n",getpid());
      fp = fopen("multiplicacion.txt","r");
      if(fp == NULL){
        printf("Error al abrir el archivo\n");
        exit(1);
      }else{
        printf("La matriz resultado de la multiplicacion es:\n\n");
        for(i = 0; i < 3; i++){
          fscanf(fp,"%d",mat3[0][i]);
          printf("%d",mat3[0][i])
        }
        for(i = 0; i < 3; i++){
          fscanf(fp,"%d",mat3[1][i]);
          printf("%d",mat3[1][i])
        }
        for(i = 0; i < 3; i++){
          fscanf(fp,"%d",mat3[2][i]);
          printf("%d",mat3[2][i])
        }

      exit(1);
      }

      exit(1);
  case 1:
			close(fd[0]);
      fprintf(stdout,"\n Soy el proceso 1 con  ID = %d \n",getpid());
      for(j = 0; j < 3; j++){
        mat3[0][j] = ([0][0] * [0][j]) + ([0][1] * [1][j]);
      }
      if((fp=fopen("multiplicacion.txt","a"))==NULL){
          printf("Error al abrir el archivo/escritura");
          exit(0);
      } else {
          printf("\n\n##########  escribiendo archivo ##########\n\n");
          for(i = 0; i < 3; i++){
              fprintf(fp,"%d ",mat3[0][i]);
          }
        exit(0);
        fclose(fp);
      }
      exit(0);
  case 2:
      fprintf(stdout,"\n Soy el proceso 2 con  ID = %d \n",getpid());
      for(j = 0; j < 3; j++){
        mat3[1][j] = ([1][0] * [0][j]) + ([1][1] * [1][j]);
      }
      if((fp=fopen("multiplicacion.txt","a"))==NULL){
        printf("error al abrir el archivo/escritura");
        exit(0);
      } else {
        printf("\n\n##########  escribiendo archivo ##########\n\n");
        fprint(fp,"\n");
        for(i = 0; i < 3; i++){
          fprintf(fp,"%d ",mat3[1][i]);
        }
        exit(0);
        fclose(fp);
  }

    exit(0);
  case 3:
  fprintf(stdout,"\n Soy el proceso 3 con  ID = %d \n",getpid());
  for(j = 0; j < 3; j++){
    mat3[2][j] = ([2][0] * [0][j]) + ([2][1] * [1][j]);
  }
  if((fp=fopen("multiplicacion.txt","a"))==NULL){
      printf("error al abrir el archivo/escritura");
      exit(0);
  } else {
      printf("\n\n##########  escribiendo archivo ##########\n\n");
      fprintf(fp, "\n");
      for(i = 0; i < 3; i++){
          fprintf(fp,"%d ",mat3[2][i]);
      }
    exit(0);
    fclose(fp);
  }
    exit(0);
}

  return 0;

}
