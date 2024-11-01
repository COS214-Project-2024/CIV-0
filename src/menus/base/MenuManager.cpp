#include "MenuManager.h"

/**
 * @brief Singleton instance method.
 * @return The singleton instance of MenuManager.
 */
MenuManager &MenuManager::instance()
{
    static MenuManager instance;
    return instance;
}

/**
 * @brief Private constructor for MenuManager.
 * Initializes all the menus and stores them in the map with the enum as the key.
 */
MenuManager::MenuManager()
{
    // Initialize all the menus and store them in the map with the enum as the key
    menus[Menu::MAIN] = std::make_shared<MainMenu>();
    menus[Menu::BUILDINGS] = std::make_shared<BuildingsMenu>();
    menus[Menu::POLICY] = std::make_shared<PolicyMenu>();
    menus[Menu::UPGRADES] = std::make_shared<UpgradesMenu>();
    menus[Menu::TAX] = std::make_shared<TaxMenu>();
    menus[Menu::DISPLAYCITY] = std::make_shared<DisplayCityMenu>();
    menus[Menu::BUY_AMENITY] = std::make_shared<BuyAmenityMenu>();
    menus[Menu::BUY_ECONOMIC_BUILDING] = std::make_shared<BuyEconomicBuildingMenu>();
    menus[Menu::BUY_RESIDENTIAL_BUILDING] = std::make_shared<BuyResidentialBuildingMenu>();
    menus[Menu::BUY_TRANSPORT] = std::make_shared<BuyTransportMenu>();
    menus[Menu::BUY_UTILITY] = std::make_shared<BuyUtilityMenu>();
    menus[Menu::BUY_RESOURCE] = std::make_shared<BuyResourceMenu>();
    menus[Menu::BUY_SERVICE] = std::make_shared<BuyServiceMenu>();
    menus[Menu::BUY_ROAD] = std::make_shared<BuyRoadMenu>();
    menus[Menu::DEMOLISH] = std::make_shared<DemolishMenu>();
    menus[Menu::STATS] = std::make_shared<StatsMenu>();

    // Set the default menu to MainMenu
    setCurrentMenu(Menu::MAIN);
}

/**
 * @brief Destructor for MenuManager.
 */
MenuManager::~MenuManager() {}

/**
 * @brief Sets the current menu by enum key.
 * @param menuType The type of the menu to switch to.
 */
void MenuManager::setCurrentMenu(Menu menuType)
{
    if (menus.find(menuType) != menus.end())
    {
        currentMenu = menus[menuType];
    }
    else
    {
        std::cerr << "Menu not found!" << std::endl;
    }
}

/**
 * @brief Sets the current menu using a dynamic menu passed as a shared pointer.
 * @param menu The shared pointer to the menu to set as current.
 */
void MenuManager::setCurrentMenu(std::shared_ptr<IMenu> menu)
{
    currentMenu = menu;
}

/**
 * @brief Displays the currently active menu.
 */
void MenuManager::displayCurrentMenu()
{
    if (currentMenu)
    {
        currentMenu->display();
    }
    else
    {
        std::cout << "No menu is set." << std::endl;
    }
}

/**
 * @brief Handles the input for the current menu.
 */
void MenuManager::handleCurrentMenuInput()
{
    if (currentMenu)
    {
        currentMenu->handleInput();
    }
}

/**
 * @brief Sets the reference to the City object to be used by menus.
 * @param city Pointer to the City object.
 */
void MenuManager::setCity(City *city)
{
    this->city = city;
}

/**
 * @brief Gets the reference to the City object.
 * @return Pointer to the City object.
 */
City *MenuManager::getCity() const
{
    return city;
}

/**
 * @brief Clears the terminal screen.
 */
void MenuManager::clearScreen() const
{
    system("clear");
}
