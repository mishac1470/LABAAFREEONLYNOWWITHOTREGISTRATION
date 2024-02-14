#include <iostream>
#include <vector>

using namespace std;

class cashRegister{
private:
   int cashOnHand;
   
public:
    cashRegister(): cashOnHand(500){}
    cashRegister(int cash): cashOnHand(cash){}
    
    int getCurrentBalance(){return cashOnHand;}
    void acceptAmount(int cash){cashOnHand += cash;}
};

class dispenserType{
private:
    int numberOfItems;
    int TypeCost;
    
public:
    dispenserType(): numberOfItems(50), TypeCost(50){}
    dispenserType(int cost, int count): numberOfItems(count), TypeCost(cost){}

    int getNoOfItems(){return numberOfItems;}
    int getCost(){return TypeCost;}
    void makeSale(){--numberOfItems;}
};

void showSelection(cashRegister&);
void sellProduct(cashRegister&, vector<dispenserType>&, int&);

int main(){
    cashRegister machine;
    
    showSelection(machine);


    return 0;
}

void showSelection(cashRegister& machine){
    vector<dispenserType> dispenser{dispenserType(), dispenserType(2000, 2), dispenserType(48, 79), dispenserType(2, 157)};
    
    bool first = true;
    
    int user;
    
    while(true){
        cout << "Вкуснейшие печенюшечки - 1" << endl;
        cout << "Идеально плоские чипсы - 2" << endl;
        cout << "Конфеты 'сногсшибающий улёт' - 3 (удар по ценам)" << endl;
        cout << "'Не отлепишь' - 4" << endl;
        if(first){cout << "Уйти, и не наполнить свой день красками - 0" << endl;}
        else{cout << "Cпасибо за покупки :) - 0" << endl;}
    
        cin >> user;
        
        if(user == 0){break;}
        if(user != 0){
            first = false;
            --user;
            if(dispenser[user].getNoOfItems() != 0){sellProduct(machine, dispenser, user);}
            else{cout << "К сожалению, это изысканное лакомство сейчас отсутствует в наличии,\nв следующий раз повезёт ;)\n" << endl;}
        }
    }
}

void sellProduct(cashRegister& machine, vector<dispenserType>& dispenser, int& user){
    cout << "Это чудо стоит " <<dispenser[user].getCost() << " воображаемой валюты" << endl;
    int money;
    cin >> money;
    if(money >= dispenser[user].getCost()){
        dispenser[user].makeSale();
        machine.acceptAmount(dispenser[user].getCost());
        if(money - dispenser[user].getCost() > 0){cout << "Наслаждайтесь лучшими мгновеньями жизни!\nВаша сдача " << money - dispenser[user].getCost() << "\n" << endl;}
        else{cout << "\n";}
    }
    else{cout << "К сожалению, вы не можете позволить себе это невероятное лакомство ;)\n" << endl;}
}