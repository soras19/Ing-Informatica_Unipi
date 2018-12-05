#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>

using namespace std;

const int dim = 26;

bool check_n_occurrance(const char* str, int n);
void open(const char* file);
int max(const int*& a);
void clean(int*& a);

int main(int argc, char const *argv[]) {
    if(argc > 1)
        for(int i = 1; i < argc; i++)
            open(argv[i]);
    else
        open("input");
    return 0;
}

int max(const int*& a){
    int max = a[0];
    int i = 1;
    for(i = 1; i < dim; i++)
        max = max > a[i] ? max : a[i];
    return max;
}

void clean(int*& a){
    for(int i = 0; i < dim; i++)
        a[i] = 0;
}

bool check_n_occurrance(const char* str, int n){
    //cout << "str is " << str << " n is " << n << endl;
    int count = 0;
    for(int i = 0; i < strlen(str); i++){
        count = 0;
        for(int j = i+1; j < strlen(str); j++){
            if(str[i] == str[j]){
                count++;
                cout << "Found " << str[i] << " == " << str[j] <<" count is: " << count << endl;
            }

            if(count == 1 && n==1 && (check_n_occurrance(str, 2) == false && flag[i] != 0)){
                return true;
            }
            else if(count == 2 && n == 2)
                return true;
        }
    }
    return false;
}

void open(const char* file){
    char s[] = "jbrelqtgagxhivmryscfukzodp"; // To check the size of strings
    fstream input;
    input.open(file, ios::in);
    if(!input)
        cout << "Apertura fallita! Il file esiste?" << endl;
    else{
        char line[strlen(s)+1];
        int checksum2 = 0, checksum3 = 0;
        while(input >> line){
            if(check_n_occurrance(line, 1))
                checksum2++;
            if(check_n_occurrance(line, 2))
                checksum3++;
        }
        cout << line << endl;
        printf("%d * %d = %d\n", checksum2, checksum3, checksum2*checksum3);
    }

    input.close();
}
