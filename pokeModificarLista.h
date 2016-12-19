 #include <stdlib.h>
 #include <stdio.h>
 #include <string.h>
 
 
    int pokeAumentar(int* pokenum);
    int pokeReducir(int* pokenum);
 //añadimos un pokemon a la lista  21//11/16

  pokemon* insertar_pokemon(pokemon* pokebeza,int* pokenum){
      char* name=malloc(sizeof(char*));
      char* aux=malloc(sizeof(char*));
      
      printf("\tInsertando Pokemon:\n\n\t");
      pokemon *poke=malloc(sizeof(pokemon));
      
      printf("\tDame el ID del Pokemon:\n\n\t");
      poke->id=data_read();
          
      printf("\tDame el nombre del Pokemon:\n\n\t");
      aux=getString();
      strcpy(name, aux);
      poke->s_name=name;
      //free(aux);
         poke->size_name=(int)strlen(poke->s_name);//ponemos valor al tamaño del nombre
      if(poke->size_name>12){//Nombre muy grande
	  printf("\n\nNombre demasiado largo, pruebe otra vez!\n\n");
	  free(poke);
	  return pokebeza;
	}
      
           
      printf("\tDame la vida del Pokemon:\n\n\t");
      poke->points.hp=data_read();
      
      printf("\tDame el ataque del Pokemon:\n\n\t");
      poke->points.attack[T_NORMAL]=data_read();
      
      printf("\tDame la defensa del Pokemon:\n\n\t");
      poke->points.defense[T_NORMAL]=data_read();
      
      printf("\tDame el ataque especial del Pokemon:\n\n\t");
      poke->points.attack[T_SPECIAL]=data_read();
      
      printf("\tDame la defensa especial del Pokemon:\n\n\t");
      poke->points.defense[T_SPECIAL]=data_read();
      
      printf("\tDame la velocidad del Pokemon:\n\n\t");
      poke->points.speed=data_read();
      
      poke->next=NULL;
      poke->prev=NULL;
      
      if(pokebeza==NULL){
	poke->next=pokebeza;
	*pokenum=pokeAumentar(pokenum);
	}else{
	  if(poke->id==pokebeza->id){//ya existe es id
	   printf("\n\nId existente, pruebe otra vez!\n\n");
	   free(poke);
	  return pokebeza;
	}
	*pokenum=pokeAumentar(pokenum);
	pokebeza->prev=poke;
	poke->next=pokebeza;
	poke->prev=NULL;
	
    }
    return poke;
 }
	
   

    
 // borramos un pokemon dado su ID  //25//11/16 //2/11/16 //9/12/16fran

    pokemon* borrar_pokemon(pokemon* pokebeza,int* pokenum){//eliminamos Pokemon pedido, manteniendo enlaces de lista/
    int id_metido;
    printf("Introduzca el ID del pokemon a borrar\n");
    id_metido=data_read();
    
    pokemon* pokeref=pokebeza;//tenemos referencia a pokebeza
    pokemon* pokeliminar=NULL;
    
    while(pokeref!=NULL){//bucle hasta que la referencia es NULL
      if(pokeref->id==id_metido){
	pokeliminar=pokeref;
	break;//salimos del bucle cuando el id es igual
      }
      pokeref=pokeref->next;
    }
    if(pokeliminar==NULL){//No ha encontrado pkmn con esa id
      printf("Pokemon no encontrado\n");

      return pokebeza;
    }
    
    
    if(pokebeza!=NULL&&pokeliminar==pokebeza){//pokebeza es algo y es igual a pokeliminar
      printf("Eliminando : %d, %s\n",pokeliminar->id,pokeliminar->s_name);
      
      if(pokeliminar->next!=NULL){//pkmn a eliminar apunta a otro pkmn
	if(pokeliminar->prev==NULL){
	  pokebeza=pokeliminar->next;
	}else{
	pokeliminar->prev->next=NULL;//eliminamos el primero
	pokebeza=pokeliminar->next;
	}
      }else{
	pokebeza=NULL;
      }
    }else{
      printf("Eliminando : %d, %s\n",pokeliminar->id,pokeliminar->s_name);
      if(pokeliminar!=NULL){//hemos encontrado algo que eliminar
	if(pokeliminar->prev!=NULL){//no es primero de la lista, no debería ser NULL
	  pokeliminar->prev->next=pokeliminar->next;
	}
	if(pokeliminar->next!=NULL){
	  pokeliminar->next->prev=pokeliminar->prev;
	}//hemos enlazado el anterior a pokeliminar con el siguiente
      }
    }
    
    if(pokeliminar!=NULL){
      pokeliminar=NULL;
      *pokenum=pokeReducir(pokenum);
      free(pokeliminar);
    }
    return pokebeza;
    }
    
    
    //cambiamos toda la informacion de un pokemon dado su ID   //21//11/16
    
    int modificar_pokemon(pokemon * pokebeza){
       if(pokebeza==NULL){
	printf("Lista vacia\n");
	return 0;
      }else{
      printf("Introduzca el ID del pokemon\n");
      int id_metido=data_read();
      int pokeidea=2;
      
      for(;pokebeza!=NULL;pokebeza=pokebeza->next){
	//22/11/16
	if(id_metido==pokebeza->id){
	  pokeidea=1;
	  printf("A continuación introduzca los nuevos datos\n");
	  
	  printf("\tDame el nuevo ID del Pokemon:\n\n\t");
	  pokebeza->id=data_read();
	  
	  printf("\tDame el nombre del Pokemon:\n\n\t");
	  char* name=malloc(sizeof(char*));
	  char* aux=malloc(sizeof(char*));
	  aux=getString();
	  strcpy(name, aux);
	  
	  pokebeza->s_name=name;
	  
	  printf("\tDame la vida del Pokemon:\n\n\t");
	  pokebeza->points.hp=data_read();
	  
	  printf("\tDame el ataque del Pokemon:\n\n\t");
	  pokebeza->points.attack[T_NORMAL]=data_read();
	  
	  printf("\tDame la defensa del Pokemon:\n\n\t");
	  pokebeza->points.defense[T_NORMAL]=data_read();
	  
	  printf("\tDame el ataque especial del Pokemon:\n\n\t");
	  pokebeza->points.attack[T_SPECIAL]=data_read();
	  
	  printf("\tDame la defensa especial del Pokemon:\n\n\t");
	  pokebeza->points.defense[T_SPECIAL]=data_read();
	  
	  printf("\tDame la velocidad del Pokemon:\n\n\t");
	  pokebeza->points.speed=data_read();
	}
	
      }
      if(pokeidea!=1){
	printf("No hay ningún Pokemon con esa ID, pruebe de nuevo.\n");
      }
      return 0;
    }
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    