#ifndef BSP_PARTITIONER_H
#define BSP_PARTITIONER_H

#include <vector>

/**
 * @brief Represents a rectangular area with position and size.
 */
class Rectangle
{
public:
    int x;       ///< The x-coordinate of the rectangle.
    int y;       ///< The y-coordinate of the rectangle.
    int width;   ///< The width of the rectangle.
    int height;  ///< The height of the rectangle.

    /**
     * @brief Constructs a Rectangle with specified position and size.
     * @param x The x-coordinate.
     * @param y The y-coordinate.
     * @param width The width of the rectangle.
     * @param height The height of the rectangle.
     */
    Rectangle(int x, int y, int width, int height) : x(x), y(y), width(width), height(height) {}
};

/**
 * @brief Handles Binary Space Partitioning (BSP) for grid partitioning.
 *        Splits a grid into smaller rectangular rooms separated by gaps.
 */
class BSPPartitioner
{
private:
    int gridWidth;                  ///< Width of the grid.
    int gridHeight;                 ///< Height of the grid.
    int minWidth;                   ///< Minimum width for partitioned rooms.
    int minHeight;                  ///< Minimum height for partitioned rooms.
    int gap;                        ///< Gap width between partitions.
    std::vector<Rectangle> rooms;   ///< List of partitioned rooms.
    std::vector<Rectangle> gaps;    ///< List of gap areas for roads.

    /**
     * @brief Recursively splits a rectangle into two smaller rectangles with a gap.
     * @param rect The rectangle to split.
     */
    void split(Rectangle rect);

public:
    /**
     * @brief Constructs a BSPPartitioner with grid dimensions, minimum room size, and gap width.
     * @param gridWidth Width of the grid.
     * @param gridHeight Height of the grid.
     * @param minWidth Minimum width of a room.
     * @param minHeight Minimum height of a room.
     * @param gap Width of the gap between partitions.
     */
    BSPPartitioner(int gridWidth, int gridHeight, int minWidth, int minHeight, int gap);

    /**
     * @brief Partitions the grid into rooms separated by gaps.
     */
    void partition();

    /**
     * @brief Retrieves the list of partitioned rooms.
     * @return Vector of rectangles representing rooms.
     */
    const std::vector<Rectangle> &getRooms() const;

    /**
     * @brief Retrieves the list of gap areas.
     * @return Vector of rectangles representing gaps.
     */
    const std::vector<Rectangle> &getGaps() const;
};

#endif // BSP_PARTITIONER_H