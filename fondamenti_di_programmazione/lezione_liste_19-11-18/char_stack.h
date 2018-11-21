struct Nodo 
{ 
    char data; 
    Nodo* next; 
}; 
  
Nodo* newNode(char data) 
{ 
    Nodo* stackNode = new Nodo; 
    stackNode->data = data; 
    stackNode->next = nullptr; 
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
    delete temp; 
  
    return popped; 
}