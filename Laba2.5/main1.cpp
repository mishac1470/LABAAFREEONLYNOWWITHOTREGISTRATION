#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main(){
    // Количество совпадений
    string s = "фыф";
    int n = 0, i = 0;
    char ch;
    bool f = false, ff = false;
    vector<string> vec;

    ifstream in1("test1.txt");
    if(in1.is_open()){
        while(in1.get(ch)){
            if(ff == true){
                if(ch == ' ' || ch == '\n'){
                    ff = false;
                }
                continue;
            }
            if(f == true){
                if(ch != ' ' && ch != '\n'){
                    n--;
                    ff = true;
                }
                f = false;
                continue;
            }
            if(ch != s[i]){
                i = 0;
                ff = true;
                continue;
            }
            else{
                i++;
            }
            if(i == s.length()){
                n++;
                f = true;
                i = 0;
            }
        }
    }
    in1.close();

    cout << n << endl;

    return 0;
}