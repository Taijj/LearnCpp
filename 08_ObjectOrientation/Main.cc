#include <iostream>

#include "Image.h"
#include "Agent.h"

void Imaging()
{
    Image my_image(100, 400);
    std::cout << my_image.get_width() << '\n';
    std::cout << my_image.get_height() << '\n';

    my_image.set_pixel(10, 10, 255);
    my_image.set_pixel(11, 11, 255);
    my_image.set_pixel(10, 11, 255);
    my_image.set_pixel(11, 10, 255);
    my_image.save_image("image.bmp");
}

void Inheritance()
{
    auto agent = Agent {"A1", 0U, 0, 0};
    auto player = Player {"P1", 0U, 0, 0};
    auto npc = Npc {"N1", 0U, 0, 0};

    // In a container this only works with pointers!
    agent.print_name();
    player.print_name();
}

int main()
{
    // Image();
    Inheritance();

    return 0;
}
