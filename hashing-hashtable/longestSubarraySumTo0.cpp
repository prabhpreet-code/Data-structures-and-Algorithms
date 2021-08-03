#include<iostream>
#include<unordered_map>

using namespace std ;

// o(N)
int longestSubarraySumTo0(int arr[] ,int n ){
  int pre = 0 ;//cumulative sum
  int len = 0 ;//overall length
  unordered_map<int,int> m ;//to store cs and index

  for (int i = 0; i < n; i++)
  {
    pre+=arr[i] ;//cs calculation

    if (pre == 0)
    {
      len = max(len , i+1) ;
    }

    //check if cs is present or not
    if (m.find(pre)!= m.end())
    {
      len=max(len,i-m[pre]);
    }

    //keep storing
    else{
      m[pre]=i ;
    }
    
  }

  return len ; 
}

int main(){
  int n , arr[10];
  cout<<"Enter the size"<<endl ;
  cin>>n ;
  for (int i = 0; i < n; i++)
  {
    cin>>arr[i] ;
  }

  cout<<longestSubarraySumTo0(arr , n ) ;
  

}