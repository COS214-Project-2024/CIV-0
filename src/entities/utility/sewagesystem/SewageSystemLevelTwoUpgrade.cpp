#include "SewageSystemLevelTwoUpgrade.h"
#include "entities/utility/sewagesystem/SewageSystemLevelThreeUpgrade.h"

SewageSystemLevelTwoUpgrade::SewageSystemLevelTwoUpgrade(SewageSystem *sewage) : SewageSystemUpgrade(sewage)
{
}

SewageSystemLevelTwoUpgrade::SewageSystemLevelTwoUpgrade(SewageSystemLevelTwoUpgrade *sewageSystemLevelTwoUpgrade) : SewageSystemUpgrade(sewageSystemLevelTwoUpgrade)
{
}

SewageSystemLevelTwoUpgrade::~SewageSystemLevelTwoUpgrade()
{
}

void SewageSystemLevelTwoUpgrade::update()
{
    sewageSystem->update();
}

int SewageSystemLevelTwoUpgrade::getLevel()
{
    return 2;
}

Entity *SewageSystemLevelTwoUpgrade::clone()
{
    return new SewageSystemLevelTwoUpgrade(this);
}

Entity *SewageSystemLevelTwoUpgrade::upgrade()
{
    return new SewageSystemLevelThreeUpgrade(sewageSystem);
}

int SewageSystemLevelTwoUpgrade::getOutput()
{
    return sewageSystem->getOutput() * UPGRADE;
}

Cost SewageSystemLevelTwoUpgrade::getCost()
{
    return Cost(sewageSystem->getCost().moneyCost * UPGRADE, sewageSystem->getCost().woodCost * UPGRADE, sewageSystem->getCost().stoneCost * UPGRADE, sewageSystem->getCost().concreteCost * UPGRADE);
}