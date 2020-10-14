#include <iostream>
using namespace std;

template <class numtype>
class compare {
private:
	numtype a, b;
public:
	compare() {

	}
	compare(numtype a,numtype b) {
		this->a = a;
		this->b = b;
	}
	numtype comparemax(numtype a, numtype b) {
		if (a >= b) {
			return a;
		}
		else {
			return b;
		}
	}
	numtype comparemin(numtype a, numtype b) {
		if (a <= b) {
			return a;
		}
		else {
			return b;
		}
	}
	bool compareequ(numtype a, numtype b) {
		if (a == b) {
			return true;
		}
		else{
			return false;
		}
	}
};

int main(){
	double a = 0, b = 0;
	cout << "������a,b:" << endl;
	cin >> a;
	cin >> b;
	compare<double> com1(a,b);
	cout << "���ֵ��" << com1.comparemax(a, b) << endl;
	cout << "��Сֵ��" << com1.comparemin(a, b) << endl;
	cout << "�Ƿ���ȣ�"<< com1.compareequ(a, b) << endl;

	int c = 0, d = 0;
	cout << "������c,d:" << endl;
	cin >> c;
	cin >> d;
	compare<int> com2(c, d);
	cout << "���ֵ��" << com2.comparemax(c, d) << endl;
	cout << "��Сֵ��" << com2.comparemin(c, d) << endl;
	cout << "�Ƿ���ȣ�" << com2.compareequ(c, d) << endl;
}