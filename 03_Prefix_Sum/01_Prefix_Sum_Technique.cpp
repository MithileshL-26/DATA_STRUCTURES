/*      
        Find answers to Q query on a static Array A of size N:
        Find the sum of elements in the range L to R in the array.

        Naive Method:
        Traverse the array in the range L to R in each Query Q.
        Time Complexity: O(Q * N)

        Ex:        0 1 2 3 4  5   
        arr[] = {4 2 3 1 -5 6};

        Prefix sum of arr[i] = p[] = {4, 6, 9, 10, 5, 11};
        So, p[i] = p[i-1] + arr[i]      Where i >= 0

        For L = 2 and R = 4, ans = 3 + 1 + (-5) = -1 
        ans[L to R] = p[R] - p[L-1]
        p[R] = sum of elements from 0 to 4
        p[L-1] = sum of elements from 0 to 1
        [0, 4] - [0, 1] = [2, 4]

        First Pre sum Computation = O(N)
        For Every Query Q = O(1). For Q Queries = O(Q)
        Time Complexity: O(N + Q)
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
        int N;
        cout << "Enter Number of Elements: ";
        cin >> N;

        int* arr = new int[N];
        cout << "Enter " << N << "  Elements: ";
        for(int i=0; i<N; i++) cin >> arr[i];

        int queries = 0;
        cout << "Enter Number of Queries: ";
        cin >> queries;

        int* sum = new int[N];
        sum[0] = arr[0];
        for(int i=1; i<N; i++) sum[i] = sum[i-1] + arr[i];

        for(int i=0; i<queries; i++)
        {
                cout << "Enter L ans R for " << i+1 << " Query: ";
                int L = -1, R = -1;
                cin >> L >> R;

                int ans = sum[R] - sum[L-1];
                cout << ans << "\n"; 
        }
        return 0;
}
