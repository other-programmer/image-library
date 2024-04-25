/*
    Image class

    The Image class from this file is the simplest class for working with images in the PPM P6 format.
    
    Image class fields:

        mWidth  -   image width in pixels
        mHeigth -   image height in pixels
        mData   -   the colors of all pixels are stored here according to the RGB color model.
                    Color is described by three one-byte numbers (red, green and blue components).
                    Accordingly, the size of this array is 3 * mWidth * mHeight.


    The inner class Color is a helper class for storing color.
    For the Color class, the + and += operators are overloaded so that colors can be conveniently added.

    Function Color::saturateCast takes an integer and limits it ranges from 0 to 255.
    This function is useful because when changing the color, the value of the components
    colors must be in this range.

    
    Methods of the Image class:

        Image(const std::string& filename)      -   constructor that is passed the name of the image file.
                                                    This image is read and an object of the Image class is created,
                                                    storing this image.


        Image(int width, int height)            -   creates an image of size width by height, black.
        Image(int width, int height, Color c)   -   creates an image of size width by height of color c.
        getWidth, getHeight, getData            -   getters for class fields

        setPixel(int i, int j, Color c)         -   set the color of the pixel with coordinates (i, j) to color c
        getPixel(int i, int j)                  -   get the color of a pixel with coordinates (i, j)

        loadPpm(const std::string& filename)    -   load an image in PPM format from a file called filename
        savePpm(const std::string& filename)    -   save the image in PPM format to a file called filename

        drawCircle(int r, int centerX, int centerY, Color c) 
                                                -   draw a circle in the picture with radius r and center
                                                    in pixel (centerX, centerY) color c.


        drawLine(int x1, int y1, int x2, int y2, Color c)  
                                                -   draw a segment in the picture from pixel (x1, y1) to
                                                    pixels (x2, y2) color c.
*/

#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <cassert>


class Image
{
private:

    int mWidth  {0};
    int mHeight {0};
    std::vector<unsigned char> mData {};

public:

    class Color
    {
    public:
        unsigned char r, g, b;

        Color& operator+=(Color c);
        Color operator+(Color c) const;
        static unsigned char saturateCast(int a);
    };

    Image();
    Image(const std::string& filename);
    Image(int width, int height);
    Image(int width, int height, Color c);

    int getWidth() const {return mWidth;}
    int getHeight() const {return mHeight;}
    unsigned char* getData() {return mData.data();}


    int getNumberOfPixels() const;

    void setPixel(int i, int j, Color c);
    Color getPixel(int i, int j) const;

    void loadPpm(const std::string& filename);
    void savePpm(const std::string& filename) const;

    void drawCircle(int r, int centerX, int centerY, Color c);
    void drawLine(int x1, int y1, int x2, int y2, Color c);

    void convertToGrayscale();
};