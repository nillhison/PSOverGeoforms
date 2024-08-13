#pragma once

#include <cctype>
#include <iostream>

#include "GeoTypes.hpp"

Operation requestOperation(Operation& op) {
    
    op = INITIAL;
    
    unsigned int attempts = 0;
    unsigned int request;
    
    const unsigned int maxAttempts = 5;
    
    while(op == INITIAL) {
        
        std::cout << "-------------------------" << std::endl;
        std::cout << "(1) Point Over Line" << std::endl;
        std::cout << "(2) Point Over Plane" << std::endl;
        std::cout << "(3) Line Over Plane" << std::endl;
        std::cout << "(4) Exit" << std::endl;
        std::cout << "Choose an operation: ";
        std::cin >> request;
    
        switch(request) {
            case 1 : op = POINT_OVER_LINE; break;
            case 2 : op = POINT_OVER_PLANE; break;
            case 3 : op = LINE_OVER_PLANE; break;
            case 4 : op = EXIT_APP; break;
            default : 
                if(attempts > maxAttempts) {
                    std::cout << "Aborting application due to unsuccessful request!" << std::endl;
                    op = EXIT_APP;
                } else {
                    std::cout << "Invalid Option! Try again" << std::endl;
                    ++attempts;
                };
        };
    };
    
}

bool newSection() {
    
    char otherSection = 0;
    bool newSection = false;
    
    while(otherSection != 'Y' && otherSection != 'N') {
        std::cout << "Perform another operation (Y/N)?: ";
        std::cin >> otherSection;
        
        otherSection = std::toupper(otherSection);
    
        if(otherSection == 'Y') {
            newSection = true;
        } else if(otherSection == 'N') {
            newSection = false;
        } else std::cout << "Invalid Option! Try again" << std::endl;
    }
    
    return newSection;
    
}

void reqCoordinates(std::string entityName, Coordinates& entity) {
    
    std::string axes[AXES];
    
    if(entityName == "point" || entityName == "point on the line") {
            axes[0] = "X";
            axes[1] = "Y";
            axes[2] = "Z";
    } else if(entityName == "direction vector of the line") {
            axes[0] = "dX";
            axes[1] = "dY";
            axes[2] = "dZ";
    } else if(entityName == "normal vector of the plane") {
            axes[0] = "nX";
            axes[1] = "nY";
            axes[2] = "nZ";
    };
    
    std::cout << "Enter the coordinates of the " << entityName << ": " << std::endl;
    std::cout << "\t" << axes[0] << ": ";
    std::cin >> entity.x;
    std::cout << "\t" << axes[1] << ": ";
    std::cin >> entity.y;
    std::cout << "\t" << axes[2] << ": ";
    std::cin >> entity.z;
    
}

void reqPointData(Coordinates& pt) {
    reqCoordinates("point", pt);
}

void reqLineData(Line& ln) {
    reqCoordinates("point on the line", ln.p);
    reqCoordinates("direction vector of the line", ln.d);
}

void reqPlaneData(Plane& pl) {
    reqCoordinates("normal vector of the plane", pl.n);
    std::cout << "Enter the plane constant value: ";
    std::cin >> pl.k;
}

template<typename T>
void exhibitResults(T& projection, T& simetric) {
    
    if(typeid(T).name() == typeid(Coordinates).name()) {
        
        std::cout << "Coordinates for the point projection: " << std::endl;
        std::cout << "\tX: " << projection.x << std::endl;
        std::cout << "\tY: " << projection.y << std::endl;
        std::cout << "\tZ: " << projection.z << std::endl;
                
        std::cout << "Coordinates for the simetic point: " << std::endl;
        std::cout << "\tX: " << simetric.x << std::endl;
        std::cout << "\tY: " << simetric.y << std::endl;
        std::cout << "\tZ: " << simetric.z << std::endl;
        
    } else if(typeid(T).name() == typeid(Line).name()) {
        
        std::cout << "Parametric equations for the projection of the line: " << std::endl;
        std::cout << "\tX = " << projection.p.x << " + " << projection.d.x << "t" << std::endl;
        std::cout << "\tY = " << projection.p.y << " + " << projection.d.y << "t" << std::endl;
        std::cout << "\tZ = " << projection.p.z << " + " << projection.d.z << "t" << std::endl;
                
        std::cout << "Parametric equations for the simetic line: " << std::endl;
        std::cout << "\tX = " << simetric.p.x << " + " << simetric.d.x << "t" << std::endl;
        std::cout << "\tY = " << simetric.p.y << " + " << simetric.d.y << "t" << std::endl;
        std::cout << "\tZ = " << simetric.p.z << " + " << simetric.d.z << "t" << std::endl;
    };

}

void logAboutRelativePosition(RelativePosition relPos) {

    switch(relPos) {
        case PERPENDICULAR: 
            std::cout << "The given line is perpendicular to the plane" << std::endl;
            std::cout << "No projection or simetric line are possible" << std::endl;
            break;
        case PARALLEL:
            std::cout << "The given line is parallel to the plane" << std::endl;
            break;
        case OBLIQUE:
            std::cout << "The given line is oblique to the plane" << std::endl;
            break;
    };

}
        