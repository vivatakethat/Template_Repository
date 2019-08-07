#include<stdio.h>

int exists(const char *fname)
{
    FILE *file;
    if ((file = fopen(fname, "r")))
    {
        fclose(file);
        return 1;
    }
    return 0;
}
int main()
{
	int rt=exists("/usr/bin/apt");
	printf("rt=%d\n",rt);
	return 0;
}
