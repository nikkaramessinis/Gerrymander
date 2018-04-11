/*
Starting from first place until div_per_state(divisions per state) and 
counting if ones are more than the half of the division incrementing by one 
*/



#include <stdio.h>
#include <iostream>

using namespace std;
int main() {
	int testcases,states,div_per_state,vote;
	cin >>testcases;
	while (testcases--) {
		cin >> states >> div_per_state;
		int *votes = new int[states*div_per_state];
		int *sum = new int[states*div_per_state];
		int i = 0;
		while (i < (states*div_per_state))
		{

			cin >> vote;
			votes[i] = vote;
			i++;
		}

		i = 0;
		while (i < states*div_per_state) {
			if (i == 0) { sum[i] = votes[i]; }
			else { sum[i] = sum[i - 1] + votes[i]; }i++;
		}
		int counter = 0;


		for (int j = 0; j < div_per_state; j++)
		{
			counter = 0;
			
			for (int k = 0; k < states; k++) {
				int div = (j + div_per_state - 1 + div_per_state * k) / (states*div_per_state);
				int mod = (j + div_per_state-1 + div_per_state * k )% (states*div_per_state);
				int first = j - 1 + div_per_state * k;
				//if you are in place 0 count from array sum last place
				if (first < 0) {
					if (sum[mod] > (div_per_state /2))counter += 1;
				}
				// if you are surpassing end and starting from beggining count from j - 1 + div_per_state * k till end and aggregate first places
				else if (div>0) {
					int subsum = sum[states*div_per_state - 1] - sum[j - 1 + div_per_state * k];
					subsum += sum[mod];
					if (subsum > div_per_state / 2)counter += 1;
				}else {// else from division end minus division start
					if (sum[mod]-sum[j - 1 + div_per_state * k] > div_per_state /2)counter += 1;
				}
			}
			if (counter > states / 2) { break; }
		}
		if (counter > states/2) {cout<< 1 << endl; }
		else { cout<< 0 << endl; }
		delete[] votes;
	}
}