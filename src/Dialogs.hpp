#pragma once

#include <limits>
#include <cctype>
#include <iostream>
#include <typeinfo>

#include "GeoTypes.hpp"

void ClearEntries()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

Operation RetrieveOperation(Operation& op)
{
    
    op = INITIAL;
    unsigned int attempts = 0;
    unsigned int Request;
    const unsigned int maxAttempts = 5;
    
    while(op == INITIAL)
    {
        std::cout << "-------------------------" << std::endl;
        std::cout << "(1) Point Over Line" << std::endl;
        std::cout << "(2) Point Over Plane" << std::endl;
        std::cout << "(3) Line Over Plane" << std::endl;
        std::cout << "(4) Exit" << std::endl;
        std::cout << "Choose an operation: ";
        std::cin >> Request;
    
        switch(Request)
        {
            case 1 : op = POINT_OVER_LINE; break;
            case 2 : op = POINT_OVER_PLANE; break;
            case 3 : op = LINE_OVER_PLANE; break;
            case 4 : op = EXIT_APP; break;
            default : 
                if(attempts > maxAttempts)
                {
                    std::cout << "Aborting application due to unsuccessful Request!" << std::endl;
                    op = EXIT_APP;
                } else {
                    std::cout << "Invalid Option! Try again" << std::endl;
                    ClearEntries();
                    ++attempts;
                }
        }
    }
    
    return op;
    
}

bool NewSection()
{
    
    char userAnwser = 0;
    bool newSection = false;

    while (userAnwser != 'Y' && userAnwser != 'N')
    {
        std::cout << "Perform another operation (Y/N)?: ";
        std::cin >> userAnwser;
        
        userAnwser = std::toupper(userAnwser);
    
        if(userAnwser == 'Y') {
            newSection = true;
        } else if(userAnwser == 'N') {
            newSection = false;
        } else {
            std::cout << "Invalid Option! Try again" << std::endl;
            ClearEntries();
        }
    }
    return newSection;
}

void ReqCoordinates(std::string_view locusName, Coordinates& locusCoord) {

    std::string axes[AXES];
    
    if(locusName == locus[0] || locusName == locus[1])
    {
            axes[0] = "X";
            axes[1] = "Y";
            axes[2] = "Z";
    } else if(locusName == locus[2]) {
            axes[0] = "dX";
            axes[1] = "dY";
            axes[2] = "dZ";
    } else if(locusName == locus[3]) {
            axes[0] = "nX";
            axes[1] = "nY";
            axes[2] = "nZ";
    }
    
    std::cout << "Enter the coordinates of the " << locusName << ": " << std::endl;
    std::cout << "\t" << axes[0] << ": ";
    std::cin >> locusCoord.x;
    std::cout << "\t" << axes[1] << ": ";
    std::cin >> locusCoord.y;
    std::cout << "\t" << axes[2] << ": ";
    std::cin >> locusCoord.z;
    
}

void ReqPointData(Coordinates& pt)
{
    ReqCoordinates(locus[0], pt);
}

void ReqLineData(Line& ln)
{
    ReqCoordinates(locus[1], ln.p);
    ReqCoordinates(locus[2], ln.d);
}

void ReqPlaneData(Plane& pl)
{
    ReqCoordinates(locus[3], pl.n);
    std::cout << "Enter the plane constant value: ";
    std::cin >> pl.k;
}
    
void WritePointResults(Coordinates& projection, Coordinates& symmetric)
{
    std::cout << "Coordinates for the point projection: " << std::endl;
    std::cout << "\tX: " << projection.x << std::endl;
    std::cout << "\tY: " << projection.y << std::endl;
    std::cout << "\tZ: " << projection.z << std::endl;
                    
    std::cout << "Coordinates for the symmetric point: " << std::endl;
    std::cout << "\tX: " << symmetric.x << std::endl;
    std::cout << "\tY: " << symmetric.y << std::endl;
    std::cout << "\tZ: " << symmetric.z << std::endl;
}

void WriteLineResults(Line& projection, Line& symmetric)
{
    std::cout << "Parametric equations for the projection of the line: " << std::endl;
    std::cout << "\tX = " << projection.p.x << " + " << projection.d.x << "t" << std::endl;
    std::cout << "\tY = " << projection.p.y << " + " << projection.d.y << "t" << std::endl;
    std::cout << "\tZ = " << projection.p.z << " + " << projection.d.z << "t" << std::endl;
                    
    std::cout << "Parametric equations for the symmetric line: " << std::endl;
    std::cout << "\tX = " << symmetric.p.x << " + " << symmetric.d.x << "t" << std::endl;
    std::cout << "\tY = " << symmetric.p.y << " + " << symmetric.d.y << "t" << std::endl;
    std::cout << "\tZ = " << symmetric.p.z << " + " << symmetric.d.z << "t" << std::endl;
}

void LogAboutRelativePosition(RelativePosition relPos)
{
    switch(relPos)
    {
        case PERPENDICULAR: 
            std::cout << "The given line is perpendicular to the plane" << std::endl;
            std::cout << "No projection or symmetric line are possible" << std::endl;
            break;
        case PARALLEL:
            std::cout << "The given line is parallel to the plane. Results are shown bellow" << std::endl;
            break;
        case OBLIQUE:
            std::cout << "The given line is oblique to the plane. Results are shown bellow" << std::endl;
            break;
    }
}
        