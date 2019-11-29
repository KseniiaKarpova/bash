#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int seve_result(FILE *f1, FILE *f2){
    stat 
}


int equals_files(char *n, char *n1){
    FILE *f1, *f2;
    if((f1= fopen(n, "r"))==NULL)
    {
        perror("Error occured while opening %s", n);
        return 1;
    }
    if((f2= fopen(n1, "r"))==NULL)
    {
        perror("Error occured while opening %s", n1);
        return 1;
    }

    while(gets(f1)==gets(f2) & gets(f1)!= EOF & gets(f2)!= EOF){
        if(gets(f1)==gets(f2) & gets(f1)== EOF & gets(f2)== EOF){
            seve_result(f1, f2);
        }
    }

    if(fclose(f1)){
        printf("Error close OUT_file\n");
        return  1;
    }
    if(fclose(f2)){
        printf("Error close IN_file\n");
        return  1;
    }

}

int folders(char *s, char *s1){
    struct dirent *d;
    DIR *dir = opendir(s);
    struct dirent *d1;
    DIR *dir1 = opendir(s1);

    if(dir==NULL){
        printf("The %s directory does not open\n", s);
        return 1;
    }
    if(dir1==NULL){
        printf("The %s directory does not open\n", s1);
        return 1;
    }

    else{
        while((d=readdir(dir))!=NULL){
            while((d1=readdir(dir1))!=NULL)
                if(equals_files(d->d_name, d1->d_name)){
                    continue;
                }
        }
        closedir(dir);
        return 0;
    }
}
 
int main(int argc, char** argv)
{
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
    
    
     
    return 0;
}