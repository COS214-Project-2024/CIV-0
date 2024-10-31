#include "BuyMenu.h"
#include "menus/base/MenuManager.h"
#include "utils/ConfigManager.h"
#include "entities/road/Road.h"

/**
 * @brief Constructs a new BuyMenu with default available resources.
 */
BuyMenu::BuyMenu() : IMenu(), availableMoney(10000), availableWood(50000), availableStone(10000), availableConcrete(10000) {}

/**
 * @brief Destructor for BuyMenu.
 */
BuyMenu::~BuyMenu() {}

/**
 * @brief Displays the base menu (empty in this base class).
 * Derived classes should implement their own display logic.
 */
void BuyMenu::display() const {}

/**
 * @brief Handles the input workflow for purchasing a building.
 * It allows the user to select the building type, size, and position, and then confirms the purchase.
 */
void BuyMenu::handleInput()
{
    hasExited = false;

    EntityType type = chooseEntityType();
    if (hasExited)
        return;

    Size size = chooseBuildingSize(type);
    if (hasExited)
        return;

    int xPos = 0;
    int yPos = 0;
    chooseBuildingPosition(xPos, yPos, type, size);
    if (hasExited)
        return;

    confirmPurchase(type, size, xPos, yPos);
}

/**
 * @brief Allows the user to choose the size of the building based on available resources.
 * Displays an error message if the user cannot afford the selected size.
 * @param type The EntityType of the building.
 * @return Size The selected size of the building.
 */
