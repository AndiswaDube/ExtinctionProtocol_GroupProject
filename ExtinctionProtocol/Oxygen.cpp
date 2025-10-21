#include "Oxygen.h"

namespace ExtinctionProtocol {
	Oxygen::~Oxygen() {}
	
	int Oxygen::getOxygenLevel() const
	{
		return oxyLevel;
	}

	void Oxygen::setOxygenLevel(int aOxyLevel)
	{
		oxyLevel = aOxyLevel;
	}
	
	void Oxygen::decreaseOxygenLevel(double aPercentage)
	{
		oxyLevel = oxyLevel - (208 * (aPercentage / 100)) >= 0 ? oxyLevel - (208 * (aPercentage / 100)) : 0;
	}

	void Oxygen::increaseOxygenLevel(double aPercentage)
	{
		oxyLevel = oxyLevel + (208 * (aPercentage / 100)) <= 208 ? oxyLevel + (208 * (aPercentage / 100)):208;	}
}
