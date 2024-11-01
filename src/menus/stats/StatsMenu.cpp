#include "StatsMenu.h"
#include "menus/base/MenuManager.h"
#include "utils/EntityType.h"
#include <iostream>
#include <iomanip>

StatsMenu::StatsMenu() : IMenu()
{
}
StatsMenu::~StatsMenu() {}

void StatsMenu::display() const
{
    clearScreen();
    displayMenu();
}

void StatsMenu::handleInput()
{

    bool choosing = true;

    while (choosing)
    {
        isInfoMenu = false;
        displayResources = false;
        setHeading("City Statistics");

        sections = {
            {"Entity Listings",
             {{'1', "🏙️ ", "List All City Entities"},
              {'2', "🏢", "List All Buildings"},
              {'3', "⚙️ ", "List All Utilities"},
              {'4', "🛣️ ", "List All Roads"},
              {'5', "🚍", "List All Transport"},
              {'6', "🏛️ ", "List All Economic Buildings"},
              {'7', "🏘️ ", "List All Residential Buildings"},
              {'8', "🏥", "List All Service Buildings"},
              {'9', "🌳", "List All Amenities"}}},
            {"Utility Listings",
             {{'a', "⚡", "List All Power Plants"},
              {'b', "💧", "List All Water Supplies"},
              {'c', "🚮", "List All Waste Management"},
              {'d', "🚰", "List All Sewage Systems"}}},
            {"Producer Listings",
             {{'e', "🪨 ", "List All Concrete Producers"},
              {'f', "🔨", "List All Stone Producers"},
              {'g', "🌲", "List All Wood Producers"}}},
            {"Statistics",
             {{'s', "📊", "View City Statistics"}}},
            {"Navigation",
             {{'q', "⬅️ ", "Back to Main Menu"}}}};

        display(); // Display the menu at the start of each loop
        char choice;
        displayChoicePrompt();
        std::cin >> choice;

        switch (choice)
        {
        case '1':
            listAllCityEntities();
            break;
        case '2':
            listAllBuildings();
            break;
        case '3':
            listAllUtilities();
            break;
        case '4':
            listAllRoads();
            break;
        case '5':
            listAllTransport();
            break;
        case '6':
            listAllEconomicBuildings();
            break;
        case '7':
            listAllResidentialBuildings();
            break;
        case '8':
            listAllServiceBuildings();
            break;
        case '9':
            listAllAmenities();
            break;
        case 'a':
            listAllPowerPlants();
            break;
        case 'b':
            listAllWaterSupplies();
            break;
        case 'c':
            listAllWasteManagement();
            break;
        case 'd':
            listAllSewageSystems();
            break;
        case 'e':
            listAllConcreteProducers();
            break;
        case 'f':
            listAllStoneProducers();
            break;
        case 'g':
            listAllWoodProducers();
            break;
        case 's':
            showCityStats();
            break;
        case 'q':
            MenuManager::instance().setCurrentMenu(Menu::MAIN);
            choosing = false;
            break;
        default:
            displayInvalidChoice();
        }
    }
}

// Example of a listing function using an iterator
void StatsMenu::listAllCityEntities()
{
    clearScreen();
    setHeading("City Entities Summary");

    City *city = City::instance();
    Iterator *iterator = city->createCityIterator(true);

    sections.clear(); // Clear previous sections
    isInfoMenu = true;

    // Prepare a section for all city entities
    std::vector<Option> entityOptions;
    for (iterator->first(); iterator->hasNext(); iterator->next())
    {
        Entity *entity = iterator->current();
        if (entity)
        {
            std::string type = entityTypeToString(entity->getType());
            std::string description = " located at (" +
                                      std::to_string(entity->getXPosition()) + ", " +
                                      std::to_string(entity->getYPosition()) + ")";

            // Create an option entry for each entity
            entityOptions.push_back({'-', entity->getSymbol() + " ", description + ", Type: " + type});
        }
    }
    delete iterator;

    // Add entity options to sections
    sections.push_back({"All City Entities", entityOptions});

    // Display entities in sections using displayMenu()
    displayMenu();

    displayPressEnterToContinue();

    isInfoMenu = false; // Reset after displaying
}