Size BuyMenu::chooseBuildingSize(EntityType type)
{
    sections.clear();
    sections.push_back({"Options", {}});

    char optionKey = '1';
    for (Size size : {Size::SMALL, Size::MEDIUM, Size::LARGE})
    {
        EntityConfig config = ConfigManager::getEntityConfig(type, size);

        // Use cityManager.canAffordToBuy to check affordability
        bool canAfford = cityManager.canAffordToBuy(type, size);

        std::string moneyColor = (City::instance()->getMoney() >= config.cost.moneyCost) ? BOLD_WHITE : BOLD_RED;
        std::string woodColor = (City::instance()->getWood() >= config.cost.woodCost) ? BOLD_WHITE : BOLD_RED;
        std::string stoneColor = (City::instance()->getStone() >= config.cost.stoneCost) ? BOLD_WHITE : BOLD_RED;
        std::string concreteColor = (City::instance()->getConcrete() >= config.cost.concreteCost) ? BOLD_WHITE : BOLD_RED;

        std::string costStr = " (Cost: " + moneyColor + std::to_string(config.cost.moneyCost) + RESET + " money, " +
                              woodColor + std::to_string(config.cost.woodCost) + RESET + " wood, " +
                              stoneColor + std::to_string(config.cost.stoneCost) + RESET + " stone, " +
                              concreteColor + std::to_string(config.cost.concreteCost) + RESET + " concrete)";

        std::string displayText = sizeToString(size) + costStr;

        sections[0].options.push_back(Option{optionKey++, "📏", displayText});
    }

    sections.push_back({"Navigation", {{'b', "⬅️ ", "Back to Buildings Menu"}, {'q', "⬅️ ", "Back to Main Menu"}}});
    setHeading("Select Size of the " + entityTypeToString(type));
    clearScreen();
    displayMenu();

    Size size;
    bool choosing = true;
    while (choosing)
    {
        char choice;
        displayChoicePrompt();
        std::cin >> choice;

        switch (choice)
        {
        case '1':
            if (!cityManager.canAffordToBuy(type, Size::SMALL))
            {
                displayErrorMessage("You cannot afford the SMALL size!");
                break;
            }
            size = Size::SMALL;
            choosing = false;
            break;
        case '2':
            if (!cityManager.canAffordToBuy(type, Size::MEDIUM))
            {
                displayErrorMessage("You cannot afford the MEDIUM size!");
                break;
            }
            size = Size::MEDIUM;
            choosing = false;
            break;
        case '3':
            if (!cityManager.canAffordToBuy(type, Size::LARGE))
            {
                displayErrorMessage("You cannot afford the LARGE size!");
                break;
            }
            size = Size::LARGE;
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

    return size;
}

/**
 * @brief Allows the user to choose the position of the building on the grid.
 * Displays available positions and lets the user select one.
 * @param xPos Reference to the x-coordinate for the building's position.
 * @param yPos Reference to the y-coordinate for the building's position.
 */
void BuyMenu::chooseBuildingPosition(int &xPos, int &yPos, EntityType type, Size size)
{
    std::vector<std::vector<int>> positions = cityManager.getAvailiablePositions(type, size);

    sections.clear();
    sections.push_back({"Options", {}});

    char optionKey = '1';
    for (int i = 0; i < positions.size(); ++i)
    {
        std::string posStr = "Position " + coordinatesToLabel(positions[i][0], positions[i][1]);
        sections[0].options.push_back(Option{optionKey++, "📍", posStr});
    }

    sections.push_back({"Navigation", {{'b', "⬅️ ", "Back to Buildings Menu"}, {'q', "⬅️ ", "Back to Main Menu"}}});
    setHeading("Select Position for the Building");
    clearScreen();
    displayMenu();

    // Display available positions on the grid after the menu
    displayAvailablePositions(positions);

    bool choosing = true;
    while (choosing)
    {
        char choice;
        displayChoicePrompt();
        std::cin >> choice;

        int index = choice - '1';

        if (index >= 0 && index < positions.size())
        {
            xPos = positions[index][0];
            yPos = positions[index][1];
            choosing = false;
        }
        else if (choice == 'b')
        {
            MenuManager::instance().setCurrentMenu(Menu::BUILDINGS);
        }
        else if (choice == 'q')
        {
            MenuManager::instance().setCurrentMenu(Menu::MAIN);
            choosing = false;
            hasExited = true;
        }
        else
        {
            displayInvalidChoice();
        }
    }
}

/**
 * @brief Confirms the building purchase and displays a summary including type, size, and cost.
 * Asks for final confirmation before proceeding with the purchase.
 * @param type The type of the building.
 * @param size The size of the building.
 * @param xPos The x-coordinate for the building's position.
 * @param yPos The y-coordinate for the building's position.
 */
void BuyMenu::confirmPurchase(EntityType type, Size size, int xPos, int yPos)
{
    clearScreen(); // Clear the screen to give a clean view for the summary

    // Get the entity configuration from the ConfigManager
    EntityConfig config = ConfigManager::getEntityConfig(type, size);

    // Prepare the content to be displayed in the summary
    std::string buildingTypeStr = "Building Type: ";
    std::string buildingTypeValue = entityTypeToString(type);

    std::string sizeStr = "Size: ";
    std::string sizeValue = sizeToString(size);

    std::string positionStr = "Position: ";
    std::string positionValue = "(" + std::to_string(xPos) + "," + std::to_string(yPos) + ")";

    // Prepare cost information separately
    std::string moneyCostStr = "Money: " + std::to_string(config.cost.moneyCost);
    std::string woodCostStr = "Wood: " + std::to_string(config.cost.woodCost);
    std::string stoneCostStr = "Stone: " + std::to_string(config.cost.stoneCost);
    std::string concreteCostStr = "Concrete: " + std::to_string(config.cost.concreteCost);

    // Calculate the total width based on the longest string
    int maxWidth = std::max({static_cast<int>(buildingTypeStr.size() + buildingTypeValue.size()),
                             static_cast<int>(sizeStr.size() + sizeValue.size()),
                             static_cast<int>(positionStr.size() + positionValue.size()),
                             static_cast<int>(moneyCostStr.size()),
                             static_cast<int>(woodCostStr.size()),
                             static_cast<int>(stoneCostStr.size()),
                             static_cast<int>(concreteCostStr.size())});

    int totalWidth = maxWidth + 4; // Adding padding space for the box

    // Print the top border
    std::cout << DARK_GRAY << "╔" << repeat("═", totalWidth) << "╗" << RESET << std::endl;

    // Print the heading centered within the box
    std::string heading = "Purchase Summary";
    int headingPadding = (totalWidth - heading.size() - 2) / 2; // Calculate padding for the heading
    std::cout << DARK_GRAY << "║ " << BOLD_WHITE << std::string(headingPadding, ' ') << heading
              << std::string(totalWidth - heading.size() - headingPadding - 2, ' ') << DARK_GRAY << " ║" << RESET << std::endl;

    // Print a dividing line below the heading
    std::cout << DARK_GRAY << "╠" << repeat("═", totalWidth) << "╣" << RESET << std::endl;

    // Print the building type, size, and position with labels in bold yellow and values in normal text
    std::cout << DARK_GRAY << "║ " << BOLD_YELLOW << buildingTypeStr << RESET << buildingTypeValue
              << std::string(totalWidth - buildingTypeStr.size() - buildingTypeValue.size() - 2, ' ') << DARK_GRAY << " ║" << RESET << std::endl;

    std::cout << DARK_GRAY << "║ " << BOLD_YELLOW << sizeStr << RESET << sizeValue
              << std::string(totalWidth - sizeStr.size() - sizeValue.size() - 2, ' ') << DARK_GRAY << " ║" << RESET << std::endl;

    std::cout << DARK_GRAY << "║ " << BOLD_YELLOW << positionStr << RESET << positionValue
              << std::string(totalWidth - positionStr.size() - positionValue.size() - 2, ' ') << DARK_GRAY << " ║" << RESET << std::endl;

    // Print a dividing line before the cost section
    std::cout << DARK_GRAY << "╠" << repeat("═", totalWidth) << "╣" << RESET << std::endl;

    // Print cost breakdown on separate lines
    std::cout << DARK_GRAY << "║ " << BOLD_YELLOW << "Cost Breakdown:" << DARK_GRAY
              << std::string(totalWidth - std::string("Cost Breakdown:").size() - 2, ' ') << " ║" << RESET << std::endl;

    std::cout << DARK_GRAY << "║ " << BOLD_WHITE << moneyCostStr
              << std::string(totalWidth - moneyCostStr.size() - 2, ' ') << DARK_GRAY << " ║" << RESET << std::endl;

    std::cout << DARK_GRAY << "║ " << BOLD_WHITE << woodCostStr
              << std::string(totalWidth - woodCostStr.size() - 2, ' ') << DARK_GRAY << " ║" << RESET << std::endl;

    std::cout << DARK_GRAY << "║ " << BOLD_WHITE << stoneCostStr
              << std::string(totalWidth - stoneCostStr.size() - 2, ' ') << DARK_GRAY << " ║" << RESET << std::endl;

    std::cout << DARK_GRAY << "║ " << BOLD_WHITE << concreteCostStr
              << std::string(totalWidth - concreteCostStr.size() - 2, ' ') << DARK_GRAY << " ║" << RESET << std::endl;

    // Print the bottom border
    std::cout << DARK_GRAY << "╚" << repeat("═", totalWidth) << "╝" << RESET << std::endl;

    // Ask for confirmation
    displayChoiceMessagePrompt("Confirm purchase (y/n):");
    char confirmation;
    std::cin >> confirmation;

    if (confirmation == 'y')
    {
        buildEntity(type, size, xPos, yPos);
        cityManager.buyEntity(type, size);
        displaySuccessMessage("Purchase successfull!");
        displayPressEnterToContinue();
        MenuManager::instance().setCurrentMenu(Menu::MAIN);
    }
    else
    {
        displayErrorMessage("Purchase cancelled.");
        displayPressEnterToContinue();
    }
}
