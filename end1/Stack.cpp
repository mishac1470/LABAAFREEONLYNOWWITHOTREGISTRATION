#include <iostream>


using namespace std;

class Node{
    private:
    int key;
    Node* p;

    public:
    Node(int value){this->key = value; this->p = nullptr;}
    ~Node(){}

    void setKey(int _key){this->key = _key;}
    void setP(Node* _p){this->p = _p;}

    int getKey(){return this->key;}
    Node* getP(){return this->p;}
};

class Stack{
    private:
    Node* top;
    int length = 0;

    public:
    Stack(){top = nullptr;}
    ~Stack(){}

    void setTop(Node* top){
        this->top = top;
    }

    Node* getTop(){return this->top;}

    void push(int value){
        this->length++;

        Node* temp = new Node(value);

        if(!temp){
            cout << "Stack Overflow\n" << endl;
            exit(1);
        }

        temp->setKey(value);
        temp->setP(top);
        top = temp;

    }

    void isEmpty(){
        if(top == nullptr){
            cout << "Stack is empty\n";
        }
        else{
            cout << "Stack is not empty\n";
        }
    }

    bool noCoutIsEmpty(){
        return top == nullptr;
    }

    void isFull(){
        cout << "It's a dynamic stack and it's never full\n";
    }

    void pop(){
        Node* temp;

        if(top == nullptr){
            cout << "Satck Underflow\n";
            exit(1);
        }
        else{
            this->length--;
            cout << top->getKey() << "\n";
            temp = top;
            top = top->getP();
            free(temp);
        }
    }

    void noCoutPop(){
        Node* temp;

        if(top == nullptr){
            cout << "Satck Underflow\n";
            exit(1);
        }
        else{
            this->length--;
            temp = top;
            top = top->getP();
            free(temp);
        }
    }

    void print(){
        Node* temp;

        if(top == nullptr){
            cout << "Satck Underflow\n";
            exit(1);
        }
        else{
            temp = top;
            while(temp != nullptr){
                cout << temp->getKey();
                temp = temp->getP();
                if(temp != nullptr){cout << " ";}
            }
            cout << "\n";
        }
    }

    void invertStack(){
        Node* temp;
        int *arr = new int[this->length];
        int n = 0;
        int tempLength = this->length;

        temp = top;
        while(temp != nullptr){
            arr[n] = temp->getKey();
            temp = temp->getP();
            n++;
        }
        this->remove();
        for(int i = 0; i < tempLength; ++i){
            this->push(arr[i]);
        }
        delete[] arr;
    }

    void copyStack(Stack stack){
        this->remove();
        stack.invertStack();
        while(stack.getTop() != nullptr){
            this->push(stack.getTop()->getKey());
            stack.setTop(stack.getTop()->getP());
        }
    }

    void remove(){
        while(top != nullptr){
            this->noCoutPop();
        }
    }

    void getLength(){
        cout << this->length;
    }

    int noCoutGetLength(){
        return this->length;
    }

    void addition(Stack stack){
        stack.invertStack();
        while(stack.getTop() != nullptr){
            this->push(stack.getTop()->getKey());
            stack.setTop(stack.getTop()->getP());
        }
    }

    void removeDouble(){
        Node* temp;
        int *arr = new int[0];
        int n = 0, ind = 0;

        this->invertStack();
        temp = top;
        while(temp != nullptr){
            for(int i = 0; i < n; ++i){
                if(arr[i] == temp->getKey()){
                    ind = 1;
                    break;
                }
            }
            if(ind == 0){
                arr[n] = temp->getKey();
                n++;
            }
            temp = temp->getP();
            ind = 0;
        }
        this->remove();
        for(int i = 0; i < n; ++i){
            this->push(arr[i]);
        }
        this->length = n;
        delete[] arr;
    }
};

int main(){
    Stack s1,s2,s3;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(3);
    s3.copyStack(s1);
    s1.push(4);
    s1.push(1);
    cout << "Cтек1"<< endl;
    s1.print();
    s1.isEmpty();
    s1.isFull();
    cout << "Копия стек1"<< endl;
    s2.copyStack(s1);
    s2.print();
    cout << "pop"<< endl;
    s2.pop();
    s2.remove();
    cout << "Стек2 больше нет"<< endl;
    cout << "Длина Cтек1"<< endl;
    s1.getLength();
    cout<<endl;
    s1.invertStack();
    cout << "Стек3"<< endl;
    s3.print();
    s1.addition(s3);
    cout << "Переворот Стек1"<< endl;
    cout << "Объеденение 1 и 3"<< endl;
    s1.print();
    cout << "Удаление двойников"<< endl;
    s1.removeDouble();
    s1.print();
}