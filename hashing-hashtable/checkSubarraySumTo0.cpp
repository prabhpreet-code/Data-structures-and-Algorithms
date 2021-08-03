#include<iostream>
#include<unordered_set>

using namespace std ;

// o(N)
bool longestSubarraySumTo0(int arr[] ,int n ){
  int pre = 0 ;//cumulative sum
  int len = 0 ;//overall length
  unordered_set<int> m ;//to store cs

  for (int i = 0; i < n; i++)
  {
    pre+=arr[i] ;//cs calculation

    if (pre == 0 || m.find(pre)!= m.end())
    {
      return true ;
    }

      m.insert(pre) ;
    
  }

  return false ; 
}

int main(){
  int n , arr[10];
  cout<<"Enter the size"<<endl ;
  cin>>n ;
  for (int i = 0; i < n; i++)
  {
    cin>>arr[i] ;
  }

  if(longestSubarraySumTo0(arr , n )){
    cout<<"present";
  } 

  else{
    cout<<"not present";
  }
  

}