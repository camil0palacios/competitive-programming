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

ll sm[3], mn[3];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll sum = 0;
    int n[3];
    fori(i,0,3) cin >> n[i];
    fori(i,0,3) {
        mn[i] = 1e9;
        fori(j,0,n[i]) {
            ll a; cin >> a;
            sum += a;
            sm[i] += a;
            mn[i] = min(mn[i], a);
        }
    }
    sort(sm, sm+3);
    sort(mn, mn+3);
    cout << sum - min(sm[0], mn[0] + mn[1])*2 << endl;
    return 0; 
}