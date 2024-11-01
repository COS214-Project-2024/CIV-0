#ifndef BSP_PARTITIONER_H
#define BSP_PARTITIONER_H

#include <vector>

class Rectangle
{
public:
    int x, y, width, height;

    Rectangle(int x, int y, int width, int height) : x(x), y(y), width(width), height(height) {}
};

class BSPPartitioner
{
private:
    int gridWidth, gridHeight;
    int minWidth, minHeight;
    int gap;
    std::vector<Rectangle> rooms;
    std::vector<Rectangle> gaps; // Stores gaps where roads will be placed

    void split(Rectangle rect);

public:
    BSPPartitioner(int gridWidth, int gridHeight, int minWidth, int minHeight, int gap);

    // Partition the grid and store sections as rectangles with gaps
    void partition();

    // Access the created rooms and gaps
    const std::vector<Rectangle> &getRooms() const;
    const std::vector<Rectangle> &getGaps() const;
};

#endif // BSP_PARTITIONER_H
