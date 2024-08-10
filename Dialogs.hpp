#pragma once

#include <iostream>

#include "GeoTypes.hpp"

Operation requestOperation() {
    
    char request;
    
    std::cout << "Choose an operation:" << std::endl;
    std::cout << "(1) Point Over Line" << std::endl;
    std::cout << "(2) Point Over Plan" << std::endl;
    std::cout << "(3) Line Over Plan" << std::endl;
    std::cout << "(4) Exit" << std::endl;
    std::cin >> request;
    
    switch(request) {
        case 1 : return PointOverLine; break;
        case 2 : return PointOverPlan; break;
        case 3 : return LineOverPlan; break;
        case 4 : return Exit; break;
        default : return NotAllowed;
    }
    
}

bool newSection() {
    
    char otherSection = 0;
    
    while(toupper(otherSection) != Y || toupper(otherSection) != N) {
        std::cout << "Perform another operation (Y/N)?: ";
        std::cin >> otherSection;
    
        if(otherSection) == Y) {
            return true;
        } else if(otherSection == N) {
            return false;
        } else std::cout << "Invalid Option! Try again" << std::endl;
}