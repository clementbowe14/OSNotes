#include <stdio.h>
#include<stdlib.h>
#include <math.h>
#include<time.h>
#define frand() (rand()/(double)RAND_MAX)
#define nrand() (sqrt(-2*log(frand()))*cos(2*M_PI*frand()))
double avg_utilization = 0;
double number_of_examined_holes = 0;
int head = 0;//head of the linked list of holes
int current_hole = 0;
void initialize(int n, int d, int v, int** mem, int**blocks){
    srand(time(NULL));
    int max_blocks = n/(d-v);//why?!
    *mem = (int*)malloc(sizeof(int)*n);
    (*mem)[0] = (*mem)[n-1] = -n+2;
    (*mem)[1] = (*mem)[2] = 0;
    *blocks = (int*)malloc(max_blocks*sizeof(int));
}
int nrand_gen(int d, double v, int n){
    double rv;
    do{
        rv=  nrand() * v + d;//use rand function here
    }while(rv < 3 || rv > n-4);
    return rv;

}
int request(int* blocks, int* block_count, int* mem, int d, double v, int n){
    if(current_hole == -1)//no hole is found!
        return 0;
    int size = nrand_gen(d, v, n); //size of hole
    int iterator = current_hole, pred, succ, new_size, block_address;
    while(size > -mem[iterator]){
        number_of_examined_holes++;
        iterator = mem[iterator + 2];//iterator = iterator->next
        if(head == iterator)
            return 0;//unsuccessful
    }
    if(abs(size+mem[iterator]) <= 4){//fill completely
        //request size is almost equal to the hole size
        size = -mem[iterator];//block fills hole completely
        mem[iterator] = mem[iterator + size + 1] = size;
        //delete the current hole since it is full now
        pred = mem[iterator+1];
        succ = mem[iterator+2];
        if (pred == iterator)//current hole is the only hole
            head = -1;
        else{
            mem[pred+2] = succ;//current->prev->next = current->next
            mem[succ+1] = pred;//current->next->prev = current->prev
            head = mem[succ];
        }
        
        block_address = iterator;
    }else{//fill partially
        mem[iterator] += (size+2);
        //adding pos by neg to make it less negative
        new_size = -mem[iterator];
        mem[iterator + new_size + 1] = mem[iterator];
        //block starts at iterator + new_size + 2
        block_address = iterator + new_size + 2;
        mem[block_address] =
        mem[block_address + size + 1] = size;
        //change current_hole to successor
        current_hole = mem[iterator];
    }
    blocks[*block_count] = block_address;
    (*block_count)++;
    return 1;//successful
}
void release(int* blocks, int* block_count, int* mem, int n){
    if(!*block_count)
        return;
    int to_be_released = rand()%(*block_count);
    printf("releasing block at location (address) %d\n", blocks[to_be_released]);
    //there are four possibilities:
    /* CASE 1: Block is surrounded by two more blocks: create a new hole and add it to the linked-list of holes we keep
     *  track of in the mem array.*/
    int block_address = blocks[to_be_released]; //use this in mem to check neighbors and traverse array looking for next
    // hole, so you can find prev and next
    int block_size = mem[block_address];
    int pre, succ;
    if (head == -1) {
        head = block_address;
    }
    if(block_address-1 > 0 && block_address + block_size + 2 < n && mem[block_address-1] > 0 && mem[block_address + block_size + 2] > 0 ){ //CASE 1 check
        mem[block_address] = mem[block_address+block_size+1] = -block_size;
        int temp_address = (block_address+block_size+2)%n;
        while(mem[temp_address] > 0 && block_address != temp_address) {
            temp_address = (temp_address+mem[temp_address]+2)%n;
        } if(block_address == temp_address) { //no other holes
            mem[block_address+1] = mem[block_address+2] = block_address;
        } else if (mem[temp_address] < 0) { //next nearest hole has been found
            succ = temp_address;
            pre = mem[temp_address+1];

            mem[block_address+1] = pre;
            mem[block_address+2] = succ;

            mem[succ+1] = block_address;
            mem[pre+2] = block_address;
        }
    }/* Case 2: Blocks right neighbor is a hole and left one is a block!: you need to merge the block with the right
     *  neighbor to extend the length of the right neighbor; make sure to reuse the right neighbors pre & succ values.*/
    else if (block_address-1 > 0 && block_address + block_size + 2 < n && mem[block_address-1] > 0 && mem[block_address + block_size + 2] < 0 ){
        int right_address = block_address + mem[block_address] + 2;
        pre = mem[right_address+1];
        succ = mem[right_address+2];

        if(right_address == head) {
            head = block_address;
        }

        mem[block_address] = mem[block_address + block_size + 3 + -mem[right_address]] = -(block_size) + mem[right_address];

        mem[block_address+1] = pre;
        mem[block_address+2] = succ;

        mem[succ + 1] = block_address;
        mem[pre + 2] = block_address;

    }/* Case 3: Blocks left neighbor is a hole and right neighbor is a block!: you need to merge the block with the left
     *  neighbor to extend the length of the left neighbor.*/
    else if (block_address-1 > 0 && block_address + block_size + 2 < n && mem[block_address-1] < 0 && mem[block_address + block_size + 2] > 0 ) {
        int left_address = block_address + mem[block_address - 1] - 2;
        if(left_address)
            mem[left_address] += -mem[block_address];
        mem[block_address + block_size + 1] = mem[left_address];
    }/* Case 4: Blocks left & right neighbors are both holes: then you need to merge the neighbors and the current block
     *  and create a larger hole covering left and right neighbor as well as the current block.*/
    else if (block_address-1 > 0 && block_address + block_size + 2 < n) {
        int left_address = block_address + mem[block_address - 1] - 2;
        int right_address = block_address + mem[block_address] + 2;
        succ = mem[right_address+2]; //pre doesnt change

        if(right_address == head) {
            head = left_address;
        }

        mem[left_address] += mem[right_address] + -block_size;
        mem[right_address + mem[right_address] + 1] = mem[left_address];
        mem[left_address +2] = succ;
        mem[succ + 1] = block_address;
    }
    //remove an integer at index to_be_released from blocks array...
    blocks[to_be_released] = blocks[(*block_count)-1];
    (*block_count)--;
}
void update_memory_utilization(int* blocks, int block_count, int* mem, int n, int x){
    double utilization = 0;
    for(int i = 0;i < block_count;i++)
        utilization += mem[blocks[i]];
    utilization /= n;
    //printf("%f\t",utilization);
    avg_utilization += utilization/x;
}
int main(int argc, char** argv) {
    int x=1000,n=16777216,d=1048576;
    double v=262144;
    //int x,n,d;
    //double v;
    while(*++argv){
        //./main -x 1000 -n 16000000 -d 1000000 -v 256000
        if(**argv != '-')
            return 1;
        switch((*argv)[1]){
            case 'x':
                x = atoi(*++argv);
                break;
            case 'n':
                n = atoi(*++argv);
                break;
            case 'd':
                d = atoi(*++argv);
                break;
            case 'v':
                v = atof(*++argv);
                break;
            default: //error
                return 1;
        }
    }
    int* mem;//the memory
    int* blocks;
    int block_count = 0;
    printf("Running the simulation with x=%d n=%d d=%d v=%.2f\n", x,n,d,v);
    initialize(n, d, v, &mem, &blocks);
    int original_x = x;
    while(x > 0){
        while(request(blocks, &block_count, mem, d, v, n));
        update_memory_utilization(blocks, block_count, mem, n, original_x);
        release(blocks,&block_count,mem, n);
        x--;
    }
    printf("avg utilization is %.3f", avg_utilization);
    printf("num holes examined: %.3f\n", number_of_examined_holes/original_x);
    return 0;
}
