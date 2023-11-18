#include<iostream>
#include<string>
#include<vector>

using namespace std;


class Bird {
    public:
    int age;
    int weight;
    int noL;
    int color;

    void eat () {
        cout << "Bird EAT " << endl;
    }

    void fly() {
        cout << "Bird fly " << endl;
    }
};

// class Sparrow : public Bird {
//     public:
//     Sparrow () {
//         this->age;
//     }
//     void grassing() {
//         cout << "Bird is grassing " << endl;
//     }
// };

class Sparrow : protected Bird {
    public:
    Sparrow () {
        this->age;
    }
    void grassing() {
        cout << "Bird is grassing " << endl;
    }
};


class Pigeon : public Bird {
    public:
    void guttering() {
        cout << "Bird is guttering " << endl;
    }
};


int main() {


    // Sparrow *s1 = new Sparrow;
    // s1.age;
    // s1.age;
    Sparrow s1;
    

    return 0;
}