/*Copyright (c) 2016 The Paradox Game Converters Project

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be included
in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.*/



#ifndef HOI4STATE_H_
#define HOI4STATE_H_



#include <vector>
#include <string>
#include <map>
#include "..\Mapper.h"
#include "..\V2World\Vic2State.h"
using namespace std;



class HoI4State
{
	public:
		HoI4State(const Vic2State* sourceState, int _ID, string _ownerTag);

		void output(string filename);

		void addProvince(int province) { provinces.insert(province); }
		void addResource(string resource, double amount)	{ resources[resource] += amount; }
		void addVP(int location, int value) { victoryPoints.insert(make_pair(location, value)); }
		void addManpower(int newManpower) { manpower += newManpower; }
		void addAirBase(int newAirBase) { airbaseLevel += newAirBase; if (airbaseLevel > 10) airbaseLevel = 10; }

		void setNavalBase(int level, int location);
		void setIndustry(int civilianFactories, int militaryFactories, string category, int railLevel);
		void addCores(const vector<string>& newCores);

		const Vic2State* getSourceState() const { return sourceState; }
		set<int>	getProvinces() const { return provinces; }
		string getOwner() const { return ownerTag; }
		set<string> getCores() const { return cores; }
		int getID() const { return ID; }
		int getNavalLocation() const { return navalLocation; }
		int getDockyards() const { return dockyards; }
		int getCivFactories() const { return civFactories; }
		int getMilFactories() const { return milFactories; }

		int getFirstProvinceByVic2Definition(const Vic2ToHoI4ProvinceMapping& provinceMap);
		bool isProvinceInState(int provinceNum);

	private:
		const Vic2State* sourceState;

		int ID;
		set<int> provinces;
		string ownerTag;
		set<string> cores;

		int manpower;

		int civFactories;
		int milFactories;
		int dockyards;
		string category;
		int railLevel;
	
		int navalLevel;
		int navalLocation;

		int airbaseLevel;

		map<string, double> resources;

		map<int, int> victoryPoints;
};



#endif // HOI4STATE_H_
