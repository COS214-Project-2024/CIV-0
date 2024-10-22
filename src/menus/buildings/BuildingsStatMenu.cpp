#include "BuildingsStatMenu.h"
#include "utils/ConfigManager.h"
#include "menus/base/MenuManager.h"
#include <iostream>
#include <iomanip>

/**
 * @brief Constructor for BuildingsStatMenu.
 * Initializes with a list of entity types to display statistics for.
 * @param types List of entity types to be shown in the stats menu.
 */
BuildingsStatMenu::BuildingsStatMenu(std::vector<EntityType> types)
    : IMenu("Building Stats Menu"), entityTypes(types)
{
    // Initialize the sections dynamically based on the entity types
    sections.push_back({"Buildings", {}}); // Add a section for buildings
    char optionKey = '1';

    // Populate the menu with each entity type
    for (EntityType type : entityTypes)
    {
        sections[0].options.push_back(Option{optionKey++, "🔍", "Show " + entityTypeToString(type) + " stats"});
    }

    // Add a navigation section
    sections.push_back({"Navigation", {{'b', "🔙", "Back to Buildings Menu"}, {'q', "🔙", "Back to Main Menu"}}});
}

/**
 * @brief Destructor for BuildingsStatMenu.
 */
BuildingsStatMenu::~BuildingsStatMenu() {}

/**
 * @brief Displays the menu allowing the user to select a building type to view stats.
 */
void BuildingsStatMenu::display() const
{
    clearScreen();
    displayMenu(); // Use inherited displayMenu to show the entity options
}

/**
 * @brief Handles user input for selecting a building type or navigating back.
 */
void BuildingsStatMenu::handleInput()
{
    while (true)
    {
        char choice;
        displayChoicePrompt();
        std::cin >> choice;

        if (choice == 'b')
        {
            MenuManager::instance().setCurrentMenu(Menu::BUILDINGS); // Navigate back to Buildings Menu
            return;
        }
        else if (choice == 'q')
        {
            MenuManager::instance().setCurrentMenu(Menu::MAIN); // Navigate back to Main Menu
            return;
        }

        // Convert the user's choice into an index for the entityTypes array
        int index = choice - '1';
        if (index >= 0 && index < entityTypes.size())
        {
            // Call displayEntityStats for the selected entity
            displayEntityStats(entityTypes[index]);
        }
        else
        {
            displayInvalidChoice();
        }
    }
}

/**
 * @brief Displays detailed statistics for a selected entity type.
 * The stats include cost breakdown, utility requirements, and additional stats for different sizes (Small, Medium, Large).
 * @param type The entity type whose stats are displayed.
 */
void BuildingsStatMenu::displayEntityStats(EntityType type) const
{
    clearScreen(); // Clear the screen for a clean display

    int boxWidth = 60; // Set a fixed box width for uniformity

    // Create a title box with double lines for the entity type
    std::string title = " Stats for " + entityTypeToString(type) + " ";
    printTopBorder(boxWidth);
    std::cout << DARK_GRAY << "║ " << BOLD_YELLOW << centerTextWithChar(title, boxWidth - 2, " ") << DARK_GRAY << " ║" << RESET << std::endl;
    printDoubleLineDivider(boxWidth);

    // Loop through each available size (Small, Medium, Large) and display stats in aligned boxes
    for (Size size : {Size::SMALL, Size::MEDIUM, Size::LARGE})
    {
        EntityConfig config = ConfigManager::getEntityConfig(type, size);

        // Create a box for each size with its title
        std::string sizeTitle = " " + sizeToString(size) + " ";
        std::cout << DARK_GRAY << "║ " << BOLD_WHITE << centerTextWithChar(sizeTitle, boxWidth - 2, " ") << DARK_GRAY << " ║" << RESET << std::endl;

        // Display Cost Breakdown with bold yellow title
        printSectionDivider(boxWidth);
        std::cout << DARK_GRAY << "║ " << BOLD_YELLOW << "Cost Breakdown:" << RESET
                  << std::string(boxWidth - 17, ' ') << DARK_GRAY << " ║" << RESET << std::endl;

        displayStatRow("Money:", std::to_string(config.cost.moneyCost), boxWidth);
        displayStatRow("Wood:", std::to_string(config.cost.woodCost), boxWidth);
        displayStatRow("Stone:", std::to_string(config.cost.stoneCost), boxWidth);
        displayStatRow("Concrete:", std::to_string(config.cost.concreteCost), boxWidth);

        // Display Utility Requirements with bold yellow title
        printSectionDivider(boxWidth);
        std::cout << DARK_GRAY << "║ " << BOLD_YELLOW << "Utility Requirements:" << RESET
                  << std::string(boxWidth - 23, ' ') << DARK_GRAY << " ║" << RESET << std::endl;

        displayStatRow("Electricity:", std::to_string(config.electricityConsumption), boxWidth);
        displayStatRow("Water:", std::to_string(config.waterConsumption), boxWidth);

        // Display Additional Stats with bold yellow title
        printSectionDivider(boxWidth);
        std::cout << DARK_GRAY << "║ " << BOLD_YELLOW << "Additional Stats:" << RESET
                  << std::string(boxWidth - 19, ' ') << DARK_GRAY << " ║" << RESET << std::endl;

        displayStatRow("Revenue:", std::to_string(config.revenue), boxWidth);
        displayStatRow("Build Time:", std::to_string(config.buildTime) + " days", boxWidth);
        displayStatRow("Local Effect:", std::to_string(config.localEffectStrength), boxWidth);
        displayStatRow("Global Effect:", std::to_string(config.globalEffectStrength), boxWidth);

        // Closing the box for the current size
        if (size != Size::LARGE)
            printDoubleLineDivider(boxWidth);
        else
            printBottomBorder(boxWidth);
    }

    // After displaying stats, prompt to return to the entity selection
    std::cout << BOLD_WHITE << "\nPress any key to return to the building selection..." << RESET << std::endl;
    std::cin.ignore();
    std::cin.get();

    clearScreen();
    display(); // Return to the entity selection menu
}

/**
 * @brief Displays a row for the stats with dynamic padding.
 * Aligns the label and value in a visually pleasing manner within a fixed-width box.
 * @param label The stat label (e.g., "Cost").
 * @param value The stat value (e.g., "1000").
 * @param boxWidth The fixed width for the stats box.
 */
void BuildingsStatMenu::displayStatRow(const std::string &label, const std::string &value, int boxWidth) const
{
    // Calculate the padding dynamically based on the length of the label and value
    std::string rowContent = label + " " + value;
    int padding = boxWidth - static_cast<int>(stripColorCodes(rowContent).size()) - 2;

    // Ensure proper alignment by adjusting padding based on the label and value size
    std::cout << DARK_GRAY << "║ " << RESET << label << " " << value
              << std::string(std::max(0, padding), ' ') << DARK_GRAY << " ║" << RESET << std::endl;
}
