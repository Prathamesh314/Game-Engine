#include "Application.h"
#include "iostream"

class Sandbox :public Hazel::Application 
{
    public:
    Sandbox(){

    }

    ~Sandbox(){

    }

    void Run(){
        std::cout<<"Running the Sandbox engine!"<<std::endl;
    }
};

int main(){
    Sandbox* s = new Sandbox();
    s->Run();
}