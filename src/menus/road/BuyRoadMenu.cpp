#include "BuyRoadMenu.h"
#include "menus/base/MenuManager.h"

BuyRoadMenu::BuyRoadMenu() : IMenu("Buy Road")
{
    setHeading("Select Position to Buy Road");
}

BuyRoadMenu::~BuyRoadMenu() {}

void BuyRoadMenu::display() const
{
    clearScreen();
    displayMenu();
}

void BuyRoadMenu::handleInput()
{
    hasExited = false;

    int xPos = 0;
    int yPos = 0;
    chooseRoadPosition(xPos, yPos);
    if (hasExited)
        return;

    confirmPurchase(xPos, yPos);
}

void BuyRoadMenu::chooseRoadPosition(int &xPos, int &yPos)
{
    // Assuming cityManager provides available positions for roads
    auto positions = cityManager.getAvailiablePositions(EntityType::ROAD, Size::SMALL);

    sections.clear();
    sections.push_back({"Options", {}});

    char optionKey = '1';
    for (int i = 0; i < positions.size(); ++i)
    {
        std::string posStr = "Position " + coordinatesToLabel(positions[i][0], positions[i][1]);
        sections[0].options.push_back(Option{optionKey++, "📍", posStr});
    }

    sections.push_back({"Navigation", {{'b', "⬅️ ", "Back to Main Menu"}}});
    displayMenu();
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
            MenuManager::instance().setCurrentMenu(Menu::MAIN);
            hasExited = true;
            choosing = false;
        }
        else
        {
            displayInvalidChoice();
        }
    }
}

void BuyRoadMenu::confirmPurchase(int xPos, int yPos)
{
    clearScreen();
    std::string positionLabel = coordinatesToLabel(xPos, yPos);
    setHeading("Confirm Road Purchase");

    std::cout << "Position: " << positionLabel << "\n";

    displayChoiceMessagePrompt("Confirm purchase of road at this position? (y/n): ");
    char confirmation;
    std::cin >> confirmation;

    if (confirmation == 'y')
    {
        if (transportManager.canAffordRoad())
        {
            cityManager.buyEntity(EntityType::ROAD, Size::SMALL);
            if (transportManager.buildRoad(xPos, yPos))
            {
                displaySuccessMessage("Road successfully built!");
            }
            else
            {
                displayErrorMessage("Failed to build road at the selected position.");
            }
        }
        else
        {
            displayErrorMessage("Not enough resources to build a road.");
        }
    }
    else
    {
        displayErrorMessage("Purchase cancelled.");
    }

    displayPressEnterToContinue();
    MenuManager::instance().setCurrentMenu(Menu::MAIN);
}
