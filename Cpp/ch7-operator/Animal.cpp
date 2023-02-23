#include <iostream>
using namespace std;

class Animal{
    friend void output(const Animal& a);
    friend ostream& operator<<(ostream& os, const Animal& a);
    friend istream& operator>>(istream& is, Animal& a);
    friend class B;
private:
    int age = 0;
    string name;
    string color;
public:
    Animal()=default;
    Animal(int age, string name,string color):
    age(age), name(name),color(color){}
/*
    void output(const Animal& a){
        cout<<a.age<<a.name<<a.color<<endl;
    }
*/
    void output(){
        cout<<age<<name<<color<<endl;
    }
};

ostream& operator<<(ostream& os, const Animal& a){
    os<<a.age<<a.name<<a.color<<endl;
    return os;
}

istream& operator>>(istream& is, Animal& a){
    is>>a.age>>a.name>>a.color;
    return is;
}
void output(const Animal& a){
    cout<<a.age<<a.name<<a.color<<endl;
}

class B{
public:
    void intput(Animal& a){
        cin>>a.age>>a.name>>a.color;
    }
};

int main(){
    Animal a(1,"cat","black");
    //operator>>(cin, a);
    cin>>a;
    output(a);
    operator<<(cout, a); //operator+(a,b)
    cout<<a;    //a+b
    a.output();
    
    //Ainmal * p;
    //void (Animal::*p)() = Animal::output;

    /*
    Animal a1;
    B b;
    b.intput(a1);
    output(a1);*/
}
/*
void swap(int & a, int& b){
    int t = a;
    a = b;
    b=a;
}
void swap(Animal& a, Animal& b){
    Animal t = a;
    a = b; //a.operator=(b);
    b = a;
}*/
