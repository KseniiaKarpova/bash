#include <stdio.h>
#include <stdlib.h>
int main(int argc, char** argv)
{
        if (argv[1]==NULL){
                printf("You are required to enter a filename\n");
                return 0;
        }
               
        FILE* file=fopen(argv[1], "w");
        
        if(file==NULL){
                printf("This file does not exist");
        }else{
              int i_input;
              while(1){
                if((i_input=getc(stdin))!=6){
                        fputc(i_input, file);
                }else{
                        printf("You stopped the recording\n");
                        if(fclose(file)){
                                printf("Error\n");
                                return  -1;
                        }
                        return 0;
                }
              }  
        }
        
}