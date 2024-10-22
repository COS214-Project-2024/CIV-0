#ifndef BUYMENU_H
#define BUYMENU_H

#include "menus/base/IMenu.h"
#include "utils/EntityType.h"
#include "utils/Size.h"

class BuyMenu : public IMenu
{
public:
    BuyMenu();
    virtual ~BuyMenu();

    /**
     * @brief Displays the base menu.
     */
    void display() const override;

    /**
     * @brief Handles user input in the base menu.
     */
    void handleInput() override;

protected:
    virtual EntityType chooseEntityType() = 0; // Must be implemented by derived classes
    Size chooseBuildingSize(EntityType type);
    void chooseBuildingPosition(int &xPos, int &yPos);
    void confirmPurchase(EntityType type, Size size, int xPos, int yPos);

    int availableMoney;
    int availableWood;
    int availableStone;
    int availableConcrete;
};

#endif // BUYMENU_H
