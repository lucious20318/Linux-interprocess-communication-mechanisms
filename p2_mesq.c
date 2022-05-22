#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <sys/wait.h>

struct mesg_buffer 
{
    long mesg_type;
    char mesg_text[5][7];
} obm,obr;

int main()
{
    int mesf=ftok("mpq",12);
    obr.mesg_type=1;
    int get_id;
    
    for(int i=0;i<10;i++)
    {
        get_id=msgget(mesf, 0666 | IPC_CREAT);
        
        if(msgrcv(get_id,&obm,sizeof(obm),1,0) > 0)
        {
            printf("Working fine");
            printf("\n");
            continue;
        }
        
        if(msgrcv(get_id,&obm,sizeof(obm),1,0) == -1)
        {
            printf("string[5] not found");
            printf("\n");
            i--;
            continue;
        }
        
        
        for(int k=0; k<5; k++)
        {
            printf("%d:%c",obm.mesg_text[k][5]);
            printf("%c",obm.mesg_text[k][0]);
            printf("%c",obm.mesg_text[k][1]);
            printf("%c",obm.mesg_text[k][2]);
            printf("%c",obm.mesg_text[k][3]);
            printf("%c",obm.mesg_text[k][4]);
            printf("\n");
        }
        
        printf("\n");
        sprintf(obr.mesg_text[0],"%d",(int)obm.mesg_text[4][5]);
        
        if(msgsnd(get_id,&obr,sizeof(obr),0) > 0)
        {
            printf("Working fine");
            printf("\n");
            continue;
        }
        
        if(msgsnd(get_id,&obr,sizeof(obr),0) == -1)
        {
            printf("error: wasn't able to send highest index");
            i--;
            continue;
        }
        
        msgctl(get_id,IPC_RMID,NULL);
    }
    
    return 0;
}
