#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;

typedef  int ll;

  
ll randomized_partition ( ll a[], ll beg,ll end )
{
     srand(NULL);
   ll q = beg+ rand()%(end-beg+1);
   ll j= beg-1;
   ll i,pivot=a[q];

   swap(a[q],a[end]);
for(i=beg;i<end;i++)
{
  if(a[i]<pivot){
      j++;

     swap(a[i],a[j]);
      }

}
   swap(a[j+1],a[i]);

return j+1;
} 

  ll ithsmallest(ll a[] ,ll beg,ll end ,ll i)
  {
     if(beg<=end)
    {
    ll q= randomized_partition(a,beg,end);
    ll k=q-beg+1;     
      if(k==i)
      return a[q];
      else if(i<k)
      return ithsmallest(a,beg,q-1,i);
      else
      return ithsmallest(a,q+1,end,i-k);
    }

return -1;
  }


int main( int argc ,char *argv[])
{

 ll n,a[1000000],i,t;
  
 ifstream fin ("input.txt");
 fin>>t;
 
while(t--)
{
   fin>>n;
  
   for(i=0;i<n;i++){
     fin>>a[i];
     }


   fin>>i;

   cout<<"\n"<<i<<" th smallest element in array is ";
   cout<<ithsmallest(a,0,n-1,i)<<"\n\n\n";
}

return 0;
}
