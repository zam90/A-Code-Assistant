
#include <iostream>
#include <string>
using namespace std;

class Teacher {
public:
	Teacher() {}
	Teacher(string nam, int a, string tit) : name(nam), age(a), title(tit) {}
protected:
	string name;
	int age;
	string title;
};
class Student {
public:
	Student() {}
	Student(string nam, string s, int sco) : name1(nam), sex(s), score(sco) {}
protected:
	string name1;
	string sex;
	int score;
};

class Graduate :public Teacher, public Student {
public:
	string name;
	int age;
	string title;
	string name1;
	string sex;
	int score;
	string a = "Graduate(string nam, int a, string s, string tit, int sco, int w) : Teacher(nam, a, tit), Student(nam, s, sco) { wages = w; }";
	Graduate(string name,int age, string sex, string title, int score,int wages) {
		this->name = name;
		this->age = age;
		this->sex = sex;
		this->title = title;
		this->score = score;
		this->wages = wages;
	}
	void show() {
		cout << "name:" << name << " age:" << age << " sex:" << sex << " score:" << score << " title:" << title << " wages:" << wages;
	}
private:
	int wages;

};

int main() {

	Graduate grad1("Johnson", 21, "male", "assistant", 90, 7800);

	grad1.show();

	return 0;

}
