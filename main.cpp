/*
    To compile:

        1)  Create folder named 'build'
        2)  Open terminal and go to 'build' folder
        3)  Run in the terminal:

                cmake ..

        4)  Run in the terminal:

                cmake --build .
        
        5)  Execute img executable

                ./img   (on Linux)  or      img.exe     (on Windows)

        6)  Open result.ppm image.
            To view images in .ppm format you can use irfanView.
*/

#include "image.h"

int main()
{
    Image im("../images/zlatoust1910.ppm");

    im.convertToGrayscale();

    // Some comment
    im.drawCircle(90, 300, 250, {100, 200, 100});
    im.drawCircle(70, 100, 100, {100, 100, 200});

    im.savePpm("result.ppm");
}
