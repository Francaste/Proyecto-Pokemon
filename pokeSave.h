  #include <pthread.h>
  #include <unistd.h>
  #include <stdlib.h>
  #include <stdio.h>
  #include <string.h>

 

  void pokeSave(pokemon* pokebeza){
    
        FILE* fichero;//variable fichero
	fichero=fopen("##autosave.dat", "w+");//abre o crea fichero lista y escribe
	if(fichero!=NULL) {//si hay algo en el fichero escribe
	pokemon* pokactual=pokebeza;//tenemos el pokemon actual
			
	while(pokactual!=NULL) {
	
	 escribe_pokemon(fichero, pokactual);
	
	 
		 
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
  void* saveActivo(void* pokebeza){
    
    while(1){
      
      pokeSave(pokebeza);
      sleep(1);
	}
	return NULL;
    
  }

     