void StatsMenu::listAllBuildings()
{
    clearScreen();
    setHeading("Buildings Summary");

    City *city = City::instance();
    Iterator *iterator = city->createBuildingIterator(true);

    sections.clear();
    isInfoMenu = true;

    std::vector<Option> buildingOptions;
    for (iterator->first(); iterator->hasNext(); iterator->next())
    {
        Entity *entity = iterator->current();
        if (entity)
        {
            std::string type = entityTypeToString(entity->getType());
            std::string description = " located at (" +
                                      std::to_string(entity->getXPosition()) + ", " +
                                      std::to_string(entity->getYPosition()) + ")";

            buildingOptions.push_back({'-', entity->getSymbol() + " ", description + ", Type: " + type});
        }
    }
    delete iterator;

    sections.push_back({"All Buildings", buildingOptions});

    displayMenu();
    displayPressEnterToContinue();

    isInfoMenu = false;
}

void StatsMenu::listAllUtilities()
{
    clearScreen();
    setHeading("Utilities Summary");

    City *city = City::instance();
    Iterator *iterator = city->createUtilityIterator(true);

    sections.clear();
    isInfoMenu = true;

    std::vector<Option> utilityOptions;
    for (iterator->first(); iterator->hasNext(); iterator->next())
    {
        Entity *entity = iterator->current();
        if (entity)
        {
            std::string type = entityTypeToString(entity->getType());
            std::string description = " located at (" +
                                      std::to_string(entity->getXPosition()) + ", " +
                                      std::to_string(entity->getYPosition()) + ")";

            utilityOptions.push_back({'-', entity->getSymbol() + " ", description + ", Type: " + type});
        }
    }
    delete iterator;

    sections.push_back({"All Utilities", utilityOptions});

    displayMenu();
    displayPressEnterToContinue();

    isInfoMenu = false;
}

void StatsMenu::listAllRoads()
{
    clearScreen();
    setHeading("Roads Summary");

    City *city = City::instance();
    Iterator *iterator = city->createRoadIterator(true);

    sections.clear();
    isInfoMenu = true;

    std::vector<Option> roadOptions;
    for (iterator->first(); iterator->hasNext(); iterator->next())
    {
        Entity *entity = iterator->current();
        if (entity)
        {
            std::string type = entityTypeToString(entity->getType());
            std::string description = " located at (" +
                                      std::to_string(entity->getXPosition()) + ", " +
                                      std::to_string(entity->getYPosition()) + ")";

            roadOptions.push_back({'-', entity->getSymbol() + " ", description + ", Type: " + type});
        }
    }
    delete iterator;

    sections.push_back({"All Roads", roadOptions});

    displayMenu();
    displayPressEnterToContinue();

    isInfoMenu = false;
}

void StatsMenu::listAllTransport()
{
    clearScreen();
    setHeading("List of All Transport");

    Iterator *iterator = City::instance()->createTransportIterator(true);

    sections.clear();
    isInfoMenu = true;

    std::vector<Option> transportOptions;
    for (iterator->first(); iterator->hasNext(); iterator->next())
    {
        Entity *entity = iterator->current();
        if (entity)
        {
            std::string type = entityTypeToString(entity->getType());
            std::string description = " located at (" +
                                      std::to_string(entity->getXPosition()) + ", " +
                                      std::to_string(entity->getYPosition()) + ")";

            transportOptions.push_back({'-', entity->getSymbol() + " ", description + ", Type: " + type});
        }
    }
    delete iterator;

    sections.push_back({"All Transport", transportOptions});

    displayMenu();
    displayPressEnterToContinue();

    isInfoMenu = false;
}

void StatsMenu::listAllEconomicBuildings()
{
    clearScreen();
    setHeading("List of All Economic Buildings");

    Iterator *iterator = City::instance()->createEconomicBuildingIterator(true);

    sections.clear();
    isInfoMenu = true;

    std::vector<Option> economicOptions;
    for (iterator->first(); iterator->hasNext(); iterator->next())
    {
        Entity *entity = iterator->current();
        if (entity)
        {
            std::string type = entityTypeToString(entity->getType());
            std::string description = " located at (" +
                                      std::to_string(entity->getXPosition()) + ", " +
                                      std::to_string(entity->getYPosition()) + ")";

            economicOptions.push_back({'-', entity->getSymbol() + " ", description + ", Type: " + type});
        }
    }
    delete iterator;

    sections.push_back({"All Economic Buildings", economicOptions});

    displayMenu();
    displayPressEnterToContinue();

    isInfoMenu = false;
}

