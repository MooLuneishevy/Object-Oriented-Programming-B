#include<iostream>
#include<vector>
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
	//摄像功能 设为虚函数
	virtual void picture(){
		cout<<"摄像"<<endl;
	}
	//设定图片质量
	void set_img_q(){
		cout<<"图片质量设定"<<endl;
		img_q=1;
	}
	//设定编码算法
	void set_code(){
		cout<<"编码算法功能设定"<<endl;
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
	//芯片类构造函数
	chip(){
		cout<<"芯片类构造函数"<<endl;
	}
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
	//芯片类析构函数
	~chip(){
		cout<<"芯片类析构函数"<<endl;
	}
};
//行车记录仪类实现
class DVR{
	camera ca;
	chip ch;
	public:
	//构造函数
	DVR(){
		cout<<"DVR构造函数"<<endl;
	}
	//摄像功能
	void picture(){
		ca.picture();
	}
	//操作菜单
	void menu(){
		ch.menu();
	}
	//析构函数
	~DVR(){
		cout<<"DVR析构函数"<<endl;
	}
};
int main() {
	camera*cam=new camera();
	camera*chi=new chip();
	vector<camera*>vec;
	vec.emplace_back(cam);
	vec.emplace_back(chi);
	//利用基类指针容器调用虚函数
	for(auto i=vec.begin();i!=vec.end();i++)
		(*i)->picture();
    delete cam;
	delete chi;
	DVR dv;
	dv.picture();
	dv.menu();
}