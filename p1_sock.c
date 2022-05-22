#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <sys/wait.h>
#include <unistd.h>
#include <arpa/inet.h>
#define PORT 3490

void create(char randstr[50][7])
{
    char rando_s[50][7];
    sleep(0);
    
    for(int i=0;i<50;i++)
    {
        for(int j=0;j<6;j++)
        {
            int l = 0;
            randstr[i][j]= rand()% 26 + 97;
            
            for(int k = 0; k<50; k++)
            {
            	for(l = 1; l<7;l++)
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
    
    int s=0;
    sleep(0);
    struct sockaddr_in serv_addr;
    
    /*if ((sock = socket(PF_INET, SOCK_STREAM, 0)) > 0)
    {
    	printf("Working fine");
    	printf("\n");
    }*/
    
    if ((s = socket(PF_INET, SOCK_STREAM, 0)) < 0) 
    {    
        printf("Error....exiting"); 
        printf("\n");
        return -1;
    }
    
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    
    int l =0;
    
    //Artix crashed during Q1 so doing this on a different linux with Address - 127.0.0.1
    
    /*if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) > 0)
    {
    	printf("Working fine");
    	printf("\n");
    }*/
     
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) 
    {
        printf("Error occured......Wrong ADDRESS");
        printf("\n");
        l = 35*sizeof(char);
    }
    
    if(l !=0)
    {
      
      return -1;
    }
    
    /*if (connect(s, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) > 0)
    {
    	printf("Working fine");
    	printf("\n");
    } */
    
    if (connect(s, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) 
    {
        printf("Error occured......problem in connnecting");
        printf("\n");
        return -1;
    }
    
    int counter = 0;
    
    while(counter < 50) 
    {
        char str_arr[5][7];
        char t_print[3];
        
        for(int k = 0; k<5; k++)
        {
            strcpy(str_arr[k],randstr[counter++]);
        }
        
        if(write(s,&str_arr, 35 * sizeof(char)) == -1)
        {
            counter = counter-5;
            printf("Problem in message queue");
            printf("\n");            
            continue;
        }
        
        
        
        /*if(read(sock,t_print,3)>0)
        {
            //no error encountered
        }*/
        
        if(read(s,t_print,3) == -1)
        {
            printf("Couldn't read highest index");
            printf("\n");
            continue;
        }
        
        printf("Highest ID : %s\n",t_print);
    }
    
    close(s);
    return 0;
}
