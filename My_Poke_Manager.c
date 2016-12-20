    /*****Irene Castell Miñón(100346306)___Rafael Gómez Prudencio(100346462)___
    *Adrián Prieto de Dios(100346299)___Francisco Javier Castellano Farrak(100346323)>*****/
    
    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    #include <pthread.h>  
    
    
    #include "funciones.h"
    #include "pokestructura.h"
    #include "pokeModificarLista.h"
    #include "pokeOpsFicheros.h"
    #include "pokEmbate.h"
    #include "pokeMostrar.h"
    #include "pokeRevivir.h"
    #include "pokeFuncionAyuda.h"
    #include "pokeContador.h"
    #include "pokeSave.h"
    //#include "pokeVolverMenu.h"
    #define NUMTHREADS 3
    
    
    //prototipos de funciones
    int combatePokemon(pokemon* pokebeza);
    void mostrar_pokemon_basico(pokemon* pokebeza);
    void mostrar_pokemon_ID(pokemon* pokebeza);
    pokemon* borrar_pokemon(pokemon* pokebeza,int* pokenum);
    pokemon* insertar_pokemon(pokemon* pokebeza,int* pokenum);
    int modificar_pokemon(pokemon* pokebeza);
    pokemon* freeList(pokemon* pokebeza,int* pokenum);
    int combatePokemon(pokemon* pokebeza);
    void menu();
    void escribir_fichero_entero(FILE* fichero,int n);
    void escribir_fichero_string(FILE* fichero,char* ptr,int length);
    ssize_t leer_fichero_entero(FILE* fichero,int n);
    ssize_t leer_fichero_string(FILE* fichero,char* ptr,int length);
    void escribe_pokemon(FILE* fichero, pokemon* pokactual);
    pokemon* lee_pokemon(FILE* fichero, pokemon* pokactual);
    void exportar_pokemon_fichero(pokemon* pokebeza);
    pokemon* importar_pokemon_siguiente(pokemon* pokebeza,FILE* fichero);
    pokemon* importar_pokemon_fichero(pokemon* pokebeza,int* pokenum);
    void pokeRevivir(pokemon* pokebeza);
    void mostrar_pokemon_corruptos(pokemon* pokebeza);
    pokemon* leer_fichero_ptr_pokemon(FILE* fichero,pokemon* poke);
    void escribir_fichero_ptr_pokemon(FILE* fichero,pokemon* poke);
    int pokeAumentar(int* pokenum);
    int pokeReducir(int* pokenum);
    void pokeSave(pokemon* pokebeza);
    int leer_fichero_pokenum(int pokenum);
    void escribe_pokenum(int pokenum);
     void* saveActivo(void* pokebeza);
     void* volver_menu(void* attr);
     
     
    
    //17/11/16
    int main(){
      int read;
      char* salirNo;
      char s='s';
      char S='S';
      pthread_t hilos[NUMTHREADS];
     
      
      
      pokemon* pokebeza=malloc(sizeof(pokemon));
      
      pokebeza=NULL;
      
      salirNo="a";
      int valor=0;
      int* pokenum=&valor;
      
     
      void *pokeTema(){
	if(pokebeza==NULL){
	  printf("Lista vacia, teclee otra opcion\n");
	  
	}else{
	  while(1){
	    pokemon* poke=pokebeza;
	    pthread_create(&hilos[2],NULL,saveActivo,(void*)poke);
	    sleep(1);
	  }
	}
	return NULL;
      }
      
    
   	do{
	  //menu:
	  menu();
	  printf("Teclee una opción\n");
	  read=data_read();
	       
	  switch (read) {
	    
	    case 1://17/11/16
	      printf("¿Está seguro de que desea salir del programa?\n[s/N]:\n");
	      salirNo=getString();
	      if(*salirNo==s||*salirNo==S){
		return 0;
	      }
	      else{
		break;
	      }
	    case 2: //21//11/16
	      pokebeza=insertar_pokemon(pokebeza,pokenum);
	      break;
	      
	    case 3://21//11/16
	      mostrar_pokemon_basico(pokebeza);
	      break;
	    case 4://21//11/16
	      mostrar_pokemon_ID(pokebeza);
	      break;
	      
	    case 5://21//11/16
	      modificar_pokemon(pokebeza);
	      break;
	      
	    case 6://21//11/16
	      pokebeza=borrar_pokemon(pokebeza,pokenum);
	      break;
	      
	    case 7://9/12/16
	      escribe_pokenum(*pokenum);
	      exportar_pokemon_fichero(pokebeza);
	      break;
	    case 8://9/12/16
	      printf("Se importará lista de Pokemon nueva\n");
	      if(*pokenum==0){
	      *pokenum=leer_fichero_pokenum(*pokenum);
	      }
	      pokebeza=importar_pokemon_fichero(pokebeza,pokenum);
	      break;
	      
	    case 9: //22/11/16
	      combatePokemon(pokebeza);
	      break;
	      
	    case 10://15/12/16
	      mostrar_pokemon_corruptos(pokebeza);
	      break;
	    case 11://18/12/16
	      
	    pthread_create(&hilos[1],NULL,pokeTema,NULL);
	    
	      
	    //  pthread_mutex_unlock(&acabado);
	      
	     
	      break;
	     
	    case 12:
	      pokeRevivir(pokebeza);
	      break;
	    case 13:
	      pokebeza=freeList(pokebeza,pokenum);
	      break;
	       
	  }
	  
	  
	  
	}while (*salirNo!=s||*salirNo!=S||(strcmp(salirNo,"a")==0));
	//pokebeza=freeList(pokebeza);
	
	return 0;
	
      }
      
      
    
      