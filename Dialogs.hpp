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
    };
    
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

void reqPointData(struct Point* pt) {
    reqCoordinates("point", pt);
}

void reqLineData(struct Line* ln) {
    reqCoordinates("point", ln.(&p));
    reqCoordinates("director line vector", ln.(&d));
}

void reqPlanData(struct Plan* pl) {
    reqCoordinates("normal plan vector", pl.(&n))
    std::cout << "Input the plan constant value: ";
    std::cin >> pl->k;
}

void reqCoordinates(std::string entityName, struct Coordinates* entity) {
    
    std::string axes[AXES];
    
    switch(entityName) {
        case "point":
            axes[0] = "X";
            axes[1] = "Y";
            axes[2] = "Z"; break;
        case "director line vector":
            axes[0] = "dX";
            axes[1] = "dY";
            axes[2] = "dZ"; break;
        case "normal plan vector":
            axes[0] = "nX";
            axes[1] = "nY";
            axes[2] = "nZ"; break;
    };
    
    std::cout << "Input the " << entityName << " coordinates: " << std::endl;
    std::cout << "\t" << axes[0] << ": ";
    std::cin >> entity->x;
    std::cout << "\t" << axes[1] << ": ";
    std::cin >> entity->y;
    std::cout << "\t" << axes[2] << ": ";
    std::cin >> entity->z;
    
}

template<typename T>
void exhibitResults(T* projection, T* simetric) {
    
    switch(typeid(*T).name()) {
        
        case Point:
        
            std::cout << "Point projection coordinates: " << std::endl;
            std::cout << "\tX: " << projection->x << std::endl;
            std::cout << "\tY: " << projection->y << std::endl;
            std::cout << "\tZ: " << projection->z << std::endl;
            
            std::cout << "Simetric point coordinates: " << std::endl;
            std::cout << "\tX: " << simetric->x << std::endl;
            std::cout << "\tY: " << simetric->y << std::endl;
            std::cout << "\tZ: " << simetric->z << std::endl;
        
        case Line:
        
            std::cout << "Line projection parametric equations: " << std::endl;
            std::cout << "\tX = " << projection->p->x << " + " << projection->d->x << "t" << std::endl;
            std::cout << "\tY = " << projection->p->y << " + " << projection->d->y << "t" << std::endl;
            std::cout << "\tZ = " << projection->p->z << " + " << projection->d->z << "t" << std::endl;
            
            std::cout << "Simetric line parametric equations: " << std::endl;
            std::cout << "\tX = " << simetric->p->x << " + " << simetric->d->x << "t" << std::endl;
            std::cout << "\tY = " << simetric->p->y << " + " << simetric->d->y << "t" << std::endl;
            std::cout << "\tZ = " << simetric->p->z << " + " << simetric->d->z << "t" << std::endl;
            
    };
    
}
