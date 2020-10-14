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
	cout << "请输入a,b:" << endl;
	cin >> a;
	cin >> b;
	compare<double> com1(a,b);
	cout << "最大值：" << com1.comparemax(a, b) << endl;
	cout << "最小值：" << com1.comparemin(a, b) << endl;
	cout << "是否相等："<< com1.compareequ(a, b) << endl;

	int c = 0, d = 0;
	cout << "请输入c,d:" << endl;
	cin >> c;
	cin >> d;
	compare<int> com2(c, d);
	cout << "最大值：" << com2.comparemax(c, d) << endl;
	cout << "最小值：" << com2.comparemin(c, d) << endl;
	cout << "是否相等：" << com2.compareequ(c, d) << endl;
}