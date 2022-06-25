#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <sys/wait.h>
char* itoa(int i){
    if(i <= 0)
        return "0";
    int digit = 1+floor(log10(i));
    char*out = (char*) malloc(digit+1);
    out[digit] = '\0';
    while(i){
        out[--digit] = i%10 + '0';
        i /= 10;
    }
    return out;
}
int nk[4][2] = {{100,1000 },{500,10000},{500,5000},{1000,10000}};
int main(){
    int i;
    pid_t pid;
    for(int i = 0; i < 4;i++){
        int kn = nk[i][1]/nk[i][0];
        for(int d = kn; d <= 25 * kn; d+= kn){
            if ((pid = fork()) == -1){
                        perror("fork error");
                break;
            }
            if(!pid){
                printf("running FIFO simulator with (n, k, d) = (%d, %d, %d)\n", nk[i][0], nk[i][1], d);
                execl("PA1FiFo/fifo", "PA1FiFo/fifo", "-n", itoa(nk[i][0]), "-k", itoa(nk[i][1]), "-d", itoa(d), NULL);
            }
            else 
                wait(NULL);
        }    
    }
    return 0;
}