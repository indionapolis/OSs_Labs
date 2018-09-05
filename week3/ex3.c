#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node{
    int value;
    struct Node *next_node;
};

struct linked_list{
    struct Node *head;
    bool empty;
};

void print_list(struct linked_list *list){
    if (!(*list).empty){
        printf("list is empty\n");
        return;
    }

    struct Node *node = list->head;

    while (1){
        printf("%d ", (*node).value);

        if ((*node).next_node == 0){
            printf("\n");
            return;
        }

        node = (*node).next_node;
    }
}

void insert_node(struct linked_list *list, int value){
    // create new node and set data
    struct Node *new_node = malloc(sizeof(struct Node));
    (*new_node).value = value;
    (*new_node).next_node = 0;

    //if list is empty set head node
    if (!(*list).empty){
        (*list).head = new_node;
        (*list).empty = 1;
        return;
    }

    //else go to tail node
    struct Node *node = list->head;

    while (1){
        if ((*node).next_node == 0){
            (*node).next_node = new_node;
            return;
        }
        node = (*node).next_node;
    }

}

void delete_node(struct linked_list *list, int index){
    // cant delete from empty list
    if (!(*list).empty){
        printf("list is empty\n");
        return;
    }

    // if user want delete first element
    if (index == 0){
        struct Node *delete = list->head;
        (*list).head = (*list).head->next_node;
        free(delete);
        // if only one element was in list
        if ((*list).head == 0){
            (*list).empty = 0;
        }
        return;
    }


    struct Node *predecessor = list->head;
    struct Node *node = (*predecessor).next_node;

    // look for certain element 
    for (int i = 1; i < index; ++i) {
        // if end is reached
        if ((*node).next_node == 0){
            printf("ran out of list\n");
            return;
        }
        predecessor = node;
        node = (*node).next_node;
    }

    // predecessor -> node -> next_node  =>  predecessor -> next_node
    (*predecessor).next_node = (*node).next_node;
    // deallocate the memory previously allocated
    free(node);
}

int main(){
    struct linked_list new_list;

    insert_node(&new_list, 3);
    insert_node(&new_list, 4);
    insert_node(&new_list, 7);
    print_list(&new_list);          // 3 4 7
    printf("\n");

    delete_node(&new_list, 3);      // ran out of list

    delete_node(&new_list, 2);
    print_list(&new_list);          // 3 4
    delete_node(&new_list, 1);
    print_list(&new_list);          // 3
    delete_node(&new_list, 0);
    print_list(&new_list);          // list is empty

    return 0;
}


