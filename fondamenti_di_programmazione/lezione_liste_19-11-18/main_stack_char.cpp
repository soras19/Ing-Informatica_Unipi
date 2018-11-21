#include <iostream>
#include "char_stack.h"

using namespace std;

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