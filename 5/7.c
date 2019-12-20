#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
int save_result(FILE *f1,char *n, char *n1, char *r, FILE *f2){
	printf("I FIND!\n");
    struct stat buff1;
    struct stat buff2;
    stat(n, &buff1);
    stat(n1, &buff2);

    FILE *result;
    if((result= fopen(r, "w"))==NULL){
        printf("Error occured while opening %s \n", r );
        //return 1;
    }

    char str[512];
    char str1[512];
    char buf[128];
    strcpy(str,n);
    

    strcat(str, "\nsize: ");
    snprintf(buf, sizeof(buf), "%ld", buff1.st_size);
    strcat(str, buf);
    
    //char buf1[128];
    strcat(str, "\nдата создания: ");
    snprintf(buf, sizeof(buf), "%ld", buff1.st_ctime);
    strcat(str, buf);

    
    strcat(str, "\nправа доступа: ");
    snprintf(buf, sizeof(buf), "%u", buff1.st_mode);
    strcat(str, buf);

    strcat(str, "\nномер индексного дескриптора: ");
    snprintf(buf, sizeof(buf), "%lu", buff1.st_ino);
    strcat(str, buf);

    fputs(str, result);
    fputs("\n", result);


    strcpy(str1,n1);

    strcat(str1, "\nsize: ");
    snprintf(buf, sizeof(buf), "%ld", buff2.st_size);
    strcat(str1, buf);

    strcat(str1, "\nдата создания: ");
    snprintf(buf, sizeof(buf), "%ld", buff2.st_ctime);
    strcat(str1, buf);

    strcat(str1, "\nправа доступа: ");
    snprintf(buf, sizeof(buf), "%u", buff2.st_mode);
    strcat(str1, buf);

    strcat(str1, "\nномер индексного дескриптора: ");
    snprintf(buf, sizeof(buf), "%lu", buff2.st_ino);
    strcat(str1, buf);
    
    fputs(str1, result);
    
    //putc((char)buff1.st_size, result);
    //char snum[256];
   /* fscanf(result,"%d",buff1.st_size);
    fscanf(result,"%d",buff1.st_mode);
    fscanf(result,"%d",buff1.st_ino);*/
    //fputs(buff1.st_size , result);
    //fputs(buff1.st_mode , result);
    //fputs(buff1.st_ino , result);

    //fputs(n1, result);//имя
    /*fscanf(result,"%d",buff2.st_size);
    fscanf(result,"%d",buff2.st_mode);
    fscanf(result,"%d",buff2.st_ino);*/
    //fputs(buff2.st_size , result);
    //fputs(buff2.st_mode , result);
    //fputs(buff2.st_ino , result);

    if(fclose(result)){
        printf("Error close file\n");
        //return  1;
    }
    exit(0);
    return 0;

}


int equals_files(char *n, char *n1, char *r){
	FILE *f1, *f2;
    f1=fopen(n, "r");
    if(f1==NULL) {
        printf("Error occured while opening n %s\n", n);
        return 0;
    }
    f2= fopen(n1, "r");
    if(f2==NULL){
        printf("Error occured while opening n1 %s\n", n1);
        return 0;
    }
    while((getc(f1))==(getc(f2)) & (getc(f1))!= EOF & (getc(f2))!= EOF){
        if((getc(f1))==(getc(f2)) & (getc(f1))== EOF & (getc(f2))== EOF){
            if(save_result(f1,n, n1, r, f2)){
                return 1;
            }
            
        }
    }

    if(fclose(f1)){
        printf("Error close file\n");
       return  0;
    }
    if(fclose(f2)){
        printf("Error close file\n");
        return  0;
    }
    return 0;
}


void folders(char* s, char* s1 , char *r){
    struct dirent *d;
    DIR *dir = opendir(s);
    struct dirent *d1;
    DIR *dir1 = opendir(s1);
    struct stat statbuf;
    struct stat statbuf1;
    printf("s = %s, s1 = %s\n", s,s1);
    
   /* if(dir==NULL){
    	break; 
    }
        //printf("The %s directory does not open\n", s);
        //return 1;
    
    if(dir1==NULL){
    	break;
        //printf("The %s directory does not open\n", s1);
        //return 1;
    }*/
    
        while((d=readdir(dir))!=NULL){
        	while((d1=readdir(dir1))!=NULL){
        			if(d->d_type == DT_DIR ){
        				if(d1->d_type == DT_DIR ){
        					char str[180];
        					char str1[180];
        					strcpy(str,s);
        					strcat(str, "/");
        					strcat(str, d->d_name);

        					strcpy(str1,s1);
        					strcat(str1,"/");
        					strcat(str1, d1->d_name);

        					folders( str, str1,r);
        					 
        				}else{
        					char str[80];
        					strcpy(str,s);
        					strcat(str, "/");
        					strcat(str, d->d_name);
        					folders(str, s1,r);
        					
        				}
        			}else if(d1->d_type == DT_DIR){
        				char str[80];
        				strcpy(str,s1);
        				strcat(str, "/");
        				strcat(str, d1->d_name);
        				folders(s, str,r);
        				
        			}else{
        				char str[180];
        					char str1[180];
        					strcpy(str,s);
        					strcat(str, "/");
        					strcat(str, d->d_name);

        					strcpy(str1,s1);
        					strcat(str1,"/");
        					strcat(str1, d1->d_name);

        					printf("%s and %s\n", str, str1);
        				if(equals_files(str, str1, r)){
	                		printf("FIND!\n");
	                	}else{
	                		continue;
	                	}
        			}
	                
	                
        		}
        	/*f(stat(d->d_name, &statbuf) == -1){
       			printf("Error stat %s \n", s); 
    		}
    		if(stat(d1->d_name, &statbuf1) == -1){
       			printf("Error stat %s \n", s); 
    		}
            if(S_ISDIR(statbuf.st_mode)){
            	DIR *dirr=opendir(d->d_name);
            	DIR *dirrr=opendir(d1->d_name);
            	if(S_ISDIR(statbuf1.st_mode) & dirr!=NULL & dirrr!=NULL){
            		folders(d->d_name, d1->d_name,r);
            	}else if(dirr!=NULL){
            		folders(d->d_name, s1,r);
            	}
                
            }else{
            	while((d1=readdir(dir1))!=NULL){
	                if((S_ISREG(statbuf.st_mode)) & (S_ISREG(statbuf1.st_mode))){
	                	equals_files(d->d_name, d1->d_name, r);
	                    continue;
	                }
	                continue;
        		}	
            }
        	continue;  */  
    }
        closedir(dir);
        //return 0;
    
}
 
int main(int argc, char** argv){
    if (argv[1]==NULL){
        printf("You are required to enter a 1_filename\n");
        return 1;
    }
    if (argv[2]==NULL){
        printf("You are required to enter a 2_filename\n");
        return 1;
    }
    if (argv[3]==NULL){
        printf("You are required to enter a 3_filename\n");
        return 1;
    }
	
    folders(argv[1],argv[2] , argv[3]);
    
    
     
    return 0;
}
