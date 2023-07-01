#include <bits/stdc++.h>
using namespace std;
const int MAXSZ=1e5+5;
const int SQRT = 320;

int arr[MAXSZ];

struct Query{
    int L, R, I;
};

bool compare(Query x, Query y){

	if (x.L/SQRT != y.L/SQRT)
		return x.L/SQRT < y.L/SQRT;

	
	return x.R < y.R;
}

void queryResults(int a[], int n, Query q[], int m)
{

	sort(q, q + m, compare);


	int currL = 0, currR = 0;
	int currSum = 0;
    int ans[MAXSZ];
    int freq[MAXSZ];
    memset(freq, 0, sizeof(freq));


	for (int i=0; i<m; i++)
	{
		
		int L = q[i].L, R = q[i].R;

		while (currL < L)
		{
            freq[a[currL]]--;
            if (freq[a[currL]] > 0 && freq[a[currL]] %2==0){
                currSum++;
            }
            else if (freq[a[currL]] >= 1 && freq[a[currL]]%2 == 1){
                currSum--;
            }
		
			currL++;
		}


		while (currL > L)
		{
            freq[a[currL-1]]++;
            if (freq[a[currL-1]] > 0 && freq[a[currL-1]] %2==0){
                currSum++;
            }
            else if (freq[a[currL-1]] > 1 && freq[a[currL-1]] %2 == 1){
                currSum--;
            }
	
			currL--;
		}
		while (currR <= R)
		{
			freq[a[currR]]++;
            if (freq[a[currR]] > 0 && freq[a[currR]] %2==0){
                currSum++;
            }
            else if (freq[a[currR]] > 1 && freq[a[currR]] %2 == 1){
                currSum--;
            }
			currR++;
		}

		while (currR > R+1)
		{
			
            freq[a[currR-1]]--;
            if (freq[a[currR-1]] > 0 && freq[a[currR-1]] %2==0){
                currSum++;
            }
            else if (freq[a[currR-1]] >= 1 && freq[a[currR-1]] %2 == 1){
                currSum--;
            }
			currR--;
		}
        ans[q[i].I] = currSum;

	}
    for (int i=0; i<m; i++){
        cout << ans[i] << "\n";
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    // cout << sizeof(freq)+sizeof(arr)+sizeof(queries);

    for (int i=0; i<n; i++) cin >> arr[i];

    int q; cin >> q;
    Query queries[q];

    for (int i=0; i<q; i++){
        int a, b; cin >> a >> b;
        a--; b--;
        queries[i].L=a; queries[i].R=b; queries[i].I=i;
    }

    queryResults(arr, n, queries, q);
}