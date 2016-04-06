#include "../lib/hash_table.h"

using namespace std;

void insertThese(HashTable& table);

int main(int argc, char const *argv[])
{
	cout << "<=====================>\n";
	cout << "Hash Table Test Program\n";
	cout << "<=====================>\n\n";

	HashTable myTable;

	// test insert
	insertThese(myTable);
	// test remove
	myTable.remove("osaifois");
	myTable.remove("aaaaaaa");
	// test find
	cout << "\nFound " << myTable.find("a") << std::endl;
	// cout << "\nFound " << myTable.find("osaifois") << std::endl;
	// test update
	cout << "\nTest Update/[] - ca - " << myTable["ca"] << endl;
	myTable.update(make_pair("ca", 99));
	cout << "\nTest Update/[] - ca - " << myTable["ca"] << endl;

	myTable.print();

	return 0;
}

void insertThese(HashTable& table) {
	table.add(make_pair("a",11));

	table.add(make_pair("ca",21));
	table.add(make_pair("CY",22));

	table.add(make_pair("ADk",31));
	table.add(make_pair("weI",32));
	table.add(make_pair("ADl",33));

	table.add(make_pair("IANl",41));
	table.add(make_pair("aytu",42));
	table.add(make_pair("akit",43));
	table.add(make_pair("akit",44));

	table.add(make_pair("Hello",51));
	table.add(make_pair("adoit",52));
	table.add(make_pair("authu",53));
	table.add(make_pair("akjia",54));
	table.add(make_pair("llial",55));

	table.add(make_pair("atnuru",61));
	table.add(make_pair("adoafa",62));
	table.add(make_pair("fsdija",63));
	table.add(make_pair("safnjs",64));
	table.add(make_pair("asfioj",65));
	table.add(make_pair("safnla",66));

	table.add(make_pair("asfoijs",71));
	table.add(make_pair("asfoima",72));
	table.add(make_pair("qwoirur",73));
	table.add(make_pair("bfojsfg",74));
	table.add(make_pair("avjofas",75));
	table.add(make_pair("djoasaa",76));
	table.add(make_pair("aaaaaaa",77));

	table.add(make_pair("asfsjfaj",81));
	table.add(make_pair("cccccccc",82));
	table.add(make_pair("asfjasfo",83));
	table.add(make_pair("osaifois",84));
	table.add(make_pair("uhsansag",85));
	table.add(make_pair("asfjksaf",86));
	table.add(make_pair("zxvjxzvz",87));
	table.add(make_pair("zzzzzzzz",88));
}


// cout << "<=================>\n";
// cout << "Enumerator Function\n";
// cout << "<=================>\n";
// char alphabet[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
// int convertedVals[26] = {-2};
// for (int i = 0; i < 26; ++i) {
// 	// convertedVals[i] = enumerateChar(alphabet[i]);
// 	cout << alphabet[i] << " - " << enumerateChar(alphabet[i]) << endl;
// }