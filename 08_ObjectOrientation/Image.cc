#include <iostream>
#include <cstdint>
#include <cstdio>

#include "Image.h"

// Class initializer list - use to initialize member variables
Image::Image(const std::uint32_t width, const std::uint32_t height) :
_width(width), _height(height), _matrix(_width, std::vector<std::uint8_t>(_height, 0))
{


    std::cout << "Image created with shape=(" << width << ", " << height << ")\n";
}

Image::~Image()
{
    std::cout << "Image destroyed!" << '\n';
}



void Image::save_image(const char *file_name) const
{
    FILE *f = nullptr;

    auto num_bytes = 3 * _width * _height;
    auto *img = new std::uint8_t[num_bytes]{};

    auto filesize = 54 + 3 * _width * _height;

    for (std::uint32_t x = 0; x < _width; ++x)
    {
        for (std::uint32_t y = 0; y < _height; y++)
        {
            img[(x + y * _width) * 3 + 2] = _matrix[x][y] % 256;
            img[(x + y * _width) * 3 + 1] = _matrix[x][y] % 256;
            img[(x + y * _width) * 3 + 0] = _matrix[x][y] % 256;
        }
    }

    std::uint8_t
        bmpfileheader[14]{'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0};
    std::uint8_t
        bmpinfoheader[40]{40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 24, 0};
    std::uint8_t bmppad[3]{0, 0, 0};

    bmpfileheader[2] = static_cast<std::uint8_t>(filesize);
    bmpfileheader[3] = static_cast<std::uint8_t>(filesize >> 8);
    bmpfileheader[4] = static_cast<std::uint8_t>(filesize >> 16);
    bmpfileheader[5] = static_cast<std::uint8_t>(filesize >> 24);

    bmpinfoheader[4] = static_cast<std::uint8_t>(_width);
    bmpinfoheader[5] = static_cast<std::uint8_t>(_width >> 8);
    bmpinfoheader[6] = static_cast<std::uint8_t>(_width >> 16);
    bmpinfoheader[7] = static_cast<std::uint8_t>(_width >> 24);
    bmpinfoheader[8] = static_cast<std::uint8_t>(_height);
    bmpinfoheader[9] = static_cast<std::uint8_t>(_height >> 8);
    bmpinfoheader[10] = static_cast<std::uint8_t>(_height >> 16);
    bmpinfoheader[11] = static_cast<std::uint8_t>(_height >> 24);

    f = fopen(file_name, "wb");
    if (f == nullptr)
    {
        delete[] img;
        img = nullptr;

        return;
    }

    fwrite(bmpfileheader, 1, 14, f);
    fwrite(bmpinfoheader, 1, 40, f);

    for (std::uint32_t i = 0; i < _height; i++)
    {
        fwrite(img + (_width * (_height - i - 1) * 3), 3, _width, f);
        fwrite(bmppad, 1, (4 - (_width * 3) % 4) % 4, f);
    }

    fclose(f);
    f = nullptr;

    delete[] img;
    img = nullptr;
}

std::uint32_t Image::get_width() const
{
    return _width;
}

std::uint32_t Image::get_height() const
{
    return _height;
}

GrayscaleMatrix Image::get_matrix() const
{
    return _matrix;
}

void Image::set_pixel(const std::uint32_t x, const std::uint32_t y, const std::uint8_t value)
{
    _matrix[x][y] = value;
}
