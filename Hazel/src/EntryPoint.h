#pragma once
#include "Application.h"

#ifdef __APPLE__
    extern Hazel::Application* CreateApplication();
    int main(int argc, char** argv){
        auto app = CreateApplication();
        app->Run();
        delete app;
        return 0;
    }
#else
    #error Only supported for Mac!
#endif