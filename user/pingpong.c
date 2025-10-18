#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int pingpong(void){
    int p1[2];
    pipe(p1);
    int p2[2];
    pipe(p2);
    char buffer;
    if(fork() == 0){
        int pid = getpid();
        read(p1[0], &buffer , 1);
        printf("%d : received ping\n" , pid);
        write(p2[1], &buffer , 1);
        exit(0);
    }
    else{
        int pid = getpid();
        write(p1[1],&buffer,1);
        read(p2[0],&buffer, 1);
        printf("%d : receive pong\n",pid);
        exit(0);
        
    }
}