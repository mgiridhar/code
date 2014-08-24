#include<iostream>
#include<cmath>
using namespace std;
struct point
{
	long int x,y;
};
// to find whether point q lies between p and r
bool is_within(point p, point q, point r)
{
	if(q.x <= max(p.x,r.x) && q.x >= min(p.x,r.x) && q.y <= max(p.y,r.y) && q.y >= min(p.y,r.y))
		return true;
	return false;
}
int orientation(point p, point q, point r)
{
	long int val = (q.y - p.y)*(r.x - q.x) - (r.y - q.y)*(q.x - p.x);
	if(val == 0) return 0; //colinear
	return (val>0)?1:2;  	//clockwise or anti-clockwise
}
bool do_intersect(point p1, point q1, point p2, point q2)
{
	int o1 = orientation(p1,q1,p2);
	int o2 = orientation(p1,q1,q2);
	int o3 = orientation(p2,q2,p1);
	int o4 = orientation(p2,q2,q1);
	//general case
	if(o1 != o2 && o3 != o4) return true;
	
	//special cases
	if(o1 == 0 && is_within(p1,p2,q1)) return true;	
	if(o2 == 0 && is_within(p1,q2,q1)) return true;
	if(o3 == 0 && is_within(p2,p1,q2)) return true;
	if(o4 == 0 && is_within(p2,q1,q2)) return true;
	
	return false;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		struct point p1,q1,p2,q2;
		p1.x = p1.y =0;
		cin>>p2.x>>p2.y>>q2.x>>q2.y>>q1.x>>q1.y;
		if(!do_intersect(p1,q1,p2,q2))
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
}
