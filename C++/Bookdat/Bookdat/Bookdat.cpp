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
	outbook.open("book.dat", ios::trunc);  //д��book.datû�����½�һ��book.dat
	cout << "�������������������ơ�����������ͼ�鶨��:" << endl;  //������Ϣ
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
	outbook.close();       //�ر��ļ�
	inbook.open("book.dat");  //��ȡ
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
			s[i].in(name[0], name[1], name[2], p); //������Ӧ��book����
			s[i].sump();  //�ۼӼ۸�
		}
	}
	cout << "����ͼ����ܼ۸�" << s[1].getsum() << endl; 
	cout << "ͼ����Ϣ���£�" << endl;
	for (int i = 0; i < 10; i++) {
		s[i].show();
	}
	inbook.close();
}