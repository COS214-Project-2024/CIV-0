#include "managers/ResourceManager.h"
#include "managers/ResourceManager.h"

ResourceManager::ResourceManager() {}
ResourceManager::~ResourceManager() {}

int ResourceManager::calculateConcreteMade()
{
	ResourceVisitor rv;
	rv.visit(City::instance());
	City::instance()->setConcrete(City::instance()->getConcrete() + rv.getTotalConcrete() * (City::instance()->getSatisfaction() / 100));
	return City::instance()->getConcrete();
}

int ResourceManager::calculateStoneMade()
{
	ResourceVisitor rv;
	rv.visit(City::instance());
	City::instance()->setStone(City::instance()->getStone() + rv.getTotalStone() * (City::instance()->getSatisfaction() / 100));
	return City::instance()->getStone();
}

int ResourceManager::calculateWoodMade()
{
	ResourceVisitor rv;
	rv.visit(City::instance());
	City::instance()->setWood(City::instance()->getWood() + rv.getTotalWood() * (City::instance()->getSatisfaction() / 100));
	return City::instance()->getWood();
}

void ResourceManager::buildIndustry(EntityType type, Size size, int x, int y)
{
	if (type != EntityType::CONCRETEPRODUCER && type != EntityType::STONEPRODUCER && type != EntityType::WOODPRODUCER)
	{
		return;
	}

	IndustryFactory *industryFactory = new IndustryFactory();
	Entity *industry = nullptr;
	industry = industryFactory->createEntity(type, size, x, y);
	if (industry != nullptr)
	{
		City::instance()->addEntity(industry);
	}
}

std::vector<Industry *> ResourceManager::getAllConcreteProducers()
{
	std::vector<std::vector<Entity *>> grid = City::instance()->getGrid();
	ConcreteProducerIterator *iterator = new ConcreteProducerIterator(grid);
	std::vector<Industry *> concreteProducers;

	for (iterator->first(); iterator->hasNext(); iterator->next())
	{
		ConcreteProducer *producer = dynamic_cast<ConcreteProducer *>(iterator->current());
		if (producer)
		{
			concreteProducers.push_back(producer);
		}
	}

	delete iterator;
	return concreteProducers;
}

std::vector<Industry *> ResourceManager::getAllStoneProducers()
{
	std::vector<std::vector<Entity *>> grid = City::instance()->getGrid();
	StoneProducerIterator *iterator = new StoneProducerIterator(grid);
	std::vector<Industry *> stoneProducers;

	for (iterator->first(); iterator->hasNext(); iterator->next())
	{
		StoneProducer *producer = dynamic_cast<StoneProducer *>(iterator->current());
		if (producer)
		{
			stoneProducers.push_back(producer);
		}
	}

	delete iterator;
	return stoneProducers;
}

std::vector<Industry *> ResourceManager::getAllWoodProducers()
{
	std::vector<std::vector<Entity *>> grid = City::instance()->getGrid();
	WoodProducerIterator *iterator = new WoodProducerIterator(grid);
	std::vector<Industry *> woodProducers;

	for (iterator->first(); iterator->hasNext(); iterator->next())
	{
		WoodProducer *producer = dynamic_cast<WoodProducer *>(iterator->current());
		if (producer)
		{
			woodProducers.push_back(producer);
		}
	}

	delete iterator;
	return woodProducers;
}

std::vector<Industry *> ResourceManager::getAllIndustryBuildings()
{
	std::vector<std::vector<Entity *>> grid = City::instance()->getGrid();
	IndustryIterator *iterator = new IndustryIterator(grid);
	std::vector<Industry *> industryBuildings;

	for (iterator->first(); iterator->hasNext(); iterator->next())
	{
		Industry *building = dynamic_cast<Industry *>(iterator->current());
		if (building)
		{
			industryBuildings.push_back(building);
		}
	}

	delete iterator;
	return industryBuildings;
}

bool ResourceManager::canAffordUpgrade(Industry *industry)
{
	Cost cost = industry->getCost();
	City *city = City::instance();

	if (cost.moneyCost <= city->getMoney() && cost.woodCost <= city->getWood() && cost.stoneCost <= city->getStone() && cost.concreteCost <= city->getConcrete())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool ResourceManager::upgrade(Industry *&industry)
{
	if (industry != nullptr && canAffordUpgrade(industry))
	{
		Entity *industryUpgrade = industry->upgrade();

		if (industryUpgrade != nullptr)
		{
			std::vector<std::vector<Entity *>> &grid = City::instance()->getGrid();

			for (int i = industry->getXPosition(); i < industry->getYPosition() + industry->getWidth(); i++)
			{
				for (int j = industry->getYPosition() - industry->getHeight() + 1; j <= industry->getYPosition(); j++)
				{
					grid[i][j] = industryUpgrade;
				}
			}

			delete industry;
			industry = (Industry *)industryUpgrade;

			return true;
		}
	}
	return false;
}

int ResourceManager::calculateMoneyMade()
{ // hardest function ive ever implemented
	TaxCalculationVisitor tv;
	tv.visit(City::instance());
	City::instance()->setMoney(City::instance()->getMoney() + tv.getTotalTax() * (City::instance()->getSatisfaction() / 100));
	return City::instance()->getMoney();
}