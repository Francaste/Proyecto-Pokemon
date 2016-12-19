  #include <stdlib.h>
 #include <stdio.h>
 
 typedef enum Stats {
      T_NORMAL=0,
      T_SPECIAL=1,
    }stats;
        
    typedef struct points{
      int hp;
      int speed;
      int attack[2];
      int defense[2];
      stats stats; //enum stats
    }points;
    
    typedef struct pokemon{
      int id;
      char* s_name;
      int size_name;
      int pokecounter;
      points points;
      struct pokemon* next;
      struct pokemon* prev;
    }pokemon;
   