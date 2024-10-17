#ifndef IMENU_H
#define IMENU_H

#include <string>
#include <vector>
#include <iostream>

struct Option
{
    char key;         // Custom key for this option
    std::string icon; // Icon for this option
    std::string text; // The actual text of the option
};

struct Section
{
    std::string heading;
    std::vector<Option> options;
};

class IMenu
{
public:
    IMenu() = default;
    IMenu(std::string heading);
    virtual ~IMenu() = default;

    virtual void display() const = 0;
    virtual void handleInput() const = 0;

protected:
    std::vector<Section> sections;
    std::string menuHeading;

    void displayMenu() const;
};

#endif // IMENU_H
