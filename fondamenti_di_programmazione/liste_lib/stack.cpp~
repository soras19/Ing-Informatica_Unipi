#include "stack.h"
#include <iostream>

template <class T> int Stack<T>::isEmpty(){
    /* Se il primo oggetto è NULL allora è vuota*/
    return (root == nullptr);
}

template <class T> Stack<T>::Stack(){
    root = nullptr;
    size = 0;
}

template <class T> int Stack<T>::isFull(){
    /* Non è mai piena ammenoché non hai finito la RAM*/
    return 0; 

}

template <class T> T Stack<T>::pop(){
    if(size == 0){
        std::cout << "La pila è vuota" << std::endl;
        return {};
    }
    Nodo<T>* tmp = root;
    root = root->next;
    T popped = tmp -> data;
    delete tmp;
    size--;
    return popped;
}

template <class T> void Stack<T>::push(T data){
    Nodo<T>* stackNode = new Nodo<T>; 
    stackNode->data = data; 
    stackNode->next = root; 
    root = stackNode; 
    size++;    
}

// Tipi che possono essere utilizzati
template class Stack<char>;
template class Stack<int>;
template class Stack<float>;
template class Stack<double>;