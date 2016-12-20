    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>
    
 
    void* volver_menu(void* attr){
      int input;
      while(input=getchar()!=EOF){//evalua siempre
      input=getchar();
      }
       printf("Volviendo al menú\n");
       return attr;
    }