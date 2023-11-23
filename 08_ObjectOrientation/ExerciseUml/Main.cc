#include "Attack.h"

int main()
{
    Weapon fists = Weapon("Fists", 1, 10, false, true);
    Axe axe_one_handed = Axe(true, false);
    Axe axe_two_handed = Axe(false, true);
    Longbow bow1 = Longbow(25, 5);
    Longbow bow2 = Longbow(10, 25);
    Weapon* axe_implicit = &axe_one_handed;

    fists.attack();
    axe_one_handed.attack();
    axe_two_handed.attack();
    bow1.attack();
    bow2.attack();

    axe_implicit->attack();

    return 0;
}
