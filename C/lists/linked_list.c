#include <stdio.h>
#include <stdlib.h>

// Node Struct and Functions

typedef struct node {
    int value;
    struct node* next;
} Node;

Node* createNode(int value);
void updateNode(Node* n, Node* new_next, int value);
void destroyNode(Node* n);

Node* createNode(int value) {
    Node* n = (Node*) malloc(sizeof(Node));
    
    n->value = value;
    n->next = NULL;

    return n;
}

void updateNode(Node* n, Node* new_next, int value) {
    n->value = value;
    n->next = new_next;
}

void destroyNode(Node* n) {
    free(n);
    n = NULL;
}

// Linked List Struct and Functions

typedef struct {
    int size;
    Node* head;
    Node* tail;
} LinkedList;

LinkedList* createLinkedList();
void removeLeftLinkedList(LinkedList* l);
void updateAtIndexLinkedList(LinkedList* l);
void destroyLinkedList(LinkedList* l);

int main() {
    Node* nodeTest = createNode(3);
    Node* nodeTest2 = createNode(0);
    Node* nodeTest3 = createNode(5);

    nodeTest->next = nodeTest2;

    printf(
        "Node Test:\n\n"
        "nodeTest: %p\n"
        "nodeTest2: %p\n"
        "nodeTest3: %p\n\n"
        "createNode():\n"
        "\tNode: %p\n"
        "\tNode->value: %d\n"
        "\tNode->next: %p\n\n"
        , nodeTest, nodeTest2, nodeTest3, nodeTest, nodeTest->value, nodeTest->next);

    updateNode(nodeTest, NULL, 4);

    printf(
        "updateNode():\n"
        "\tNode: %p\n"
        "\tNode->value: %d\n"
        "\tNode->next: %p\n\n"
        , nodeTest, nodeTest->value, nodeTest->next);

    destroyNode(nodeTest);

    printf(
        "destroyNode():\n"
        "\tNode: %p\n"
        "\tNode->value: %d\n"
        "\tNode->next: %p\n"
        , nodeTest, nodeTest->value, nodeTest->next);

    return 0;
}