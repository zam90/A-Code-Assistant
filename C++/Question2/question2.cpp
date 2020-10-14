#include <iostream>
#include <string>
using namespace std;

class Student {
private:
	string name;
	string number;
public:
	Student() {

	}
	Student(string a, string b) {
		this->name = a;
		this->number = b;
	}
	~Student() {
		cout << "delete!";
	}
};

int main() {
	Student* p = new Student("John", "2016010916");
	delete p;
	return 0;
}