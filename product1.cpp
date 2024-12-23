#include<iostream>
using namespace std;
//摄像机类实现
class camera{
	int code;
    protected:
	int img_q;
    public:
    //camera类构造函数
	camera():img_q(0),code(0){
        cout<<"camera类构造函数"<<endl;
    }
	camera(int i,int j):img_q(i),code(j){
        cout<<"camera类构造函数"<<endl;
    }
	//摄像功能
	void picture(){
        cout<<"摄像"<<endl;
    }
	//设定图片质量
	void set_img_q(){
        cout<<"图片质量设定"<<endl;
        img_q=1;
    }
	//设定编码算法
	void set_code(){
        cout<<"编码算法设定"<<endl;
        code=1;
    }
	//camera类析构函数
	~camera(){
        cout<<"camera类析构函数"<<endl;
    }
};
//芯片类实现
class chip:public camera{
    public:
	//操作菜单
	void menu(){
        cout<<"操作菜单"<<endl;
    }
	//车速传感器
	void sensor(){
        cout<<"车速传感器"<<endl;
    }
	//自动拍摄
	void autoshoot(){
        cout<<"自动拍摄"<<endl;
    }
	//源代码
	void coding(){
        cout<<"源代码"<<endl;
    }
};
//行车记录仪1类实现
class DVR_1:public camera{
	private:
	chip chip1;
	public:
	//构造函数
	DVR_1():camera(){
		cout<<"public继承 DVR_1类构造函数"<<endl;
	}
	DVR_1(int i,int j):camera(i,j){
		cout<<"public继承 DVR_1类构造函数"<<endl;
	}
	//芯片操作菜单
	void call_menu(){
		chip1.menu();
	}
	//析构函数
	~DVR_1(){
		cout<<"public继承 DVR_1类析构函数"<<endl;
	}
};
//行车记录仪2类实现
class DVR_2:protected camera{
	private:
	chip chip2;
	public:
	//构造函数
	DVR_2():camera(){
		cout<<"protected继承 DVR_2类构造函数"<<endl;
	}
	DVR_2(int i,int j):camera(i,j){
		cout<<"protected继承 DVR_2类构造函数"<<endl;
	}
	//芯片操作菜单
	void call_menu(){
		chip2.menu();
	}
	//析构函数
	~DVR_2(){
		cout<<"protected继承 DVR_2类析构函数"<<endl;
	}
};
//行车记录仪3类构造
class DVR_3:private camera{
	private:
	chip chip3;
	public:
	//构造函数
	DVR_3():camera(){
		cout<<"private继承 DVR_3类构造函数"<<endl;
	}
	DVR_3(int i,int j):camera(i,j){
		cout<<"private继承 DVR_3类构造函数"<<endl;
	}
	//芯片操作菜单
	void call_menu(){
		chip3.menu();
	}
	//析构函数
	~DVR_3(){
		cout<<"private继承 DVR_3类析构函数"<<endl;
	}
};
int main(){
	camera ca;
	ca.picture();
	ca.set_img_q();
	ca.set_code();
	DVR_1 ta1;
	ta1.picture();
	ta1.call_menu();
	DVR_2 ta2;
	ta2.call_menu();
	DVR_3 ta3;
	ta3.call_menu();
}