
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(){
    // input given to standard input
    long long n, m, a;
    cin >> n;
    cin >> m;
    cin >> a;
    long long num_n = (long long)ceil( ((double)n) / ((double)a) );
    long long num_m = (long long)ceil( ((double)m) / ((double)a) );
    cout << (num_n * num_m) << endl;
}