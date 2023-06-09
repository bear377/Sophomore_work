#include<iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;


class Book {
public:
	static float sum;
	void in(string a,string b,string c,float d) {
		Bname = a;
		Aname = b;
		Pname = c;
		price = d;
	};
	void sump() {
		sum += price;
	}
	float getsum() {
		return sum;
	}
	void show() {
		cout << Bname << '\t' << Aname << '\t'  << Pname << '\t' << price << endl;
	}

private:
	string Bname;
	string Aname;
	string Pname;
	float price;
};
float Book::sum = 0;

void main(){
	Book* s = new Book[10];
	ofstream outbook;
	ifstream inbook;
	string name[3];
	float p ;
	outbook.open("book.dat", ios::trunc);  //写入book.dat没有则新建一个book.dat
	cout << "输入书名、出版社名称、作者姓名、图书定价:" << endl;  //输入信息
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 4; j++) {
			if (j == 3) { 
				cin >> p; 
				outbook << p;
			}
			else {
				string c;
				cin >> c;
				outbook << c;
				outbook << " ";
			}
		}
		if(i!=9) outbook << "\n";  
	}
	outbook.close();       //关闭文件
	inbook.open("book.dat");  //读取
	while (!inbook.eof()){
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 4; j++) {
				if (j == 3) {
					inbook >> p;
				}
				else {
					inbook >> name[j];
				}
			}
			s[i].in(name[0], name[1], name[2], p); //建立对应的book对象
			s[i].sump();  //累加价格
		}
	}
	cout << "所有图书的总价格：" << s[1].getsum() << endl; 
	cout << "图书信息如下：" << endl;
	for (int i = 0; i < 10; i++) {
		s[i].show();
	}
	inbook.close();
}