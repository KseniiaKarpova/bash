#include <stdio.h>
 
int main(int argc, char** argv)
{
    if (argv[1]==NULL){
        printf("You are required to enter a OUTPUTfilename\n");
        return 0;
    }
    if (argv[2]==NULL){
        printf("You are required to enter a INPUTfilename\n");
        return 0;
    }
    char cc[256];
    FILE *f1, *f2;
     
    if((f1= fopen(argv[1], "r"))==NULL)
    {
        perror("Error occured while opening file");
        return 1;
    }
    if((f2= fopen(argv[2], "w"))==NULL)
    {
        perror("Error occured while opening file");
        return 1;
    }
     
    while((fgets(cc, 256, f1))!=NULL)
    {
        fputs(cc, f2);
        printf("%s", cc);
    }
     
    if(fclose(f1)){
        printf("Error close OUT_file\n");
        return  -1;
    }
    if(fclose(f2)){
        printf("Error close IN_file\n");
        return  -1;
    }
     
    return 0;
}