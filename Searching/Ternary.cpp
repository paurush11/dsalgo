#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int ternarysearch(int l , int r, int arr[], int k){
    while(r>=l){
        ///{0,1,2,3,4,5,6,7,8,9,10}
        ///initially l == 0, r == 10;
        /// 3 parts -
        /// {0,1,2} 3
        /// {4,5,6} 7
        /// {8,9,10)
        ///mid1 == 3 ( l + r-l/3) , mid2 = 7 ( r - (r-l)/3)

        int mid1 = l + (r-l)/3;
        int mid2 = r - (r-l)/3;
        if(arr[mid1] == k){
            return mid1;
        }else if(arr[mid2] == k){
            return mid2;
        }else if(arr[mid1]>k){
            return ternarysearch(l, mid1 -1,arr,k);
        }else if(arr[mid2]<k){
            return ternarysearch(mid2+1,r,arr,k);
        }
        return ternarysearch(mid1+1,mid2-1, arr, k);

    }
    return -1;

}



int main(){
    int a[] = {0,6,8,5,7,8,9,11,2,23,25,55,32,45};
    int n = sizeof(a)/sizeof(a[0]);
    sort(a, a+n);
    cout<<n<<endl;
    for(int i = 0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    cout<<ternarysearch(0,n,a,6);


}
