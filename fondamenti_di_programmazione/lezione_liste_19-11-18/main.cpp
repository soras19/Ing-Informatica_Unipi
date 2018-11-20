#include <iostream>
using namespace std;

struct Nodo 
{ 
    char data; 
    Nodo* next; 
}; 
  
Nodo* newNode(char data) 
{ 
    Nodo* stackNode = new Nodo; 
    stackNode->data = data; 
    stackNode->next = NULL; 
    return stackNode; 
}

void push(Nodo** root, char data) 
{ 
    Nodo* stackNode = newNode(data); 
    stackNode->next = *root; 
    *root = stackNode; 
} 

char pop(Nodo** root) 
{ 
    if (!root) 
        return 0; 
    Nodo* temp = *root; 
    *root = (*root)->next; 
    char popped = temp->data; 
    free(temp); 
  
    return popped; 
}

int main(int argc, char const *argv[])
{
    Nodo* root = NULL;
    for(char i = getchar(); i!='\n'; i = getchar()){
        push(&root, i);
    }
    while(root){
        cout << pop(&root);
    }
    return 0;
}