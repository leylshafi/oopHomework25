#include <iostream>
#include<list>
#include<vector>
#include<algorithm>
#include <numeric>
using namespace std;
#include"Debtor.h"

//Predicate

void AgeBetween(const Debtor& d)
{
	if ((2022 - d.getBirthday().year) >= 26 && (2022 - d.getBirthday().year) < 36)
		cout << d << endl;
}

void DebitMoreThan500(const Debtor& d)
{
	if (d.getDebt() > 5000)
		cout << d << endl;
}

void IfInDecember(const Debtor& d)
{
	if (d.getBirthday().month == "December")
		cout << d << endl;
}

bool debtorDebtASC(const Debtor& d1, const Debtor& d2) {
	return d1.getDebt()>d2.getDebt();
}

void IfSawSecondWorldWar(const Debtor& d)
{
	if (d.getBirthday().year >= 1939 && d.getBirthday().year < 1945)
		cout << d << endl;
}

bool sortForName(const Debtor& d1, const Debtor& d2) {
	return (d1.getFullName() < d2.getFullName());
}

bool sortForDebt(const Debtor& d1, const Debtor& d2) {
	if(d1.getFullName()==d2.getFullName())
		return (d1.getFullName() < d2.getFullName());
}

bool countSeven(string a) {
	if (a == "7")
		return true;
		
}

//Functor

class AgeBetweenUp
{
	int up;
	int lower;
public:
	AgeBetweenUp(int lower, int up)
		:up(up),lower(lower){}

	void operator()(const Debtor& d) {
		if ((2022 - d.getBirthday().year) >= lower && (2022 - d.getBirthday().year) < up)
			cout << d << endl;
	}
};


class DebitMoreThan
{
	int moreThan;
public:
	DebitMoreThan(int moreThan)
		:moreThan(moreThan)
	{}
	void operator()(const Debtor& d) {
		if (d.getDebt() > moreThan)
			cout << d << endl;
	}

};

class inWhichMonth
{
	string month;
public:
	inWhichMonth(string month)
	{
		this->month = month;
	}

