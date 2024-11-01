#include "UpgradesMenu.h"
#include "menus/base/MenuManager.h"
#include <iostream>

UpgradesMenu::UpgradesMenu() : IMenu() {}

UpgradesMenu::~UpgradesMenu() {}

void UpgradesMenu::display() const {}

void UpgradesMenu::handleInput()
{
    sections = {
        {"Upgrade Categories",
         {{'1', "🔧", "Upgrade Utilities"},
          {'2', "🏭", "Upgrade Industries"}}},
        {"Navigation",
         {{'q', "⬅️ ", "Back to Main Menu"}}}};
    setHeading("Upgrades Menu");
    clearScreen();
    displayMenu();

    bool choosing = true;

    while (choosing)
    {
        char choice;
        displayChoicePrompt();
        std::cin >> choice;

        switch (choice)
        {
        case '1':
            upgradeUtilities();
            choosing = false;
            break;
        case '2':
            upgradeIndustries();
            choosing = false;
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

void UpgradesMenu::upgradeUtilities()
{
    clearScreen();
    setHeading("Select Utility to Upgrade");
    sections = {
        {"Utilities",
         {{'1', "💧", "Water Supply"},
          {'2', "⚡", "Power Plant"},
          {'3', "🚮", "Waste Management"},
          {'4', "🚰", "Sewage System"}}},
        {"Navigation",
         {{'b', "⬅️ ", "Back to Upgrades Menu"}, {'q', "⬅️ ", "Back to Main Menu"}}}};

    displayMenu();

    bool choosing = true;

    while (choosing)
    {
        char choice;
        displayChoicePrompt();
        std::cin >> choice;

        switch (choice)
        {
        case '1':
            selectSpecificUtility("Water Supply", utilityManager.getAllWaterSupplies());
            choosing = false;
            break;
        case '2':
            selectSpecificUtility("Power Plant", utilityManager.getAllPowerPlants());
            choosing = false;
            break;
        case '3':
            selectSpecificUtility("Waste Management", utilityManager.getAllWasteManagements());
            choosing = false;
            break;
        case '4':
            selectSpecificUtility("Sewage System", utilityManager.getAllSewageSystems());
            choosing = false;
            break;
        case 'b':
            MenuManager::instance().setCurrentMenu(Menu::UPGRADES);
            choosing = false;
            return;
        case 'q':
            MenuManager::instance().setCurrentMenu(Menu::MAIN);
            choosing = false;
            return;
        default:
            displayInvalidChoice();
            break;
        }
    }
}

void UpgradesMenu::upgradeIndustries()
{
    clearScreen();
    setHeading("Select Industry to Upgrade");
    sections = {
        {"Industries",
         {{'1', "🪨 ", "Stone Producer"},
          {'2', "🏗️ ", "Concrete Producer"},
          {'3', "🌲", "Wood Producer"}}},
        {"Navigation",
         {{'b', "⬅️ ", "Back to Upgrades Menu"}, {'q', "⬅️ ", "Back to Main Menu"}}}};

    displayMenu();

    bool choosing = true;

    while (choosing)
    {
        char choice;
        displayChoicePrompt();
        std::cin >> choice;

        std::vector<std::string> industryList; // Placeholder for a list of industry instances.
        switch (choice)
        {
        case '1':
            selectSpecificIndustry("Stone Producer", resourceManager.getAllStoneProducers());
            choosing = false;
            break;
        case '2':
            selectSpecificIndustry("Concrete Producer", resourceManager.getAllConcreteProducers());
            choosing = false;
            break;
        case '3':
            selectSpecificIndustry("Wood Producer", resourceManager.getAllWoodProducers());

            choosing = false;
            break;
        case 'b':
            MenuManager::instance().setCurrentMenu(Menu::UPGRADES);
            choosing = false;
            return;
        case 'q':
            MenuManager::instance().setCurrentMenu(Menu::MAIN);
            choosing = false;
            return;
        default:
            displayInvalidChoice();
            break;
        }
    }
}

void UpgradesMenu::selectSpecificUtility(const std::string &type, const std::vector<Utility *> &options)
{
    clearScreen();
    setHeading("Select " + type + " to Upgrade");

    sections.clear(); // Reset sections to display specific instances
    sections.push_back({"Available " + type + "s", {}});

    char optionKey = '1';
    for (auto *utility : options)
    {
        std::string label = type + " (" + std::to_string(utility->getXPosition()) + "," + std::to_string(utility->getYPosition()) + ") (Output = " + std::to_string(utility->getOutput()) + ") (Level " + std::to_string(utility->getLevel()) + ")";
        sections[0].options.push_back(Option{optionKey++, "🔧", label});
    }

    sections.push_back({"Navigation", {{'b', "⬅️ ", "Back to " + type + " Menu"}, {'q', "⬅️ ", "Back to Main Menu"}}});
    displayMenu();

    bool choosing = true;

    while (choosing)
    {
        char choice;
        displayChoicePrompt();
        std::cin >> choice;

        int index = choice - '1';
        if (index >= 0 && index < options.size())
        {
            Utility *selectedUtility = options[index];
            utilityManager.canAffordUpgrade(selectedUtility);
            if (utilityManager.canAffordUpgrade(selectedUtility))
            {
                utilityManager.upgrade(selectedUtility);
            }
            else
            {
                displayErrorMessage("You cannot afford the upgrade");
            }
            choosing = false;
            displayPressEnterToContinue();
        }
        else if (choice == 'b')
        {
            upgradeUtilities(); // Go back to utilities menu
            choosing = false;
        }
        else if (choice == 'q')
        {
            MenuManager::instance().setCurrentMenu(Menu::MAIN);
            choosing = false;
        }
        else
        {
            displayInvalidChoice();
        }
    }
}

void UpgradesMenu::selectSpecificIndustry(const std::string &type, const std::vector<Industry *> &options)
{
    clearScreen();
    setHeading("Select " + type + " to Upgrade");

    sections.clear(); // Reset sections to display specific instances
    sections.push_back({"Available " + type + "s", {}});

    char optionKey = '1';
    for (auto *industry : options)
    {
        std::string label = type + " (" + std::to_string(industry->getXPosition()) + "," + std::to_string(industry->getYPosition()) + ") (Output = " + std::to_string(industry->getOutput()) + ") (Level " + std::to_string(industry->getLevel()) + ")";
        sections[0].options.push_back(Option{optionKey++, "🔧", label});
    }

    sections.push_back({"Navigation", {{'b', "⬅️ ", "Back to " + type + " Menu"}, {'q', "⬅️ ", "Back to Main Menu"}}});
    displayMenu();

    bool choosing = true;

    while (choosing)
    {
        char choice;
        displayChoicePrompt();
        std::cin >> choice;

        int index = choice - '1';
        if (index >= 0 && index < options.size())
        {
            Industry *selectedIndustry = options[index];
            resourceManager.canAffordUpgrade(selectedIndustry);
            if (resourceManager.canAffordUpgrade(selectedIndustry))
            {
                resourceManager.upgrade(selectedIndustry);
            }
            else
            {
                displayErrorMessage("You cannot afford the upgrade");
            }
            choosing = false;
            displayPressEnterToContinue();
        }
        else if (choice == 'b')
        {
            upgradeUtilities(); // Go back to industries menu
            choosing = false;
        }
        else if (choice == 'q')
        {
            MenuManager::instance().setCurrentMenu(Menu::MAIN);
            choosing = false;
        }
        else
        {
            displayInvalidChoice();
        }
    }
}

void UpgradesMenu::confirmUpgrade(const std::string &entityName, int currentLevel, int upgradeCost)
{
    clearScreen(); // Clear the screen to give a clean view for the summary

    // Prepare content for the upgrade confirmation
    std::string entityStr = "Upgrading: " + entityName;
    std::string currentLevelStr = "Current Level: " + std::to_string(currentLevel);
    std::string newLevelStr = "New Level: " + std::to_string(currentLevel + 1);
    std::string upgradeCostStr = "Upgrade Cost: " + std::to_string(upgradeCost) + " resources";

    // Calculate the total width based on the longest string
    int maxWidth = std::max({static_cast<int>(entityStr.size()),
                             static_cast<int>(currentLevelStr.size()),
                             static_cast<int>(newLevelStr.size()),
                             static_cast<int>(upgradeCostStr.size())});

    int totalWidth = maxWidth + 4; // Adding padding space for the box

    // Print the top border
    std::cout << DARK_GRAY << "╔" << repeat("═", totalWidth) << "╗" << RESET << std::endl;

    // Print the heading centered within the box
    std::string heading = "Upgrade Confirmation";
    int headingPadding = (totalWidth - heading.size() - 2) / 2; // Calculate padding for the heading
    std::cout << DARK_GRAY << "║ " << BOLD_WHITE << std::string(headingPadding, ' ') << heading
              << std::string(totalWidth - heading.size() - headingPadding - 2, ' ') << DARK_GRAY << " ║" << RESET << std::endl;

    // Print a dividing line below the heading
    std::cout << DARK_GRAY << "╠" << repeat("═", totalWidth) << "╣" << RESET << std::endl;

    // Print entity details with labels in bold yellow and values in normal text
    std::cout << DARK_GRAY << "║ " << BOLD_YELLOW << entityStr
              << std::string(totalWidth - entityStr.size() - 2, ' ') << DARK_GRAY << " ║" << RESET << std::endl;

    std::cout << DARK_GRAY << "║ " << BOLD_YELLOW << currentLevelStr
              << std::string(totalWidth - currentLevelStr.size() - 2, ' ') << DARK_GRAY << " ║" << RESET << std::endl;

    std::cout << DARK_GRAY << "║ " << BOLD_YELLOW << newLevelStr
              << std::string(totalWidth - newLevelStr.size() - 2, ' ') << DARK_GRAY << " ║" << RESET << std::endl;

    // Print a dividing line before the cost section
    std::cout << DARK_GRAY << "╠" << repeat("═", totalWidth) << "╣" << RESET << std::endl;

    // Print upgrade cost
    std::cout << DARK_GRAY << "║ " << BOLD_WHITE << upgradeCostStr
              << std::string(totalWidth - upgradeCostStr.size() - 2, ' ') << DARK_GRAY << " ║" << RESET << std::endl;

    // Print the bottom border
    std::cout << DARK_GRAY << "╚" << repeat("═", totalWidth) << "╝" << RESET << std::endl;

    // Ask for confirmation
    displayChoiceMessagePrompt("Confirm upgrade (y/n):");
    char confirmation;
    std::cin >> confirmation;

    if (confirmation == 'y')
    {
        displaySuccessMessage("Upgrade to " + newLevelStr + " successful!");
    }
    else
    {
        displayErrorMessage("Upgrade canceled.");
    }

    // Press Enter to return prompt
    displayPressEnterToContinue();
    MenuManager::instance().setCurrentMenu(Menu::UPGRADES);
}
