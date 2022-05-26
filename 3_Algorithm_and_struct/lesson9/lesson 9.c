#include <stdio.h>
#include <stdlib.h>
#define SZ 10
#define T int
#define SIZE 1000
#define true 1 == 1
#define false 1 != 1


//////////////////////////////////////////////////////////////////////
///////////////////      Task 1      /////////////////////////////////
//////////////////////////////////////////////////////////////////////
typedef struct
{
    int pr;
    int dat;
} Node;

Node *arr[SZ];
int head;
int tail;
int items;


void initQueue()
{
    for(int i = 0; i < SZ; ++i)
    {
        arr[i] = NULL;
    }
    head = 0;
    tail = 0;
    items = 0;
}

void ins(int pr,int dat)
{
    Node *node = (Node*) malloc(sizeof(Node));
    node -> dat = dat;
    node -> pr = pr;
    if(items == SZ)
    {
        printf("%s\n","Queue is full");
        return;
    }
    if(tail==SZ)
    {
        tail = 0;
    }
        arr[tail] = node;
        items++;
        tail++;

}

Node* rem()
{
    if (items == 0)
    {
        printf("%s\n","Queue is emty");
        return NULL;
    }
    int idx = head++ % SZ;
    for(int i = 0; i < SZ; i++)
    {
        if(arr[i] == NULL)
            continue;
        if(arr[i] -> pr > arr[idx] -> pr)
        {
            idx = i;
        }
    }
    Node *tmp1 = arr[idx];
    Node *tmp2;
    arr[idx] = NULL;
    items--;
    for(int j = idx; j>0; j--)
    {
            tmp2  = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = tmp2;
    }
    return tmp1;
}

void printQueue() {
    printf("[ ");
    for (int i = 0; i < SZ; ++i) {
        if (arr[i] == NULL)
            printf("[*, *] ");
        else
            printf("[%d, %d] ", arr[i]->pr, arr[i]->dat);
    }
    printf(" ]\n");
}
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////
///////////////////      Task 2      /////////////////////////////////
//////////////////////////////////////////////////////////////////////
typedef int boolean;
int cursor = -1;
T Stack[SIZE];

boolean pushStack(T data)
{
    if (cursor < SIZE)
    {
        Stack[++cursor] = data;
        return true;
    }
    else
    {
        printf("%s \n", "Stack overflow");
        return false;
    }
}

T popStack() {
    if (cursor != -1) {
        return Stack[cursor--];
    } else {
        printf("%s \n", "Stack is empty");
        return -1;
    }
}

void convToBinary(int num)
{
    while(num!=0)
    {
        pushStack(num%2);
        num/=2;
    }
    while(cursor != -1)
    {
        printf("%d ",popStack());
    }
}

int main()
{

///// Task 1 /////
//////////////////
    initQueue();
    ins(8,10);
    ins(5,2);
    ins(4,3);
    ins(9,4);
    ins(2,5);
    ins(6,51);
    ins(7,75);
    ins(3,13);
    ins(1,11);
    ins(2,1);
    printQueue();
    rem();
    rem();
    rem();
    rem();
    printQueue();
//////////////////


///// Task 2 /////
//////////////////
    printf("\n");
    convToBinary(1856);
//////////////////


    return 0;
}
