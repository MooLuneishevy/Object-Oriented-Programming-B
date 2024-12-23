#ifndef ploynomial_h
#define ploynomial_h
#include<iostream>
#include<cmath>
using namespace std;
//多项式类的定义
class polynomial{
    int n;
    double*p;
    public:
    //存储的多项式数目
    static int count;
    polynomial():n(0),p(nullptr){
        count++;
    }
    //构造函数 new创建动态数组
    polynomial(int t):n(t),p(new double[n+1]){
        count++;
    }
    //拷贝函数
    polynomial(const polynomial&a):n(a.n),p(new double[a.n+1]){
        for(int i=0;i<n+1;i++)
            this->p[i]=a.p[i];
        count++;
    }
    //析构函数 释放动态数组空间
    ~polynomial(){
        delete[]p;
        --count;
    }
    //多项式创建
    void create();
    //多项式输出
    void const show() const;
    //多项式计算
    double const calculate(double x)const;
    //+运算符重载
    friend polynomial operator+(const polynomial&a,const polynomial&b);
    //-运算符重载
    friend polynomial operator-(const polynomial&a,const polynomial&b);
    //*运算符重载
    friend polynomial operator*(const polynomial&a,const polynomial&b);
    //=运算符重载
    polynomial&operator=(const polynomial&a);
};
#endif