 #include <stdlib.h>
 #include <stdio.h>
 #include <string.h>
 
 //prototipos
 pokemon* freeList(pokemon *pokebeza,int* pokenum);
 void escribir_fichero_string(FILE* fichero,char* ptr,int length);
 void escribir_fichero_entero(FILE* fichero,int n);
 ssize_t leer_fichero_entero(FILE* fichero,int n);
 ssize_t leer_fichero_string(FILE* fichero,char* ptr,int length);
 void escribe_pokemon(FILE* fichero, pokemon* pokactual);//escribe cada parametro del pokemon
 pokemon* lee_pokemon(FILE* fichero, pokemon* pokactual);//lee cada parametro del pokemon
 
 void escribe_pokenum(int pokenum){
   
   FILE* fichero;//variable fichero
   fichero=fopen("listaBinaria.bin", "wb+");//abre o crea fichero lista y escribe
   if(fichero!=NULL) {//si hay algo en el fichero escribe
     
     
     fseek(fichero,0,SEEK_END);
     fwrite(&pokenum,sizeof(int),1,fichero);
     printf("Num Pokemon:%d\n",pokenum);
     
     fclose(fichero);//cerramos fichero
     
     fichero=NULL;
     return;
 }else {//si es NULL el fichero ha habido un error
   printf("Error de lecutura\n");
   return;
 }
 
 
 
 }
 int leer_fichero_pokenum(int pokenum){
   
   FILE* fichero;
   fichero=fopen("listaBinaria.bin","rb+");
   if(fichero!=NULL){
     
     //fseek(fichero,0,SEEK_END);
     //long tamano=ftell(fichero);
     //rewind(fichero);
     
     ssize_t bytes_leidos;
     fseek(fichero,0,SEEK_SET);
     bytes_leidos=fread(&pokenum,sizeof(int),1,fichero);
     printf("Num Pokemon:%d\n",pokenum);
     
     
     
   }else{
     
     printf("Error al abrir el fichero\n");
     
   }
   fclose(fichero);
   fichero=NULL;
   
   return pokenum;
   
 }
 
 
 // Exportar lista a un fichero 2
 void exportar_pokemon_fichero(pokemon* pokebeza){
   if(pokebeza==NULL){
     printf("Lista vacia\n");
     return;
   }else{
     FILE* fichero;//variable fichero
     fichero=fopen("listaBinaria.bin", "wb+");//abre o crea fichero lista y escribe
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
 
 
 
 pokemon* importar_pokemon_siguiente(pokemon* pokebeza,FILE* fichero){
   
   
   if(pokebeza==NULL){
     pokebeza=malloc(sizeof(pokemon));
      /*pokebeza->s_name=NULL;
    pokebeza->size_name=0;
     pokebeza->id=0;
     pokebeza->points.hp=0;
     pokebeza->points.speed=0;
     pokebeza->points.attack[0]=0;
     pokebeza->points.attack[1]=0;
     pokebeza->points.defense[0]=0;
     pokebeza->points.defense[1]=0;*/
     
     
     pokebeza=lee_pokemon(fichero,pokebeza);
     pokebeza->next=NULL;
     pokebeza->prev=NULL;
     
   }else{
     pokemon* pokeindice=pokebeza;
     pokemon* pokenuevo=malloc(sizeof(pokemon));
     
     while(pokeindice->next!=NULL){
       pokeindice=pokeindice->next;
     }
     
     pokenuevo=lee_pokemon(fichero,pokenuevo);
     pokeindice->next=pokenuevo;
     pokenuevo->next=NULL;
     pokenuevo->prev=pokeindice;
     
     
     
   }
   return pokebeza;
 }
 
 
 pokemon* importar_pokemon_fichero(pokemon* pokebeza,int* pokenum){
   
   FILE* fichero;
   fichero=fopen("listaBinaria.bin","rb+");
   
   
   if(fichero!=NULL){
         
     freeList(pokebeza,pokenum);
   
     pokebeza = NULL;
     //TAMAÑO FICHERO ENTRE SIZEOF POKEMON
     /*fseek(fichero,0,SEEK_END);
     long tamano=ftell(fichero);
     rewind(fichero);*/
     
     
     
     //int pokenum=(int)(tamano/tamano_Leer);//numero de pokemon leidos
     printf("Numero de Pokemon: %d\n\n\n",*pokenum);
     int tamano_Leer=sizeof(pokemon);//tamaño primer poke
     if(*pokenum==0){
      
       pokemon *poke=malloc(sizeof(pokemon));;
       int i=0; 
       char *nombre;
       //fseek(fichero,sizeof(int),SEEK_SET);
       while(nombre!=NULL){
	 printf("Hace algo\n");
	 fseek(fichero,(tamano_Leer*i),SEEK_SET);
	 
	 poke=lee_pokemon(fichero,poke);
	 poke->next=NULL;
	 poke->prev=NULL;
	 nombre=poke->s_name;
	 
	 if(pokebeza==NULL){
	   pokebeza=poke;
	 }else{
	   poke->next=pokebeza;
	   pokebeza=poke;
	   i++;
	 } 
	 
       } return pokebeza;
     }
     else{
       int i=0;
       
       for(i=0;i<=*pokenum;i++){
	 
	 fseek(fichero,(tamano_Leer*i),SEEK_SET);
	 pokebeza=importar_pokemon_siguiente(pokebeza,fichero);
	 
       }
       
     }
     
   }else{
     printf("Error al abrir el fichero\n");
   }
   fclose(fichero);
   fichero=NULL;
   
   return pokebeza;
 }
 
 
 
 
 //od -c MyficheroBinario