#include <stdio.h>
#include <dirent.h>

int folder(char *s){
	struct dirent *d;
	DIR *dir = opendir(s);
    if(dir==NULL){
    	printf("The %s directory does not open\n", s);
    	return 1;
    }else{
    	printf("In %s directory:\n", s);
    	while((d=readdir(dir))!=NULL){
    		printf("%s\n", d->d_name);
    	}
    	closedir(dir);
    	return 0;
    }
}
int main(int argc, char** argv)
{
    if (argv[1]==NULL){
        printf("You are required to enter a filename\n");
        return 1;
    }

    if(folder(".")==0){
    	if(folder(argv[1])==0){
    		printf("THE END\n");
    		return 0;
    	}else{
    		printf("Error\n");
    		return 1;
    	}

    }else{
    	printf("Error\n");
    	return 1;
    }
    


}