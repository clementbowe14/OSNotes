
typedef struct {
    struct ProcessNode** data;
    int size;
    unsigned capacity;
} srtheap;

srtheap create_heap(unsigned capacity);
int is_empty(srtheap h);
int is_full(srtheap h);
void min_insert(srtheap *h, struct ProcessNode* node);
struct ProcessNode *peek(srtheap* h);
struct ProcessNode* delete(srtheap *h);
void min_insert(srtheap *h, struct ProcessNode* node);
void min_percolate_down(srtheap h, int index);
void printSrtHeap(srtheap h);