#ifndef LIST_H
#define LIST_H

#include <iostream>

template <class T>
struct Nodo 
{ 
    T data; 
    Nodo* next; 
}; 
  
template <class T> class List{
    
    public:
        int isEmpty();
        int isFull();
        T pop();
        void push(T data);
        int get_size(){
            return size;
        }
        void print(){
            std::cout << "<";
            while(root->next){
                std::cout << pop() << ", ";
            }
            std::cout << pop() << ">\n";
        }
        List();
    private:
        int size;
        Nodo<T>* head;
    protected:


        
};


#endif
