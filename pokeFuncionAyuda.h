      #include <stdlib.h>
      #include <stdio.h>
      #include <string.h>
      
      
      void escribir_fichero_entero(FILE* fichero,int n){
	
	fwrite(&n,sizeof(int),1,fichero);
	
      }
      
      void escribir_fichero_string(FILE* fichero,char* ptr,int length){
	
	strcat(ptr,"");//str length+1
	//fwrite(ptr,length,1,fichero);
	
	//fwrite(&length,sizeof(int),1,fichero);
	fwrite(ptr,sizeof(char),length,fichero);
	
      }
      
      ssize_t leer_fichero_entero(FILE* fichero,int n){
	ssize_t bytes_leidos;
	bytes_leidos=fread(&n,sizeof(int),1,fichero);
	
	return bytes_leidos;
	
      }
      
      ssize_t leer_fichero_string(FILE* fichero,char* ptr,int length){
	ssize_t bytes_leidos;
	//fread(&length,sizeof(int),1,fichero);
	
	bytes_leidos=fread(ptr,sizeof(char),length,fichero);
	//bytes_leidos=fread(&length,sizeof(int),1,fichero);
	
	return bytes_leidos;
      }
      
   
      
      
      
      void escribe_pokemon(FILE* fichero, pokemon* pokactual){
	//mientras no hayamos acabado la lista
	//guardamos siguiente y previo del pokactual
	
	//pokemon para mantener el siguiente y previo al actual
	
	pokemon* poke_Mantienenext=NULL;
	pokemon* poke_Mantieneprev=NULL;
	
	poke_Mantienenext=pokactual->next;
	poke_Mantieneprev=pokactual->prev;
	
	//ponemos a null el next y prev del pokactual
	pokactual->next=NULL;
	pokactual->prev=NULL;
	
	fseek(fichero,0,SEEK_END);
	
	escribir_fichero_entero(fichero,pokactual->id);//escribe id
	printf("Id:%d\n",pokactual->id);
	escribir_fichero_entero(fichero,pokactual->size_name);//escribe el tamaño del nombre
	printf("Size Name:%d\n",pokactual->size_name);
	escribir_fichero_string(fichero,pokactual->s_name,pokactual->size_name);//escribe nombre
	printf("Name:%s\n",pokactual->s_name);
	escribir_fichero_string(fichero,"",1);
	escribir_fichero_entero(fichero,pokactual->points.hp);//escribe la vida
	printf("Hp:%d\n",pokactual->points.hp);
	escribir_fichero_entero(fichero,pokactual->points.speed);//escribe la velocidad
	printf("Speed:%d\n",pokactual->points.speed);
	escribir_fichero_entero(fichero,pokactual->points.attack[0]);//escribe el primer ataque
	printf("Attack:%d\n",pokactual->points.attack[0]);
	escribir_fichero_entero(fichero,pokactual->points.attack[1]);//escribe el segundo ataque
	printf("Sp Attack:%d\n",pokactual->points.attack[1]);
	escribir_fichero_entero(fichero,pokactual->points.defense[0]);//escribe la primera defensa
	printf("Defense:%d\n",pokactual->points.defense[0]);
	escribir_fichero_entero(fichero,pokactual->points.defense[1]);//escribe la segunda defensa
	printf("Sp Defense:%d\n\n",pokactual->points.defense[1]);
	
	pokactual->next=poke_Mantienenext;//recuperamos next y prev
	pokactual->prev=poke_Mantieneprev;
	
	poke_Mantienenext=NULL;//volvemos a ponerlos a NULL para la siguiente vuelta
	poke_Mantieneprev=NULL;
	
	
      }
      
      
      
     pokemon* lee_pokemon(FILE* fichero,pokemon* pokactual){//lee un pokemon una vez del fichero
      ssize_t bytes_leidos;
      pokactual=malloc(sizeof(pokemon));
      
      printf("Puede que Id:%d\n\n",pokactual->id);
      
      bytes_leidos=leer_fichero_entero(fichero,pokactual->id);//lee id
      printf("Id:%d\n",pokactual->id);
      bytes_leidos=leer_fichero_entero(fichero,pokactual->size_name);//lee el tamaño del nombre
      printf("Size Name:%d\n",pokactual->size_name);
      // bytes_leidos=leer_fichero_entero(fichero,length);
      bytes_leidos=leer_fichero_string(fichero,pokactual->s_name,pokactual->size_name);//lee nombre
      printf("Name:%s\n",pokactual->s_name);
      //fread("\0",sizeof(char),1,fichero);
      //fseek(fichero,0,SEEK_END);
      bytes_leidos=leer_fichero_entero(fichero,pokactual->points.hp);//lee la vida
      printf("Hp:%d\n",pokactual->points.hp);
      bytes_leidos=leer_fichero_entero(fichero,pokactual->points.speed);//lee la velocidad
      printf("Speed:%d\n",pokactual->points.speed);
      bytes_leidos=leer_fichero_entero(fichero,pokactual->points.attack[0]);//lee el primer ataque
      printf("Attack:%d\n",pokactual->points.attack[0]);
      bytes_leidos=leer_fichero_entero(fichero,pokactual->points.attack[1]);//lee el segundo ataque
      printf("Sp Attack:%d\n",pokactual->points.attack[1]);
      bytes_leidos=leer_fichero_entero(fichero,pokactual->points.defense[0]);//lee la segunda defensa
      printf("Defense:%d\n",pokactual->points.defense[0]);
      bytes_leidos=leer_fichero_entero(fichero,pokactual->points.defense[1]);//lee la segunda defensa
      printf("Sp Defense:%d\n",pokactual->points.defense[1]);
      return pokactual ;
      }
      
      




