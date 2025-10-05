#include "Hazel.h"
#include <iostream>

int main() {
    std::cout << "Sandbox Application Started" << std::endl;
    
    Hazel::InitializeEngine();
    Hazel::Print();
    
    std::cout << "Sandbox Application Ending" << std::endl;
    
    return 0;
}