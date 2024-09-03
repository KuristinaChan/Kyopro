#ifndef DEBUG_TEMPLATE_CPP
#define DEBUG_TEMPLATE_CPP


#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace chrono;
using namespace __gnu_pbds;


namespace __DEBUG_UTIL__
{
    using namespace std;
    /* Primitive Datatypes Print */
    void print(const char *x) { cerr << x; }
    void print(bool x) { cerr << (x ? "T" : "F"); }
    void print(char x) { cerr << '\'' << x << '\''; }
    void print(signed short int x) { cerr << x; }
    void print(unsigned short int x) { cerr << x; }
    void print(signed int x) { cerr << x; }
    void print(unsigned int x) { cerr << x; }
    void print(signed long int x) { cerr << x; }
    void print(unsigned long int x) { cerr << x; }
    void print(signed long long int x) { cerr << x; }
    void print(unsigned long long int x) { cerr << x; }
    void print(float x) { cerr << x; }
    void print(double x) { cerr << x; }
    void print(long double x) { cerr << x; }
    void print(string x) { cerr << '\"' << x << '\"'; }
    template <size_t N>
    void print(bitset<N> x) { cerr << x; }
    void print(vector<bool> v)
    { /* Overloaded this because stl optimizes vector<bool> by using
          _Bit_reference instead of bool to conserve space. */
        int f = 0;
        cerr << '{';
        for (auto &&i : v)
            cerr << (f++ ? "," : "") << (i ? "T" : "F");
        cerr << "}";
    }
    /* Templates Declarations to support nested datatypes */
    template <typename T>
    void print(T &&x);
    template <typename T>
    void print(vector<vector<T>> mat);
    template <typename T, size_t N, size_t M>
    void print(T (&mat)[N][M]);
    template <typename F, typename S>
    void print(pair<F, S> x);
    template <typename T, size_t N>
    struct Tuple;
    template <typename T>
    struct Tuple<T, 1>;
    template <typename... Args>
    void print(tuple<Args...> t);
    template <typename... T>
    void print(priority_queue<T...> pq);
    template <typename T>
    void print(stack<T> st);
    template <typename T>
    void print(queue<T> q);
    /* Template Datatypes Definitions */
    template <typename T>
    void print(T &&x)
    {
        /*  This works for every container that supports range-based loop
            i.e. vector, set, map, oset, omap, dequeue */
        int f = 0;
        cerr << '{';
        for (auto &&i : x)
            cerr << (f++ ? "," : ""), print(i);
        cerr << "}";
    }
    template <typename T>
    void print(vector<vector<T>> mat)
    {
        int f = 0;
        cerr << "\n~~~~~\n";
        for (auto &&i : mat)
        {
            cerr << setw(2) << left << f++, print(i), cerr << "\n";
        }
        cerr << "~~~~~\n";
    }
    template <typename T, size_t N, size_t M>
    void print(T (&mat)[N][M])
    {
        int f = 0;
        cerr << "\n~~~~~\n";
        for (auto &&i : mat)
        {
            cerr << setw(2) << left << f++, print(i), cerr << "\n";
        }
        cerr << "~~~~~\n";
    }
    template <typename F, typename S>
    void print(pair<F, S> x)
    {
        cerr << '(';
        print(x.first);
        cerr << ',';
        print(x.second);
        cerr << ')';
    }
    template <typename T, size_t N>
    struct Tuple
    {
        static void printTuple(T t)
        {
            Tuple<T, N - 1>::printTuple(t);
            cerr << ",", print(get<N - 1>(t));
        }
    };
    template <typename T>
    struct Tuple<T, 1>
    {
        static void printTuple(T t) { print(get<0>(t)); }
    };
    template <typename... Args>
    void print(tuple<Args...> t)
    {
        cerr << "(";
        Tuple<decltype(t), sizeof...(Args)>::printTuple(t);
        cerr << ")";
    }
    template <typename... T>
    void print(priority_queue<T...> pq)
    {
        int f = 0;
        cerr << '{';
        while (!pq.empty())
            cerr << (f++ ? "," : ""), print(pq.top()), pq.pop();
        cerr << "}";
    }
    template <typename T>
    void print(stack<T> st)
    {
        int f = 0;
        cerr << '{';
        while (!st.empty())
            cerr << (f++ ? "," : ""), print(st.top()), st.pop();
        cerr << "}";
    }
    template <typename T>
    void print(queue<T> q)
    {
        int f = 0;
        cerr << '{';
        while (!q.empty())
            cerr << (f++ ? "," : ""), print(q.front()), q.pop();
        cerr << "}";
    }
    /* Printer functions */
    void printer(const char *) {} /* Base Recursive */
    template <typename T, typename... V>
    void printer(const char *names, T &&head, V &&...tail)
    {
        /* Using && to capture both lvalues and rvalues */
        int i = 0;
        for (size_t bracket = 0; names[i] != '\0' and (names[i] != ',' or bracket != 0); i++)
            if (names[i] == '(' or names[i] == '<' or names[i] == '{')
                bracket++;
            else if (names[i] == ')' or names[i] == '>' or names[i] == '}')
                bracket--;
        cerr.write(names, i) << " = ";
        print(head);
        if (sizeof...(tail))
            cerr << " ||", printer(names + i + 1, tail...);
        else
            cerr << "]\n";
    }
    /* PrinterArr */
    void printerArr(const char *) {} /* Base Recursive */
    template <typename T, typename... V>
    void printerArr(const char *names, T arr[], size_t N, V... tail)
    {
        size_t ind = 0;
        for (; names[ind] and names[ind] != ','; ind++)
            cerr << names[ind];
        for (ind++; names[ind] and names[ind] != ','; ind++)
            ;
        cerr << " = {";
        for (size_t i = 0; i < N; i++)
            cerr << (i ? "," : ""), print(arr[i]);
        cerr << "}";
        if (sizeof...(tail))
            cerr << " ||", printerArr(names + ind + 1, tail...);
        else
            cerr << "]\n";
    }
}
#ifndef ONLINE_JUDGE
#define debug(...) std::cerr << __LINE__ << ": [", __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
#define debugArr(...) std::cerr << __LINE__ << ": [", __DEBUG_UTIL__::printerArr(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...)
#define debugArr(...)
#endif
#endif

