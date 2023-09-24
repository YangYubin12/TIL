#include <iostream>
using namespace std;

int main()
{
	int a, b;
	string s;
	cin >> s >> a >> b;
	cout << s.substr(a,b);
	return 0;
}
