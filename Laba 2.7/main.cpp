#include <iostream>
#include <chrono>
#include <vector>
#include <list>

using namespace std;

int main(){
	vector<int> vect{1, 2, 3, 4, 5};
	list<int> list{1, 2, 3, 4, 5};

	cout << sizeof(vect.begin()) * 3 + sizeof(vect[0]) * vect.capacity() << endl;
	cout << sizeof(list.begin()) * (2 * list.size() + 2) + sizeof(list.size()) + sizeof(list.front()) * list.size() << endl;

	chrono::time_point<chrono::system_clock> start1, end1, start2, end2;

	start1 = chrono::system_clock::now();
	for(int i = 0; i < 100000; i++){
		vect.insert(vect.begin(), 10);
	}
	end1 = chrono::system_clock::now();
	chrono::duration<double> diff1 = end1 - start1;

	start2 = chrono::system_clock::now();
	for(int i = 0; i < 100000; i++){
		list.insert(list.begin(), 10);
	}
	end2 = chrono::system_clock::now();
	chrono::duration<double> diff2 = end2 - start2;
	cout << diff1.count() << endl << diff2.count() << endl;

	return 0;
}