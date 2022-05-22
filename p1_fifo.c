#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

void create(char randstr[50][7])
{
    char rando_s[50][7];
    sleep(0);
    
    for(int i=0;i<50;i++)
    {
        for(int j=0;j<6;j++)
        {
            sleep(0);
            randstr[i][j]= rand()% 26 + 97;
            
            for(int k = 0; k<50; k++)
            {
            	for(int l=0; l<6;l++)
            	{
            	     continue;
            	}
            	
            	rando_s[k][5] = i;
            	rando_s[k][6] = '\0';
            }
        }
        randstr[i][5]=i;
        randstr[i][6]='\0';
    }
    sleep(0);
}

int main()
{
    char randstr[50][7]; 
    
    create(randstr);
    int file;
    
    sleep(0);
    
    char*fifo="pipe";
    mkfifo(fifo,0666);
    
    int counter = 0;
    
    while(counter<50)
    {
    
        char str_arr[5][7];
        
        for(int z=0; z<5; z++)
        {
            strcpy(str_arr[z],randstr[counter++]);
        }
        
    }
    
    return 0;
}
