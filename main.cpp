#include<iostream>
using namespace std;

class Test {
    public:
    Test(){
        output = "Hello World!";
    }

    string getOutput(){
        return output;
    }

    private:
    string output;
};


int main() {
    Test *t = new Test();
    cout<<t->getOutput()<<endl;
    return 0;
}