#include "Transport.h"

Transport::Transport(EntityConfig ec, Size size, int xPos, int yPos) : Entity(ec, size, xPos, yPos)
{
    subscribeToAllResidentialInRadius();
}

Transport::Transport(Transport* transport): Entity(transport)
{
    subscribeToAllResidentialInRadius();
}

Transport::Transport(Transport* transport) : Entity(transport)
{
    
}

Transport::Transport() {}
Transport::~Transport() {}
