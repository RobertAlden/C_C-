#include <iostream>
#include <cmath>

using namespace std;

bool is_prime(int x){
    if (x < 2) {
        return false;
    }
    for (int i = 2; i < int(sqrt(x))+1; ++i) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int iterations = 30000;
    int primes = 0;
    for (int i = 1; i < iterations; ++i) {
        int side_length = 2 * i + 1;
        int max_value = round(pow(side_length,2));
        int corners[3] = {max_value - (side_length-1), max_value - (side_length-1)*2, max_value - (side_length-1)*3};
        for (int c = 0; c < 3; ++c){
            //cout << corners[c] << " ";
            primes += int(is_prime(corners[c]));
        }

        //cout << ":s:" << side_length << "/"<< max_value << " p:" << primes << " r:" << (double(primes) / (i*4 + 1)) << endl;

        if (float(primes) / (i*4 + 1) < 0.1) {
            cout << side_length;
            break;
        }
    }
    return 0;
}