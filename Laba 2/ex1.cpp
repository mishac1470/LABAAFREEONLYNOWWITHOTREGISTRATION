#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <ctime>
#include <stdlib.h>
#include <algorithm>

using namespace std;

void SposobZapoln(vector<string> &names, vector<int> &marks){
    int i;
    cout << "1. Анализ на дефолтном массиве\n2. Анализ на выборке из дефолтного массива\n3. Анализ на вашем массиве\n";
    cin >> i;
    switch(i){
        case 1:
        {
        names = {"Вася", "Валера", "Генадий", "Володя", "Владимер", "СВЯТОслав", "СуньЮнь", "Масяня", "Жёра", "Димоооон"};
        marks = {1, 2, 4, 8, 16, 32, 64, 32, 64, 100};
        break;
        }
        
        case 2:
        {
        vector<string> AllNames{"Мавр", "Мавра", "Маврикий", "Мавродий", "Мавсима", "Магда", "Магдалина", "Магистриан", "Магн", "Магна", "Магрин", "Маина", "Маиса", "Май", "Майор", "Майя", "Макар", "Макарий", "Македон", "Македоний", "Макрида", "Макрина", "Макровий", "Макс", "Максентий", "Максиан", "Максим", "Максима", "Максимиан", "Максимилиан", "Максимильян", "Мал", "Малания", "Маланья", "Малафей", "Малахей", "Малахий", "Малахия", "Малей", "Малина", "Малх", "Мальвина", "Мамант", "Мамелфа", "Мамелхва", "Маммий", "Манефа", "Манефия", "Мануил", "Мануйла", "Мануйло", "Мар", "Маргарита", "Мардар", "Мардарий", "Мардоний", "Марей", "Марес", "Маресий", "Марея", "Мариав", "Мариам", "Мариамна", "Мариан", "Мариана", "Марианна", "Марий", "Маримьяна", "Марин", "Марина", "Марионелла", "Марионилла", "Мария", "Марк", "Марка", "Маркей", "Маркел", "Маркелл", "Маркеллин", "Маркеллина", "Маркиан", "Маркий", "Маркиян", "Марлен", "Марлена", "Марон", "Марсалий", "Март", "Марта", "Мартиан", "Мартимьян", "Мартин", "Мартина", "Мартиниан", "Мартиниана", "Мартирий", "Мартын", "Мартьян", "Маруф", "Марфа"};
        auto iter = AllNames.cbegin();
        int viborka, randznach;
        
        do {
        cout << "Введите размер выборки, которая не превосходит " << AllNames.size() << '\n';
        cin >> viborka;
        } while(AllNames.size() < viborka);
        
        for(i = 0; i < viborka; ++i){
            randznach = rand()%AllNames.size();
            names.push_back(AllNames[randznach]);
            AllNames.erase(iter + randznach);
            marks.push_back(rand()%101);
        }
        break;
        }
        
        case 3:
        {
        int flag=0;
        string name;
        int mark;
        while (flag == 0){
            cout << "Введите имя ученика, если вы всё ввели, напишите \"EndEnter\"\n";
            cin >> name;
            if (name == "EndEnter"){break;}
            names.push_back(name);
            cout << "Введите оценку данного ученика (0-100)\n";
            cin >> mark;
            marks.push_back(mark);
        }
        break;
        }
        
        default:
        {
            char ex;
            cout << "Ужс, даже цифру из 3 правильно выбрать не смог.";
            scanf("%s", &ex);
            exit;
        }
    }
}

float median(vector<int> masiv)
{
    sort(masiv.begin(), masiv.end()); 
    if (masiv.size() % 2 == 1){return masiv[masiv.size() / 2];}
    else {return 0.5 * (masiv[masiv.size() / 2 - 1] + masiv[masiv.size() / 2]);}
}       

float srznach(vector<int> masiv)
{
   float znach = 0;
   for(int i: masiv){
         znach+=i;
     }
   return znach/masiv.size();
}

vector<int> moda(vector<int> masiv)
{
    vector<int> Moda{};
    sort(masiv.begin(), masiv.end());
    int count = 0, check = 0, max = 0, maxcheck = 0;
    for(int i: masiv){
        if (i != check)
        {
            if (max == count)
            {
                maxcheck = check;
                Moda.push_back(maxcheck);
            }
            
            if (max < count)
            {
                maxcheck = check;
                Moda.clear();
                Moda.push_back(maxcheck);
                max = count;
            }
            
            check = i;
            count = 0;
        }
        count++;
    }
    return Moda;
}

int main()
{
    srand(time(NULL));
    vector<string> names{};
    vector<int> marks{};
    SposobZapoln(names, marks);
    
    // auto itern{names.cbegin()};
    // auto iterm{marks.cbegin()};
    // for(int j = 0; j < names.size(); ++j){
    //     cout << *(itern + j) << ' ' << *(iterm + j) << " | ";
    // }
    
    //for(string j: names){
    //    cout << j << ' ';
    //}
    // cout << '\n';
    //for(int j: marks){
    //    cout << j << ' ';
    //}
    
     for(int j = 0; j < names.size(); ++j){
         cout << names[j] << ' ' << marks[j] << endl;
     }
     cout << "Среднее значение: " << srznach(marks) << endl;
     cout << "Медиана: " << median(marks) << endl;
     vector<int> modaMasiv = moda(marks);
     cout << "Мода: ";
     for(int i : modaMasiv){
         cout << i << ' ';
     }
    return 0;
}