	void operator()(const Debtor& d) {
		if (d.getBirthday().month == month)
			cout << d << endl;
	}
};
int main()
{
	vector<Debtor>debtors;
	debtors.push_back(Debtor("Shirley T. Qualls", DateTime{ "December",3,1992}, "530-662-7732", "ShirleyTQualls@teleworm.us", "3565 Eagles Nest Drive Woodland, CA 95695", 2414));
	debtors.push_back(Debtor("Danielle W. Grier", DateTime("October", 18, 1953), "321-473-4178", "DanielleWGrier@rhyta.com", "1973 Stoneybrook Road Maitland, FL 32751", 3599));
	debtors.push_back(Debtor("Connie W. Lemire", DateTime("June", 18, 1963), "828-321-3751", "ConnieWLemire@rhyta.com", "2432 Hannah Street Andrews, NC 28901", 1219));
	debtors.push_back(Debtor("Coy K. Adams", DateTime("March", 1, 1976), "410-347-1307", "CoyKAdams@dayrep.com", "2411 Blue Spruce Lane Baltimore, MD 21202", 3784));
	debtors.push_back(Debtor("Bernice J. Miles", DateTime("June", 1, 1988), "912-307-6797", "BerniceJMiles@armyspy.com", "4971 Austin Avenue Savannah, GA 31401", 4060));
	debtors.push_back(Debtor("Bob L. Zambrano", DateTime("February", 28, 1990), "706-446-1649", "BobLZambrano@armyspy.com", "2031 Limer Street Augusta, GA 30901", 6628));
	debtors.push_back(Debtor("Adam D. Bartlett", DateTime("May", 6, 1950), "650-693-1758", "AdamDBartlett@rhyta.com", "2737 Rardin Drive San Jose, CA 95110", 5412));
	debtors.push_back(Debtor("Pablo M. Skinner", DateTime("August", 26, 1936), "630-391-2034", "PabloMSkinner@armyspy.com", "16 Fraggle Drive Hickory Hills, IL 60457", 11097));
	debtors.push_back(Debtor("Dorothy J. Brown", DateTime("July", 9, 1971), "270-456-3288", "DorothyJBrown@rhyta.com", "699 Harper Street Louisville, KY 40202", 7956));
	debtors.push_back(Debtor("Larry A. Miracle", DateTime("May", 22, 1998), "301-621-3318", "LarryAMiracle@jourrapide.com", "2940 Adams Avenue Columbia, MD 21044", 7150));
	debtors.push_back(Debtor("Jessica J. Stoops", DateTime("April", 22, 1989), "360-366-8101", "JessicaJStoops@dayrep.com", "2527 Terra Street Custer, WA 98240", 11805));
	debtors.push_back(Debtor("Audry M. Styles", DateTime("February", 7, 1937), "978-773-4802", "AudryMStyles@jourrapide.com", "151 Christie Way Marlboro, MA 01752", 1001));
	debtors.push_back(Debtor("Violet R. Anguiano", DateTime("November", 4, 1958), "585-340-7888", "VioletRAnguiano@dayrep.com", "1460 Walt Nuzum Farm Road Rochester, NY 14620", 9128));
	debtors.push_back(Debtor("Charles P. Segundo", DateTime("October", 21, 1970), "4157-367-3341", "CharlesPSegundo@dayrep.com", "1824 Roosevelt Street Fremont, CA 94539", 5648));
	debtors.push_back(Debtor("Paul H. Sturtz", DateTime("September", 15, 1944), "336-376-1732", "PaulHSturtz@dayrep.com", "759 Havanna Street Saxapahaw, NC 27340", 10437));
	debtors.push_back(Debtor("Doris B. King", DateTime("October", 10, 1978), "205-231-8973", "DorisBKing@rhyta.com", "3172 Bedford Street Birmingham, AL 35203", 7230));
	debtors.push_back(Debtor("Deanna J. Donofrio", DateTime("April", 16, 1983), "952-842-7576", "DeannaJDonofrio@rhyta.com", "1972 Orchard Street Bloomington, MN 55437", 515));
	debtors.push_back(Debtor("Martin S. Malinowski", DateTime("January", 17, 1992), "7657-599-3523", "MartinSMalinowski@dayrep.com", "3749 Capitol Avenue New Castle, IN 47362", 1816));
	debtors.push_back(Debtor("Melissa R. Arner", DateTime("May", 24, 1974), "530-508-7328", "MelissaRArner@armyspy.com", "922 Hill Croft Farm Road Sacramento, CA 95814", 5037));
	debtors.push_back(Debtor("Kelly G. Hoffman", DateTime("September", 22, 1969), "505-876-8935", "KellyGHoffman@armyspy.com", "4738 Chapmans Lane Grants, NM 87020", 7755));
	debtors.push_back(Debtor("Doyle B. Short", DateTime("June", 15, 1986), "989-221-4363", "DoyleBShort@teleworm.us", "124 Wood Street Saginaw, MI 48607", 11657));
	debtors.push_back(Debtor("Lorrie R. Gilmore", DateTime("December", 23, 1960), "724-306-7138", "LorrieRGilmore@teleworm.us", "74 Pine Street Pittsburgh, PA 15222", 9693));
	debtors.push_back(Debtor("Lionel A. Cook", DateTime("April", 16, 1972), "201-627-5962", "LionelACook@jourrapide.com", "29 Goldleaf Lane Red Bank, NJ 07701", 2712));
	debtors.push_back(Debtor("Charlene C. Burke", DateTime("January", 18, 1990), "484-334-9729", "CharleneCBurke@armyspy.com", "4686 Renwick Drive Philadelphia, PA 19108", 4016));
	debtors.push_back(Debtor("Tommy M. Patton", DateTime("June", 30, 1981), "774-571-6481", "TommyMPatton@rhyta.com", "748 Rockford Road Westborough, MA 01581", 349));
	debtors.push_back(Debtor("Kristin S. Bloomer", DateTime("June", 16, 1944), "4437-652-0734", "KristinSBloomer@dayrep.com", "15 Hewes Avenue Towson, MD 21204", 9824));
	debtors.push_back(Debtor("Daniel K. James", DateTime("November", 10, 1997), "801-407-4693", "DanielKJames@rhyta.com", "3052 Walton Street Salt Lake City, UT 84104", 8215));
	debtors.push_back(Debtor("Paula D. Henry", DateTime("September", 6, 1976), "618-378-5307", "PaulaDHenry@rhyta.com", "3575 Eagle Street Norris City, IL 62869", 5766));
	debtors.push_back(Debtor("Donna C. Sandoval", DateTime("December", 13, 1947), "540-482-5463", "DonnaCSandoval@rhyta.com", "675 Jehovah Drive Martinsville, VA 24112", 8363));
	debtors.push_back(Debtor("Robert T. Taylor", DateTime("August", 17, 1932), "270-596-6442", "RobertTTaylor@armyspy.com", "2812 Rowes Lane Paducah, KY 42001", 7785));

	//3 Yashi 26-dan 36-ya qeder olan borclulari cixartmag

	/*for_each(debtors.begin(), debtors.end(), [](const Debtor& d) {
		if ((2022 - d.getBirthday().year) >= 26 && (2022 - d.getBirthday().year) < 36)
			cout << d << endl;
		});*/

	// for_each(debtors.begin(), debtors.end(), AgeBetween); //Predicate
	//for_each(debtors.begin(), debtors.end(), AgeBetweenUp(20, 40)); //functor


	//4 Borcu 5000-den cox olmayan borclularic cixartmag
	/*for_each(debtors.begin(), debtors.end(), [](const Debtor& d) {
		if (d.getDebt() > 5000)
			cout << d << endl;
		});*/

	// for_each(debtors.begin(), debtors.end(), DebitMoreThan500); //Predicate 
	// for_each(debtors.begin(), debtors.end(), DebitMoreThan(7000)); //Funtor



	//5 Butov adi 18 simvoldan cox olan ve telefon nomresinde 2 ve ya 2-den cox 7 reqemi olan borclulari cixartmaq
	
	for_each(debtors.begin(), debtors.end(), [&](const Debtor& d) {
		int count = 0;
		for (size_t i = 0; i < d.getPhone().size(); i++)
		{
			if (d.getPhone()[i] == '7')
				count++;
			if (d.getFullName().size() >= 18 && count>=2) {
				cout << d << endl;
				break;
			}
		}
		
		
		});



	//7 Qishda anadan olan borclulari cixardmaq 
	for_each(debtors.begin(), debtors.end(), [](const Debtor& d) {
		if(d.getBirthday().month=="December")
			cout << d << endl;
		});

	// for_each(debtors.begin(), debtors.end(), IfInDecember); //Predicate 
	// for_each(debtors.begin(), debtors.end(), inWhichMonth("October")); //Functor

	//8 Borcu, umumi borclarin orta borcunnan cox olan borclulari cixarmaq ve evvel familyaya gore sonra ise meblegin azalmagina gore sortirovka etmek
	int sum = 0;
	for (size_t i = 0; i < debtors.size(); i++)
	{
		sum += debtors[i].getDebt();
	}
	sum /= debtors.size();

	for_each(debtors.begin(), debtors.end(), [&](const Debtor& d)
		{
			
			if (d.getDebt() > sum)
			{
				sort(debtors.begin(), debtors.end(), sortForName);
				sort(debtors.begin(), debtors.end(), sortForDebt);
				cout << d << endl;
			}
		});



	//14 Borcu en boyuk olan 5 borclunun siyahisini cixartmaq
	sort(debtors.begin(), debtors.end(), debtorDebtASC);
	for_each(debtors.begin(), debtors.begin()+=5, [](const Debtor& d) {
			cout << d << endl;
		});

	//15 Butun borcu olanlarin borcunu cemleyib umumi borcu cixartmaq
	auto sum = accumulate(debtors.begin(), debtors.end(), 0, [](double result, const Debtor& d) {
		result += d.getDebt();
		return result;
		});

	cout << "Sum: " << sum << endl;

	//16 2ci dunya muharibesin gormush borclularin siyahisi cixartmaq
	for_each(debtors.begin(), debtors.end(), [](const Debtor& d) {
		if (d.getBirthday().year >= 1939 && d.getBirthday().year < 1945)
			cout << d << endl;
		});

	// for_each(debtors.begin(), debtors.end(), IfSawSecondWorldWar);
	
}



