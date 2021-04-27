#ifndef IMAGE_H
#define IMAGE_H

#pragma once

/**
 * This file contains the Image Class Documentation
 * Image class is part of the UI namespace to avoid potential name class
 * when requiring this project for the future
 * 
 */

namespace UI {
    class Image {
    private:
        int width;
        int height;
        int channels;
        int components;

        char *image_data;

    public:
        Image ();
        Image (int width, int height, int channel, int components = 0);
        Image (char *image_data);
        Image (Image &other);
        ~Image ();

    };
};

#endif