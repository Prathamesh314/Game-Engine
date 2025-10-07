#pragma once
#include "Application.h"
#include "Log.h"

#ifdef __APPLE__
    extern Hazel::Application* Hazel::CreateApplication();
    int main(int argc, char** argv){
        Hazel::Log::Init();
        HZ_CORE_WARN("Initialized Logger!");
        HZ_CORE_INFO("Hello from client!");
        Hazel::Application* app = Hazel::CreateApplication();
        app->Run();
        delete app;
        return 0;
    }
#else
    #error Only supported for Mac!
#endif