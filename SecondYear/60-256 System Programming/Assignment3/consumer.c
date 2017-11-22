//System Programming
//Assignment 3 - consumer.c
//Marcus Toldo - 104623006
//Sunday, November 5, 2017

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>


int main(void) {
    
    FILE * fp;
    fp = fopen("storage.txt", "r+");
    int num=0;
    fscanf(fp, "%d", &num);
    num -= 3;
    
    rewind(fp);
    
    fprintf(fp, "%d\n", num);
    
    printf("from Consumer: Current total is %d\n", num);
    
    sleep(1);
    if (fork() == 0) {
        
        execl("./producer.sh", "producer.sh",   (char *)0);
        
        
        
    }
    
    fclose(fp);
    
	return 0;
}
