#ifndef IMENU_H
#define IMENU_H

#include <string>
#include <vector>
#include <iostream>

/**
 * @brief Represents a menu option with a custom key, icon, and text.
 */
struct Option
{
    char key;         ///< Custom key for this option
    std::string icon; ///< Icon for this option
    std::string text; ///< The actual text of the option
};

/**
 * @brief Represents a section in the menu, which contains a heading and multiple options.
 */
struct Section
{
    std::string heading;         ///< The heading of the section
    std::vector<Option> options; ///< The list of options in the section
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
    virtual void handleInput() const = 0;

protected:
    std::vector<Section> sections; ///< List of sections in the menu
    std::string menuHeading;       ///< The heading of the menu

    // Utility functions and color constants for inherited classes

    /**
     * @brief ANSI color codes and styles for use in all menus.
     * These are static constants so that derived classes can access them easily.
     */
    static constexpr const char *RESET = "\033[0m";
    static constexpr const char *BOLD_WHITE = "\033[1;37m";
    static constexpr const char *NORMAL_WHITE = "\033[0;37m";
    static constexpr const char *DARK_GRAY = "\033[1;30m";
    static constexpr const char *BOLD_YELLOW = "\033[1;33m";

    static constexpr int MIN_MENU_WIDTH = 50; ///< Minimum width for the menu

    /**
     * @brief Utility function to repeat a string multiple times.
     * @param str The string to repeat.
     * @param times How many times to repeat the string.
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
};

#endif // IMENU_H
