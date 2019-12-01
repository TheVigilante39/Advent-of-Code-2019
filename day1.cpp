#include <bits/stdc++.h>
using namespace std;

ifstream f("input.txt");
ofstream g("out.txt");

int main(){


    float x, aux;
    int s1 = 0, s2 = 0, s3 = 0;
    while (f >> x){
        // part 1
        s1+=floor(x/3)-2;
        // part 2
        aux = x;
        s2 = 0;
        while (floor(aux/3)-2 > 0){
            s2+=floor(aux/3)-2;
            aux = floor(aux/3)-2;
        }
        s3 += s2;

    }
    g << s1 << endl;
    g << s3 << endl;
}
