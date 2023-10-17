#include "SimpleHashTable.h"

HashTable* HashTable::SHT_CreateHashTable(int TableSize)
{
	HashTable* HT = new HashTable;

	HT->Table = new Node[TableSize];
	HT->TableSize = TableSize;

	return HT;
}

void HashTable::SHT_Set(HashTable* HT, KeyType Key, ValueType Value)
{
	int Address = SHT_Hash(Key, HT->TableSize);

	HT->Table[Address].Key = Key;
	HT->Table[Address].Value = Value;
}

ValueType HashTable::SHT_Get(HashTable* HT, KeyType Key)
{
	int Address = SHT_Hash(Key, HT->TableSize);

	return HT->Table[Address].Value;
}

void HashTable::SHT_DestroyHashTable(HashTable* HT)
{
	delete[] HT->Table;
	delete HT;
}

int HashTable::SHT_Hash(KeyType Key, int TableSize)
{
	return Key % TableSize;
}