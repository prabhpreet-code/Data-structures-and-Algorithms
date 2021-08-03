#include<iostream>
#include<unordered_map>

using namespace std ;

// o(N)
int longestSubarraySumToK(int arr[] ,int n ,int k){
  int pre = 0 ;//cumulative sum
  int len = 0 ;//overall length
  unordered_map<int,int> m ;//to store cs and index

  for (int i = 0; i < n; i++)
  {
    pre+=arr[i] ;//cs calculation

    if (pre == k)
    {
      len = max(len , i+1) ;
    }

    //check if cs - k is present or not
    if (m.find(pre-k)!= m.end())
    {
      len=max(len,i-m[pre-k]);
    }

    //keep storing
    else{
      m[pre]=i ;
    }
    
  }

  return len ; 
}

int main(){
  int n , k , arr[10];
  cout<<"Enter the size"<<endl ;
  cin>>n ;
  cout<<"Enter the sum to K"<<endl ;
  cin>>k ;
  for (int i = 0; i < n; i++)
  {
    cin>>arr[i] ;
  }

  cout<<longestSubarraySumToK(arr , n , k) ;
  

}