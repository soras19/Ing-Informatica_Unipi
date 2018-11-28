#include "list.h"
#include <iostream>

template <class T> int List<T>::isEmpty(){
    /* Se il primo oggetto è NULL allora è vuota*/
    return (head == nullptr);
}

template <class T> List<T>::List(){
    head = nullptr;
    size = 0;
}

template <class T> int List<T>::isFull(){
    /* Non è mai piena ammenoché non hai finito la RAM*/
    return 0; 

}

template <class T> T List<T>::pop(){
    if(size == 0){
        std::cout << "La pila è vuota" << std::endl;
        return {};
    }
    Nodo<T>* tmp = head;
    head = head->next;
    T popped = tmp -> data;
    delete tmp;
    size--;
    return popped;
}

template <class T> void List<T>::push(T data){
    Nodo<T>* ListNode = new Nodo<T>; 
    ListNode->data = data; 
    ListNode->next = head; 
    head = ListNode; 
    size++;    
}

// Tipi che possono essere utilizzati
template class List<char>;
template class List<int>;
template class List<float>;
template class List<double>;