void StatsMenu::listAllResidentialBuildings()
{
    clearScreen();
    setHeading("List of All Residential Buildings");

    Iterator *iterator = City::instance()->createResidentialBuildingIterator(true);

    sections.clear();
    isInfoMenu = true;

    std::vector<Option> residentialOptions;
    for (iterator->first(); iterator->hasNext(); iterator->next())
    {
        Entity *entity = iterator->current();
        if (entity)
        {
            std::string type = entityTypeToString(entity->getType());
            std::string description = " located at (" +
                                      std::to_string(entity->getXPosition()) + ", " +
                                      std::to_string(entity->getYPosition()) + ")";

            residentialOptions.push_back({'-', entity->getSymbol() + " ", description + ", Type: " + type});
        }
    }
    delete iterator;

    sections.push_back({"All Residential Buildings", residentialOptions});

    displayMenu();
    displayPressEnterToContinue();

    isInfoMenu = false;
}

void StatsMenu::listAllServiceBuildings()
{
    clearScreen();
    setHeading("List of All Service Buildings");

    Iterator *iterator = City::instance()->createServiceBuildingIterator(true);

    sections.clear();
    isInfoMenu = true;

    std::vector<Option> serviceOptions;
    for (iterator->first(); iterator->hasNext(); iterator->next())
    {
        Entity *entity = iterator->current();
        if (entity)
        {
            std::string type = entityTypeToString(entity->getType());
            std::string description = " located at (" +
                                      std::to_string(entity->getXPosition()) + ", " +
                                      std::to_string(entity->getYPosition()) + ")";

            serviceOptions.push_back({'-', entity->getSymbol() + " ", description + ", Type: " + type});
        }
    }
    delete iterator;

    sections.push_back({"All Service Buildings", serviceOptions});

    displayMenu();
    displayPressEnterToContinue();

    isInfoMenu = false;
}

void StatsMenu::listAllAmenities()
{
    clearScreen();
    setHeading("List of All Amenities");

    Iterator *iterator = City::instance()->createAmenityIterator(true);

    sections.clear();
    isInfoMenu = true;

    std::vector<Option> amenityOptions;
    for (iterator->first(); iterator->hasNext(); iterator->next())
    {
        Entity *entity = iterator->current();
        if (entity)
        {
            std::string type = entityTypeToString(entity->getType());
            std::string description = " located at (" +
                                      std::to_string(entity->getXPosition()) + ", " +
                                      std::to_string(entity->getYPosition()) + ")";

            amenityOptions.push_back({'-', entity->getSymbol() + " ", description + ", Type: " + type});
        }
    }
    delete iterator;

    sections.push_back({"All Amenities", amenityOptions});

    displayMenu();
    displayPressEnterToContinue();

    isInfoMenu = false;
}

void StatsMenu::listAllPowerPlants()
{
    clearScreen();
    setHeading("List of All Power Plants");

    Iterator *iterator = City::instance()->createPowerPlantIterator(true);

    sections.clear();
    isInfoMenu = true;

    std::vector<Option> powerPlantOptions;
    for (iterator->first(); iterator->hasNext(); iterator->next())
    {
        Entity *entity = iterator->current();
        if (entity)
        {
            std::string type = entityTypeToString(entity->getType());
            std::string description = " located at (" +
                                      std::to_string(entity->getXPosition()) + ", " +
                                      std::to_string(entity->getYPosition()) + ")";

            powerPlantOptions.push_back({'-', entity->getSymbol() + " ", description + ", Type: " + type});
        }
    }
    delete iterator;

    sections.push_back({"All Power Plants", powerPlantOptions});

    displayMenu();
    displayPressEnterToContinue();

    isInfoMenu = false;
}

