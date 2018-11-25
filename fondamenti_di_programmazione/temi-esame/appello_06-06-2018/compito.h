#include <iostream>

using namespace std;

class Display
{
    char **dis;
    int col;
    int lin;
    int cur;

    friend ostream& operator<<(ostream& os, const Display& d);

public:
    Display(int L, int C);
    void writeT(const char* str);
    void writeW(const char* str);
    Display(const Display& d);
    Display& operator=(const Display& d);
    ~Display();
};
