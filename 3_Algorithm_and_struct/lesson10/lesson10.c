#include <stdio.h>
#include <stdlib.h>
#define T char
#define true 1 == 1
#define false 1 != 1
typedef int boolean;

typedef struct OneLinkNode
{
    T dat;
    struct OneLinkNode *next;
} OneLinkNode;

typedef struct
{
    OneLinkNode *head;
    int size;
} OneLinkList;


///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////
void initOneLinkList(OneLinkList *lst)
{
    lst->head = NULL;
    lst->size = 0;
}

void insert(OneLinkList *lst, T data)
{
    OneLinkNode *new = (OneLinkNode*) malloc(sizeof(OneLinkNode));
    new->dat = data;
    new->next = NULL;

    OneLinkNode *current = lst->head;
    if (current == NULL)
    {
        lst->head = new;
        lst->size++;
    } else
    {
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = new;
        lst->size++;
    }
}

OneLinkNode* rm(OneLinkList *lst, T data) {
    OneLinkNode *current = lst->head;
    OneLinkNode *parent = NULL;
    if (current == NULL)
        return NULL;

    while (current->next != NULL && current->dat != data) {
        parent = current;
        current = current->next;
    }
    if (current->dat != data) {
        return NULL;
    }
    if (current == lst->head) {
        lst->head = current->next;
        lst->size--;
        return current;
    }
    parent->next = current->next;
    lst->size--;
    return current;
}

void printOneLinkIntNode(OneLinkNode *n)
{
    if (n == NULL)
    {
        printf("[]");
        return;
    }
    printf("[%c]", n->dat);
}

void printOneLinkIntList(OneLinkList *lst)
{
    OneLinkNode *current = lst->head;
    if (current == NULL)
    {
        printOneLinkIntNode(current);
    } else
    {
        do
        {
            printOneLinkIntNode(current);
            current = current->next;
        } while (current != NULL);
    }
    printf(" Size: %d \n", lst->size);
}
///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////

boolean seqBrackets(OneLinkList *lst)
{
    OneLinkNode *current = lst->head;
    int openBrac = 0;
    int closeBrac = 0;
    int arrBrackets[6];
    for(int i = 0; i < 6; i++)
    {
        arrBrackets[i]=0;
    }

    if(current == NULL)
    {
        return -1;
    }
    while(current != NULL)
    {
        if(closeBrac == 1 && openBrac == 0)
        {
            return false;
        }

        switch (current -> dat)
        {
            case '(':
                arrBrackets[0]++;
                current = current -> next;
                break;
            case ')':
                arrBrackets[1]++;
                current = current -> next;
                break;
            case '[':
                arrBrackets[2]++;
                current = current -> next;
                break;
            case ']':
                arrBrackets[3]++;
                current = current -> next;
                break;
            case '{':
                arrBrackets[4]++;
                current = current -> next;
                break;
            case '}':
                arrBrackets[5]++;
                current = current -> next;
                break;
            default:
                current = current -> next;
        }
    }
    if(arrBrackets[0] == arrBrackets[1] && arrBrackets[2] == arrBrackets[3] && arrBrackets[4] == arrBrackets[5])
        return true;
    else
        return false;
}


void copyOneList(OneLinkList *lst, OneLinkList *cplst)
{
    OneLinkNode *currentLst = lst->head;
    OneLinkNode *currentCpLst = cplst->head;

    while(currentLst != NULL)
    {
        currentCpLst -> dat = currentLst->dat;
        currentLst = currentLst -> next;
        currentCpLst = currentCpLst -> next;
    }

}


int main()
{
//////////////// Task 1 ////////////////////////////////////////////////////
    OneLinkList* lst = (OneLinkList*) malloc(sizeof(OneLinkList));
    initOneLinkList(lst);
    printOneLinkIntList(lst);
    insert(lst, '(');
    insert(lst, '5');
    insert(lst, ')');
    printOneLinkIntList(lst);
    if(seqBrackets(lst)==true)
       {
           printf("%s\n","The sequence of brackets is correct");
       }
       else
        printf("%s\n","The sequence of brackets is not correct");

    rm(lst, '[');
    rm(lst, '}');
    insert(lst, ')');
    insert(lst, '2');
    insert(lst, '*');
    insert(lst, '3');
    insert(lst, '(');
    insert(lst, '=');
    printOneLinkIntList(lst);
    if(seqBrackets(lst)==true)
       {
           printf("%s\n","The sequence of brackets is correct");
       }
       else
        printf("%s\n","The sequence of brackets is not correct");
////////////////////////////////////////////////////////////////////////////


//////////////// Task 2 ////////////////////////////////////////////////////
    OneLinkList* lst2 = (OneLinkList*) malloc(sizeof(OneLinkList));
    initOneLinkList(lst2);
    copyOneList(lst, lst2);
    printOneLinkIntList(lst);
    printOneLinkIntList(lst2);
    return 0;
}
