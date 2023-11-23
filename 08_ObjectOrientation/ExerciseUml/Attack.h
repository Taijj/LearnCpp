#include <string>
#include <iostream>

class Attack
{
    public:
        Attack() = default;
        ~Attack() = default;

        virtual void attack() const = 0;
};

class Weapon : Attack
{
    protected:
        const std::string _name;
        const float _damage;
        const float _attack_speed;
        const bool _is_single_handed;
        const bool _is_dual_handed;

    public:
        Weapon() = delete;

        Weapon(const std::string name, const float damage, const float attack_speed, const bool is_single_handed, const bool is_dual_handed)
        : _name(name), _damage(damage), _attack_speed(attack_speed), _is_single_handed(is_single_handed), _is_dual_handed(is_dual_handed)
        {}

        ~Weapon() = default;



        std::string get_name() const
        {
            return _name;
        }

        float get_damage() const
        {
            return _damage;
        }

        float get_attack_speed() const
        {
            return _attack_speed;
        }

        bool get_is_single_handed() const
        {
            return _is_single_handed;
        }

        bool get_is_dual_handed() const
        {
            return _is_dual_handed;
        }

        void attack() const override
        {
            std::cout << "Attacking with " << _name << "! " << _damage << " damage dealt!" << '\n';
        }
};

class Axe : public Weapon
{
    public:
        Axe() = delete;

        Axe(bool is_single_handed, bool is_dual_handed)
        : Weapon("Axe", 15, 5, is_single_handed, is_dual_handed)
        {}

        ~Axe() = default;



        void attack() const final
        {
            Weapon::attack();
            if(_is_single_handed)
                std::cout << "Speed Bonus: " << _attack_speed << "'\n";
        }

};

class Longbow : public Weapon
{
    public:
        Longbow() = delete;

        Longbow(float damage, float attack_speed)
        : Weapon("Longbow", damage, attack_speed, false, true)
        {}

        ~Longbow() = default;



        void attack() const final
        {
            Weapon::attack();
            std::cout << "Arrow Bonus: " << _attack_speed << "'\n";
        }
};
