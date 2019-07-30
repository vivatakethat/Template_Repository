#define _GNU_SOURCE
#include<sys/utsname.h>
#include<stdio.h>

//#include "tlpi_hdr.h"


int main(int argc,char *argv[])
{

    struct utsname uts;
   // if(uname(&uts)==-1)
   // errExit("uanme");

    printf("Node name:  %s\n",uts.nodename);
    printf("System name:    %s\n",uts.sysname);


    return 0;
}


//