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

    int optionKey = 1; // Start option keys from 1
    for (int i = 0; i < positions.size(); ++i)
    {
        std::string posStr = "Position " + coordinatesToLabel(positions[i][0], positions[i][1]);
        sections[0].options.push_back(Option{optionKey++, "📍", posStr});
    }

    sections.push_back({"Navigation", {{0, "⬅️ ", "Back to Main Menu"}}}); // 0 for 'Back'
    displayMenu();
    displayAvailablePositions(positions);

    bool choosing = true;
    while (choosing)
    {
        displayChoicePrompt();
        std::string choiceStr;
        std::cin >> choiceStr;

        // Check if user entered 'q' to quit
        if (choiceStr == "q")
        {
            MenuManager::instance().setCurrentMenu(Menu::MAIN);
            hasExited = true;
            choosing = false;
        }
        else
        {
            try
            {
                int choice = std::stoi(choiceStr); // Convert input to integer

                if (choice > 0 && choice <= positions.size())
                {
                    xPos = positions[choice - 1][0];
                    yPos = positions[choice - 1][1];
                    choosing = false;
                }
                else if (choice == 0) // Back option
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
            catch (std::invalid_argument &)
            {
                displayInvalidChoice();                                             // If conversion fails, display an invalid choice message
                std::cin.clear();                                                   // Clear the error state
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
            }
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
            if (transportManager.buildRoad(xPos, yPos))
            {
                cityManager.buyEntity(EntityType::ROAD, Size::SMALL);
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
