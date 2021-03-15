#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fori(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)
#define fore(i,a,b) for(int i = a; i <= b; i++)
#define ft first
#define sd second
#define all(v) v.begin(), v.end()
#define sz(v) (int) v.size()
#define pb push_back
#define eb emplace_back
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vll;

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, d;
        cin >> n >> d;
        vi a(n);
        fori(i,0,n) cin >> a[i];
        sort(all(a));
        bool ok = 1;
        fori(i,0,n) ok &= a[i] <= d;
        if(n >= 2 && a[0] + a[1] <= d) ok |= 1;
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0; 
}