#define kuristina() ios_base::sync_with_stdio(false);std::cin.tie(NULL);std::cout.tie(NULL)
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define si set<int>
#define sll set<long long>
#define sc set<char>
#define vc vector<char>

#define rep(i,a,b) for(int i=a;i<b;i++)
#define repb(i,a,b) for(int i=a;i<=b;i++)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define ff first
#define ss second
#define ln endl

#define mp make_pair
#define pqueue priority_queue
#define pb push_back

ll gcd(const ll a, const ll b){return(b==0?a:gcd(b,a%b));}
ll lcm(const ll a, const ll b){return a/gcd(a,b)*b;}
ll binpow(ll a,ll n){ll ans=1;for(;n;n/=2,a*=a)if(n&1)ans*=a;return ans;}
ll binpow(ll a,ll n,const ll&mod){ll ans=1;for(;n;n/=2,a=a*a%mod)if(n&1)ans=ans*a%mod;return ans;}
ll cdiv(const ll&a,const ll&b){return(a/b+((a^b)>0 && a%b));}
ll fdiv(const ll&a,const ll&b){return a/b-((a^b)<0 && a%b);}
const ll mod = 1000000007;
// const ll mod = 998244353;
using namespace std;
vll tre;
ll f(int node,int node_low,int node_high,int query_low,int query_high){
    if(query_low<=node_low && query_high>=node_high){
        return tre[node];
    }
    if(query_low>node_high || query_high<node_low){
        return 0;
    }
    int last_in_left = (node_low + node_high)>>1;
    debug(tre);
    return max(f(2*node,node_low,last_in_left,query_low,query_high),f(2*node+1,last_in_left+1,node_high,query_low,query_high));
}
void change(int node,int node_low,int node_high,int query_low,int query_high,int val){
     if(query_low<=node_low && query_high>=node_high){
        tre[node]=val;
        return;
    }
    if(query_low>node_high || query_high<node_low){
        return;
    }
    int last_in_left = (node_low + node_high)>>1;
    change(2*node,node_low,last_in_left,query_low,query_high,val);change(2*node+1,last_in_left+1,node_high,query_low,query_high,val);
    tre[node]=max(tre[2*node],tre[2*node+1]);
    debug(tre);
}
struct segmenttree{
int n;
vector<int> st;

void init(int n){
    this->n = n;
    st.resize(4*n , 0 /*default value */);
}

void build(int start , int ending , int node , vector<int> &v){

          if(start==ending){

            st[node] = v[start];

            return;

          }

          int mid = (start + ending)/2;

          //left subtree
          build(start , mid , 2*node+1 , v);

          // right subtree
          build(mid+1 , ending , 2*node+2 , v);

          // operation
          st[node] = st[2*node+1] + st[2*node+2];

}

void build(vector<int> &v){ build(0 , n-1 , 0 , v);}

int query(int start , int ending , int l , int r , int node){

    // no overlapping
    if(start>r || ending<l){
        return 0;
    }

    // complete overlap
    if(start>=l && ending<=r){
        return st[node];
    }

    //partial case
    int mid = (start+ending)/2;

    int q1 = query(start,mid,l,r,2*node+1);

    int q2 = query(mid+1 , ending , l , r , 2*node + 2);

    return max(q1,q2);
}
int query(int l , int r){ return query(0 , n-1 , l , r , 0);}

void update(int start , int ending , int node , int index , int value){
     
     if(start==ending){
        st[node] = value;
        return;
     }

     int mid = (start+ending)/2;

     if(index<=mid){
        //left subtree
       update(start , mid , 2*node+1 , index , value);
     }
     else{
        //right subtree
       update(mid+1 , ending , 2*node+2 , index , value);
     }
     
     // update with new value
     st[node] = max(st[2*node+1] , st[2*node+2]);
}

void update(int x , int y){
     update(0 , n-1 , 0 , x , y);
}

};
// void solve(){
    int n;
    std::cin>>n;
    vector<ll> dp(n,0);
    vector<int> h(n);
    rep(i,0,n)std::cin>>h[i];
    map<int,ll> b;
    rep(i,0,n){
        ll x;
        std::cin>>x;
        b[--h[i]]=x;
    }
    while(__builtin_popcount(n)!=1){
        dp.pb(0);
        n++;
    }
    tre.resize(2*n);
    rep(i,0,n){
        tre[n+i]=dp[i];
    }
    for(int i=n-1;i>=1;i--){
        tre[i]=max(tre[2*i],tre[2*i+1]);
    }
    for(int i=n-1;i>=0;i--){
        dp[h[i]]=b[h[i]]+f(1,0,n-1,h[i]+1,n-1);
        change(1,0,n-1,h[i],h[i],dp[h[i]]);
        debug(tre);
    }
    ll ans = -1;
    rep(i,0,n){
        ans = max(ans,dp[i]);
    }
    cout<<ans<<ln;
}
void solcve(){
    int n;
    cin>>n;
    vector<int> h(n);
    for(int i=0; i<n; i++)cin>>h[i];
    vector<int> a(n);
    for(int i=0; i<n; i++)cin>>a[i];
    vector<int> dp(n,-1);
    dp[0]=a[0];
    segmenttree stree;
    stree.init(n);
    stree.update(h[0],a[0]);
    set<int> s;
    s.insert(h[0]);
    for(int i=1; i<n; i++){
       auto it = s.lower_bound(h[i]);
       int temp;
       if(*it==h[i] || it==s.end()){
          temp = stree.query(0,h[i]);
       }
       else{
           if(it!=s.begin()){
            it--;
           }
        temp = stree.query(0,*it);
       }
       ans = max(ans , temp+a[i]);

       stree.update(h[i],temp+a[i]);

       s.insert(h[i]);

    }
    cout<<ans<<endl;
    return;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
    #endif
    kuristina();

    solve();
}