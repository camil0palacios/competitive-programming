#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

struct pt {
    double x, y;
    pt(){}
    pt(double x, double y): x(x), y(y) {}
};

struct line {
    double a, b, c;
    line(){}
    line(pt p, pt q) {
        a = p.y - q.y;
        b = q.x - p.x;
        c = -a*p.x - b*p.y;
    }
};

const double EPS = 1e-9;

bool onSegment(pt p, pt q, pt r) { 
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && 
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y)) 
       return true; 
  
    return false; 
} 

int orientation(pt p, pt q, pt r)  { 
    int val = (q.y - p.y) * (r.x - q.x) - 
              (q.x - p.x) * (r.y - q.y); 
  
    if (val == 0) return 0;  // colinear 
  
    return (val > 0)? 1: 2; // clock or counterclock wise 
} 
  
bool doIntersect(pt p1, pt q1, pt p2, pt q2)  { 
    int o1 = orientation(p1, q1, p2); 
    int o2 = orientation(p1, q1, q2); 
    int o3 = orientation(p2, q2, p1); 
    int o4 = orientation(p2, q2, q1); 
  
    // General case 
    if (o1 != o2 && o3 != o4) 
        return true; 
  
    // Special Cases 
    // p1, q1 and p2 are colinear and p2 lies on segment p1q1 
    if (o1 == 0 && onSegment(p1, p2, q1)) return true; 
  
    // p1, q1 and q2 are colinear and q2 lies on segment p1q1 
    if (o2 == 0 && onSegment(p1, q2, q1)) return true; 
  
    // p2, q2 and p1 are colinear and p1 lies on segment p2q2 
    if (o3 == 0 && onSegment(p2, p1, q2)) return true; 
  
     // p2, q2 and q1 are colinear and q1 lies on segment p2q2 
    if (o4 == 0 && onSegment(p2, q1, q2)) return true; 
  
    return false; // Doesn't fall in any of the above cases 
} 

double det(double a, double b, double c, double d) {
    return a*d - b*c;
}

bool intersect(line m, line n, pt & res) {
    double zn = det(m.a, m.b, n.a, n.b);
    if (abs(zn) < EPS)
        return false;
    res.x = -det(m.c, m.b, n.c, n.b) / zn;
    res.y = -det(m.a, m.c, n.a, n.c) / zn;
    return true;
}

double dist(pt a, pt b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx*dx + dy*dy);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout << fixed << setprecision(10);
    pt p1[2], p2[2];
    for(int i = 0; i < 2; i++) {
        cin >> p1[i].x >> p1[i].y;
    }
    for(int i = 0; i < 2; i++) {
        cin >> p2[i].x >> p2[i].y;
    }
    line l1(p1[0], p1[1]), l2(p2[0], p2[1]);
    pt a, b, c;
    if(!doIntersect(p1[0], p1[1], p2[0], p2[1])) {
        cout << double(0) << endl;
    } else { 
        intersect(l1, l2, b);
        if(p1[1].y < p2[1].y) {
            a = p1[1];
            line l3(p1[1], pt(1000, p1[1].y));
            intersect(l2, l3, c);
        } else {
            a = p2[1];
            line l3(p2[1], pt(0, p2[1].y));
            intersect(l1, l3, c);
        }
        double A = dist(a, b);
        double B = dist(a, c);
        double C = dist(b, c);
        double s = (A + B + C) / 2.0;
        double Area = sqrt(s*(s - A)*(s - B)*(s - C));
        cout << Area << endl;
    }
    return 0; 
}