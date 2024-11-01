#include "SewageSystemUpgrade.h"

SewageSystemUpgrade::SewageSystemUpgrade(SewageSystem *sewage) : SewageSystem(sewage)
{
    this->sewageSystem = new SewageSystem(sewage);
}

SewageSystemUpgrade::SewageSystemUpgrade(SewageSystemUpgrade *sewageSystemUpgrade) : SewageSystem(sewageSystemUpgrade)
{
    this->sewageSystem = new SewageSystem(sewageSystemUpgrade->sewageSystem);
}

SewageSystemUpgrade::~SewageSystemUpgrade()
{
    if (sewageSystem != nullptr)
    {
        delete sewageSystem;
        sewageSystem = nullptr;
    }
}