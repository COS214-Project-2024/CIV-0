#include "IMenu.h"
#include "city/City.h"
#include "entities/road/Road.h"
#include <algorithm> // For std::max
#include <iostream>
#include <iomanip>
#include <sstream>
#include <regex>

// Define color constants
const char *IMenu::RESET = "\033[0m";
const char *IMenu::BOLD_WHITE = "\033[1;37m";
const char *IMenu::NORMAL_WHITE = "\033[0;37m";
const char *IMenu::DARK_GRAY = "\033[1;30m";
const char *IMenu::BOLD_YELLOW = "\033[1;33m";
const char *IMenu::BOLD_GREEN = "\033[1;32m";
const char *IMenu::BOLD_RED = "\033[1;31m";
const char *IMenu::BOLD_CYAN = "\033[1;36m";
const char *IMenu::BLUE = "\033[34m";

std::string IMenu::coordinatesToLabel(int x, int y)
{
    char xLabel = indexToExtendedChar(x);
    char yLabel = indexToExtendedChar(y);
    return "(" + std::string(1, xLabel) + ", " + std::to_string(y + 1) + ")";
}

void IMenu::displayAvailablePositions(const std::vector<std::vector<int>> &positions) const
{
    City *city = City::instance();
    const auto &grid = city->getGrid();
    int width = city->getWidth();
    int height = city->getHeight();

    std::vector<std::vector<bool>> positionMarkers(height, std::vector<bool>(width, false));
    for (const auto &pos : positions)
    {
        int x = pos[0];
        int y = pos[1];
        if (x >= 0 && x < width && y >= 0 && y < height)
        {
            positionMarkers[x][y] = true;
        }
    }

    std::cout << "    ";
    for (int i = 0; i < width; ++i)
    {
        std::cout << indexToExtendedChar(i) << " ";
    }
    std::cout << std::endl
              << "  ";
    printTopBorder(width * 2 + 1);

    for (int col = 0; col < height; ++col)
    {
        std::cout << indexToExtendedChar(col) << DARK_GRAY << " ║ " << RESET;

        for (int row = 0; row < width; ++row)
        {
            Entity *entity = grid[row][col];
            if (entity != nullptr && dynamic_cast<Road *>(entity))
            {
                std::cout << entity->getSymbol() << " ";
            }
            else if (positionMarkers[row][col])
            {
                std::cout << BOLD_YELLOW << "□ " << RESET;
            }
            else
            {
                std::cout << DARK_GRAY << ". " << RESET;
            }
        }
        std::cout << DARK_GRAY << "║" << RESET << std::endl;
    }

    std::cout << "  ";
    printBottomBorder(width * 2 + 1);
}

char IMenu::indexToExtendedChar(int index)
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
IMenu::IMenu(std::string heading) : menuHeading(heading), displayResources(true), isInfoMenu(false) {}

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
    maxWidth = std::max(maxWidth, 80); // Example width, adjust as necessary

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

    // Conditionally display the resources section
    if (displayResources)
    {
        std::cout << DARK_GRAY << "║ " << NORMAL_WHITE
                  << centerTextWithChar("City Resources", maxWidth - 2, "•")
                  << DARK_GRAY << " ║" << RESET << "\n";
        printSectionDivider(maxWidth);

        // Define resource lines with aligned and conditionally color-coded values
        std::vector<std::pair<std::string, std::string>> resourceLines = {
            {"Money:", std::string(BOLD_GREEN) + std::to_string(city->getMoney()) + RESET},
            {"Wood:", std::string(BOLD_CYAN) + std::to_string(city->getWood()) + RESET},
            {"Stone:", std::string(BOLD_CYAN) + std::to_string(city->getStone()) + RESET},
            {"Concrete:", std::string(BOLD_CYAN) + std::to_string(city->getConcrete()) + RESET},
            {"Population:", std::to_string(city->getPopulation()) + "/" + std::to_string(city->getPopulationCapacity())}};

        // Conditionally color electricity and water consumption/production
        int electricityConsumption = city->getElectricityConsumption();
        int electricityProduction = city->getElectricityProduction();
        int waterConsumption = city->getWaterConsumption();
        int waterProduction = city->getWaterProduction();

        std::string electricityColor = electricityConsumption > electricityProduction ? BOLD_RED : BOLD_GREEN;
        std::string waterColor = waterConsumption > waterProduction ? BOLD_RED : BOLD_GREEN;

        resourceLines.push_back({"Electricity :",
                                 electricityColor + std::to_string(electricityConsumption) + RESET + "/" +
                                     BOLD_GREEN + std::to_string(electricityProduction) + RESET});

        resourceLines.push_back({"Water :",
                                 waterColor + std::to_string(waterConsumption) + RESET + "/" +
                                     BOLD_GREEN + std::to_string(waterProduction) + RESET});

        // Set satisfaction color based on value
        int satisfaction = static_cast<int>(city->getSatisfaction());
        std::string satisfactionColor = satisfaction >= 70 ? BOLD_GREEN : satisfaction >= 30 ? BOLD_YELLOW
                                                                                             : BOLD_RED;
        resourceLines.push_back({"Satisfaction:", satisfactionColor + std::to_string(satisfaction) + "%" + RESET});

        // Display each resource line
        for (const auto &line : resourceLines)
        {
            std::ostringstream formattedLine;
            formattedLine << BOLD_WHITE << std::left << std::setw(25) << line.first << RESET;

            // Add the already formatted value string
            formattedLine << line.second;

            int padding = maxWidth - 4 - stripColorCodes(formattedLine.str()).size();
            std::cout << DARK_GRAY << "║ " << RESET << formattedLine.str()
                      << std::string(std::max(0, padding), ' ') << DARK_GRAY << "   ║" << RESET << "\n";
        }
        printSectionDivider(maxWidth);
    }

    // Display each section and its options
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
            int iconWidth = 2; // Icon width is assumed to be 2 characters

            // Determine the width of the key (character or integer)
            int keyWidth = 1;
            if (auto keyChar = std::get_if<char>(&option.key))
            {
                keyWidth = 1; // single character width for char keys
            }
            else if (auto keyInt = std::get_if<int>(&option.key))
            {
                keyWidth = std::to_string(*keyInt).size(); // calculate width of integer key
            }

            int keyAndIconWidth = keyWidth + 5 + iconWidth; // Key, icon, and additional space
            int padding = maxWidth - plainText.size() - keyAndIconWidth;

            // Display the key based on its type (char or int)
            std::cout << DARK_GRAY << "║ ";
            if (auto keyChar = std::get_if<char>(&option.key))
            {
                std::cout << BOLD_YELLOW << *keyChar;
                if (!isInfoMenu)
                    std::cout << "."; // Conditionally add a period
                else
                    std::cout << " ";
            }
            else if (auto keyInt = std::get_if<int>(&option.key))
            {
                std::cout << BOLD_YELLOW << *keyInt;
                if (!isInfoMenu)
                    std::cout << "."; // Conditionally add a period
            }
            std::cout << RESET << " " << option.icon << " " << option.text
                      << std::string(std::max(0, padding), ' ') << DARK_GRAY << " ║" << RESET << std::endl;
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
