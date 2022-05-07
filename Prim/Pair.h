#pragma once
#include <string>

using namespace std;


class Pair {
private:
	int priority;
	int value;
	int index;

public:
	Pair(int p, int v);
	int getPriority();
	int getValue();
	void setPri(int p) { priority = p; }
	void setValue(int v) { value = v; }
	int getIndex() { return index; }
	void setIndex(int i) { index = i; }
};