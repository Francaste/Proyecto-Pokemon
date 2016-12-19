 #include <stdlib.h>
 #include <stdio.h>
 #include <string.h>
 
     void pokeRevivir(pokemon * pokebeza){
       if(pokebeza==NULL){
	printf("Lista vacia\n");
	return;
      }else{
         int pokeidea=2;
	 int num_revividos=0;
      
	 printf("Reviviendo Pokemon debilitados\n\n");
      for(;pokebeza!=NULL;pokebeza=pokebeza->next){
	if(pokebeza->points.hp<=0){
	  pokeidea=1;
	 pokebeza->points.hp=10;
	  num_revividos++;
	}
      }
      printf("Hemos revivido %d Pokemon.\n",num_revividos);
      if(pokeidea==2){
	printf("No hay ningún Pokemon para revivir.\n");
      }
     }
    }