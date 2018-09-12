#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

struct min_heap{
    int index;
    int data;
    struct min_heap* left;
    struct min_heap* right;
};

int main(){
    int n;
    int i;
    int x;
    int found = 0;
    int arr[100];

    printf("Introduceti numarul de elemente:\n");
    scanf("%d", &n);
    printf("Introduceti elementele:\n");

    for(i = 1; i <= n; i++){
        scanf("%d", &arr[i]);
    }

    create_min_heap_array(arr, n);

    struct min_heap* root = min_heap_tree(root, arr, 0, n);

    printf("Min heap-ul va fii:\n\n\n");
    printf("Parinte:    ");

    for(i = 1; i <= n; i++){
        printf("%d   ", arr[i]);
    }

    printf("\n");
    printf("Fiu stang:  ");

    for(i=1; i<=n; i++)
        if(2 * i <= n)
            printf("%d   ", arr[2 * i]);
        else
            printf(" -   ");

    printf("\n");
    printf("Fiu drept:  ");

    for(i=1; i<=n; i++)
        if(2 * i + 1 <= n)
            printf("%d   ", arr[2 * i + 1]);
        else
            printf(" -   ");

    printf("\n\n\nIntroduceti numarul cautat:\n");
    scanf("%d", &x);

    search_min_heap(root, x, &found);

    if(arr[n] == x)
        printf("\nDa!\n");
    else if(found == 0)
        printf("\nNu!\n");
    else
        printf("\nDa!\n");
}

