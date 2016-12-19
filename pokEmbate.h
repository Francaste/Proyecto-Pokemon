  #include <stdlib.h>
  #include <stdio.h>
  #include <string.h>
  #include <unistd.h> //para combate por turnos
 
 
 //actualiza vida de pokemon en combate
  void combateUpdate(pokemon* poke1,pokemon *poke2){
    int danoA1=0;
    int danoA2=0;
    //calculamos daño
    printf("%s ha atacado a %s\n",poke1->s_name,poke2->s_name);
    danoA2=(((86+rand()%15)*poke1->points.attack[T_NORMAL])/poke2->points.defense[T_NORMAL])/10;
    poke2->points.hp-=danoA2;//calculamos nueva vida de poke2
    printf("Pokemon:%s----Vida:%d\nPokemon:%s----Vida:%d\n",poke1->s_name,
	       poke1->points.hp,poke2->s_name,poke2->points.hp);
    
    sleep(1);//espera 1 segundo para seguir
    printf("%s ha atacado a %s\n",poke2->s_name,poke1->s_name);
    danoA1=(((86+rand()%15)*poke2->points.attack[T_NORMAL])/poke1->points.defense[T_NORMAL])/10;
    poke1->points.hp-=danoA1;//calculamos nueva vida de poke1
    
    printf("Pokemon:%s----Vida:%d\nPokemon:%s----Vida:%d\n",poke1->s_name,
	       poke1->points.hp,poke2->s_name,poke2->points.hp);
    
  }
  //22/11/16 Combate Pokemon 
   
  int combatePokemon(pokemon * pokebeza){
    int id_metido1=0;
    int id_metido2=0;
    pokemon* pokelegido1=malloc(sizeof(pokemon));
    pokemon* pokeaux=malloc(sizeof(pokemon));
    pokemon* pokelegido2=malloc(sizeof(pokemon));
      
    if(pokebeza==NULL){
      printf("Lista vacia\n");
      return 0;
    }else{
      {//Buscamos Pokemon para combatir
      int pokeidea=2;
      printf("Introduzca el ID del Pokemon 1 \n");
      
      id_metido1=data_read();
      
      printf("Buscando Pokemon...\n");
      pokeaux=pokebeza;
      
      for(;pokeaux!=NULL;pokeaux=pokeaux->next){
	if(id_metido1==pokeaux->id){
	  pokelegido1=pokeaux;
	  pokeidea=1;
	  break;
	}
      }
      
      if(pokeidea!=1){
	fprintf(stderr,"No hay ningún Pokemon con esa ID, pruebe de nuevo.\n");
	//free(pokelegido1);
	
	return 0;
      }
      printf("Introduzca el ID del pokemon 2 \n");
      id_metido2=data_read(); 
      
      printf("Buscando Pokemon...\n");
      pokeaux=pokebeza;
      
      
      if(pokeidea==1){//ha encontrado pokemon 1
	
	pokeidea=2;
	
	for(;pokeaux!=NULL;pokeaux=pokeaux->next){
	  if(id_metido2==pokeaux->id){
	    pokelegido2=pokeaux;
	    pokeidea=1;
	    break;
	  }
	}
	  
	  if(pokeidea!=1){
	    fprintf(stderr,"No hay ningún Pokemon con esa ID, pruebe de nuevo.\n");
	       
	    return 0;
	  }
	}
       }
      }
      
      //comprobamos vida
  
      if(pokelegido1->points.hp>0&&pokelegido2->points.hp>0){//pueden luchar
	printf("Comenzando combate\n\n");
	while(pokelegido1->points.hp>0&&pokelegido2->points.hp>0){
	  combateUpdate(pokelegido1,pokelegido2);
	}
	printf("Combate finalizado\n");
	
	
      } else{
	
	if(pokelegido1->points.hp<0){
	 printf("El Pokemon %s esta debilitado, no puede luchar!\n",pokelegido1->s_name);
	}else if(pokelegido2->points.hp<0){ 
	  printf("El Pokemon %s esta debilitado, no puede luchar!\n",pokelegido2->s_name);
	}else{
	  printf("Combate finalizado\n");
	}
      }
      return 0;
    }
 
 
    
    
    
    
    
    
    
    
    
    
    
    

    
    
    
    
  
  
  