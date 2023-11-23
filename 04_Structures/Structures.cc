#include <iostream>
#include <cstdint>
#include <string>

namespace Tutorial
{
    enum class Kind
    {
        NONE = 0,

        STUDENT,
        TUTOR,
        INSTRUCTOR,
        ADMIN
    };

    enum class ServerGroup
    {
        ADMIN, // Conflict with Kind::ADMIN without enum class
        USER
    };

    struct UserData
    {
        std::string name;
        std::uint32_t id;
        Kind kind;
    };

    void print_user(UserData &user)
    {
        std::cout << user.name << " with ID " << user.id << ":\n";

        if(user.kind == Kind::ADMIN)
            std::cout << "Is Admin!" << std::endl;

        switch(user.kind)
        {
            case Kind::NONE: break;

            case Kind::TUTOR:
                std::cout << "TUTOR" << std::endl;
                break;

            default:
            {
                std::cout << "DEFAULT" << std::endl;
                break;
            }
        }
    }
}

using namespace Tutorial;

int main()
{
    UserData Tobey = {"Tobey", 80288, Kind::STUDENT};
    UserData Auron = {"Auron", 80220, Kind::ADMIN};
    UserData Niro;
    Niro.name = "Niro";
    Niro.id = 50223;
    Niro.kind = Kind::ADMIN;

    //Designated initializer - order dependent
    UserData Abe = {
        .name = "Abe",
        .id = 8888,
        .kind = Kind::STUDENT
    };

    print_user(Tobey);
    print_user(Auron);
    print_user(Abe);

    return 0;
}
