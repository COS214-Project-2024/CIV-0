#include "StatsMenu.h"
#include "menus/base/MenuManager.h"
#include "utils/EntityType.h"
#include "city/CivZero.h"
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
             {{'0', "🏙️ ", "List All City Entities"},
              {'1', "🏢", "List All Buildings"},
              {'2', "⚙️ ", "List All Utilities"},
              {'3', "🛠️ ", "List All Industries"},
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
        case '0':
            listEntities(City::instance()->createCityIterator(true), labelGenerator, "City Entities Summary");
            break;
        case '1':
            listEntities(City::instance()->createBuildingIterator(true), labelGenerator, "Buildings Summary");
            break;
        case '2':
            listEntities(City::instance()->createUtilityIterator(true), utilityLabelGenerator, "Utilities Summary");
            break;
        case '3':
            listEntities(City::instance()->createIndustryIterator(true), industrialLabelGenerator, "Industry Summary");
            break;
        case '4':
            listEntities(City::instance()->createRoadIterator(true), labelGenerator, "Roads Summary");
            break;
        case '5':
            listEntities(City::instance()->createTransportIterator(true), labelGenerator, "Transport Summary");
            break;
        case '6':
            listEntities(City::instance()->createEconomicBuildingIterator(true), labelGenerator, "Economic Buildings Summary");
            break;
        case '7':
            listEntities(City::instance()->createResidentialBuildingIterator(true), residentialLabelGenerator, "Residential Buildings Summary");
            break;
        case '8':
            listEntities(City::instance()->createServiceBuildingIterator(true), labelGenerator, "Service Buildings Summary");
            break;
        case '9':
            listEntities(City::instance()->createAmenityIterator(true), labelGenerator, "Amenities Summary");
            break;
        case 'a':
            listEntities(City::instance()->createPowerPlantIterator(true), utilityLabelGenerator, "Power Plants Summary");
            break;
        case 'b':
            listEntities(City::instance()->createWaterSupplyIterator(true), utilityLabelGenerator, "Water Supplies Summary");
            break;
        case 'c':
            listEntities(City::instance()->createWasteManagementIterator(true), utilityLabelGenerator, "Waste Management Summary");
            break;
        case 'd':
            listEntities(City::instance()->createSewageSystemIterator(true), utilityLabelGenerator, "Sewage Systems Summary");
            break;
        case 'e':
            listEntities(City::instance()->createConcreteProducerIterator(true), industrialLabelGenerator, "Concrete Producers Summary");
            break;
        case 'f':
            listEntities(City::instance()->createStoneProducerIterator(true), industrialLabelGenerator, "Stone Producers Summary");
            break;
        case 'g':
            listEntities(City::instance()->createWoodProducerIterator(true), industrialLabelGenerator, "Wood Producers Summary");
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

std::string StatsMenu::labelGenerator(Entity *entity)
{
    std::string type = entityTypeToString(entity->getType());
    std::string size = sizeToString(entity->getSize());
    std::string position = coordinatesToLabel(entity->getXPosition(), entity->getYPosition());
    std::string observers = std::to_string(entity->getObservers().size());
    return position + ", " + type + ", " + size + ", Observers = " + observers;
}

std::string StatsMenu::residentialLabelGenerator(Entity *entity)
{
    std::string type = entityTypeToString(entity->getType());
    std::string position = coordinatesToLabel(entity->getXPosition(), entity->getYPosition());
    int satisfaction = dynamic_cast<ResidentialBuilding *>(entity)->getSatisfaction();
    std::string satisfactionColor = (satisfaction >= 70) ? BOLD_GREEN : (satisfaction >= 40) ? BOLD_YELLOW
                                                                                             : BOLD_RED;
    return position + ", " + type + ", Satisfaction = " + satisfactionColor + std::to_string(satisfaction) + "%" + RESET;
}

std::string StatsMenu::industrialLabelGenerator(Entity *entity)
{
    std::string type = entityTypeToString(entity->getType());
    std::string position = coordinatesToLabel(entity->getXPosition(), entity->getYPosition());
    std::string productionRate = std::to_string(dynamic_cast<Industry *>(entity)->getOutput());
    int level = dynamic_cast<Industry *>(entity)->getLevel();

    // Determine color based on the level
    std::string color;
    switch (level)
    {
    case 1:
        color = IMenu::BOLD_CYAN; // Cyan for level 1
        break;
    case 2:
        color = IMenu::BLUE; // Blue for level 2
        break;
    case 3:
        color = IMenu::BOLD_YELLOW; // Bold Yellow for level 3
        break;
    default:
        color = ""; // No color change for level 0
        break;
    }

    return position + ", " + type + ", Production Rate = " + productionRate + ", Level = " + color + std::to_string(level) + IMenu::RESET;
}

std::string StatsMenu::utilityLabelGenerator(Entity *entity)
{
    std::string type = entityTypeToString(entity->getType());
    std::string position = IMenu::coordinatesToLabel(entity->getXPosition(), entity->getYPosition());
    int level = dynamic_cast<Utility *>(entity)->getLevel();

    // Determine color based on the level
    std::string color;
    switch (level)
    {
    case 1:
        color = IMenu::BOLD_CYAN; // Cyan for level 1
        break;
    case 2:
        color = IMenu::BLUE; // Blue for level 2
        break;
    case 3:
        color = IMenu::BOLD_YELLOW; // Bold Yellow for level 3
        break;
    default:
        color = ""; // No color change for level 0
        break;
    }

    return position + ", " + type + ", Level = " + color + std::to_string(level) + IMenu::RESET;
}

void StatsMenu::listEntities(Iterator *it, std::string (*labelGenerator)(Entity *), std::string heading)
{
    setHeading(heading);
    clearScreen();

    sections.clear(); // Clear previous sections
    isInfoMenu = true;

    std::vector<Option> entityOptions;
    for (it->first(); it->hasNext(); it->next())
    {
        Entity *entity = it->current();
        if (entity)
        {
            std::string description = labelGenerator(entity);
            entityOptions.push_back({'-', entity->getSymbol() + " ", description});
        }
    }
    sections.push_back({"Entity List", entityOptions});
    displayMenu();
    displayPressEnterToContinue();

    isInfoMenu = false; // Reset after displaying
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
         {{'-', "🌅", "Day: " + std::string(BOLD_YELLOW) + std::to_string(CivZero::instance().getGameLoop()) + RESET},
          {'-', "👥", "Population: " + std::to_string(city->getPopulation()) + "/" + std::to_string(city->getPopulationCapacity())},
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
