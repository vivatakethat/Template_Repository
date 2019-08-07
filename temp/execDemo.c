//execDemo.c 
  
#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
int main() 
{ 
        //A null terminated array of character  
        //pointers 
        //char *args[]={"./EXEC",NULL}; 
        char *args[]={"eval getent passwd {$(awk '/^UID_MIN/ {print $2}' /etc/login.defs)..$(awk '/^UID_MAX/ {print $2}' /etc/login.defs)}  | cut -d: -f1 | wc -l | awk 1 ORS=''","-l"}; 
//        execvp(args[0],args); 
      
	execl("/bin/bash", "sh", "-c", args[0], (char *)0);
        /*All statements are ignored after execvp() call as this whole  
        process(execDemo.c) is replaced by another process (EXEC.c) 
        */
        printf("Ending-----"); 
      
    return 0; 
} 
