#include "IMenu.h"
#include <algorithm> // For std::max
#include <iostream>  // For std::setw

// ANSI color codes for styling
#define RESET "\033[0m"
#define BOLD_WHITE "\033[1;37m"
#define NORMAL_WHITE "\033[0;37m"
#define DARK_GRAY "\033[1;30m"
#define BOLD_YELLOW "\033[1;33m"

// Minimum width for the menu
constexpr int MIN_MENU_WIDTH = 50;

IMenu::IMenu(std::string heading) : menuHeading(heading) {}

// Custom function to repeat a multi-byte Unicode string
std::string repeat(const std::string &str, int times)
{
    std::string result;
    for (int i = 0; i < times; ++i)
    {
        result += str;
    }
    return result;
}

// Utility function to calculate dynamic width
int calculateMaxWidth(const std::string &menuHeading, const std::vector<Section> &sections)
{
    int maxWidth = static_cast<int>(menuHeading.size());

    for (const auto &section : sections)
    {
        maxWidth = std::max(maxWidth, static_cast<int>(section.heading.size()));
        for (const auto &option : section.options)
        {
            // Account for the key (1 char), icon (2 chars), and spaces (2 chars) + text length
            int optionWidth = static_cast<int>(option.text.size()) + 5; // Adjusted width calculation
            maxWidth = std::max(maxWidth, optionWidth);
        }
    }

    // Ensure that the calculated width is at least MIN_MENU_WIDTH
    maxWidth = std::max(maxWidth + 4, MIN_MENU_WIDTH); // Add padding and enforce minimum width
    return maxWidth;
}

// Function to print the top border of the menu
void printTopBorder(int width)
{
    std::cout << DARK_GRAY << "╔" << repeat("═", width) << "╗" << RESET << std::endl;
}

// Function to print the bottom border of the menu
void printBottomBorder(int width)
{
    std::cout << DARK_GRAY << "╚" << repeat("═", width) << "╝" << RESET << std::endl;
}

// Function to print the menu section divider
void printSectionDivider(int width)
{
    std::cout << DARK_GRAY << "╟" << repeat("─", width) << "╢" << RESET << std::endl;
}

// Function to print a double-line divider for the main heading
void printDoubleLineDivider(int width)
{
    std::cout << DARK_GRAY << "╠" << repeat("═", width) << "╣" << RESET << std::endl;
}

// Function to center text
std::string centerText(const std::string &text, int width)
{
    int padding = (width - static_cast<int>(text.size())) / 2;
    return std::string(padding, ' ') + text + std::string(width - text.size() - padding, ' ');
}

// Generalized function to center text with a custom character on both sides
std::string centerTextWithChar(const std::string &text, int width, const std::string &padChar = " ")
{
    int padding = (width - static_cast<int>(text.size())) / 2;
    std::string leftPadding = repeat(padChar, padding - 1) + " ";
    std::string rightPadding = " " + repeat(padChar, width - text.size() - padding - 1);
    return leftPadding + text + rightPadding;
}

void IMenu::displayMenu() const
{
    // Calculate the maximum width based on the longest piece of text
    int maxWidth = calculateMaxWidth(menuHeading, sections);

    // Print the menu heading if it exists
    if (!menuHeading.empty())
    {
        printTopBorder(maxWidth);
        // Use centerTextWithChar to pad the heading with "█" characters
        std::cout << DARK_GRAY << "║ " << BOLD_WHITE << centerTextWithChar(menuHeading, maxWidth - 2, "█") << DARK_GRAY << " ║" << RESET << std::endl;
        printDoubleLineDivider(maxWidth); // Double line divider after the heading
    }

    // Determine whether to display section headings
    bool showSections = sections.size() > 1;

    // Loop through the sections and display them
    for (size_t sectionIndex = 0; sectionIndex < sections.size(); ++sectionIndex)
    {
        const auto &section = sections[sectionIndex];

        // Display the section heading only if there is more than one section
        if (showSections)
        {
            std::cout << DARK_GRAY << "║ " << NORMAL_WHITE << centerTextWithChar(section.heading, maxWidth - 2, "•") << DARK_GRAY << " ║" << RESET << std::endl;
            printSectionDivider(maxWidth);
        }

        // Display each option in the section with its custom key
        for (const auto &option : section.options)
        {
            int iconWidth = 2;                   // Assume each icon takes 2 characters
            int keyAndIconWidth = 6 + iconWidth; // Key (1 char), space (1 char), icon, and space (1 char)
            int padding = maxWidth - static_cast<int>(option.text.size()) - keyAndIconWidth;

            // Print the option with dynamically calculated padding
            std::cout << DARK_GRAY << "║ " << BOLD_YELLOW << option.key << RESET << ". " << option.icon << " "
                      << option.text << std::string(std::max(0, padding), ' ') << DARK_GRAY << " ║" << RESET << std::endl;
        }

        // Print the bottom border only after the last section
        if (sectionIndex == sections.size() - 1)
        {
            printBottomBorder(maxWidth);
        }
        else
        {
            printSectionDivider(maxWidth); // No extra spacing, just a section divider
        }
    }
}
