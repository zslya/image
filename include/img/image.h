#pragma once

#include <vector>

class Image {
    unsigned short int *image_data;
    size_t data_size;
    size_t width;
    size_t height;

    int channels;

    Image (const std::string image_file_name);
    Image (size_t width, size_t height, int channels);
    Image (const Image &other_image);
    ~Image ();

    bool read_file (std::string image_file_name);
    bool write_file (const std::string image_file_name);
};