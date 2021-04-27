#ifndef IMAGE_H
#define IMAGE_H

#pragma once

/**
 * This file contains the Image Class Documentation
 * Image class is part of the UI namespace to avoid potential name class
 * when requiring this project for the future
 * 
 * libraries included for this class include:
 */

#include <iostream> // for input/output/strings



namespace UI {
    class Image {
    private:
        size_t image_size;
        int width;
        int height;
        int channels;
        int components;

        char *image_data;

    public:

        /**
         * Default constructors for the image class
         */

        Image ();

        /**
         * Image(width, height, channel, components = 0) Creates a new structure from the 
         *      specified parameters
         * effects: Allocates space. Caller must free the component
         * time: O(1)
         */
        Image (int width, int height, int channel, int components = 0);


        /**
         * Image(image_data) Creates a new structure from the specified parameters
         * effects: Allocates space. Caller must free the component
         * time: O(n) where n is the length of image_data
         */
        Image (char *image_data);

        /**
         * Image(other) Creates a new structure based on the content of another image
         * effects: Allocates space. Caller must free the component
         * time: O(n) where n is the size of image other
         */
        Image (const Image &other);

        /**
         * Image(file_name) Creates a new structure by reading content from its file
         * effects: Allocates space. Caller must free the component
         * time: O(n) since this calls the function read_from_file(file_name)
         */
        Image (std::string file_name);

        /**
         * ~Image() destructore for the class
         * effects: frees the given structure's memory in heap
         * time: O(1) ????
         */
        ~Image ();

        /**
         * read_from_file(file_name) tries to read the image content from the file
         * Note: This method can potentially fail. Make sure to guard against that
         * time: O(n) where n is the length of the file_content 
         */
        bool read_from_file (std::string file_name);

        /**
         * write_to_file(file_name) attempts to write content in the specified file_name
         * Note: This method can potentially fail. Make sure to guard againsnt that
         *       This method can potentially override the existing content in file
         * time: O(n) where n is the size of the image to write to file
         */
        bool write_to_file(std::string file_name);

    };
};

#endif