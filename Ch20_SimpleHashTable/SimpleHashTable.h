#pragma once

#include <iostream>
using namespace std;

using KeyType = int;
using ValueType = int;

typedef struct Node
{
	KeyType Key;
	ValueType Value;
};

class HashTable
{
	int TableSize;
	Node* Table;
public:
	static HashTable* SHT_CreateHashTable(int TableSize);
	static void SHT_Set(HashTable* HT, KeyType Key, ValueType Value);
	static ValueType SHT_Get(HashTable* HT, KeyType Key);
	static void SHT_DestroyHashTable(HashTable* HT);
	static int SHT_Hash(KeyType Key, int TableSize);
};