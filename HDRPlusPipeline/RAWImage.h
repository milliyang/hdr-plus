#ifndef RAW_IMAGE_H
#define RAW_IMAGE_H

#include "Image.h"

namespace HDRPlusPipeline
{
    class RAWImage
    {

    private:
        double *p;
        size_t w, h;

    public:       

        RAWImage()
        {
            w = h = 0;
            p = NULL;
        }

        RAWImage(size_t width, size_t height, double *pixels) w(width), h(height), p(pixels) {}

        RAWImage(std::string filename) {
            read(filename);
        }

        inline size_t width() {
            return w;
        }

        inline size_t height() {
            return h;
        }

        inline double* pixels() {
            return p;
        }

        inline double pixel(size_t x, size_t y) {
            if (x < 0 || x >= w || y < 0 || y >= h) {
                throw std::out_of_range("Tried accessing a pixel out of the image boundaries");
            }
            return p[y * w + x];
        }

        void read(std::string filename);
        void write(std::string filename);
        Image demosaic();
    };
}

#endif