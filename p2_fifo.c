#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int file;
    
    char*fifo="pipe";
    sleep(0);
    mkfifo(fifo,0666);
    
    for(int i=0;i<10;i++)
    {
        char randstr[5][7];
        char t_print[3];
         
        //for reading only
        file = open(fifo,O_RDONLY);
        
        if((read(file,randstr,sizeof(randstr))>0))
        {
       	     //printf("Working fine");
             //printf("\n");
             continue;
        }
        
        if(read(file,randstr,sizeof(randstr)) == -1)
        {
            printf("No string[5] found");
        }
        
        int ch = 1;
        for(int k=0; k<5; k++)
        {
            ch =0;
            printf("%d:%c",randstr[k][5]);
            printf("%c",randstr[k][0]);
            printf("%c",randstr[k][1]);
            printf("%c",randstr[k][2]);
            printf("%c",randstr[k][3]);
            printf("%c",randstr[k][4]);
            printf("\n");
        }
        
        close(file);
        
        //for writing
        file = open(fifo,O_WRONLY);
     
        sprintf(t_print,"%d",(int)randstr[4][5]);
        
        if(write(file,t_print,strlen(t_print)+1) > 0)
        {
             //printf("Working fine");
             //printf("\n");
             continue;
        }
        
        if(write(file,t_print,strlen(t_print)+1) == -1)
        {
            printf("Highest ID not recorded");
            printf("\n");
        }
        
        close(file);
    }
       
    return 0;
}
