#include "BuyAmenityMenu.h"
#include "menus/base/MenuManager.h"

EntityType BuyAmenityMenu::chooseEntityType()
{
    sections = {
        {"Options",
         {{'1', "🌳", "Park"},
          {'2', "🎭", "Theater"},
          {'3', "🗽", "Monument"}}},
        {"Navigation",
         {{'b', "🔙", "Back to Building Menu"},
          {'q', "🔙", "Back to Main Menu"}}}};
    setHeading("Select Amenity Type");
    clearScreen();
    displayMenu();

    EntityType type;
    bool choosing = true;

    while (choosing)
    {
        char choice;
        displayChoicePrompt();
        std::cin >> choice;

        switch (choice)
        {
        case '1':
            type = EntityType::PARK;
            choosing = false;
            break;
        case '2':
            type = EntityType::THEATER;
            choosing = false;
            break;
        case '3':
            type = EntityType::MONUMENT;
            choosing = false;
            break;
        case 'b':
            MenuManager::instance().setCurrentMenu(Menu::BUILDINGS);
            choosing = false;
            hasExited = true;
            break;
        case 'q':
            MenuManager::instance().setCurrentMenu(Menu::MAIN);
            choosing = false;
            hasExited = true;
            break;
        default:
            displayInvalidChoice();
            break;
        }
    }

    return type;
}
