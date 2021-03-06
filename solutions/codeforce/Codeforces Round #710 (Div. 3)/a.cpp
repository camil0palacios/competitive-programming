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
    int t;
    cin >> t;
    while(t--) {
        ll n, m, x;
        cin >> n >> m >> x;
        ll l = 0, r = m; 
        while(l <= r) {
            ll mid = (l + r) >> 1;
            if(mid*n < x) l = mid+1;
            else r = mid-1;
        }
        ll c = x - (l-1)*n;
        ll ans = (c-1)*m + l;
        cout << ans << endl;
    }
    return 0; 
}