#include<bits/stdc++.h>
using namespace std;

//prime factorisation 
//time complexity = O(sqrt(n))

vector<int> primes(int n){
    vector<int> res;
    for(int i=2;i*i<=n;i++){
        while(n%i==0){
            res.push_back(i);
            n/=i;
        }
    }
    if(n>1)res.push_back(n);
    return res;
}
//counting divisors O(sqrt(x))
// #include <iostream>

// using namespace std;

// int main() {
// 	int n;
// 	cin >> n;
// 	for (int q = 0; q < n; q++) {
// 		int x;
// 		int div_num = 0;
// 		cin >> x;
// 		for (int i = 1; i * i <= x; i++) {
// 			if (x % i == 0) { div_num += i * i == x ? 1 : 2; }
// 		}
// 		cout << div_num << '\n';
// 	}
// }
//counting divisors in O((x+n)(log(x)))
// const int MAX_N = 1e6;
//max_div[i] contains the largest prime that goes into i
// int max_div[MAX_N + 1];

// int main() {
// 	for (int i = 2; i <= MAX_N; i++) {
// 		if (max_div[i] == 0) {
// 			for (int j = i; j <= MAX_N; j += i) { max_div[j] = i; }
// 		}
// 	}

// 	int n;
// 	cin >> n;

// 	for (int i = 0; i < n; i++) {
// 		int x;
// 		cin >> x;
// 		int div_num = 1;
// 		while (x != 1) {
// 			/*
// 			 * get the largest prime that can divide x and see
// 			 * how many times it goes into x (stored in count)
// 			 */
// 			int prime = max_div[x];
// 			int count = 0;
// 			while (x % prime == 0) {
// 				count++;
// 				x /= prime;
// 			}
// 			div_num *= count + 1;
// 		}
// 		cout << div_num << '\n';
// 	}
// }