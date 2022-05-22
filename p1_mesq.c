#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <sys/wait.h>

struct mesg_buffer {
    long mesg_type;
    char mesg_text[5][7];
} obm,obr;

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
    
    int counter=0;
    while(counter<50)
    {
        
        for(int k=0; k<5; k++)
        {  
            strcpy(obm.mesg_text[k],randstr[counter++]);
        }
    }
    
    return 0;
}
