#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define true 1 == 1
#define false 1 != 1
typedef int boolean;
int levelMin;
int levelMax;
int count=0;

typedef struct Node
{
    int key;
    struct Node* left;
    struct Node* right;
}TreeNode;

TreeNode* treeInsert(TreeNode *t, int data)
{
    TreeNode *newNode;
    newNode = (TreeNode*) malloc(sizeof(TreeNode));
    newNode -> key = data;
    newNode -> left = NULL;
    newNode -> right = NULL;
    TreeNode *current = t;
    TreeNode *parent = t;
    if(t == NULL)
    {
        t = newNode;
    }
    else
    {
        while(current -> key != data)
        {
            parent = current;
            if(current -> key > data)
            {
                current = current -> left;
                if(current -> key ==NULL)
                {
                    parent -> left = newNode;
                    return t;
                }
            }
            else
            {
                current = current -> right;
                if(current == NULL)
                {
                    parent -> right = newNode;
                    return t;
                }
            }
        }
    }
    return t;
}

void printTree(TreeNode *t)
{
    if(t)
    {
        printf("%d",t -> key);
        if(t -> right || t ->left)
        {
            printf("(");
            if(t -> left)
                printTree(t -> left);
            else
                printf("NULL");
            printf(",");
            if(t -> right)
                printTree(t -> right);
            else
                printf("NULL");
            printf(")");
        }
    }
}


void bypassTree(TreeNode *tree) {
    if (tree)
    {
        count++;
        bypassTree(tree->left);
        bypassTree(tree->right);
    }
    else
    {
        if(count > levelMax)
            levelMax = count;
        if(count < levelMin)
            levelMin = count;
        count = 0;
    }
}
///////////////////////////////////////////////////////
/////////////////// Task 1 ////////////////////////////
///////////////////////////////////////////////////////
boolean checkBalanceTree(TreeNode *t)
{
    TreeNode *newNode;
    newNode = (TreeNode*) malloc(sizeof(TreeNode));
    TreeNode *current = t;
    TreeNode *parent = t;

    if(t == NULL)
    {
        return false;
    }
    while(current -> left != NULL)
    {
        current = current -> left;
        levelMax++;
        levelMin++;
    }
    bypassTree(t);
    if(levelMax-levelMin >= 1)
        return true;
    else
        return false;
}


void fillGarden(TreeNode *g, const int SIZE, const int lenght)
{
    for(int i=0; i < SIZE; i++)
    {
        for(int j=0; j < lenght; j++)
        treeInsert(&g[i], rand()%10+5);
    }
}

void printGarden(TreeNode *g, const int SIZE)
{
    for(int i=0;i<SIZE;i++)
    {
        printTree(&g[i]);
        printf("\n");
    }
}
///////////////////////////////////////////////////////


///////////////////////////////////////////////////////
/////////////////// Task 2 ////////////////////////////
///////////////////////////////////////////////////////

boolean recBinSearch(TreeNode *t, int value)
{
    if (t)
    {
        recBinSearch(t->left, value);
        if(t->key == value)
            return true;
        recBinSearch(t->right, value);
    }
        return false;

}
///////////////////////////////////////////////////////

int main(const int argc, const char **argv)
{
    srand(time(0));
    const int SIZE = 50;
    const int lenghtBranch = 1000;
    int balancePercent = 0;
    TreeNode* garden = (TreeNode*) calloc(sizeof(TreeNode), SIZE);
    fillGarden(garden, SIZE, lenghtBranch);
    for(int i=0;i<SIZE;i++)
    {
        if(checkBalanceTree(&garden[i]) == true)
        {
            balancePercent++;
        }
    }
    if(balancePercent == 0)
        printf("\nAll trees are not balanced\n");
    else
        balancePercent /= SIZE;
        printf("%d percent of the trees are balanced", balancePercent);

//////////////////////////////////////////////////////////////////////////////
    TreeNode *tree = treeInsert(tree, 10);
    treeInsert(tree, 5);
    treeInsert(tree, 12);
    treeInsert(tree, 7);
    treeInsert(tree, 1);
    treeInsert(tree, 2);
    if(recBinSearch(tree, 7))
    {
        printf("Element is present in tree\n");
    }
    else
        printf("Element is absent\n");


    return 0;
}
