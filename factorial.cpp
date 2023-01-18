// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string multiply(string n1, string n2); 

// https://www.hackerrank.com/challenges/extra-long-factorials/problem?isFullScreen=true&h_r=next-challenge&h_v=zen

int main() {
    int n = 200;
    string r = "1";
    for(int i = 2; i <= n; i++){
        r = multiply(r, to_string(i));
    }
    
    cout << r;
    return 0;
}

string multiply(string s1, string s2){
    int l = s1.size() + s2.size() + 1; 
    int r[l];
    for(int i = 0; i < l; i++){
        r[i] = 0; 
    }

    for(int i = s2.size() - 1; i >= 0; i--){
        int p2 = int(s2[i] - '0');
        int rt = 0;
        int ii = l - (s2.size() - i);
            
        for(int j = s1.size() - 1; j >= 0; j--){
            int p1 = int(s1[j] - '0');
            int m = p1 * p2 + rt;
            int a = r[ii] + (m % 10);
            r[ii] = a % 10; 
            rt = (m / 10 + a / 10);
            ii--;
        }
        if(rt > 0){
            int a = r[ii] + rt;
            r[ii] = a % 10;
            if(a / 10 > 0) r[ii - 1] = a / 10; 
        } 
    }
    
    string mult = "";
    bool f = false;
    for(int i = 0; i < l; i++){
        if(!f && r[i] != 0) f = true;
        if(f) 
            mult += to_string(r[i]);
    }
    
    return mult; 
}





