#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

struct Node {
    char *directory;
    struct Node *next;
};

/**
 * printPathList - prints the path list
 * @head: a head node to the linked list
*/
void printPathList(struct Node *head) {
    struct Node *current = head;
    while (current != NULL) {
        printf("%s\n", current->directory);
        current = current->next;
    }
}

/**
 * buildPathList - creates a linked list
 * Return: a struct node
*/
struct Node *buildPathList() {
    const char *path = getenv("PATH");

    if (path == NULL) {
        printf("PATH environment variable is not set.\n");
        return (NULL);
    }

    char *pathCopy = strdup(path);
    if (pathCopy == NULL) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }

    struct Node *head = NULL;
    struct Node *current = NULL;

    char *token = strtok(pathCopy, ":");
    while (token != NULL) {
        struct Node *newNode = malloc(sizeof(struct Node));
        if (newNode == NULL) {
            perror("Memory allocation error");
            exit(EXIT_FAILURE);
        }

        newNode->directory = strdup(token);
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            current = newNode;
        } else {
            current->next = newNode;
            current = newNode;
        }

        token = strtok(NULL, ":");
    }

    free(pathCopy);

    return (head);
}

/**
 * freePathList - frees the memory
 * @head: takes in the heads node to free
*/
void freePathList(struct Node *head) {
    struct Node *current = head;
    while (current != NULL) {
        struct Node *temp = current;
        current = current->next;
        free(temp->directory);
        free(temp);
    }
}
/**
 * main - starts here
 * Return: always zero
*/
int main(void) {
    struct Node *pathList = buildPathList();
    
    if (pathList != NULL) {
        printPathList(pathList);
        freePathList(pathList);
    }

    return (0);
}
