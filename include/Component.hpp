#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include "Entity.hpp"

// Figure out whether the Entity should have a vector components or whether each component should 
// have access to its host
struct Component
{
    public:
        Component(Entity* host) : host(host) {}

        Entity* const host;
};

#endif