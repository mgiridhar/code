/*
 * Given A, a sorted int array of length n. How many times does the value x occur in A.
 *
 * Algorithm more efficient that linear scan?
 */
int binary_search(vector<int> A, int low, int high, int x) {
	if(low > high)
		return 0;
	if(low == high)
		return (A[low] == x) ? 1 : 0;
	
	int mid = low + (high - low)/2 ;
	if(A[mid] == x) {
		return 1 + binary_search(A, low, mid-1, x) + binary_search(A, mid+1, high, x);
	}
	else if(A[mid] > x) {
		return binary_search(A, low, mid-1, x);
	}
	else if(A[mid] < x) {
		return binary_search(A, mid+1, high, x);
	}
}
