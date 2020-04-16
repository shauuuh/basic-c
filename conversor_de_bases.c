#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int algoritmo1(int m,int x,char num[]);
int algoritmo2(int y,int diez);
float algoritmo3(int m,int x,char num[]);
int algoritmo4(int m,int y,float bdiez2);
int numero(char num[],int x,int opc);
int checar1();
int checar2();


int main(){
    int x,y,m,bdiez1,opc,dig,a,b,op;
    float bdiez2;
	do{
        printf("\t====PROGRAMA QUE HACE CONVERSIONES DE B%cSES N%cMERICAS====\n",181,233);
        printf("\nN%cmero fraccionario=1",163);
        printf("\nN%cmero entero=2\n",163);
        printf("Salir=0\n");
        scanf("%d",&opc);
        system("cls");
        if(opc == 0){
            system("exit");
        }
        x=checar1();//ingresar base numerica de num

        char num[100];//cadena p/ numero a convertir

        if(opc == 1){//fraccionario
    	    printf("\nCu%cntos d%cgitos deseas obtener?:",160,161);
   	        scanf("%d",&dig);
    	    printf("\n\n");
   	        printf("\nIngrese el n%cmero a convertir",163);
    	    printf("0.");
    	    numero(num,x,opc);//comprueba que el numero sea valido de acuerdo a su base
    	    m=numero(num,x,opc);

    	    y=checar2();//base numerica a convertir
    	    bdiez2=algoritmo3(m,x,num);//convierte a decimal punto flotante
    	    algoritmo4(dig,y,bdiez2);//convierte a base deseada 
        }
        if(opc==2){//entero
    	    printf("\n\n");
   	        printf("\nIngrese el n%cmero a convertir:",163);
    	    numero(num,x,opc);//comprueba que el numero sea valido de acuerdo a su base
    	    m=numero(num,x,opc);
    	    y=checar2();//base valida a convertir
    	    bdiez1=algoritmo1(m,x,num);//conversion a decimal
    	    algoritmo2(y,bdiez1);//conversion a base deseada

	    }
	    printf("\nPara salir presione 0,");
	    printf("\nPara regresar al menu presione 2,\n");
	    scanf("%d",&op);
    }while(op==2);
    system("pause");
    return 1;
}


int algoritmo1(int m,int x,char num[]){;//algoritmo p/ convertir a base decimal
    int n=0,i;
    for(i=0;i<m;i++){
        n=n*x+num[i];
    }
    return n;
    }

int algoritmo2(int y,int bdiez1){//algoritmo p/ convertir de decimal a otra base(2-16)
    int q,n,p,cont=0;
    int a[100];
    int i=0;
    do{
        q=bdiez1/y;
        p=bdiez1-q*y;
        a[i]=p;
        cont++;
        bdiez1=q;
        i+=1;
    }while(q!=0);
    printf("Conversi%cn:",162);
    for(i=cont-1;i>=0;i--){
        printf("%x",a[i]);
    }
    printf("\n\n");
    return a[cont];
    }


float algoritmo3(int m,int x,char num[]){//algoritmo p/ numero fraccionario en decimal
    float n=0;
    int i;
    for(i=m-1;i>=0;i--){
        n=(n+num[i])/x;
        }
    return n;
    }

int algoritmo4(int dig,int y,float bdiez2){//algoritmo p/ numero fraccionario decimal a otra base
    int i,z;
    int a[50];
    for(i=0;i<dig;i++){
        bdiez2=bdiez2*y;
        z=bdiez2;
        bdiez2=bdiez2-z;
        a[i]=z;
    }
    printf("Conversi%cn:",162);
    for(i=0;i<dig;i++){
        printf("%x",a[i]);
    }
    printf("\n\n");
        return a[dig];
    }

int numero(char num[],int x,int opc){//verifica si el numero es valido de acuerdo a la base ingresada
    int i,m=0,aux,c;

    do{
        aux=0;
        m=0;
        num[0]='\0';
        gets(num);

    	for (i=0;num[i]!='\0' && aux==0;i++){
        	if (isdigit(num[i]))//si los caracteres son numeros los convierte a enteros.
            		c =(num[i])-48;
        	else
            		c =(toupper(num[i]))-'A'+10;//letras mayusculas o minusculas
            		//n = (int)strtol(num[i], NULL, x);
        	if(c>=x || c<0){//digito no exceda la base o sea menor a 0
            		aux=1;
        	}else{
            		num[i]=c;//se agrega digito al arreglo si es valido
           	 	m++;
		}
    }
    if(aux==1){
        printf("\nN%cmero no v%clido para esta base.",163,160,num);
        printf ("\nIntroduce tu n%cmero:",163);
        }
    }while(aux==1);
    //strlen(num);
    if(opc==1){
        printf("\nN%cmero a convertir: ",163);
        for(i=0;i<m;i++){
            printf ("%x",num[i]);
    }

    }
    if(opc==2){
        printf("\nN%cmero a convertir: ",163);
        for(i=0;i<m;i++){
            printf ("%x",num[i]);
        }
        return m;
    }
}

int checar1(){//checa base original del numero
	int x;
	printf("\n\nIngrese la base en la que se encuentra el n%cmero:",163);
    scanf("%d",&x);
	while(x<=1 || x>16){
	    printf("\nBase no v%clida.\n",160);
	    printf("Ingrese una base v%clida:(2(binaria)-16(hexadecimal)):",160);
	    scanf("%d",&x);
	}
	return x;
}

int checar2(){//checa base a convertir 
	int y;
	printf("\nA que base deseas convertir tu n%cmero?:",163);
    scanf("%d",&y);
	while(y<=1 || y>16){
	    printf("\nBase no v%clida.\n",160);
	    printf("Ingrese una base v%clida:(2(binaria)-16(hexadecimal)):",160);
	    scanf("%d",&y);
	}
	return y;
}
