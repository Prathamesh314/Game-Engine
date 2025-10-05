#include "Application.h"
#include <iostream>

namespace Hazel {
    Application::Application(){

    }

    Application::~Application(){

    }

    void Application::Run(){
        std::cout<<"running from the application!"<<std::endl;
        while (true);
    }
}