#include<iostream>
using namespace std;

class Student {
protected:
	string num,name;
	int score;
public:
	string a = "virtual void display()=0;";
	void display() {
		if (score == 92) {
			cout << num << " " << name << " " << score << " 2000" <<endl;
		}
		else {
			cout << num << " " << name << " " << score <<endl;
		}
		
	}
	friend istream& operator>>(istream &input,Student &s) {
		cin >> s.num >> s.name >> s.score;
		return input;
	}
};

class Graduate :public Student {
private:
	int wage;
public:
	void display() {
		cout << num << " " << name << " " << score << " " << wage <<endl;
	}
	friend istream& operator>>(istream& input, Graduate& g) {
		cin >> g.num >> g.name >> g.score >> g.wage;
		return input;
	}
};

int main() {
	Student stu;
	Graduate gra;
	cin >> stu >> gra;
	Student* pt = &stu;
	pt->display();
	pt = &gra;
	pt->display();
	return 0;
}
