//{ Driver Code Starts
// Program to find best buying and selling days
#include <bits/stdc++.h>

using namespace std;

// This function finds the buy sell schedule for maximum profit
void stockBuySell(int *, int);

// Driver program to test above functions
int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, i;
        cin >> n;
        int price[n];
        for (i = 0; i < n; i++) cin >> price[i];
        // function call
        stockBuySell(price, n);
    }
    return 0;
}

// } Driver Code Ends


// User function template for C++

// This function finds the buy sell schedule for maximum profit
void stockBuySell(int price[], int n) {
    bool found=false;
    int max=price[0], min=price[0], maxIndex=0, minIndex=0;
    for(int i=1;i<n;i++)
    {
        if(price[i]>max)
        {
            max=price[i];
            maxIndex=i;
        }
        else if(price[i]<max)
        {
            if(max!=min)
            {
                found =true;
                cout<<"("<<minIndex<<" "<<maxIndex<<")"<<" ";
            }
            min=price[i];
            minIndex=i;
            maxIndex=i;
            max=price[i];
        }
        
    }
    if(max>min)
        {
            cout<<"("<<minIndex<<" "<<maxIndex<<")";
            found =true;
        }
        if(!found)
        {
            cout<<"No Profit";
        }
        cout<<endl;
}