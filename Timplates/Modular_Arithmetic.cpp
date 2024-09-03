#include<bits/stdc++.h>
using namespace std;

// Modular exponentiation
#define ll long long
ll binpow(ll x,ll n,ll m){
    ll res = 1;
    if(n==0)return res;
    x%=m;
    while(n>0){
        if(n&1)res = (res*x)%m;
        res = (res%m)*(res%m);
        n>>1;
    }
    return res;
}

//Modular Multiplicative Inverse
//Using Fermat's little theorem
ll modinv(ll x,ll p){
    //x and p should be coprime 
    return binpow(x,p-2,p);
}