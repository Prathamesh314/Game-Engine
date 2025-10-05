#pragma once
#include "Application.h"

#ifdef __APPLE__
    extern Hazel::Application* Hazel::CreateApplication();
    int main(int argc, char** argv){
        Hazel::Application* app = Hazel::CreateApplication();
        app->Run();
        delete app;
        return 0;
    }
#else
    #error Only supported for Mac!
#endif