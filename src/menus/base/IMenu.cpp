#include "IMenu.h"
#include "city/City.h"
#include <algorithm> // For std::max
#include <iostream>
#include <iomanip>
#include <sstream>
#include <regex>

char IMenu::indexToExtendedChar(int index) const
{
    if (index >= 0 && index <= 9)
    {
        return '0' + index;
    }
    else if (index >= 10 && index <= 35)
    {
        return 'A' + (index - 10);
    }
    else if (index >= 36 && index <= 61)
    {
        return 'a' + (index - 36);
    }
    else
    {
        const char specialChars[] = "!@#$%^&*()_+-=`~|\\{}[]:\";'<>?,./";
        int specialIndex = index - 62;
        if (specialIndex >= 0 && specialIndex < sizeof(specialChars) - 1)
        {
            return specialChars[specialIndex];
        }
    }
    throw std::out_of_range("Index out of range for extended character conversion");
}

/**
 * @brief Constructs a menu with the specified heading.
 * @param heading The heading of the menu.
 */
IMenu::IMenu(std::string heading) : menuHeading(heading) {}

void IMenu::setHeading(const std::string &heading)
{
    this->menuHeading = heading;
}

/**
 * @brief Repeats a given string for a specified number of times.
 *
 * @param str The string to be repeated.
 * @param times The number of times to repeat the string.
 * @return The repeated string.
 */
std::string IMenu::repeat(const std::string &str, int times) const
{
    std::string result;
    for (int i = 0; i < times; ++i)
    {
        result += str;
    }
    return result;
}

/**
 * @brief Calculates the maximum width of the menu based on its heading and sections.
 *
 * This function calculates the maximum width of the menu by comparing the heading
 * and the text of the options in the sections to ensure the menu is wide enough
 * to fit all content.
 *
 * @param menuHeading The heading of the menu.
 * @param sections The sections of the menu.
 * @return The maximum width of the menu.
 */
int IMenu::calculateMaxWidth(const std::string &menuHeading, const std::vector<Section> &sections) const
{
    int maxWidth = static_cast<int>(stripColorCodes(menuHeading).size());

    for (const auto &section : sections)
    {
        // Compare section heading width
        maxWidth = std::max(maxWidth, static_cast<int>(stripColorCodes(section.heading).size()));

        for (const auto &option : section.options)
        {
            // Strip color codes to calculate the plain text width
            std::string plainText = stripColorCodes(option.text);
            int optionWidth = static_cast<int>(plainText.size()) + 6; // Account for key, icon, and spacing
            maxWidth = std::max(maxWidth, optionWidth);
        }
    }

    // Set a reasonable minimum width for all menus to ensure it’s large enough for the longest text
    maxWidth = std::max(maxWidth, 70); // Example width, adjust as necessary

    return maxWidth;
}

/**
 * @brief Prints the top border of the menu using box-drawing characters.
 *
 * @param width The width of the menu.
 */
void IMenu::printTopBorder(int width) const
{
    std::cout << DARK_GRAY << "╔" << repeat("═", width) << "╗" << RESET << std::endl;
}

/**
 * @brief Prints the bottom border of the menu using box-drawing characters.
 *
 * @param width The width of the menu.
 */
void IMenu::printBottomBorder(int width) const
{
    std::cout << DARK_GRAY << "╚" << repeat("═", width) << "╝" << RESET << std::endl;
}

/**
 * @brief Prints a section divider in the menu using box-drawing characters.
 *
 * @param width The width of the menu.
 */
void IMenu::printSectionDivider(int width) const
{
    std::cout << DARK_GRAY << "╟" << repeat("─", width) << "╢" << RESET << std::endl;
}

/**
 * @brief Prints a double-line divider for the main heading of the menu.
 *
 * @param width The width of the menu.
 */
void IMenu::printDoubleLineDivider(int width) const
{
    std::cout << DARK_GRAY << "╠" << repeat("═", width) << "╣" << RESET << std::endl;
}

/**
 * @brief Centers text with space padding on both sides.
 *
 * @param text The text to be centered.
 * @param width The total width to center the text within.
 * @return A string containing the centered text.
 */
