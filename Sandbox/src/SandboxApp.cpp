#include "Application.h"
#include "EntryPoint.h"
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

Hazel::Application* Hazel::CreateApplication(){
    return new Sandbox();
}
