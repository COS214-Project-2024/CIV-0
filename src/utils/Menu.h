#ifndef MENU_H
#define MENU_H

/**
 * @brief Enumeration for different menu types.
 *
 * This enum is used to identify and switch between different menus in the MenuManager.
 */
enum class Menu
{
    MAIN,                     ///< The Main Menu
    BUILDINGS,                ///< The Buildings Menu
    UPGRADES,                 ///< The Upgrades Menu
    POLICY,                   ///< The Policy Menu
    TAX,                      ///< The Tax Menu
    DISPLAYCITY,              ///< The Display City Menu
    BUY_AMENITY,              /// < The Menu for buying an Amnity
    BUY_ECONOMIC_BUILDING,    /// < The Menu for buying economic buildings
    BUY_RESIDENTIAL_BUILDING, /// < The Menu for buying residential buildings
    BUY_TRANSPORT,            /// < The Menu fior buying transport methods
    BUY_UTILITY,              /// < The Menu for buying utilities
    BUY_RESOURCE,             /// < The Menu for buying resource plants
    BUY_SERVICE,              /// < The Menu for buying a service building
    BUY_ROAD,                 /// < This Menu is for buying roads
    DEMOLISH,                 /// < This Menu is for selling building(s)

};

#endif // MENU_H
