#include<iostream>

using namespace std;

class A {
    private:
    int x;
    public:
    A (int _val):x(_val) {}; 
    int getX() {
        return x;
    }

    void setX (int _val) {
        this->x = _val;
    }

    friend void print(const A&a);
};



void print(const A &a) {
    cout << a.x << endl;
}

int main () {

    A a(5);
    a.getX();




    return 0;
}