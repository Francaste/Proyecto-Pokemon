 #include <stdlib.h>
 #include <stdio.h>
 #include <string.h>
 
     //Libera lista
     pokemon* freeList(pokemon* pokebeza,int* pokenum) {
	if(pokebeza==NULL){
	printf("Lista vacia\n");
	return pokebeza;
        }else{
	pokemon *pokeliminar=pokebeza;
	pokemon *pokeref = NULL;
	
	while(pokeliminar!=NULL) {
	pokeref=pokeliminar->next;
	printf("Eliminando:\nNombre:%s ID:%d\n",pokeliminar->s_name,pokeliminar->id);
	*pokenum=pokeReducir(pokenum);
	free(pokeliminar);
	pokeliminar = pokeref;
	}
	pokebeza=NULL;
	pokeref=NULL;
	free(pokeref);
	return pokebeza;
      }
     }
    
    //mostramos las partes básicas de los pokemon metidos  21//11/16
    void mostrar_pokemon_basico(pokemon * pokebeza){
      if(pokebeza==NULL){
	printf("Lista vacia\n");
      }else{
	printf("|ID|\tNombre|\t\tVida|\tAtaque|\tDefensa|\n");
	for(;pokebeza!=NULL;pokebeza=pokebeza->next){
	  printf("%d\t%s\t\t%d\t%d\t%d\n\n", pokebeza->id,pokebeza->s_name,pokebeza->points.hp,pokebeza->points.attack[0],pokebeza->points.defense[0] );
	}
      }
    }
    
    //mostramos toda la informaciń de un pokemon dado su ID   21//11/16 mod:25/11/16
    void mostrar_pokemon_ID(pokemon * pokebeza){
       if(pokebeza==NULL){
	printf("Lista vacia\n");
	return;
      }else{
      printf("Introduzca el ID del pokemon\n");
      int id_metido=data_read();
      printf("\nInformación completa del Pokemon\n");
      int pokeidea=2;
      
      for(;pokebeza!=NULL;pokebeza=pokebeza->next){
	if(id_metido==pokebeza->id){
	  printf("ID=%d\nVida=%d\nNombre=%s\nAtaque=%d\nDefensa=%d\nAtaque Esp=%d\nDefensa Esp=%d\nVelocidad=%d\nTamaño nombre=%d\n\n\n", pokebeza->id,pokebeza->points.hp,pokebeza->s_name,pokebeza->points.attack[T_NORMAL],
		 pokebeza->points.defense[T_NORMAL],pokebeza->points.attack[T_SPECIAL],pokebeza->points.defense[T_SPECIAL],pokebeza->points.speed,pokebeza->size_name);
		 pokeidea=1;
		 break;
	}
      }
      
      if(pokeidea!=1){
	printf("No hay ningún Pokemon con esa ID, pruebe de nuevo.\n");
      }
     }
    }
    
     //mostramos pokemon con vida negativa porque no pueden tener mismo id
    void mostrar_pokemon_corruptos(pokemon * pokebeza){
       if(pokebeza==NULL){
	printf("Lista vacia\n");
	return;
      }else{
         int pokeidea=2;
	 int num_corruptos=0;
      
	 printf("==================\nPokemon Corruptos\n==================\n\n");
      for(;pokebeza!=NULL;pokebeza=pokebeza->next){
	if(pokebeza->points.hp<0){
	  pokeidea=1;
	  printf("ID=%d\nVida=%d\nNombre=%s\nAtaque=%d\nDefensa=%d\nAtaque Esp=%d\nDefensa Esp=%d\nVelocidad=%d\nTamaño nombre=%d\n\n\n", pokebeza->id,pokebeza->points.hp,pokebeza->s_name,pokebeza->points.attack[T_NORMAL],
		 pokebeza->points.defense[T_NORMAL],pokebeza->points.attack[T_SPECIAL],pokebeza->points.defense[T_SPECIAL],pokebeza->points.speed,pokebeza->size_name);
		 pokeidea=1;
		 num_corruptos++;
	}
      }
      printf("Hay %d Pokemon corruptos.\n",num_corruptos);
      if(pokeidea==2){
	printf("No hay ningún Pokemon corrupto.\n");
      }
     }
    }
    
    
    
    
    
    
  //Imprime menu 10/11/16
    void menu(){
      printf("===========================\n\tPOKEMANAGER\n===========================\n\n[1] Salir\n\n[2] Insertar Pokemon\n"
      "\n[3] Mostrar Pokemon\n\n[4] Mostrar Pokemon por ID\n\n[5] Modificar Pokemon por ID\n\n[6] Borrar Pokemon por ID\n"
      "\n[7] Exportar catálogo Pokemon\n\n[8] Importar catálogo Pokemon\n\n[9] Combate Pokemon\n"
      "\n[10] Mostrar Pokemon corruptos\n\n[11] Autosalvado(10 sec)\n\n[12] Revivir Pokemon\n\n[13] Liberar Lista\n\n\n"
      );
      
    }    
