#include <unistd.h>



int main()
{


char buffer_name[100]={0};

int ret=getlogin_r(buffer_name, sizeof(buffer_name));

printf("buffer_name=%s\n",buffer_name);


return 0;
}