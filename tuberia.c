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
int main(){
int fd[2]; //argumento pipe
int mat[3][2], mat2[2][3], mat3[3][3];
char resultado[3], buf[20];
int i,j;
pipe(fd);

for(i = 0; i < 3; i++){
	for(j = 0; j < 2; j++){
		mat[i][j] = rand()%10;
		mat2[j][i] = rand()%10
	}
}

for(i = 0; i < 3; i++){
	for(j = 0; j < 3; j++){
		mat3[i][j] = (mat[i][0] * mat2[0][j]) + (mat[i][1] * mat2[1][j]);
	}
}


pid=process_fork(2);

switch (pid) {
	case -1://Error
					break;
	case 0: //hijo
				for(i = 0; i < 3; i++){
						for(j = 0; j < 3; j++){
							close(fd[0]);
							resultado = (mat3[i][j]) + '0';
							write(fd[1],resultado,sizeof(resultado));
						}
						write(fd[1],"/n",3)
				}
				close(fd[1]);
				exit(0);
				break;
	default://padre
								close(fd[1]);
								read(fd[0],buf,sizeof(buf));
		            close(fd[0]);
						  	exit(0);
					break;
}
}
