#include<iostream>
#include<string>
#include<vector>
using namespace std;
//定义日期类 存储员工生日
class date{
	private:
	int year,month,day;
	public:
	//构造函数
	date(int y,int m,int d):year(y),month(m),day(d){}
	//返回日期情况
	int show_year(){
		return year;
	}
	int show_month(){
		return month;
	}
	int show_day(){
		return day;
	}
};
//定义雇员类 存储姓名 id以及生日
class employee{
	public:
	string name;
	int id;
	date birthday;
	//构造函数
	employee(string n,int i,date b):name(n),id(i),birthday(b){}
	//计算员工收入 设定为虚函数
	virtual double cal_salary(int m)=0;
	//输出员工信息 设定为虚函数
	virtual void show_info(int m)=0;
};
//周薪雇员类
class SalariedEmployee:public employee{
	double week_salary;
	public:
	//构造函数
	SalariedEmployee(string n,int i,double w,date b):employee(n,i,b),week_salary(w){}
	//计算员工收入 如果生日在本月+100
	double cal_salary(int m){
		return m==birthday.show_month()?week_salary+100:week_salary;
	}
	//输出雇员信息
	void show_info(int m) {
		cout<<"雇员类型：周薪雇员"<<endl;
		cout<<"姓名："<<this->name<<endl;
		cout<<"工号："<<id<<endl;
		cout<<"固定周薪："<<week_salary<<endl;
		cout<<"工资："<<cal_salary(m)<<endl;
		cout<<"生日："<<birthday.show_year()<<"年"<<birthday.show_month()<<"月"<<birthday.show_day()<<"日"<<endl;
	}
};
//时薪雇员类
class HourlyEmployee:public employee{
	double hour_salary;
	int hour;
	public:
	//构造函数
	HourlyEmployee(string n,int i,double s,int h,date b):employee(n,i,b),hour_salary(s),hour(h){}
	//计算员工收入 如果生日在本月+100
	double cal_salary(int m){
		if(hour<40)
			return m==birthday.show_month()?hour*hour_salary+100:hour*hour_salary;
		else
			return m==birthday.show_month()?40*hour_salary+(hour-40)*hour_salary*1.5+100:40*hour_salary+(hour-40)*hour_salary*1.5;
	}
	//输出雇员信息
	void show_info(int m){
		cout<<"雇员类型：时薪雇员"<<endl;
		cout<<"姓名："<<this->name<<endl;
		cout<<"工号："<<id<<endl;
		cout<<"固定时薪："<<hour_salary<<endl;
		cout<<"工作时长："<<hour<<endl;
		cout<<"工资："<<cal_salary(m)<<endl;
		cout<<"生日："<<birthday.show_year()<<"年"<<birthday.show_month()<<"月"<<birthday.show_day()<<"日"<<endl;
	}
};
//佣金雇员类
class CommissionEmployee:public employee{
	double com_salary;
	int n;
	public:
	//构造函数
	CommissionEmployee(string n,int i,double c,int h,date b):employee(n,i,b),com_salary(c),n(h){}
	//计算员工收入 如果生日在本月+100
	double cal_salary(int m){ 
		return m==birthday.show_month()?n*com_salary+100:n*com_salary;
	}
	//输出雇员信息
	void show_info(int m){
		cout<<"雇员类型：佣金雇员"<<endl;
		cout<<"姓名："<<this->name<<endl;
		cout<<"工号："<<id<<endl;
		cout<<"销售佣金："<<com_salary<<endl;
		cout<<"销售数量："<<n<<endl;
		cout<<"工资："<<cal_salary(m)<<endl;
		cout<<"生日："<<birthday.show_year()<<"年"<<birthday.show_month()<<"月"<<birthday.show_day()<<"日"<<endl;
	}
};
//带底薪佣金雇员类
class BasePlusCommissionEmployee:public employee{
	double base_salary;
	int n;
	double com_salary;
	public:
	//构造函数
	BasePlusCommissionEmployee(string n,int i,double s,int h,double c,date b):employee(n,i,b),base_salary(s),n(h),com_salary(c){}
	//计算员工收入 如果生日在本月+100
	double cal_salary(int m){
		return m==birthday.show_month()?base_salary*1.1+n*com_salary+100:base_salary*1.1+n*com_salary;
	}
	//输出雇员信息
	void show_info(int m){
		cout<<"雇员类型：带底薪佣金雇员"<<endl;
		cout<<"姓名："<<this->name<<endl;
		cout<<"工号："<<id<<endl;
		cout<<"底薪："<<base_salary<<endl;
		cout<<"销售数量："<<n<<endl;
		cout<<"销售佣金："<<com_salary<<endl;
		cout<<"工资："<<cal_salary(m)<<endl;
		cout<<"生日："<<birthday.show_year()<<"年"<<birthday.show_month()<<"月"<<birthday.show_day()<<"日"<<endl;
	}
};
//测试函数
int main(){
	//依次建立定义的雇员类
	date BD1(2004,4,26);
	employee*emp1=new SalariedEmployee("小a",15221014,3000,BD1);
	date BD2(2004,7,21);
	employee*emp2=new HourlyEmployee("小b",15221015,50,60,BD2);
	date BD3(2004,5,20);
	employee*emp3=new CommissionEmployee("小c",15221016,45,75,BD3);
	date BD4(2004,10,24);
	employee*emp4=new BasePlusCommissionEmployee("小d",15221017,1000,40,55,BD4);
	vector<employee*>employees;
	employees.emplace_back(emp1);
	employees.emplace_back(emp2);
	employees.emplace_back(emp3);
	employees.emplace_back(emp4);
	for(auto i=employees.begin();i!=employees.end();i++)
		(*i)->show_info(4);
	return 0;
}