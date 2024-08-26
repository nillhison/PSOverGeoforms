#include "Dialogs.hpp"
#include "PSOverGeoforms.hpp"

int main()
{
    static Operation operation;
        
    while(operation != EXIT_APP)
    {
        RetrieveOperation(operation);
        switch(operation)
        {
            case INITIAL : continue;
            case POINT_OVER_LINE :
                RunPointOverLine();
                if(!NewSection()) operation = EXIT_APP; break;
            case POINT_OVER_PLANE :
                RunPointOverPlane();
                if(!NewSection()) operation = EXIT_APP; break;
            case LINE_OVER_PLANE :
                RunLineOverPlane();
                if(!NewSection()) operation = EXIT_APP; break;
            case EXIT_APP : return 0;
        };
    };
}
