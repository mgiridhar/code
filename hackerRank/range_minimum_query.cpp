#include<iostream>
#include<algorithm>
#include<limits>
using namespace std;

void build_seg_tree(long int arr[], long int seg_tree[], unsigned long int low, unsigned long int high, unsigned long int pos)
{
	if(low > high)
		return;
	if(low == high)
	{
		seg_tree[pos] = arr[low];
		return;
	}
	unsigned long int mid = low + ((high - low)/2);
	build_seg_tree(arr, seg_tree, low, mid, 2*pos + 1);
	build_seg_tree(arr, seg_tree, mid+1, high, 2*pos + 2);
	seg_tree[pos] = min(seg_tree[2*pos + 1], seg_tree[2*pos + 2]);
}

long int range_query(long int arr[], long int seg_tree[], unsigned long int range_low, unsigned long int range_high, unsigned long int low, unsigned long int high, unsigned long int pos)
{
	if(low > high || range_low > range_high)
		return LONG_MAX;
	if(low > range_high || high < range_low)
		return LONG_MAX;
	else if(low >= range_low && high <= range_high)
		return seg_tree[pos];
	else
	{
		unsigned long int mid = low + ((high-low)/2);
		long int left_min = range_query(arr, seg_tree, range_low, range_high, low, mid, 2*pos + 1);
		long int right_min = range_query(arr, seg_tree, range_low, range_high, mid+1, high, 2*pos + 2);
		return min(left_min, right_min);
	}
}

int main()
{
	unsigned long int n,m, pow2, range_low, range_high;
	cin >> n >> m;
	long int arr[n];
	for(unsigned long int i = 0; i<n; i++)
		cin >> arr[i];
	if((n&(n-1)) == 0)
		pow2 = n;
	else
	{
		pow2 = (n&(n-1)) << 1;
	}
	long int seg_tree[2*pow2-1];
	for(unsigned long int i = 0; i<(2*pow2-1); i++)
		seg_tree[i] = LONG_MAX;
	build_seg_tree(arr, seg_tree, 0, n-1, 0);
	
	/*
	for(unsigned long int i = 0; i<(2*pow2-1); i++)
		cout << seg_tree[i] << " ";
	*/

	for(unsigned long int q=0; q<m; q++)
	{
		cin >> range_low >> range_high;
		cout << range_query(arr, seg_tree, range_low, range_high,  0, n-1, 0) << endl;
	}
	return 0;
}