void StatsMenu::listAllWaterSupplies()
{
    clearScreen();
    setHeading("List of All Water Supplies");

    Iterator *iterator = City::instance()->createWaterSupplyIterator(true);

    sections.clear();
    isInfoMenu = true;

    std::vector<Option> waterSupplyOptions;
    for (iterator->first(); iterator->hasNext(); iterator->next())
    {
        Entity *entity = iterator->current();
        if (entity)
        {
            std::string type = entityTypeToString(entity->getType());
            std::string description = " located at (" +
                                      std::to_string(entity->getXPosition()) + ", " +
                                      std::to_string(entity->getYPosition()) + ")";

            waterSupplyOptions.push_back({'-', entity->getSymbol() + " ", description + ", Type: " + type});
        }
    }
    delete iterator;

    sections.push_back({"All Water Supplies", waterSupplyOptions});

    displayMenu();
    displayPressEnterToContinue();

    isInfoMenu = false;
}

void StatsMenu::listAllWasteManagement()
{
    clearScreen();
    setHeading("List of All Waste Management");

    Iterator *iterator = City::instance()->createWasteManagementIterator(true);

    sections.clear();
    isInfoMenu = true;

    std::vector<Option> wasteManagementOptions;
    for (iterator->first(); iterator->hasNext(); iterator->next())
    {
        Entity *entity = iterator->current();
        if (entity)
        {
            std::string type = entityTypeToString(entity->getType());
            std::string description = " located at (" +
                                      std::to_string(entity->getXPosition()) + ", " +
                                      std::to_string(entity->getYPosition()) + ")";

            wasteManagementOptions.push_back({'-', entity->getSymbol() + " ", description + ", Type: " + type});
        }
    }
    delete iterator;

    sections.push_back({"All Waste Management", wasteManagementOptions});

    displayMenu();
    displayPressEnterToContinue();

    isInfoMenu = false;
}

void StatsMenu::listAllSewageSystems()
{
    clearScreen();
    setHeading("List of All Sewage Systems");

    Iterator *iterator = City::instance()->createSewageSystemIterator(true);

    sections.clear();
    isInfoMenu = true;

    std::vector<Option> sewageSystemOptions;
    for (iterator->first(); iterator->hasNext(); iterator->next())
    {
        Entity *entity = iterator->current();
        if (entity)
        {
            std::string type = entityTypeToString(entity->getType());
            std::string description = " located at (" +
                                      std::to_string(entity->getXPosition()) + ", " +
                                      std::to_string(entity->getYPosition()) + ")";

            sewageSystemOptions.push_back({'-', entity->getSymbol() + " ", description + ", Type: " + type});
        }
    }
    delete iterator;

    sections.push_back({"All Sewage Systems", sewageSystemOptions});

    displayMenu();
    displayPressEnterToContinue();

    isInfoMenu = false;
}

void StatsMenu::listAllConcreteProducers()
{
    clearScreen();
    setHeading("List of All Concrete Producers");

    Iterator *iterator = City::instance()->createConcreteProducerIterator(true);

    sections.clear();
    isInfoMenu = true;

    std::vector<Option> concreteProducerOptions;
    for (iterator->first(); iterator->hasNext(); iterator->next())
    {
        Entity *entity = iterator->current();
        if (entity)
        {
            std::string type = entityTypeToString(entity->getType());
            std::string description = " located at (" +
                                      std::to_string(entity->getXPosition()) + ", " +
                                      std::to_string(entity->getYPosition()) + ")";

            concreteProducerOptions.push_back({'-', entity->getSymbol() + " ", description + ", Type: " + type});
        }
    }
    delete iterator;

    sections.push_back({"All Concrete Producers", concreteProducerOptions});

    displayMenu();
    displayPressEnterToContinue();

    isInfoMenu = false;
}

void StatsMenu::listAllStoneProducers()
{
    clearScreen();
    setHeading("List of All Stone Producers");

    Iterator *iterator = City::instance()->createStoneProducerIterator(true);

    sections.clear();
    isInfoMenu = true;

    std::vector<Option> stoneProducerOptions;
    for (iterator->first(); iterator->hasNext(); iterator->next())
    {
        Entity *entity = iterator->current();
        if (entity)
        {
            std::string type = entityTypeToString(entity->getType());
            std::string description = " located at (" +
                                      std::to_string(entity->getXPosition()) + ", " +
                                      std::to_string(entity->getYPosition()) + ")";

            stoneProducerOptions.push_back({'-', entity->getSymbol() + " ", description + ", Type: " + type});
        }
    }
    delete iterator;

    sections.push_back({"All Stone Producers", stoneProducerOptions});

    displayMenu();
    displayPressEnterToContinue();

    isInfoMenu = false;
}

