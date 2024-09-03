#include<bits/stdc++.h>
using namespace std;

/*The totient function is multiplicative meaning that $\phi(nm)=\phi(n) \cdot \phi(m)$, where $n$ and $m$ are coprime - $gcd(n, m)=1$. For example $\phi(15)=\phi(3 \cdot 5)=\phi(3) \cdot \phi(5) = 2 \cdot 4 = 8$.

Let's take a look at some edge cases for $\phi(n)$:

If n is a prime number then $\phi(n)=n-1$ because $gcd(n, x)=1$ for all $1 \leq x \le n$
If n is a power of a prime number, $n=p^q$ where p is a prime number and $1 \leq q$ then
there are exactly $p^{q-1}$ numbers divisible by $p$, so
$\phi(p^q)=p^{q} - p^{q-1} = p^{q-1}(p - 1)$


Using the multiplicative property and the last edge case we can compute the value of $\phi(n)$ from the factorization of number $n$.
Let the factorization be $n=p_1^{q_1} \cdot p_2^{q_2} \cdot \ldots \cdot p_k^{q_k}$ where $p_i$ is a prime factor of $n$, then:

$$\phi(n)=\phi(p_1^{q_1}) \cdot \phi(p_2^{q_2}) \cdot \ldots \cdot \phi(p_k^{q_k}) = p_1^{q_1-1}(p_1 - 1) \cdot p_2^{q_2-1}(p_2 - 1) \cdot \ldots \cdot p_k^{q_k-1}(q_k - 1)$$

Below is an implementation for factorization in $\mathcal{o}(\sqrt{n})$. It can be a little bit tricky to understand why we substract $and/p$ from $ans$. For example
$ans=p_q \cdot x$ ,where $p$ is a prime factor and $x$ is the rest of the prime factorization. By substracting $\frac{ans}{p}=p_{q-1} \cdot x$ we end up with:
$p_q \cdot x - p_{q-1} \cdot x = p_{q-1} \cdot x \cdot (p - 1)$ which is exactly the form of $\phi(n)$ described a few linew above.*/

// int phi(int n){
//     int ans = n;
//     for(int p=2;p*p<=n;p++){
//         if(n%p==0){
//             while(n%p==0)n/=p;
//             ans -= ans/p;
//         }
//     }
//     if(n>1)ans -= ans/n;
//     return ans;
// }
const int MAX_N = 100100;
int phi[MAX_N];
void precompute() {
	for (int i = 1; i < MAX_N; i++) { phi[i] = i; }
	for (int i = 2; i < MAX_N; i++) {
		// If i is prime
		if (phi[i] == i) {
			for (int j = i; j < MAX_N; j += i) { phi[j] -= phi[j] / i; }
		}
	}
}

int main(){
    int x;
    x = 12090;
    cout<<phi[x]<<endl;
    return 0;
}