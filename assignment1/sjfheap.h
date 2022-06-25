
typedef struct {
    struct ProcessNode** data;
    int size;
    unsigned capacity;
} sjfheap;

sjfheap create_heap(unsigned capacity);
int is_empty(sjfheap h);
int is_full(sjfheap h);
void min_insert(sjfheap *h, struct ProcessNode* node);
struct ProcessNode *peek(sjfheap* h);
struct ProcessNode* delete(sjfheap *h);
void min_insert(sjfheap *h, struct ProcessNode* node);
void min_percolate_down(sjfheap h, int index);
void printSrtHeap(sjfheap h);