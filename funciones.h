#include <stdlib.h>
#include <stdio.h>

//funciones get line


char *getString(){
  char *cadena=NULL;
 size_t ntotal=0;
  int nleidos= getline(&cadena, &ntotal, stdin);
  
  if(nleidos<0){printf("error de lectura");
  
  
  }
  else{
    if(cadena[nleidos-1]=='\n'){
      cadena[nleidos-1]='\0'; 
    }
  }
  return cadena;
}

int data_read(){
  char *cadena=getString();
  int aux;
  if(cadena==NULL){
    aux=-1;
  }else{
    aux=strtol(cadena,NULL,10);
  }
  free(cadena);
  return aux;
}





