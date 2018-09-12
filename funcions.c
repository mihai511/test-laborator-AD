#include <stdio.h>
#include "functions.h"
#include <stdlib.h>

struct min_heap{
    int index;
    int data;
    struct min_heap* left;
    struct min_heap* right;
};

struct min_heap* min_heap_tree(struct min_heap* root, int arr[], int i, int n){
    if(i < n){
        struct min_heap* new_node = (struct min_heap*)malloc(sizeof(struct min_heap));
        new_node->index = i;
        new_node->data = arr[i];
        new_node->left = NULL;
        new_node->right = NULL;

        root = new_node;

        root->left = min_heap_tree(root->left, arr, 2 * i + 1, n);

        root->right = min_heap_tree(root->right, arr, 2 * i + 2, n);
    }

    return root;
}

void ordering_array(int arr[], int i, int n){
    int j;
    int aux = arr[i];

    j = 2 * i;

    while(j <= n){
        if( (j < n) && (arr[j + 1] < arr[j]) )
            j++;

        if (aux < arr[j])
            break;
        else{
            arr[j/2] = arr[j];
            j = 2 * j;
        }
    }

    arr[j/2] = aux;

    return;
}

void create_min_heap_array(int arr[], int n){
    int i;

    for(i = n/2; i >= 1; i--){
        ordering_array(arr, i, n);
    }
}

void search_min_heap(struct min_heap *root, int searched_value, int *found){
    if ( (root != NULL) && (root->data == searched_value) ){
        (*found) = 1;
        return;
    }else{
        if(root->left != NULL)
            search_min_heap(root->left, searched_value, found);
        if(root->right != NULL)
            search_min_heap(root->right, searched_value, found);
    }
}
