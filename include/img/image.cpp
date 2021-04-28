#include "image.h"

#include "../stb/stb_image.h"
#include "../stb/stb_image_write.h"

namespace UI {

    Image::Image(): width(0), height(0), channels(0), components(0), image_size(0) {
    }

    Image::Image(std::string file_name) {
        assert(!file_name.empty());
        bool check = read_from_file(file_name);

        if (!check) {
            std::cerr << "Could not read from file " << file_name << std::endl;
            exit(1);
        }

        this->image_size = this->width * this->height * this->channels;
    }

    Image::Image(int width, int height, int channel, int component = 0): 
                    width(width), height(height), channels(channel), components(component) {

        this->image_size = this->width * this->height * this->channels;
    }

    Image::Image (const type_t *image_data, size_t image_data_size) {
        assert(image_data != nullptr);
        assert(image_data_size > 0);
    }

    Image::Image (const Image &other): Image(other.width, other.height, other.channel, other.component) {
        memcpy(image_data, other.image_data, other.image_size);
        image_size = other.image_size;
    }

    Image::~Image () {
        stbi_image_free(this->image_data);
        this->image_size = 0;
    }

    bool Image::read_from_file (const std::string file_name) {
        assert(!file_name.empty());

        this->image_data = stbi_load(file_name.c_str(), &this->width, &this->height, &this->channels, this->components);

        return this->image_data != NULL;
    }

    bool Image::write_to_file (const std::string file_name) {
        assert(!file_name.empty());
    }
};
