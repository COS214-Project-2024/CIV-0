#include "IMenu.h"
#include <iostream>
#include <vector>

// ANSI Escape codes for colors and formatting
#define RESET "\033[0m"
#define BOLDWHITE "\033[1;37m" // Bold White
#define GRAY "\033[1;30m"      // Gray

// Helper function to repeat a string (e.g., "═") multiple times
std::string repeat(const std::string &str, int count)
{
    std::string result;
    for (int i = 0; i < count; ++i)
    {
        result += str;
    }
    return result;
}

IMenu::IMenu(const std::string &heading) : heading(heading), menuWidth(60) {}
IMenu::~IMenu() {}

void IMenu::displayMenu() const
{
    // Fancy double border
    const std::string topBorder = "╔" + repeat("═", menuWidth - 2) + "╗";
    const std::string bottomBorder = "╚" + repeat("═", menuWidth - 2) + "╝";

    // Display the top border
    std::cout << BOLDWHITE << topBorder << RESET << std::endl;

    // Display the heading centered within the border
    int headingPadding = (menuWidth - 2 - heading.size()) / 2;
    std::cout << BOLDWHITE << "║" << std::string(headingPadding, ' ') << heading
              << std::string(menuWidth - 2 - heading.size() - headingPadding, ' ') << "║" << RESET << std::endl;

    // Separator between heading and options
    const std::string separator = "╟" + repeat("─", menuWidth - 2) + "╢";
    std::cout << BOLDWHITE << separator << RESET << std::endl;

    // Display the options with their keys
    for (const MenuOption &option : options)
    {
        int optionPadding = menuWidth - 7 - option.text.size(); // Adjust for key, dot, and space
        std::cout << BOLDWHITE << "║ " << RESET << option.key << ". " << option.text
                  << std::string(optionPadding, ' ') << BOLDWHITE << " ║" << RESET << std::endl;
    }

    // Display the bottom border
    std::cout << BOLDWHITE << bottomBorder << RESET << std::endl;

    // Prompt for input
    std::cout << GRAY << "Please enter your choice: " << RESET;
}

void IMenu::setMenuWidth(int width)
{
    this->menuWidth = width;
}

void IMenu::setCity(City *city)
{
    this->city = city;
}