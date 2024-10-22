#include "DisplayCityMenu.h"
#include "menus/base/MenuManager.h"
#include "city/CivZero.h"
#include <cstdlib> // For rand()
#include <ctime>   // For time()

DisplayCityMenu::DisplayCityMenu() : IMenu("Display City")
{
    sections = {
        {"Display City Menu", {{'q', "🔙", "Back to Main Menu"}}}};
}
DisplayCityMenu::~DisplayCityMenu() {}

void DisplayCityMenu::display() const
{
    displayMenu();
    displayCity();
}

void DisplayCityMenu::displayCity() const
{
    const int width = 26;
    const int height = 13;

    // Use std::string for grid cells to hold multi-byte characters
    std::vector<std::vector<std::string>> cityGrid(height, std::vector<std::string>(width, " "));

    // Seed the random number generator
    srand(static_cast<unsigned>(time(0)));

    // Random walk for streets, but with more grid-like structure
    int x = width / 2;
    int y = height / 2;
    cityGrid[y][x] = "█"; // Start street from the middle of the grid

    int direction = rand() % 4; // Initially pick a random direction
    int walkLength = 5;         // This controls how long the road goes in a straight line

    for (int i = 0; i < 200; ++i) // Adjust total iterations to create more streets
    {
        if (walkLength == 0 || rand() % 10 == 0) // Occasionally change direction
        {
            direction = rand() % 4;       // Pick a new direction
            walkLength = 5 + rand() % 10; // Continue in a new direction for a random length
        }

        // Move in the current direction and mark the street
        if (direction == 0 && x > 0)
            x--; // Move left
        else if (direction == 1 && x < width - 1)
            x++; // Move right
        else if (direction == 2 && y > 0)
            y--; // Move up
        else if (direction == 3 && y < height - 1)
            y++; // Move down

        cityGrid[y][x] = "█";
    }

    // Function to check if a cell is adjacent to a street
    auto isNextToStreet = [&](int x, int y) -> bool
    {
        if (x > 0 && cityGrid[y][x - 1] == "█")
            return true;
        if (x < width - 1 && cityGrid[y][x + 1] == "█")
            return true;
        if (y > 0 && cityGrid[y - 1][x] == "█")
            return true;
        if (y < height - 1 && cityGrid[y + 1][x] == "█")
            return true;
        return false;
    };

    // Place buildings next to streets
    for (int i = 0; i < 50; ++i)
    {
        int bx = rand() % width;
        int by = rand() % height;

        // Ensure building is placed next to a street
        if (cityGrid[by][bx] == " " && isNextToStreet(bx, by))
        {
            int buildingSize = rand() % 3; // 0: House, 1: Apartment, 2: Factory
            if (buildingSize == 1 && bx < width - 1 && by < height - 1)
            {
                // Apartment (2x2)
                if (cityGrid[by + 1][bx] == " " && cityGrid[by][bx + 1] == " " && cityGrid[by + 1][bx + 1] == " ")
                {
                    cityGrid[by][bx] = cityGrid[by + 1][bx] = cityGrid[by][bx + 1] = cityGrid[by + 1][bx + 1] = "A";
                }
            }
            else if (buildingSize == 2 && bx < width - 2 && by < height - 2)
            {
                // Factory (3x3)
                bool canPlaceFactory = true;
                for (int fy = by; fy < by + 3 && canPlaceFactory; ++fy)
                {
                    for (int fx = bx; fx < bx + 3 && canPlaceFactory; ++fx)
                    {
                        if (cityGrid[fy][fx] != " ")
                            canPlaceFactory = false;
                    }
                }
                if (canPlaceFactory)
                {
                    for (int fy = by; fy < by + 3; ++fy)
                    {
                        for (int fx = bx; fx < bx + 3; ++fx)
                        {
                            cityGrid[fy][fx] = "F";
                        }
                    }
                }
            }
            else
            {
                // House (1x1)
                cityGrid[by][bx] = "H";
            }
        }
    }

    // Display the city grid with borders and labels
    std::cout << "   ";
    for (int i = 0; i < width; ++i)
    {
        std::cout << static_cast<char>('A' + i % 26) << "";
    }
    std::cout << std::endl
              << "  ";

    printTopBorder(width);
    for (int i = 0; i < height; ++i)
    {
        std::cout << static_cast<char>('A' + i % 26) << DARK_GRAY << " ║" << RESET;
        for (int j = 0; j < width; ++j)
        {
            if (cityGrid[i][j] == "█")
            {
                std::cout << DARK_GRAY << "█" << RESET << "";
            }
            else
            {
                std::cout << cityGrid[i][j] << "";
            }
        }
        std::cout << DARK_GRAY << "║" << RESET << std::endl;
    }
    std::cout << "  ";
    printBottomBorder(width);
}

void DisplayCityMenu::handleInput()
{
    char choice;
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch (choice)
    {
    case 'q':
        MenuManager::instance().setCurrentMenu(Menu::MAIN);
        break;
    default:
        std::cout << "Invalid choice. Please select a valid option." << std::endl;
        break;
    }
}