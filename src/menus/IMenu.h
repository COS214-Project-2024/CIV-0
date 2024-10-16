#ifndef IMENU_H
#define IMENU_H

#include <iostream>
#include <string>
#include <vector>
#include "city/City.h" // Include the City class

// Struct to represent a menu option with a key and text
struct MenuOption
{
    int key;
    std::string text;
};

class IMenu
{
public:
    IMenu(const std::string &heading); // Constructor to set the heading
    virtual ~IMenu();

    virtual void display() const = 0;
    virtual void handleInput() = 0;
    void setCity(City *city);

protected:
    std::string heading;             // Store the menu heading
    std::vector<MenuOption> options; // Store the menu options for the derived classes
    int menuWidth;
    City *city;

    void displayMenu() const; // Display menu with the stored heading and options
    void setMenuWidth(int width);
};

#endif // IMENU_H
