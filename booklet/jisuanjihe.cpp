#include <bits/stdc++.h>
using namespace std;
const double eps=1e-8;
#define ll long long
#define sz(x) (int)(x).size()
const double PI=acos(-1.0);
ll gcd(ll x,ll y){return y==0?x:gcd(y,x%y);}
int sgn(double x){if(abs(x)<eps)return 0;return x<0?-1:1;}
struct point{
    double x,y;

    point(double _x=0,double _y=0){
        x=_x;
        y=_y;
    }
    double norm(){return sqrt(x*x+y*y);}
    point operator - (const point & b)const {return {x-b.x,y-b.y};}
    point operator + (const point & b)const {return {x+b.x,y+b.y};}
    point operator / (const double & b)const {return {x/b,y/b};}
    point operator * (const double & b)const {return {x*b,y*b};}
    double operator * (const point & b)const {return x*b.y-b.x*y;}//叉乘
    bool operator < (const point & b)const {return sgn(x-b.x)?x<b.x:sgn(y-b.y)?y<b.y:0;}
    bool operator == (const point & b)const {return !sgn(x-b.x) && !sgn(y-b.y);}
};
struct line{
    point a,b;
};
double area(const point& a,const point& b,const point& c){return abs((b-a)*(c-a))/2;}
pair<bool,point> line_intersection(const line & a,const line & b){
    if(!sgn((a.a-a.b)*(b.a-b.b)))return {0,{}};
    if(sgn((b.a-a.a)*(b.a-b.b))*sgn((b.a-a.b)*(b.a-b.b))>0)return {0,{}};
    if(sgn((a.a-b.a)*(a.a-a.b))*sgn((a.a-b.b)*(a.a-a.b))>0)return {0,{}};
    double sa=area(a.a,b.a,a.b);
    double sb=area(a.b,a.a,b.b);
    return {1,b.a+(b.b-b.a)*sa/(sa+sb)};
}
vector<point> graham(vector<point> p){
    sort(p.begin(),p.end(),[](const point & a,const point & b){return a.x==b.x?a.y<b.y:a.x<b.x;});
    p.erase(unique(p.begin(),p.end()),p.end());
    int n=sz(p),m=0,k,i;
    vector<point> res(n+1); 
    for(i=0;i<n;i++){
        while(m>1&&(res[m-1]-res[m-2])*(p[i]-res[m-2])<=0) m--; 
        res[m++]=p[i]; 
    }
    k=m;
    for(i=n-2;i>=0;i--){
        while(m>k&&(res[m-1]-res[m-2])*(p[i]-res[m-2])<=0) m--; 
        res[m++]=p[i]; 
    }
    if(n>1) m--;
    res.resize(m);
    return res;
}


double dot( point a , point b ) { return a.x * b.x + a.y * b.y ; }
double det( point a , point b ) { return a.x * b.y - a.y * b.x ; }
double dist( point a , point b ) { return ( a - b ).norm() ; }
int CircleInterLine( point a, point b, point o, double r, point *p )
{
    point p1 = a - o ;
    point d = b - a ;
    double A = dot( d, d ) ;
    double B = 2 * dot( d, p1 ) ;
    double C = dot( p1, p1 ) - r*r ;

    double delta = B*B - 4*A*C ;
    if ( sgn(delta) < 0 ) return 0 ;//相离
    if ( sgn(delta) == 0 ) { //相切
        double t = -B / (2*A) ; // 0 <= t <= 1说明交点在线段上
        if ( sgn( t - 1 ) <= 0 && sgn( t ) >= 0 ) {
            p[0] = a + d*t ; 
            return 1 ;
        }
    }
    if ( sgn(delta) > 0 ) { //相交
        double t1 = ( -B - sqrt(delta) ) / (2*A) ;
        double t2 = ( -B + sqrt(delta) ) / (2*A) ; //0 <= t1, t2 <= 1说明交点在线段上
        int k = 0 ;
        if ( sgn( t1 - 1 ) <= 0 && sgn( t1 ) >= 0 ) 
            p[k++] = a + d*t1 ; 
        if ( sgn( t2 - 1 ) <= 0 && sgn( t2 ) >= 0 ) 
            p[k++] = a + d*t2 ;
        return k ;
    }
    return 0;
}
double Triangle_area( point a, point b )
{
    return fabs( det( a , b ) ) / 2.0  ;
}
double Sector_area( point a, point b ,double r)
{
    double ang = atan2( a.y , a.x ) - atan2( b.y, b.x  ) ;
    while ( ang <= 0 ) ang += 2 * PI ;
    while ( ang > 2 * PI ) ang -= 2 * PI ;
    ang = min( ang, 2*PI - ang ) ;
    return r*r * ang/2 ;
}
double calc( point a , point b , double r )
{
    point pi[2] ;
    if ( sgn( a.norm() - r ) < 0 ) {
        if ( sgn( b.norm() - r ) < 0 ) {
            return Triangle_area( a, b ) ;
        }
        else {
            CircleInterLine( a, b, point(0,0), r, pi) ;
            return Sector_area( b, pi[0],r) + Triangle_area( a, pi[0] ) ;
        }
    }
    else {
        int cnt = CircleInterLine( a, b, point(0,0), r, pi ) ;
        if ( sgn( b.norm() - r ) < 0 ) {
            return Sector_area( a, pi[0],r ) + Triangle_area( b, pi[0] ) ;
        }
        else {
            if ( cnt == 2 )
                return Sector_area( a, pi[0],r ) + Sector_area( b, pi[1],r ) + Triangle_area( pi[0], pi[1] ) ;
            else
                return Sector_area( a, b ,r) ;
        }
    }
    return 0;
}
double area_CircleAndPolygon( point *p , int n , point o , double r )
{
    double res = 0 ;
    p[n] = p[0] ;
    for ( int i = 0 ; i < n ; i++ ) {
        int tmp = sgn( det( p[i] - o , p[i+1] - o ) ) ;
        if ( tmp )  
            res += tmp * calc( p[i] - o , p[i+1] - o , r ) ;
    }
    return fabs( res ) ;
}
// 简单多边形与圆面积交
//p 简单多边形(有序),n 多边形个数, o 圆心 r 半径


int main(){
    
    return 0;
}
