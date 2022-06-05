#include <stdio.h>
#include <stdlib.h>
#define n 6
#define SIZE 1000
#define true 1 == 1
#define false 1 != 1

typedef int boolean;
int cursor = -1;
int Stack[SIZE];

boolean pushStack(int data) {
    if (cursor < SIZE) {
        Stack[++cursor] = data;
        return true;
    } else {
        printf("%s \n", "Stack overflow");
        return false;
    }
}

int popStack() {
    if (cursor != -1) {
        return Stack[cursor--];
    } else {
        printf("%s \n", "Stack is empty");
        return -1;
    }
}

int matrix[n][n] = {
        {0, 1, 1, 0, 0, 0},
        {0, 0, 0, 1, 1, 1},
        {0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0},
};
int visitedDepth[n] = {0};

void stackDepthTravers(int st)
{
    visitedDepth[st] = 1;
    pushStack(st);
    int i = st;
    while(i != n*n)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 1 && !visitedDepth[j])
            {
                pushStack(j);
                visitedDepth[j] = 1;
                i = j-1;
                continue;
            }
        }
        i++;
    }

    while(cursor != -1)
    {
        printf("%d ",popStack());
    }
}


void resetArr()
{
    for (int i = 0; i < n; ++i)
    {
        visitedDepth[i] = 0;
    }
}


int main()
{
    stackDepthTravers(0);
    resetArr();
    printf("\n");
    stackDepthTravers(2);
    resetArr();
    return 0;
}
