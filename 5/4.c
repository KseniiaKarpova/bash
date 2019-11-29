#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char** argv){

	
	if (argv[1]==NULL){
                printf("You are required to enter a filename\n");
                return 0;
        }
               
        FILE* file=fopen(argv[1], "r");
        if(file==NULL){
                printf("This file does not exist");
        }else{
              int i_input;
              while(1){
              	if(i_input>-2){
              		if(i_input==-1){
                        if(fclose(file)){
                                printf("Error close file\n");
                                return  -1;
                        }
                        printf("You stopped the reading\n");
                        return 0;
	                }else{
	                    char *c;
						for(int i=0; i < i_input; i++){
							//с =fgets(file);
							if((c = fgetc(file)) != "\n"){
								printf("%s\n", c);
							}else{
								printf("THE END\n");
							}
							
						}   
	                        
	                }
	            }else{
	            	printf("Error input data\n"); 
	              return -1; 
	            }   
            }    
        }
}