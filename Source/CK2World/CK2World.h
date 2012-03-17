#ifndef CK2WORLD
#define CK2WORLD


#include "..\Parsers\Object.h"
#include "..\Date.h"
#include "CK2Title.h"
#include "CK2Province.h"


class CK2World
{
	public:
		void							init(Object*);
		date							getEndDate();
		vector<CK2Title*>			getIndependentTitles();
		map<int, CK2Province*>	getProvinces();
		~CK2World();
	private:
		date							endDate;
		vector<CK2Title*>			independentTitles;
		vector<CK2Title*>			hreMembers;
		map<string, CK2Title*>	titles;
		map<int, CK2Province*>	provinces;
};


#endif // CK2WORLD