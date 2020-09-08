#include "view.h"
#include "chip8.h"


int main(int argc, char* argv[])
{
    Chip8 myChip8;
    View myView;

    myView.init();

    for(;;) {
        myChip8.emulateCycle();

        if (myView.getDrawFlag())
            myView.drawFrame();
        else {
            // TODO: Talvez mudar isto?
            exit(0);
        }
        
    }

    //myView.run();

    return 0;
}