#include "BSPPartitioner.h"
#include <cstdlib>
#include <ctime>

// Constructor initializes the grid dimensions, min width, min height, and gap
BSPPartitioner::BSPPartitioner(int gridWidth, int gridHeight, int minWidth, int minHeight, int gap)
    : gridWidth(gridWidth), gridHeight(gridHeight), minWidth(minWidth), minHeight(minHeight), gap(gap)
{
    // Removed local seeding to use the seed set by CityManager
}

// Main partitioning function
void BSPPartitioner::partition()
{
    // Start with the entire grid as the initial rectangle
    Rectangle initialRect(0, 0, gridWidth, gridHeight);
    split(initialRect);
}

// Recursive function to split a rectangle into two smaller rectangles with a gap
void BSPPartitioner::split(Rectangle rect)
{
    // Base case: Stop if the rectangle is below the minimum width or height plus gap
    if (rect.width <= minWidth + gap || rect.height <= minHeight + gap)
    {
        rooms.push_back(rect); // Store the final room
        return;
    }

    // Decide whether to split horizontally or vertically based on the dimensions
    bool splitHorizontally = (rect.width > rect.height); // Prefer split direction based on aspect ratio

    // Random split point, ensuring the split is within the rectangle's boundaries and considers gap
    int splitPoint = (splitHorizontally)
                         ? (rect.width / 4 + rand() % (rect.width / 2 - gap))
                         : (rect.height / 4 + rand() % (rect.height / 2 - gap));

    if (splitHorizontally && rect.width > minWidth + gap)
    {
        // Split horizontally with gap
        Rectangle leftRect(rect.x, rect.y, splitPoint - gap / 2, rect.height);
        Rectangle rightRect(rect.x + splitPoint + gap / 2, rect.y, rect.width - splitPoint - gap / 2, rect.height);

        // Create a gap rectangle between left and right rooms
        Rectangle horizontalGap(rect.x + splitPoint - gap / 2, rect.y, gap, rect.height);
        gaps.push_back(horizontalGap); // Store the gap

        // Recursively split the left and right partitions
        split(leftRect);
        split(rightRect);
    }
    else if (!splitHorizontally && rect.height > minHeight + gap)
    {
        // Split vertically with gap
        Rectangle topRect(rect.x, rect.y, rect.width, splitPoint - gap / 2);
        Rectangle bottomRect(rect.x, rect.y + splitPoint + gap / 2, rect.width, rect.height - splitPoint - gap / 2);

        // Create a gap rectangle between top and bottom rooms
        Rectangle verticalGap(rect.x, rect.y + splitPoint - gap / 2, rect.width, gap);
        gaps.push_back(verticalGap); // Store the gap

        // Recursively split the top and bottom partitions
        split(topRect);
        split(bottomRect);
    }
    else
    {
        // If it cannot be split further due to minimum dimensions, add the room
        rooms.push_back(rect);
    }
}

// Accessors for rooms and gaps
const std::vector<Rectangle> &BSPPartitioner::getRooms() const
{
    return rooms;
}

const std::vector<Rectangle> &BSPPartitioner::getGaps() const
{
    return gaps;
}
