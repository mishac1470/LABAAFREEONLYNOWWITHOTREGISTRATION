#include <string> 
#include <iostream> 
 
/* 
1) strlen - str.length() 
2) strcpy - str1 = str2 
3) strcmp - strcmp(), compare() 
4) strcat - strcat(), + 
5) someString[index] - someString[index] 
6) strcat - push_back 
7) strcpy - pop_back 
 
В C строки это char массивы, заканчивающиеся нулевым байтом, 
в C++ строки имеют автоматизированное динамическое распределение памяти. 
*/ 
 
using namespace std; 
 
string RemoveSymbols(string str){ 
    string clearString; 
    for(int i = 0; i < str.length(); ++i){ 
        if(str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z'){ 
            clearString += str[i]; 
        } 
    } 
    return clearString; 
} 
 
string Sorting(string clearString){ 
    char minElement; 
    string sortedString; 
    while(clearString.length() != 0){ 
        minElement = clearString[0]; 
        for(int i = 0; i < clearString.length(); ++i){ 
            if(clearString[i] < minElement){ 
                minElement = clearString[i]; 
            } 
        } 
        sortedString += minElement; 
         
        clearString.replace(clearString.find(minElement), 1, ""); 
    } 
    return sortedString; 
} 
 
 
int main() 
{ 
    string str, sortedString; 
    getline(cin, str); 
    str = RemoveSymbols(str); 
    cout << Sorting(str); 
 
    return 0; 
}