void StatsMenu::listAllWoodProducers()
{
    clearScreen();
    setHeading("List of All Wood Producers");

    Iterator *iterator = City::instance()->createWoodProducerIterator(true);

    sections.clear();
    isInfoMenu = true;

    std::vector<Option> woodProducerOptions;
    for (iterator->first(); iterator->hasNext(); iterator->next())
    {
        Entity *entity = iterator->current();
        if (entity)
        {
            std::string type = entityTypeToString(entity->getType());
            std::string description = " located at (" +
                                      std::to_string(entity->getXPosition()) + ", " +
                                      std::to_string(entity->getYPosition()) + ")";

            woodProducerOptions.push_back({'-', entity->getSymbol() + " ", description + ", Type: " + type});
        }
    }
    delete iterator;

    sections.push_back({"All Wood Producers", woodProducerOptions});

    displayMenu();
    displayPressEnterToContinue();

    isInfoMenu = false;
}

void StatsMenu::showCityStats()
{
    setHeading("City Statistics Summary");

    City *city = City::instance();

    isInfoMenu = true;
    displayResources = false;

    std::string satisfactionColor = (city->getSatisfaction() >= 70) ? BOLD_GREEN : (city->getSatisfaction() >= 30) ? BOLD_YELLOW
                                                                                                                   : BOLD_RED;

    sections = {
        {"General Statistics",
         {{'-', "👥", "Population: " + std::to_string(city->getPopulation()) + "/" + std::to_string(city->getPopulationCapacity())},
          {'-', "😊", "Satisfaction: " + satisfactionColor + std::to_string(static_cast<int>(city->getSatisfaction())) + "%" + RESET}}},
        {"Resources",
         {{'-', "💵", "Money: " + std::string(BOLD_GREEN) + std::to_string(city->getMoney()) + RESET},
          {'-', "🌲", "Wood: " + std::string(BOLD_CYAN) + std::to_string(city->getWood()) + RESET},
          {'-', "🪨 ", "Stone: " + std::string(BOLD_CYAN) + std::to_string(city->getStone()) + RESET},
          {'-', "🏗️ ", "Concrete: " + std::string(BOLD_CYAN) + std::to_string(city->getConcrete()) + RESET}}},
        {"Production & Consumption",
         {{'-', "⚡", "Electricity Production: " + std::string(BOLD_YELLOW) + std::to_string(city->getElectricityProduction()) + RESET + ", Consumption: " + std::string(BOLD_RED) + std::to_string(city->getElectricityConsumption()) + RESET},
          {'-', "💧", "Water Production: " + std::string(BOLD_YELLOW) + std::to_string(city->getWaterProduction()) + RESET + ", Consumption: " + std::string(BOLD_RED) + std::to_string(city->getWaterConsumption()) + RESET},
          {'-', "🚮", "Waste Production: " + std::string(BOLD_YELLOW) + std::to_string(city->getWasteProduction()) + RESET + ", Consumption: " + std::string(BOLD_RED) + std::to_string(city->getWasteConsumption()) + RESET},
          {'-', "🚰", "Sewage Production: " + std::string(BOLD_YELLOW) + std::to_string(city->getSewageProduction()) + RESET + ", Consumption: " + std::string(BOLD_RED) + std::to_string(city->getSewageConsumption()) + RESET}}},
        {"Tax Rates",
         {{'-', "🏡", "Residential Tax Rate: " + std::string(BOLD_CYAN) + std::to_string(city->getResidentialTax()) + "%" + RESET},
          {'-', "🏢", "Economic Tax Rate: " + std::string(BOLD_CYAN) + std::to_string(city->getEconomicTax()) + "%" + RESET}}}};

    // Display the statistics in sections using displayMenu()
    displayMenu();

    // Wait for user input to return to Stats menu
    displayPressEnterToContinue();

    isInfoMenu = false;
    displayResources = true;
    MenuManager::instance().setCurrentMenu(Menu::STATS);
}
