#include <iostream>

#include "Dialogs.hpp"
#include "PSOverGeoforms.hpp"

int main() {
    
    static Operation operation = Initial;
        
    while(operation != Exit) {
        
        operation = requestOperation();
        
        switch(operation) {
            
            case PointOverLine :
                runPOL();
                if(!newSection()) operation = Exit;
            break;
                
            case Operation::PointOverPlan :
                runPOP();
                if(!newSection()) operation = Exit;
            break;
            
            case Operation::LineOverPlan :
                runLOP();
                if(!newSection()) operation = Exit;
            break;
            
            case NotAllowed:
                std::cout << "Invalid Option! Try Again!" << std::endl;
            break;
        };

    };
    
}