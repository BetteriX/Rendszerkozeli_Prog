#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct Queue
{
    int data;
    struct Queue *nextdata;
} Queue;

Queue *create_queue(int data)
{

    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->data = data;
    q->nextdata = NULL;
    return q;
}

Queue *insert_queue(Queue *q, int d)
{

    if (q == NULL)
    {
        return create_queue(d);
    }

    q->nextdata = insert_queue(q->nextdata, d);

    return q;
}

void queue_free(Queue *q)
{
    if (q != NULL)
    {
        queue_free(q->nextdata);
        free(q);
    }
}

int main(int argc, char const argv[])
{
    int size = 10;
    int count = 1;

    Queue *root = NULL;

    root = insert_queue(root, 1);
    printf("%d\n", root->data);

    root = insert_queue(root, 2);
    printf("%d\n", root->nextdata->data);

    queue_free(root);
    return 0;
}