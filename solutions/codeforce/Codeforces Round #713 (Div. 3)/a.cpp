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
        int n;
        cin >> n;
        vii a(n);
        fori(i,0,n) {
            cin >> a[i].ft;
            a[i].sd = i;
        }
        sort(all(a));
        int idx = 0;
        fori(i,0,n) {
            int j = i;
            while(j < n && a[i].ft == a[j].ft) j++;
            if(j-i == 1) {
                idx = a[i].sd + 1;
            }
            i = j-1;
        }
        cout << idx << endl;
    }
    return 0; 
}