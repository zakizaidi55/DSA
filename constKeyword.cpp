// #include<iostream>

// using namespace std;

// class ABC {
//     int x; 
//     int *y; 
//     const int z;

//     // ABC(int _x, int _y, int _z=0) {
//     //     x = _x;
//     //     y = new int(_y);
//     //     z = _z;
//     // }

//     // initialisation list
//     ABC(int _x, int _y, int _z=0) :x(_x), y(new int(_y)), z(_z){}


// };

// int main() {

//     // const int a = 5;

//     // cout << a << endl;

//     // 2. const with pointers

//     // int *a = new int;
//     // *a = 2;

//     // cout << *a << endl;
//     // delete a;
//     // int b = 5;
//     // a = &b;
//     // cout << *a << endl;

//     // const int *a = new int(5); //const data , non constant pointer
//     // int const* a = new int(5) same as line 22
//     // // *a = 2; cant change the content of pointer


//     // cout << *a << endl;
    
//     // int b = 20;
//     // a = &b; //pointer can be reassign
//     // cout << *a << endl;


//     // const pointer and non constant data

//     // int *const a = new int(4);
//     // *a = 20;

//     // const pointer and const data
//     const int *const a = new int(5);


//     return 0;
// }


//---------------static ---------------------------

#include<iostream>


class abc{
    public: 
    static int x, y;

    static void print() {
        cout << x << " " << y << endl;
    }
    // copy constrctor

    // abc(const abc &srcObj) {
    //     this->x = srcObj.x;
    // }

};

int abc::x;
int abc::y;


using namespace std;

int main() {

    // abc obj1;
    // obj1.x = 1;
    // obj1.y = 2;
    // obj1.print();

    // abc obj2;
  
    // obj2.x = 20;
    // obj2.y = 30;
    // obj1.print();
    // obj2.print();


    
    
    // abc obj1;
    // abc::x = 1;
    // abc::y = 2;
    // abc::print();

    // abc obj2;
  
    // abc::x = 20;
    // abc::y = 30;
    // abc::print();
    // abc::print();


    abc *s1 = new abc;
    delete s1;

    return 0;   
}