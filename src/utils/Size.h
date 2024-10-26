#ifndef SIZE_H
#define SIZE_H

#include <string>
#include <stdexcept> // For std::invalid_argument

enum class Size
{
    SMALL,
    MEDIUM,
    LARGE,
};

/**
 * @brief Converts a Size enum to its corresponding string value.
 * @param size The Size enum value.
 * @return The string representation of the size.
 */
inline std::string sizeToString(Size size)
{
    switch (size)
    {
    case Size::SMALL:
        return "SMALL";
    case Size::MEDIUM:
        return "MEDIUM";
    case Size::LARGE:
        return "LARGE";
    default:
        throw std::invalid_argument("Invalid Size enum value");
    }
}

/**
 * @brief Converts a string to its corresponding Size enum value.
 * @param sizeStr The string representation of the size.
 * @return The corresponding Size enum value.
 * @throws std::invalid_argument if the string does not match any enum value.
 */
inline Size stringToSize(const std::string &sizeStr)
{
    if (sizeStr == "SMALL")
        return Size::SMALL;
    else if (sizeStr == "MEDIUM")
        return Size::MEDIUM;
    else if (sizeStr == "LARGE")
        return Size::LARGE;
    else
        throw std::invalid_argument("Invalid size string: " + sizeStr);
}

#endif // SIZE_H
