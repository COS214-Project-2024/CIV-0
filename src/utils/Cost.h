#ifndef COST_H
#define COST_H

struct Cost
{
    int moneyCost;
    int woodCost;
    int stoneCost;
    int concreteCost;

    Cost(int money = 0, int wood = 0, int stone = 0, int concrete = 0)
        : moneyCost(money), woodCost(wood), stoneCost(stone), concreteCost(concrete) {}
};

#endif // COST_H
