#include <iostream>

using namespace std;

struct A {
    ~A() {throw 1;}
};

struct B {
    ~B() noexcept(false) {throw 2;}
};

struct C {
    B b;
};

void funA() {A a;}
void funB() {B b;}
void funC() {C c;}

int main() {
    try {
        new int(0);
        funB();
    } catch(...) {
        cout << "catch funB" << endl;
    }

    try {
        funC();
    } catch(...) {
        cout << "catch funC" << endl;
    }

    try {
        funA();
    } catch(...) {
        cout << "catch funA" << endl;
    }
    return 0;
}
