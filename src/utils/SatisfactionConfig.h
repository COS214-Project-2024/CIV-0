#ifndef SATISFACTIONCONFIG_H
#define SATISFACTIONCONFIG_H

struct SatisfactionConfig
{
    float localRate;
    float globalRate;
    float localExtreme;
    float globalExtreme;

    SatisfactionConfig()
        : localRate(0.0f), globalRate(0.0f), localExtreme(0.0f), globalExtreme(0.0f) {}

    SatisfactionConfig(float localRate = 0.0f, float globalRate = 0.0f, float localExtreme = 0.0f, float globalExtreme = 0.0f)
        : localRate(localRate), globalRate(globalRate), localExtreme(localExtreme), globalExtreme(globalExtreme) {}
};

#endif // SATISFACTIONCONFIG_H
