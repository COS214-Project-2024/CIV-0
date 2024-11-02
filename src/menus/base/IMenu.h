#ifndef IMENU_H
#define IMENU_H

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits>
#include <variant>
#include "managers/CityManager.h"

/**
 * @brief Represents a menu option with a custom key (char or int), icon, and text.
 */
struct Option
{
    std::variant<char, int> key; ///< Custom key can be either char or int.
    std::string icon;            ///< Icon representing this option.
    std::string text;            ///< The display text for the option.
};

/**
 * @brief Represents a section in the menu, containing a heading and multiple options.
 */
struct Section
{
    std::string heading;         ///< The heading/title of the section.
    std::vector<Option> options; ///< The list of options within the section.
};

/**
 * @brief Abstract base class for creating menus.
 *
 * This class provides the common functionality and interface for all menus.
 * Derived classes must implement the display and input handling methods.
 */
class IMenu
{
public:
    /**
     * @brief Default constructor for IMenu.
     */
    IMenu() = default;

    /**
     * @brief Constructor to initialize a menu with a specified heading.
     * @param heading The heading/title of the menu.
     */
    IMenu(std::string heading);

    /**
     * @brief Virtual destructor for IMenu.
     */
    virtual ~IMenu() = default;

    /**
     * @brief Pure virtual function to display the menu.
     *
     * Must be implemented by derived classes to handle the rendering of the menu.
     */
    virtual void display() const = 0;

    /**
     * @brief Pure virtual function to handle user input in the menu.
     *
     * Must be implemented by derived classes to process user interaction.
     */
    virtual void handleInput() = 0;

    /**
     * @brief Sets the heading of the menu.
     * @param heading The new heading for the menu.
     */
    void setHeading(const std::string &heading);

protected:
    std::vector<Section> sections; ///< List of sections contained in the menu.
    std::string menuHeading;       ///< The heading/title of the menu.
    bool hasExited;                ///< Flag indicating if the menu has been exited.
    CityManager cityManager;       ///< Manager for city-related operations.

    bool displayResources; ///< Flag indicating whether to display resources in the menu.
    bool isInfoMenu;       ///< Flag indicating whether to display option numbers.

    // Utility functions and color constants for inherited classes.

    /**
     * @brief ANSI color codes and styles for use in all menus.
     */
    static const char *RESET;
    static const char *BOLD_WHITE;
    static const char *NORMAL_WHITE;
    static const char *DARK_GRAY;
    static const char *BOLD_YELLOW;
    static const char *BOLD_GREEN;
    static const char *BOLD_RED;
    static const char *BOLD_CYAN;

    /**
     * @brief Converts a numeric index (0-99) to a single character in an extended set.
     *
     * @param index Numeric index to convert (0-99).
     * @return The corresponding character for the given index.
     * @throws std::out_of_range If the index is outside the allowed range.
     */
    char indexToExtendedChar(int index) const;

    /**
     * @brief Utility function to repeat a string multiple times.
     * @param str The string to repeat.
     * @param times The number of times to repeat the string.
     * @return A concatenated string repeated the specified number of times.
     */
    std::string repeat(const std::string &str, int times) const;

    /**
     * @brief Calculates the maximum width required for the menu.
     *
     * This function ensures the menu is wide enough to fit the heading and options.
     * @param menuHeading The heading of the menu.
     * @param sections The sections of the menu.
     * @return The maximum width needed to display the menu.
     */
    int calculateMaxWidth(const std::string &menuHeading, const std::vector<Section> &sections) const;

    /**
     * @brief Prints the top border of the menu using box-drawing characters.
     * @param width The width of the menu.
     */
    void printTopBorder(int width) const;

    /**
     * @brief Prints the bottom border of the menu using box-drawing characters.
     * @param width The width of the menu.
     */
    void printBottomBorder(int width) const;

    /**
     * @brief Prints a section divider in the menu using box-drawing characters.
     * @param width The width of the menu.
     */
    void printSectionDivider(int width) const;

    /**
     * @brief Prints a double-line divider for the main heading of the menu.
     * @param width The width of the menu.
     */
    void printDoubleLineDivider(int width) const;

    /**
     * @brief Centers text within a specified width using space padding.
     * @param text The text to be centered.
     * @param width The total width to center the text within.
     * @return A string containing the centered text with space padding.
     */
    std::string centerText(const std::string &text, int width) const;

    /**
     * @brief Centers text within a specified width using a custom character for padding.
     * @param text The text to be centered.
     * @param width The total width to center the text within.
     * @param padChar The character used for padding.
     * @return A string containing the centered text with custom character padding.
     */
    std::string centerTextWithChar(const std::string &text, int width, const std::string &padChar) const;

    /**
     * @brief Displays the formatted menu, including sections and options.
     */
    void displayMenu() const;

    /**
     * @brief Displays the choice prompt for user input.
     */
    void displayChoicePrompt() const;

    /**
     * @brief Displays a custom message prompt for user input.
     * @param message The custom message to display.
     */
    void displayChoiceMessagePrompt(const std::string &message) const;

    /**
     * @brief Displays an error message when the user makes an invalid choice.
     */
    void displayInvalidChoice() const;

    /**
     * @brief Displays a general error message.
     * @param message The error message to display.
     */
    void displayErrorMessage(const std::string &message) const;

    /**
     * @brief Displays a success message in green color.
     * @param message The success message to display.
     */
    void displaySuccessMessage(const std::string &message) const;

    /**
     * @brief Displays a message asking the user to press Enter to continue.
     */
    void displayPressEnterToContinue() const;

    /**
     * @brief Clears the terminal screen.
     */
    void clearScreen() const { system("clear"); }

    /**
     * @brief Strips ANSI color codes from a string.
     * @param input The string potentially containing color codes.
     * @return The string with color codes removed.
     */
    std::string stripColorCodes(const std::string &input) const;

    /**
     * @brief Converts x and y coordinates to a labeled string (e.g., "A, 1").
     *
     * @param x The x-coordinate.
     * @param y The y-coordinate.
     * @return A formatted string representing the labeled coordinates.
     */
    std::string coordinatesToLabel(int x, int y) const;

    /**
     * @brief Displays available positions on the city grid for an entity.
     *
     * Marks positions based on availability for a given type and size.
     * @param positions A vector of available positions on the grid.
     */
    virtual void displayAvailablePositions(const std::vector<std::vector<int>> &positions) const;
};

#endif // IMENU_H