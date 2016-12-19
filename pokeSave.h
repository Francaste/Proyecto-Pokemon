  #include <pthread.h>
  #include <unistd.h>
  #include <stdlib.h>
  #include <stdio.h>
  #include <string.h>

 
  

  void pokeSave(pokemon* pokebeza){
    if(pokebeza==NULL){
	printf("Lista vacia\n");
	return;
        }else{
        FILE* fichero;//variable fichero
	fichero=fopen("##autosave.dat", "a+");//abre o crea fichero lista y escribe
	if(fichero!=NULL) {//si hay algo en el fichero escribe
	pokemon* pokactual=pokebeza;//tenemos el pokemon actual
			
	while(pokactual!=NULL) {
	
	 escribe_pokemon(fichero, pokactual);
	
	 printf("Escribiendo Pokemon:%s \n",pokactual->s_name);
		 
	 pokactual=pokactual->next;
	}
	
	fclose(fichero);//cerramos fichero
	
	fichero=NULL;
	 return;
	}else {//si es NULL el fichero ha habido un error
	printf("Error de lecutura\n");
	return;
	}
	
      }
     
  }
  void* saveActivo(void* pokebeza){
    while(1){
      
      pokeSave(pokebeza);
      sleep(10);
      
    }
    pthread_exit(0);
    
  }
