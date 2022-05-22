#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/wait.h>
#include <unistd.h>
#define PORT 3490

int main()
{

    struct sockaddr_in adr;

    int count =0;
    int adr_size = sizeof(adr);
    
    int so_id;
    int p2s;
    
    if ((so_id = socket(PF_INET, SOCK_STREAM, 0)) == 0) 
    {
        count = 1;
    }
    
    if(count != 0)
    {
    	return -1;
    }
    
    
    int ch = 1;
    if (setsockopt(so_id, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,&ch, sizeof(ch))) 
    {
        count = 1;
        return -1;
    }
    
    if(count != 0)
    {
        printf("Error occurred in setsockopt");
    }
    
    
    adr.sin_family = AF_INET;
    adr.sin_addr.s_addr = INADDR_ANY;
    adr.sin_port = htons( PORT );
    
    count = 0;
    
    /*if (bind(so_id, (struct sockaddr *)&adr, sizeof(adr))>0) 
    {
        printf("Binding..");
        count = 0;
    }*/
    
    if (bind(so_id, (struct sockaddr *)&adr, sizeof(adr)) == -1) 
    {
        count = 1;
    }
    
    if(count != 0)
    {
        printf("Error occurred in bind");
    	return -1;
    }
    
    if (listen(so_id, 10) == -1) 
    {
        count = 1;
        printf("Error occurred in listen");
        return -1;
    }
    
    if(count != 0)
    {
        printf("Error occurred in listen");
    }
    
    if ((p2s = accept(so_id, (struct sockaddr *)&adr, (socklen_t*)&adr_size)) == -1) 
    {
        printf("Connection not established");
        count = 1;
        return -1;
    }
    
    if(count != 0)
    {
    	printf("\n");
    }
    
    for(int i=0;i<10;i++)
    {
        char t_print[3];
        char randstr[5][7];
        
        if(read(p2s,randstr,sizeof(randstr)) == -1)
        {
            printf("string[5] not recived");
            //continue;
        }
        
        int c =1;
        for(int k=0; k<5; k++)
        {
            c = 0;
            printf("%d : %c",randstr[k][5]);
            c++;
            printf("%c",randstr[k][0]);
            printf("%c",randstr[k][1]);
            printf("%c",randstr[k][2]);
            printf("%c",randstr[k][3]);
            printf("%c",randstr[k][4]);
            printf("\n");
        }
        
	sprintf(t_print,"%d",(int)randstr[4][5]);
	
	/*if(write(p2_soc,t_print,strlen(t_print)+1) > 0)
        {
        	printf("Working fine");
        	printf("\n");
        }*/
        sleep(0);
        
        if(write(p2s,t_print,strlen(t_print)+1) == -1)
        {
            printf("Highest ID not recieved");
        }
    }
    
    close(so_id);
    close(p2s);
    return 0;
}
