#include<iostream> 
#include<algorithm> 
#include<climits> 
#include<fstream>
using namespace std; 

typedef long long int ll;

void inputfile_generator( ll n)
{
     ofstream fout ("largeinput2.txt");
      srand(time(NULL));

   ll i,key,k;
    
   
     
    
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

  void swap(ll *a, ll *b) 
{ 
    ll temp = *a; 
    *a = *b; 
    *b = temp; 
} 
  
  
 ll partition(ll a[], ll l, ll r, ll x) 
{ 

    ll i; 
    for (i=l; i<r; i++) 
        if (a[i] == x) 
           break; 
    swap(&a[i], &a[r]); 
  
    i = l; 
    for (ll j = l; j <= r - 1; j++) 
    { 
        if (a[j] <= x) 
        { 
            swap(&a[i], &a[j]); 
            i++; 
        } 
    } 
    swap(&a[i], &a[r]); 
    return i; 
} 
   
 
ll findMedian(ll a[], ll n) 
{ 
    sort(a, a+n);   
    return a[n/2];   
} 
  
ll kthSmallest(ll a[], ll l, ll r, ll k) 
{ 
    if (k > 0 && k <= r - l + 1) 
    { 
        ll n = r-l+1; 
  
 
        ll i, median[(n+4)/5];  
        for (i=0; i<n/5; i++) 
            median[i] = findMedian(a+l+i*5, 5); 
        if (i*5 < n)  
        { 
            median[i] = findMedian(a+l+i*5, n%5);  
            i++; 
        }     
   
        ll medOfMed = (i == 1)? median[i-1]: 
                                 kthSmallest(median, 0, i-1, i/2); 
  
        ll pos = partition(a, l, r, medOfMed); 
        if (pos-l == k-1) 
            return a[pos]; 
        if (pos-l > k-1)   
            return kthSmallest(a, l, pos-1, k); 
  
        return kthSmallest(a, pos+1, r, k-pos+l-1); 
    } 
  
    return INT_MAX; 
} 
  



int main() 
{ 
    ll a[1000000];
    ll t,n,i,k;
  
inputfile_generator(3000);
 ifstream fin ("largeinput2.txt");

   fin>>n;
  
   for(i=0;i<n;i++){
     fin>>a[i];
     }

    fin>>k;
  cout <<k<<"'th smallest element is "<< kthSmallest(a, 0, n-1, k);
  cout<<endl<<endl; 

    return 0; 
} 
