/* C++ Program to illustrate Gift Wrapping Algorithm
Running Time: O(n*h) where h is the number of points on the convex hull
Algorithm:
        -> we build the convex hull step by step by adding one additional point to the hull at each step, O(n) for each  added point.
        -> Counter Clockwise Direction.
*/

#include<iostream>
#include<stdlib.h>
#include<algorithm>
#include<stack>
#include<cmath>
#include<cstdio>
using namespace std;
typedef long long ll;
typedef long double ld;
#define MAX 7000009
#define NEGINF -10000
#define INF 10000
#define rep(i,n) for(i=0;i<n;i++)

struct Point {
        ld x;
        ld y;
}p[MAX];

ll n,flag[MAX];

ll getOrientation(Point p,Point q,Point r){
    ld turn =  (  q.x - p.x)*(r.y - q.y) - (r.x - q.x)*(q.y - p.y) ; //Cross product

    if(turn > 0)
        return 1;   // Anti Clockwise Turn
    else if(turn == 0)
        return 0;   // Collinear
    else
        return -1;  // Clockwise Turn
}

 void generateHull(){
    ll i,j,index,count,a,b,initial;
    Point temp,p1,p2;

    rep(i,n)
        flag[i] =  -1;

    index = 0;
    count = 0;

    rep(i,n)
        if(p[i].x < p[index].x ) index = i; //With the least x

    rep(i,n)
        if(p[i].x == p[index].x && p[i].y < p[index].y) index = i; // Least x with Least y


    flag[index] = 1;
     a = index;
     initial = a;



    while(true){
        b = (a+1)%n; // We do't want b to be a

            rep(i,n)
                if( getOrientation(p[a],p[i],p[b]) == 1 )
                        b = i;

            flag[b] = 1;

            if(initial == b)
                break;
            count++;
            a = b;
    }

    rep(i,n)
        if(flag[i] == 1)
            printf("(%llf,%llf)\n",p[i].x,p[i].y);
    cout<<"count: "<<count<<endl;
}//generateHull


int main() {
    ll i,j;
    ld temp;

    i = 0;
    while(true){
        if( !(cin>>p[i].x>>p[i].y>>temp))
            break;
        i++;
    }

    n = i;
    generateHull();

return 0;
}
