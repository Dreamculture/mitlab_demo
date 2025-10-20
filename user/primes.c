#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

/*void primes(void) {
    int p[2];
    pipe(p);
    if(fork() == 0) {
        // Child reads numbers
        close(p[1]);       // close write end
        int buf;
        for (int i = 2; i <= 35; i++) {
            read(p[0], &buf, 4);
            printf("the number is %d\n", buf);
        }
        close(p[0]);
        exit(0);
    } else {
        // Parent writes numbers
        close(p[0]);       // close read end
        for (int i = 2; i <= 35; i++) {
            write(p[1], &i, 4);
        }
        close(p[1]);
        wait(0);
        exit(0);
    }
}
*/

int onceprimes(int* array , int n  ){ 
    int a = array[0];
    printf("prime %d\n",a);    
    int p[2];
    pipe(p);   
    int np[2]  ;
    pipe (np);
    if(fork() == 0){
        int buf;
        int counter = 0;
        for(int i = 0; i < n ; i++){
            read(p[0] , &buf , 4);
            if(buf % a != 0){
                array[counter] = buf;
                counter ++;
                printf("the number in order is %d\n", array[counter]);
            }                    
        }   
         /*    
        int b = counter;
        write(np[1], &b , 4);
        printf("send the %d\n",counter);
        exit(0);
        */
        close(p[0]);
        close(p[1]); 
        return counter;        
             
        
    }
    else{
        int buf;
        int c;
        for(int i = 0 ; i < n ; i++){                        
            buf = array[i] ;
            write(p[1], &buf ,4);
        }   
        
        /*         
        close(p[0]);
        close(p[1]);
        */
        wait(0);
        exit(0);
        read(np[0], &c , 4);
        printf("received the %d\n",c);
        return c;
    } 
}



int main(void){
 /*   printf("for test1\n");   */

    int rn = 30;
    int array[32];
    for(int i = 0; i < rn ; i++){
        array[i] = i+2 ;    
        //printf("the array[%d] is %d\n",i , i)   ;
    }   
    while(rn >= 1){
    rn= onceprimes(array , rn);
    //printf("the return number is %d\n",rn);
}
    
    exit(0);
}
    
