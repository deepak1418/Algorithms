#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<ctime>
using namespace std;

typedef  int ull;

void inputfile_generator( ull n)
{
     ofstream fout ("largeinput1.txt");
      srand(time(NULL));

   ull i,key,k;
    
   
     
    
   fout<<n<<endl;
    for(i=1;i<=n;i++){
    key = (rand()%RAND_MAX)+1;
       fout<<key<<" ";
    }
    fout<<endl;
   fout<<(rand()%(n-1))+1;
   fout<<endl;
    
   fout.close();


}

  
ull randomized_partition ( ull a[], ull beg,ull end )
{
     srand(NULL);
   ull q = beg+ rand()%(end-beg+1);
   ull j= beg-1;
   ull i,pivot=a[q];

   swap(a[q],a[end]);
for(i=beg;i<end;i++)
{
  if(a[i]<pivot)
  {
      j++;

     swap(a[i],a[j]);
  }

}
   swap(a[j+1],a[i]);

return j+1;
} 

  ull ithsmallest(ull a[] ,ull beg,ull end ,ull i)
  {
     if(beg<=end)
    {
    ull q= randomized_partition(a,beg,end);
    ull k=q-beg+1;     
      if(k==i)
      return a[q];
      else if(i<k)
      return ithsmallest(a,beg,q-1,i);
      else
      return ithsmallest(a,q+1,end,i-k);
    }

return -1;
  }


int main()
{

 ull n,a[1000000],i;
  
   inputfile_generator(50);   //  passing the size of array 
   ifstream fin ("largeinput1.txt");

 
   
   fin>>n;
    
    for(i=0;i<n;i++){
     fin>>a[i];
     }


     fin>>i;

   cout<<"\n"<<i<<" th smallest element in array is ";
   cout<<ithsmallest(a,0,n-1,i)<<"\n\n\n";


return 0;
}
