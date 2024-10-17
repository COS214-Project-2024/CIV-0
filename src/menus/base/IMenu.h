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

    /**
     * @brief Function to display the formatted menu with sections and options.
     */
    void displayMenu() const;
};

#endif // IMENU_H
