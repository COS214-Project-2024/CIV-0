#include "IMenu.h"
#include <algorithm> // For std::max
#include <iostream>  // For std::setw
#include <regex>

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
    // Calculate the maximum width based on the longest piece of text (ignoring color codes)
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

        // Display each option in the section with its custom key and proper padding
        for (const auto &option : section.options)
        {
            std::string plainText = stripColorCodes(option.text); // Remove color codes for proper alignment
            int iconWidth = 2;                                    // Assume each icon takes 2 characters
            int keyAndIconWidth = 6 + iconWidth;                  // Key (1 char), space (1 char), icon, and space (1 char)
            int padding = maxWidth - static_cast<int>(plainText.size()) - keyAndIconWidth;

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
