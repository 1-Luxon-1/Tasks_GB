#include <stdio.h>
#include <stdlib.h>
#define true 1==1
#define false 1!=1
#define T char
typedef int boolean;

typedef struct
{
    int data;
    int key;
} KeyNode;

////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
KeyNode** hashTable;
int hashTableSize;

KeyNode *nullItem;
boolean insertNode(int data);

int hashFunc(int key)
{
    return key % hashTableSize;
}

KeyNode* createNode(int data)
{
    KeyNode *p = (KeyNode*) malloc(sizeof(KeyNode));
    if (!p)
    {
        printf("Out of memory \n");
        return NULL;
    }
    p->data = data;
    p->key = data;
    return p;
}

void initTable(int size, int idx)
{
    for (int i = idx; i < size; ++i)
    {
        hashTable[i] = NULL;
    }
}

boolean isFull()
{
    for (int i = 0; i < hashTableSize; ++i)
    {
        if (hashTable[i] == NULL || hashTable[i] == nullItem)
            return false;
    }
    return true;
}

void increaseCapacity()
{
    hashTableSize *= 2;
    KeyNode** oldHashTable = hashTable;
    hashTable = (KeyNode**) calloc(hashTableSize, sizeof(KeyNode*));
    int i;
    for (i = 0; i < hashTableSize / 2; ++i)
        insertNode(oldHashTable[i]->data);
    initTable(hashTableSize, i);
    free(oldHashTable);
}


int hashFuncDbl(int key)
{
    return 19 - key % 19;
}

boolean insertNode(int data)
{
    KeyNode *node = createNode(data);
    if (!node) return false;

    int hashVal = hashFunc(node->key);
    if (isFull()) increaseCapacity();
    int step = hashFuncDbl(node->key);
    while (hashTable[hashVal] && hashTable[hashVal] != nullItem)
    {
        hashVal += step;
        hashVal %= hashTableSize;
    }
    hashTable[hashVal] = node;
    return true;
}

KeyNode* findNode(int data)
{
    int key = data;
    int hashVal = hashFunc(key);
    int step = hashFuncDbl(key);
    while (hashTable[hashVal])
    {
        if (hashTable[hashVal]->key == key)
        {
            return hashTable[hashVal];
        }
        hashVal += step;
        hashVal %= hashTableSize;
    }
    return NULL;
}

KeyNode* deleteNode(int data)
{
    int key = data;
    int hashVal = hashFunc(key);
    int step = hashFuncDbl(key);
    while (hashTable[hashVal])
    {
        if (hashTable[hashVal]->key == key)
        {
            KeyNode *temp = hashTable[hashVal];
            hashTable[hashVal] = nullItem;
            return temp;
        }
        hashVal += step;
        hashVal %= hashTableSize;
    }
    return NULL;
}

void prntNode(KeyNode *n)
{
    if (!n)
    {
        printf("[*,*] ");
        return;
    }
    printf("[k=%d,d=%d] ", n->key, n->data);
}

void prntTbl() {
    for (int i = 0; i < hashTableSize; ++i)
    {
        prntNode(hashTable[i]);
    }
    printf("\n");
}

void zeroArray(int *array, const int SZ)
{
    for(int i = 0; i < SZ; i++)
    {
        array[i]=0;
    }
}

void printArray(int *array, const int SZ)
{
    int i = 0;
    while(array[i] != 0 && i < SZ)
    {
        printf("%d ", array[i]);
        i++;
    }
}
////////////////////////////////////////////////////////////////////////
///////////////////////// Task 1 ///////////////////////////////////////
////////////////////////////////////////////////////////////////////////
boolean insertNodeStr(char *str)
{

    int data = 0;
    int i=0;
    while(str[i]!= '\0')
    {
        if(data==0)
        {
            data = (int)str[i];
        }
        else
        if((int)str[i]/100 > 0)
        {
            data*=1000;
            data+=(int)str[i];
        }
        else
            if((int)str[i]/10 > 0)
            {
                data*=100;
                data+=(int)str[i];

            }
        else
            {
                data*=10;
                data+=(int)str[i];
            }
        i++;
    }


    KeyNode *node = createNode(data);
    if (!node) return false;

    int hashVal = hashFunc(node->key);
    if (isFull()) increaseCapacity();
    int step = hashFuncDbl(node->key);
    while (hashTable[hashVal] && hashTable[hashVal] != nullItem)
    {
        hashVal += step;
        hashVal %= hashTableSize;
    }
    hashTable[hashVal] = node;
    return true;
}


boolean insertSummNodeStr(char *str)
{

    int data = 0;
    int i=0;
    while(str[i]!= '\0')
    {
        if(data==0)
        {
            data = (int)str[i];
        }
        else
            data+=(int)str[i];
        i++;
    }


    KeyNode *node = createNode(data);
    if (!node) return false;

    int hashVal = hashFunc(node->key);
    if (isFull()) increaseCapacity();
    int step = hashFuncDbl(node->key);
    while (hashTable[hashVal] && hashTable[hashVal] != nullItem)
    {
        hashVal += step;
        hashVal %= hashTableSize;
    }
    hashTable[hashVal] = node;
    return true;
}
////////////////////////////////////////////////////////////////////////
///////////////////////// Task 2 ///////////////////////////////////////
////////////////////////////////////////////////////////////////////////
void summ98(int *money, int *seq)
{
    int sum = 0;
    int i = 0;
    int j = 0;
    while(sum != 98)
    {
        if(sum < 98)
        {
            sum += money[i];
            seq[j] = money[i];
            j++;
        }
        else
        {
            sum-=money[i];
            seq[j]=0;
            j--;
            i++;
        }
    }
}

////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
int main()
{
//////////// Task 1 /////////////////////////////////////
    hashTableSize = 25;
    hashTable = (KeyNode**) calloc(hashTableSize, sizeof(KeyNode*));
    nullItem = createNode(-1);

    insertNodeStr("abcd");
    insertSummNodeStr("abc");
    insertNode(150);
    insertNode(10);
    insertNode(20);
    insertNode(30);

    prntTbl();
    printf("\n");

//////////// Task 2 /////////////////////////////////////
    const int SIZE = 20;
    int money[]={50, 10, 5, 2, 1};
    int seq[SIZE];
    zeroArray(seq, SIZE);
    summ98(money, seq);
    printArray(seq, SIZE);

    return 0;
}
