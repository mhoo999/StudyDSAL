#include "SimpleHashTable.h"

int main()
{
	HashTable* HT = HashTable::SHT_CreateHashTable(193);

	HashTable::SHT_Set(HT, 418, 32114);
	HashTable::SHT_Set(HT, 9, 514);
	HashTable::SHT_Set(HT, 27, 8917);
	HashTable::SHT_Set(HT, 1031, 286);

	cout << "Key: " << 418 << ", Value: " << HashTable::SHT_Get(HT, 418) << endl;
	cout << "Key: " << 9 << ", Value: " << HashTable::SHT_Get(HT, 9) << endl;
	cout << "Key: " << 27 << ", Value: " << HashTable::SHT_Get(HT, 27) << endl;
	cout << "Key: " << 1031 << ", Value: " << HashTable::SHT_Get(HT, 1031) << endl;

	HashTable::SHT_DestroyHashTable(HT);

	return 0;
}