#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
    ifstream in("text.txt");
    istream_iterator<int> start(in), end;
    vector<int> vec(start, end);

    ostream_iterator<int> out(cout, " ");
    copy(vec.begin(), vec.end(), out);
    cout << endl;

    reverse(vec.begin(), vec.end());
    copy(vec.begin(), vec.end(), out);
    cout << endl;

    cout << *min_element(vec.begin(), vec.end()) << endl;

    vec.erase(remove_if(vec.begin(), vec.end(), [](int i){return i % 2 == 0;}), vec.end());
    copy(vec.begin(), vec.end(), out);
    cout << endl;

    sort(vec.begin(), vec.end(), greater<int>());
    copy(vec.begin(), vec.end(), out);
    cout << endl;

    int a = 16;
    vec.insert(find_if(vec.begin(), vec.end(), [a](int i){return i < a;}), a);
    copy(vec.begin(), vec.end(), out);
    cout << endl;

    vec.insert(find_if(vec.begin(), vec.end(), [a](int i){return i < a;}), a);
    cout << distance(vec.begin(), find_if(vec.begin(), vec.end(), [a](int i){return i == a;})) << endl;

    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    copy(vec.begin(), vec.end(), out);
    cout << endl;

    return 0;
}