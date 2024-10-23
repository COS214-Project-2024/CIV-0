#include "Transport.h"

Transport::Transport(EntityConfig ec, Size size, int xPos, int yPos) : Entity(ec, size, xPosition, yPosition)
{

}

Transport::Transport(Transport* transport) : Entity(transport)
{
    
}

Transport::Transport() {}
Transport::~Transport() {}
