
#include<iostream> 
#include <vector> 
#include<algorithm>  
using namespace std;
using std::vector;

double greedy(vector<int>x, int s)
{
	vector<int>st(s + 1, 0);
	vector<int>su(s + 1, 0);
	int n = x.size();
	sort(x.begin(), x.end());
	int i = 0, j = 0;
	while (i < n) {
		st[j] += x[i];
		su[j] += st[j];
		i++;j++;
		if (j == s)j = 0;
	}
	double t= 0;
	for (i = 0; i < s; i++)
		t += su[i];
	t /= n;
	return t;
}

void  main()
{
	int n,s,i,a,t;
	vector<int>x;
	cin >> n;
	cin >> s;
	for (i = 1; i <= n; i++)
	{
		cin >> a;
		x.push_back(a);
	}
	t = greedy(x, s);
	cout << endl << t << endl;
}