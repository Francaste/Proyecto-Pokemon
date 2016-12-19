      #include <stdlib.h>
      #include <stdio.h>
      
      int pokeAumentar(int* pokenum){
	*pokenum+=1;
	printf("pokenum:%d\n",*pokenum);
	return *pokenum;
      }
      
      int pokeReducir(int* pokenum){
	*pokenum-=1;
	printf("pokenum:%d\n",*pokenum);
	return *pokenum;
      }