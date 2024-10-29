#include "Transport.h"

Transport::Transport(EntityConfig ec, Size size, int xPos, int yPos) : Entity(ec, size, xPosition, yPosition)
{
    subscribeToAllResidentialInRadius();
}

Transport::Transport(Transport* transport): Entity(transport)
{
    subscribeToAllResidentialInRadius();
}

Transport::Transport() {}
Transport::~Transport() {}
