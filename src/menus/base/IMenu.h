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
    std::variant<char, int> key; // Custom key can be either char or int.
    std::string icon;            // Icon for this option.
    std::string text;            // The actual text of the option.
};

/**
 * @brief Represents a section in the menu, which contains a heading and multiple options.
 */
struct Section
{
    std::string heading;         ///< The heading of the section.
    std::vector<Option> options; ///< The list of options in the section.
};

/**
 * @brief Base class for creating menus.
 * Derived menus should implement display and input handling.
 */
class IMenu
{
public:
    /**
     * @brief Default constructor for IMenu.
     */
    IMenu() = default;

    /**
     * @brief Constructor to initialize a menu with a heading.
     * @param heading The heading of the menu.
     */
    IMenu(std::string heading);

    /**
     * @brief Virtual destructor for IMenu.
     */
    virtual ~IMenu() = default;

    /**
     * @brief Pure virtual function to display the menu.
     */
    virtual void display() const = 0;

    /**
     * @brief Pure virtual function to handle user input in the menu.
     */
    virtual void handleInput() = 0;

    /**
     * @brief Sets the heading of the menu.
     * @param heading The new heading for the menu.
     */
    void setHeading(const std::string &heading);

protected:
    std::vector<Section> sections; ///< List of sections in the menu.
    std::string menuHeading;       ///< The heading of the menu.
    bool hasExited;
    CityManager cityManager;

    // Utility functions and color constants for inherited classes.

    /**
     * @brief ANSI color codes and styles for use in all menus.
     */
    static constexpr const char *RESET = "\033[0m";
    static constexpr const char *BOLD_WHITE = "\033[1;37m";
    static constexpr const char *NORMAL_WHITE = "\033[0;37m";
    static constexpr const char *DARK_GRAY = "\033[1;30m";
    static constexpr const char *BOLD_YELLOW = "\033[1;33m";
    static constexpr const char *BOLD_GREEN = "\033[1;32m";
    static constexpr const char *BOLD_RED = "\033[1;31m";
    static constexpr const char *BOLD_CYAN = "\033[1;36m";

    static constexpr int MIN_MENU_WIDTH = 50; ///< Minimum width for the menu.

    /**
     * @brief Converts a numeric index (0-99) to a single character in an extended set.
     *
     * @param index Numeric index to convert (0-99).
     * @return char Corresponding character.
     */
    char indexToExtendedChar(int index) const;

    /**
     * @brief Utility function to repeat a string multiple times.
     * @param str The string to repeat.
     * @param times The number of times to repeat the string.
     * @return A concatenated string repeated n times.
     */
    std::string repeat(const std::string &str, int times) const;

    /**
     * @brief Calculates the maximum width for the menu.
     * @param menuHeading The heading of the menu.
     * @param sections The sections of the menu.
     * @return The maximum width.
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
     * @brief Centers text with space padding on both sides.
     * @param text The text to be centered.
     * @param width The total width to center the text within.
     * @return A string containing the centered text.
     */
    std::string centerText(const std::string &text, int width) const;

    /**
     * @brief Centers text with custom character padding on both sides.
     * @param text The text to be centered.
     * @param width The total width to center the text within.
     * @param padChar The character used to pad the text.
     * @return A string containing the centered text with padding.
     */
    std::string centerTextWithChar(const std::string &text, int width, const std::string &padChar) const;

    /**
     * @brief Function to display the formatted menu with sections and options.
     */
    void displayMenu() const;

    /**
     * @brief Displays the choice prompt for the user.
     */
    void displayChoicePrompt() const;

    /**
     * @brief Displays a message prompt with a custom message for the user.
     * @param message The message to display.
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
     * @brief Clears the screen.
     */
    void clearScreen() const { system("clear"); }

    /**
     * @brief Strips ANSI color codes from a string.
     * @param input The string with potential color codes.
     * @return A plain string with color codes removed.
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
     * @brief Displays available positions for an entity on the city grid.
     * Positions are marked based on availability for a given type and size.
     *
     * @param positions Vector of available positions.
     */
    void displayAvailablePositions(const std::vector<std::vector<int>> &positions) const;
};

#endif // IMENU_H
