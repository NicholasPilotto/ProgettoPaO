#include "Utilities/DeepPtr/deep_ptr.hpp"
#include "Utilities/Contenitore/u_vector.hpp"
#include <iostream>
//Non so come controllare gli operatori *, ->, 
class A{
    public:
    virtual void m(){std::cout << "A::m()" << std::endl;}
    virtual A* clone(){
        std::cout << "A::clone()" << std::endl;
        return new A(*this);
    }
};

class B : public A{
    public:
    virtual void m(){std::cout << "B::m()" << std::endl;}
    virtual B* clone(){
        std::cout << "B::clone()" << std::endl;
        return new B(*this);
    }
};

int main(){
    A* a = new A();
    deep_ptr<A> a1(a);
    deep_ptr<A> a2(a1);
    deep_ptr<A> a3 = a1;
    std::cout << a1.pointer << ' ' << a2.pointer << ' ' << a3.pointer << std::endl;
    deep_ptr<A> a4;
    a4 = a1;
    std::cout << a1.pointer << ' ' << a2.pointer << ' ' << a3.pointer << ' ' << a4.pointer << std::endl;
    A* getter = a1.get();
    std::cout << a1.pointer << ' ' << getter << std::endl;
    std::cout << bool(a1 > getter) << ' ' << bool(a1 >= a2) << ' ' << bool(a1 >= a4) << std::endl;
    deep_ptr<A> a5;
    std::cout << bool(a1) << std::endl << bool(a2) << std::endl << bool(a3) << std::endl << bool(a4) << std::endl << bool(a5) << std::endl;
}