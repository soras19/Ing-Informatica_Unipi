#ifndef STACK_H
#define STACK_H

template <class T>
struct elemento{
    T var;
    elemento* next;
};

template <class T> class Stack{
    
    public:
        int isEmpty();
        int isFull();
        T pop();
        int push(T obj);
        Stack();
    private:
         

        
};


#endif