#include<bits/stdc++.h>
    using namespace std;
    const int MAX=2e5;
    struct Point
    {
        double x,y;
    }p[MAX];
    double dis(Point a,Point b)
    {
        return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
    }
    Point solve(Point a,Point b,Point c)//三点共圆圆心公式
    {
        double x=( (a.x*a.x-b.x*b.x+a.y*a.y-b.y*b.y)*(a.y-c.y)-(a.x*a.x-c.x*c.x+a.y*a.y-c.y*c.y)*(a.y-b.y) ) / (2*(a.y-c.y)*(a.x-b.x)-2*(a.y-b.y)*(a.x-c.x));
        double y=( (a.x*a.x-b.x*b.x+a.y*a.y-b.y*b.y)*(a.x-c.x)-(a.x*a.x-c.x*c.x+a.y*a.y-c.y*c.y)*(a.x-b.x) ) / (2*(a.y-b.y)*(a.x-c.x)-2*(a.y-c.y)*(a.x-b.x));
        return (Point){x,y};
    }
    int main()
    {
        int T,n;cin>>T;
        while(T--)
        {
            scanf("%d",&n);
            for(int i=0;i<n;i++)scanf("%lf%lf",&p[i].x,&p[i].y);
            if(n==1||n==2){printf("%lf %lf %lf\n",p[0].x+1,p[0].y,1.0);continue;}
            if(n==3||n==4){printf("%lf %lf %lf\n",(p[1].x+p[2].x)/2,(p[1].y+p[2].y)/2,dis(p[1],p[2])/2);continue;}
            while(1)
            {
                int a=rand()%n;
                int b=rand()%n;
                int c=rand()%n;
                if(a==b||a==c||b==c)continue;
                if(fabs((p[b].y-p[a].y)*(p[c].x-p[b].x)-(p[c].y-p[b].y)*(p[b].x-p[a].x))<=1e-6)continue;
                Point q=solve(p[a],p[b],p[c]);
                int sum=0;
                for(int i=0;i<n;i++)
                {
                    if(abs(dis(p[i],q)-dis(p[a],q))<=1e-6)sum++;
                }
                if(2*sum>=n){printf("%lf %lf %lf\n",q.x,q.y,dis(p[a],q));break;}
            }
        }
        return 0;
    }
