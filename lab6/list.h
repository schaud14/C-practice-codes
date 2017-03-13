#define EMPTY 0
struct Data{
int data;
};

struct Vector{
struct Data * list;
unsigned int current_size;
unsigned int maximum_size;
};


struct Node{
struct Data * data_ptr;
struct Node * next;
struct Node * previous;
};

struct List{
struct Node * head;
};


struct Stack
{
	struct List * list;
};

struct Queue
{
	struct List * list;
};


struct Vector * createVector();
void vectorInsertInc(struct Vector * , int , struct Data );
void vectorInsertGeo(struct Vector * , int , struct Data );
void vectorRemove(struct Vector * , int );
int vectorRead(struct Vector * , int );
void displayVector(struct Vector * );

struct List * newList();
struct Node * newNode(struct Data * );
void listInsert( struct List * , struct Data *  );
int listIndexinsert( struct List * , int , struct Data *  );
void display_list( struct List *   );
void display_listb( struct List *   );
int listIndexDelete( struct List * , int  );
void deleteList(struct List * );
void deleteList1(struct List * );
struct Node * headnode( struct List *  );
int searchForward( struct List * , int  );
int searchBackward( struct List * , int  );

void push( struct Stack * , struct Data *  );
int pop( struct Stack *  );
void enqueue( struct Queue * , struct Data *  );
int dequeue( struct Queue *  );





