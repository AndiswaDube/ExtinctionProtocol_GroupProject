#pragma once

namespace ExtinctionProtocol {
	struct Oxygen
	{
		private: 
			int oxyLevel;

		public:
			Oxygen() { oxyLevel = 208; }
			~Oxygen();
			int getOxygenLevel() const;
			void setOxygenLevel(int aOxyLevel);
			void decreaseOxygenLevel(double aPercentage);
			void increaseOxygenLevel(double aPercentage);
	};
}

