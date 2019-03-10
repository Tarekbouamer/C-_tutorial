#include<iostream>
#include<vector>

using namespace std;


int totalBoxesRemoved(vector<int> arr)
{
	int n = arr.size();
	int count = 0;
	int prev = arr[0];

	for (int i = 0; i < n; i++) {
	
		if (arr[i] > prev) {
			cout << i << "	" << prev << "	" << arr[i] << endl;
			count ++;
			arr[i] = prev;
			prev = arr[i];
			for (int j = 0; j < n; j++){ cout << "	" << arr[j]; }
			cout << endl;
			
		}
		if (arr[i] < prev) {
			cout << "		swap		"<< endl;
			prev = arr[i];
			i = -1;
		}
	}

	return count;
}

// Driver code 
int main()
{
	vector<int>  arr= { 4, 5, 5, 2, 4, 1, 10, 4};

	cout << totalBoxesRemoved(arr);
	cin.get();
	return 0;
}
