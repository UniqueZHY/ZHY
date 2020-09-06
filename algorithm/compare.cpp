/*************************************************************************
	> File Name: compare.cpp
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月19日 星期二 22时59分35秒
 ************************************************************************/
struct m {
	string name;
	int sum = 0;
}arr[100];

int main() {
	int n, x, maxx = 0, minn = 100, summ = 0, y, z;
	cin >> n;
	string a, s;
	for (int i = 0; i < n; i++) {
		cin >> a;
		for (int j = 0; j < 4; j++) {
			cin >> y;
			arr[i].sum += y;
			if (y > maxx) maxx = y;
			if (y < minn) minn = y;
		}
		if (arr[i].sum > summ) {
			summ = arr[i].sum;
			z = i;
		}
		arr[i].name = a;
	}
	for (int i = 0; i < n; i++) {
		cout << arr[i].sum << endl;
	}
	cout << arr[z].name << endl;
	cout << maxx << ' ' << minn;
	return 0;
