#ifndef BUYSERVICEMENU_H
#define BUYSERVICEMENU_H

#include "menus/base/BuyMenu.h"
#include "managers/ServiceManager.h"

/**
 * @brief Menu for purchasing service buildings (Police Station, School, Hospital).
 */
class BuyServiceMenu : public BuyMenu
{
public:
    /**
     * @brief Constructor for BuyServiceMenu.
     */
    BuyServiceMenu();

    /**
     * @brief Destructor for BuyServiceMenu.
     */
    ~BuyServiceMenu();

protected:
    /**
     * @brief Override to choose service building types.
     * @return The selected EntityType (Police Station, School, or Hospital).
     */
    EntityType chooseEntityType() override;

    void buildEntity(EntityType type, Size size, int xPos, int yPos) override;

private:
    ServiceManager serviceManager;
};

#endif // BUYSERVICEMENU_H
