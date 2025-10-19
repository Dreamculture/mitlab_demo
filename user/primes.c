#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

void primes(void){
    int p[2];
    pipe(p);
    if(fork() == 0){
        int buf;
        close(0);
        dup(p[0]);
        close(p[0]); 
        for(int i = 2; i <= 35; i++){
        read(0, &buf , 4);  
        int n = buf % 2;
        if(n != 0){
        }
        exit(0);
    }      
    }
    else{
        close(1);
        dup(p[1]);
        close(p[1]);
        for (int i = 2 ; i <= 35 ; i ++){
            int data = i;
        write(1, &data , 4);
        }
        exit(0);
    }
}