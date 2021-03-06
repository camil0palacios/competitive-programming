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
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ar array
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; ll t;
    cin >> n >> t;
    list<int> l;
    ll s = 0;
    fori(i,0,n) {
        int a; cin >> a;
        l.eb(a);
    }
    ll ans = 0;
    bool ok = 1;
    while(t) {
        ok = s = 0;
        for(auto it = l.begin(); it != l.end();) {
            if(s + *it <= t) {
                s += *it;
                it++;
                ok = 1;
            } else it = l.erase(it);
        }
        if(!ok) break; 
        ll k = t/s;
        ans += k*sz(l);
        t %= s;
    }
    cout << ans << endl;
    return 0; 
}