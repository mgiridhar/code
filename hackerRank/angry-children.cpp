#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;


// It is NOT mandatory to use the provided template. You can handle the IO section differently.

int main() {
    /* The code required to enter n,k, candies is provided*/

    unsigned long long int N, K, unfairness=INT_MAX,i,j;
    cin >> N >> K;
    unsigned long long int candies[N];
    for (i=0; i<N; i++)
        cin >> candies[i];
    
    sort(candies,candies+N);
    
    i=0;
    j=K-1;
    while(i<=(N-K))
    {
	if((candies[j]-candies[i]) < unfairness)
		unfairness = candies[j] - candies[i];
	i++;
	j++;
    }
    /** Write the solution code here. Compute the result, store in  the variable unfairness --
    and output it**/
    cout << unfairness << "\n";
    return 0;
}
		