std::string IMenu::centerText(const std::string &text, int width) const
{
    int padding = (width - static_cast<int>(text.size())) / 2;
    return std::string(padding, ' ') + text + std::string(width - text.size() - padding, ' ');
}

/**
 * @brief Centers text with custom character padding on both sides.
 *
 * @param text The text to be centered.
 * @param width The total width to center the text within.
 * @param padChar The character used to pad the text.
 * @return A string containing the centered text with padding.
 */
std::string IMenu::centerTextWithChar(const std::string &text, int width, const std::string &padChar) const
{
    int padding = (width - static_cast<int>(text.size())) / 2;
    std::string leftPadding = repeat(padChar, padding - 1) + " ";
    std::string rightPadding = " " + repeat(padChar, width - text.size() - padding - 1);
    return leftPadding + text + rightPadding;
}

std::string IMenu::stripColorCodes(const std::string &input) const
{
    static const std::regex colorCodePattern("\033\\[\\d+(;\\d+)*m");
    return std::regex_replace(input, colorCodePattern, "");
}

/**
 * @brief Displays the menu by printing its sections, options, and borders.
 */
void IMenu::displayMenu() const
{
    // Access the city instance
    City *city = City::instance();

    // Calculate the maximum width of the menu based on all sections and options
    int maxWidth = calculateMaxWidth(menuHeading, sections);
    maxWidth = std::max(maxWidth, calculateMaxWidth("City Resources", {}));

    clearScreen(); // Clear screen at the start of each display

    // Display the main menu heading at the top
    if (!menuHeading.empty())
    {
        printTopBorder(maxWidth);
        std::cout << DARK_GRAY << "║ " << BOLD_WHITE
                  << centerTextWithChar(menuHeading, maxWidth - 2, "█")
                  << DARK_GRAY << " ║" << RESET << std::endl;
        printDoubleLineDivider(maxWidth);
    }

    // Display City Resources section with the correct heading format
    std::cout << DARK_GRAY << "║ " << NORMAL_WHITE
              << centerTextWithChar("City Resources", maxWidth - 2, "•")
              << DARK_GRAY << " ║" << RESET << "\n";
    printSectionDivider(maxWidth);

    // Gather city resources with alignment and color
    std::vector<std::pair<std::string, std::string>> resourceLines = {
        {"Money:", std::to_string(city->getMoney())},
        {"Population:", std::to_string(city->getPopulation()) + "/" + std::to_string(city->getPopulationCapacity())},
        {"Wood:", std::to_string(city->getWood())},
        {"Stone:", std::to_string(city->getStone())},
        {"Concrete:", std::to_string(city->getConcrete())},
        {"Electricity Production:", std::to_string(city->getElectricityProduction())},
        {"Electricity Consumption:", std::to_string(city->getElectricityConsumption())},
        {"Water Production:", std::to_string(city->getWaterProduction())},
        {"Water Consumption:", std::to_string(city->getWaterConsumption())}};

    // Get satisfaction value and prepare it for conditional color display
    int satisfaction = static_cast<int>(city->getSatisfaction());
    std::string satisfactionColor;
    if (satisfaction >= 70)
    {
        satisfactionColor = BOLD_GREEN;
    }
    else if (satisfaction >= 30)
    {
        satisfactionColor = BOLD_YELLOW;
    }
    else
    {
        satisfactionColor = BOLD_RED;
    }
    resourceLines.push_back({"Satisfaction:", satisfactionColor + std::to_string(satisfaction) + "%" + RESET});

    // Display each resource line with color formatting
    for (const auto &line : resourceLines)
    {
        std::ostringstream formattedLine;
        formattedLine << BOLD_WHITE << std::left << std::setw(25) << line.first << RESET;

        // Apply different colors to values based on resource type
        if (line.first == "Money:")
        {
            formattedLine << BOLD_GREEN << line.second << RESET; // Green for money
        }
        else if (line.first.find("Production") != std::string::npos)
        {
            formattedLine << BOLD_YELLOW << line.second << RESET; // Yellow for production values
        }
        else if (line.first.find("Consumption") != std::string::npos)
        {
            formattedLine << BOLD_RED << line.second << RESET; // Red for consumption values
        }
        else if (line.first == "Satisfaction:")
        {
            formattedLine << line.second; // Satisfaction is already colored
        }
        else
        {
            formattedLine << BOLD_CYAN << line.second << RESET; // Cyan for other resources
        }

        int padding = maxWidth - 4 - stripColorCodes(formattedLine.str()).size(); // Calculate right padding for alignment
        std::cout << DARK_GRAY << "║ " << RESET << formattedLine.str()
                  << std::string(std::max(0, padding), ' ') << DARK_GRAY << "   ║" << RESET << "\n";
    }

    printSectionDivider(maxWidth); // Divider between City Resources and the rest of the menu

    // Display the main menu sections (Options, Navigation, etc.)
    bool showSections = sections.size() > 1;

    for (size_t sectionIndex = 0; sectionIndex < sections.size(); ++sectionIndex)
    {
        const auto &section = sections[sectionIndex];

        if (showSections)
        {
            std::cout << DARK_GRAY << "║ " << NORMAL_WHITE
                      << centerTextWithChar(section.heading, maxWidth - 2, "•")
                      << DARK_GRAY << " ║" << RESET << "\n";
            printSectionDivider(maxWidth);
        }

        for (const auto &option : section.options)
        {
            std::string plainText = stripColorCodes(option.text);
            int iconWidth = 2;                   // Icon width assumed as 2 characters
            int keyAndIconWidth = 6 + iconWidth; // Key, space, icon, and additional space
            int padding = maxWidth - plainText.size() - keyAndIconWidth;

            std::cout << DARK_GRAY << "║ " << BOLD_YELLOW << option.key << RESET << ". " << option.icon << " "
                      << option.text << std::string(std::max(0, padding), ' ') << DARK_GRAY << " ║" << RESET << std::endl;
        }

        if (sectionIndex == sections.size() - 1)
        {
            printBottomBorder(maxWidth); // Bottom border after the last section
        }
        else
        {
            printSectionDivider(maxWidth);
        }
    }
}

