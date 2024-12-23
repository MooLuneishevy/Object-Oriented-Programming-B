#include"polynomial.h"
//多项式创建
void polynomial::create(){
    cout<<"Please enter the highest power"<<endl;
    cin>>n;
    p=new double[n+1];
    cout<<"Please enter the coefficients in sequence"<<endl;
    for(int i=0;i<n+1;i++)
        cin>>p[i];
}
//多项式输出
const void polynomial::show()const{
    for(int i=n;i>=0;i--){
        if(p[i]!=0){
            if(i==n){
                if(p[i]==1)
                    cout<<"x^"<<i;
                else if(p[i]==-1)
                    cout<<"-x^"<<i;
                else
                    cout<<p[i]<<"x^"<<i;
            }
            else if(i==0){
                if(p[i]>0)
                    cout<<"+"<<p[i];
                else
                    cout<<p[i];
            }
            else if(p[i]>0){
                if(p[i]==1)
                    cout<<"+x^"<<i;
                else
                    cout<<"+"<<p[i]<<"x^"<<i;
            }
            else{
                if(p[i]==-1)
                    cout<<"-x^"<<i;
                else
                    cout<<p[i]<<"x^"<<i;
            }
        }
    }
    cout<<endl;
}
//多项式输出
const double polynomial::calculate(double x)const{
    double sum=0;
    double xi=1;
    for(int i=0;i<n+1;i++){
        sum+=p[i]*xi;
        xi*=x;
    }
    return sum;
}
//+运算符重载
polynomial operator+(const polynomial&a,const polynomial&b){
    int n=a.n>b.n?a.n:b.n;
    polynomial c(n);
    for(int i=0;i<n+1;i++){
        if(i<=a.n && i<=b.n)
            c.p[i]=a.p[i]+b.p[i];
        else if(i<=a.n)
            c.p[i]=a.p[i];
        else
            c.p[i]=b.p[i];
    }
    return c;
}
//-运算符重载
polynomial operator-(const polynomial&a,const polynomial&b){
    int n=a.n>b.n?a.n:b.n;
    polynomial c(n);
    for(int i=0;i<n+1;i++){
        if(i<=a.n && i<=b.n)
            c.p[i]=a.p[i]-b.p[i];
        else if(i<=a.n)
            c.p[i]=a.p[i];
        else
            c.p[i]=-b.p[i];
    }
    return c;
}
//*运算符重载
polynomial operator*(const polynomial&a,const polynomial&b){
    int n=a.n+b.n;
    polynomial c(n);
    for(int i=0;i<a.n+1;i++){
        for(int j=0;j<b.n+1;j++)
            c.p[i+j]=a.p[i]*b.p[j];
    }
    return c;
}
//=运算符重载
polynomial&polynomial::operator=(const polynomial&a){
    if(&a==this)
        return*this;
    this->n=a.n;
    delete[]this->p;
    this->p=new double[n+1];
    for(int i=0;i<n+1;i++)
        this->p[i]=a.p[i];
    return*this;
}
//初始化count
int polynomial::count=0;
int main(){
    polynomial a,b;
    a.create();
    b.create();
    cout<<"a=";
    a.show();
    cout<<"b=";
    b.show();
    polynomial c;
    polynomial d(a);
    cout<<"d=";
    d.show();
    cout<<"a+b=";
    c=a+b;
    c.show();
    cout<<"a-b=";
    c=a-b;
    c.show();
    cout<<"a*b=";
    c=a*b;
    c.show();
    cout<<"a=b=";
    c=a=b;
    c.show();
    cout<<"when x=1 a="<<a.calculate(1)<<endl;
    return 0;
}