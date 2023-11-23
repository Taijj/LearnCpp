#pragma once

#include <string>
#include <iostream>
#include <cstdint>

// default
// to tell the compiler to generate the needed code itself
// e.g. virtual ~Destructor() = default;

// delete
// to make explicit, that certain expected things are purposefully not provided
// e.g. EmptyConstructor() = delete;

// For child classes:
// override - as is
// final
// Mark method as "not overridable"

class Agent
{
    public:
        Agent(const std::string &name, const std::uint32_t id, const std::uint32_t hp, const std::uint32_t energy)
            : m_name(name), m_id(id), m_hp(hp), m_energy(energy)
        {

        }

        // Necessary as soon as there is one virtual method
        // Ensures that all the hierarchy's destructors are called when object where allocated on the heap
        virtual ~Agent()
        {}

        virtual void print_name()
        {
            std::cout << m_name << '\n';
        }

    protected:
        const std::string m_name;
        const std::uint32_t m_id;
        const std::uint32_t m_hp;
        const std::uint32_t m_energy;
};

// Inheritance access modifiers
// public - all stay as defined in parent
// protected - all public become protected
// private - everything becomes private
class Player : public Agent
{
    public:
        Player(const std::string &name, const std::uint32_t id, const std::uint32_t hp, const std::uint32_t energy) : Agent(name, id, hp, energy)
        {

        }

        ~Player()
        {}

        void print_name() override // !
        {
            std::cout << "Playor: " << m_name << '\n';
        }
};

class Npc : public Agent
{
    public:
        Npc(const std::string &name, const std::uint32_t id, const std::uint32_t hp, const std::uint32_t energy) : Agent(name, id, hp, energy)
        {

        }

        ~Npc()
        {}
};
