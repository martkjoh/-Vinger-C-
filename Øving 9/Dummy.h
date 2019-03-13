#include <iostream>

using namespace::std;

class Dummy {
    public:
        int *num;

        Dummy() {num = new int{0};}
        ~Dummy() {delete num;}
        Dummy(const Dummy& a) {num = new int{*a.num};}

        void operator= (Dummy a)
        {
            swap(num, a.num);
        }
}; 
void dummyTest();
