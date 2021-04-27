#include "image.h"
#include "../stb/stb_image.h"
#include "../stb/stb_image_write.h"
#include <iostream>

Image::Image (const std::string image_file_name) {
    if (read_file(image_file_name)) {
        std::cout << "successfully read file" << std::endl;
        data_size = width * height * channels;
    }
    else {
        std::cerr << "[error]: could not read file" << std::endl;
    }
}
Image::Image (size_t width, size_t height, int channels) {
    data_size = width * height * channels;
    image_data = new unsigned short int [data_size];
}
Image::Image (const Image &other_image) {

}
Image::~Image () {
    stbi_image_free(image_data);
}

bool Image::read_file (std::string image_file_name) {
    return true;
}

bool Image::write_file (const std::string image_file_name) {
    return true;
}
