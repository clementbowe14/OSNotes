
typedef struct {
    struct ProcessNode** data;
    int size;
    unsigned capacity;
} heap;

heap create_heap(unsigned capacity);
int is_empty(heap h);
int is_full(heap h);
void min_insert(heap *h, struct ProcessNode* node);
struct ProcessNode *peek(heap* h);
struct ProcessNode* delete(heap *h);
void min_insert(heap *h, struct ProcessNode* node);
void min_percolate_down(heap h, int index);
