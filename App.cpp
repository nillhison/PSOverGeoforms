#include <iostream>

#include "Dialogs.hpp"
#include "PSOverGeoforms.hpp"

int main() {
    
    static Operation operation;
        
    while(operation != EXIT_APP) {
        
        retrieveOperation(operation);
        
        switch(operation) {
            
            case INITIAL : continue;
            
            case POINT_OVER_LINE :
            
                runPointOverLine();
                
                if(!newSection()) operation = EXIT_APP;
                
            break;
                
            case POINT_OVER_PLANE :
            
                runPointOverPlane();
                
                if(!newSection()) operation = EXIT_APP;
                
            break;
            
            case LINE_OVER_PLANE :
            
                runLineOverPlane();
                
                if(!newSection()) operation = EXIT_APP;
                
            break;
            
            case EXIT_APP : return 0;
            
        };

    };
    
}
