#include "stdafx.h"
#include <algorithm>
#include <iostream>
using namespace std;

int getRandomCharacter(int n) {
	return rand() % n;
}

int main()
{
	srand(3);
	int n = 30;
	int x = 18;
	int x_index = 0;
	bool success = false;
	int* S = new int[n];
	for (int i = 0; i < n; i++) {
		S[i] = getRandomCharacter(n);
		cout << S[i] << " ";
	}cout << endl;

	std::sort(S, S+n); // this is O(n log n)
	for (int i = 0; i < n; i++) {
		cout << S[i] << " ";
		if (i < x) { x_index = i; }
	}cout <<"x_i=" << x_index << endl;

	// see if 2 numbers add to x - this will be in linear time O(n)
	for (int i = 0, l = 0, h = x_index-1; (i < x_index) && (l < h); i++) {
		if (S[l] + S[h] == x) {
			success = true;
			cout << S[l] << " + " << S[h] << " = " << x << endl;
			break;
		}
		else if (S[l] + S[h] < x) {
			l++;
		}
		else {
			h--;
		}
	}
	if (success) {
		cout << "2 numbers found" << endl;
	}
	else {
		cout << "2 numbers not found" << endl;
	}

    return 0;
}

