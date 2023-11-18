#include<iostream>

using namespace std;

class Animal {
    public:
    virtual void sound() {
        cout << "Animal making sound " << endl;
    }

    ~Animal() {
        cout << "~Aniamal" << endl;
    }
};

class Dog: public Animal {
    public:
    void sound() override 
    // override keyword readibility k liye h compulsory nhi h
    {
        cout << "Dog is barking " << endl; 
    }
};

class Cat: public Animal {
    public:
    void sound() {
        cout << "Cat Meowing" << endl; 
    }
};


void sound(Animal* animal) {
    animal->sound();

}

int main() {

    Animal *animal = new Dog();
    
    sound(animal);
    animal = new Cat();
    sound(animal);

    return 0;
}