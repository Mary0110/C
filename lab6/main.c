#include <stdlib.h>
#include <stdio.h>
#include "main.h"
#include <time.h>

int main(void)
{
    int j, data;
    char buffer[128];
    tnode* root = NULL;
    tnode* rootNew = NULL;
    srand(time(NULL));

    for(j = 0; j < 10; j++)
    {
        data = rand() % 201 - 100;        
        AddNode(data, &root);
    }

    AddToSearchTree(root, AddSearchNode, &rootNew);
    printTree(rootNew);
    return 0;
}

void AddToSearchTree(tnode* node, void (*AddSearchNode)(int, tnode**), tnode** root)
{
    if (node != NULL)
    {
        AddSearchNode(node->data, root);
        AddToSearchTree(node->left, AddSearchNode, root);
        AddToSearchTree(node->right, AddSearchNode, root);
    }
}

void printTree(tnode* node)
{
    if (node != NULL)
    {
        printTree(node->left);
        printf("%d ", node->data);
        printTree(node->right);
    }
}

void AddSearchNode(int data, tnode** root)
{
    if (*root == NULL)
    {
        *root = (tnode*)calloc(1, sizeof(tnode));
        if (*root)
        {
            (*root)->data = data;
            (*root)->left = (*root)->right = NULL;
        }
    }
    else
    {
        if (data < (*root)->data)
            AddSearchNode(data, &((*root)->left));
        else if (data > (*root)->data)
            AddSearchNode(data, &((*root)->right));
    }
}

void AddNode(int data, tnode** node)
{
    int i;

    if (*node == NULL)
    {
        *node = (tnode*)calloc(1, sizeof(tnode));
        if (*node)
        {
            (*node)->data = data;
            (*node)->left = (*node)->right = NULL;
        }
    }
    else
    {
        i = rand() % 2;
        if (i == 0)
            AddNode(data, &((*node)->left));
        else if (i == 1)
            AddNode(data, &((*node)->right));
    }
}