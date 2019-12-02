#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream f("input.txt");

long val(vector<long> a, int k, int l){
    a[1] = k;
    a[2] = l;
    for (int i = 0; i < a.size();){
        if (a[i] == 1 && (i%4 == 0 || i==0)){
            a[a[i+3]] = a[a[i+1]]+a[a[i+2]];
            i+=4;
        }
        else if (a[i] == 2 && (i%4 == 0 || i==0)){
            a[a[i+3]] = a[a[i+1]]*a[a[i+2]];
            i+=4;
        }
        else
            i++;
    }
    return a[0];
}

int main(){

    vector<long> a;
    //char s[500];
    string s;
    f >> s;
    char *p = strtok((char*)s.c_str(), ",");
    while (p){
        a.push_back(atol(p));
        p = strtok(NULL, ",");
    }
    cout << val(a, 12, 2) << endl;
    for (int k = 99; k >= 0; k--){
       for (int l = 0; l <= 99; l++){
            if (val(a,k,l) == 19690720){
                cout << 100*k+l<<endl;
                return 0;
            }
        }
    }
}