/**
 * @brief Displays the choice prompt for user input.
 */
void IMenu::displayChoicePrompt() const
{
    std::string prompt = "Enter your choice: ";

    displayChoiceMessagePrompt(prompt);
}

/**
 * @brief Displays a message prompt with a custom message.
 *
 * @param message The message to display.
 */
void IMenu::displayChoiceMessagePrompt(const std::string &message) const
{
    // Create a visually appealing prompt with some spacing, a border, and colors
    std::cout << DARK_GRAY << "\n>> "   // Start with a subtle ">>" in dark gray
              << BOLD_YELLOW << message // Make the prompt itself stand out
              << RESET;                 // Reset color back to normal for input
}

/**
 * @brief Displays an error message when the user makes an invalid choice.
 */
void IMenu::displayInvalidChoice() const
{
    std::string message = "Invalid choice. Please select a valid option.";

    displayErrorMessage(message);
}

/**
 * @brief Displays an error message with the provided message text.
 *
 * @param message The error message to display.
 */
void IMenu::displayErrorMessage(const std::string &message) const
{
    // Create a styled error message with colors and spacing
    std::cout << DARK_GRAY << "\n>> " // Subtle indicator in dark gray
              << BOLD_RED << message  // Bold red to make the error message stand out
              << RESET << std::endl;  // Reset color and add a new line
}

/**
 * @brief Displays a success message with green color.
 *
 * @param message The success message to display.
 */
void IMenu::displaySuccessMessage(const std::string &message) const
{
    // Create a styled success message with colors and spacing
    std::cout << DARK_GRAY << "\n>> "  // Subtle indicator in dark gray
              << BOLD_GREEN << message // Bold green to make the success message stand out
              << RESET << std::endl;   // Reset color and add a new line
}

void IMenu::displayPressEnterToContinue() const
{
    // Display the message asking the user to press enter
    std::cout << BOLD_WHITE << "\nPress Enter to continue..." << RESET << std::endl;

    // Wait for the user to press enter
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}
