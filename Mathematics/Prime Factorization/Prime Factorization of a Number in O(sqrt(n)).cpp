//Prime Factorization of a Number in O(sqrt(n))
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define INF 1<<28
#define lli long long int
#define ulli unsigned long long int
#define MX 1000000000
#define SIZE 1000000
#define sfint(a) scanf("%d",&a)
#define sfllint(a) scanf("%lld",&a)
#define sfch(a) scanf("%c",&a)
#define sfchsq(a) scanf("%s",a)
#define sfint2(a,b) scanf("%d%d",&a,&b)
#define sfllint2(a,b) scanf("%lld%lld",&a,&b)
#define sfint3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define forlp0(i,n) for(int i=0;i<n;i++)
#define forlp1(i,n) for(int i=1;i<=n;i++)
#define forlp2(i,n) for(int i=2;i<=n;i++)
#define forlpa(i,a,n) for(int i=a;i<=n;i++)
#define rvforlp(i,n) for(int i=n-1;i>=0;i--)
#define rvforlp1(i,n) for(int i=n-1;i>0;i--)
#define mem(a,b) memset(a, (b), sizeof(a))
#define mem2d(a,n,m,b) memset(a, (b), sizeof(a[0][0] * n * m))
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define SZ 1000009
typedef pair<int,int> PII;
inline int gcd(int a, int b) { if (b == 0) return a; return gcd(b, a % b);}

vector<PII> primeStore;
void primeFactors(lli n){
	int count = 0;
	while(n%2 == 0){
		n/=2;
		count++;
	}
	if(count)
		primeStore.pb(mp(2,count));
	for(int i=3; i<=sqrt(n); i+=2){
		count = 0;
		while(n%i == 0){
			count++;
			n/=i;
		}
		if(count)
			primeStore.pb(mp(i,count));
	}
	if(n>2){
		primeStore.pb(mp(n,1));
	}
}

int main(){
IOS
	
	lli n;
	sfllint(n);
	primeFactors(n);
	
	forlp0(i,(int)primeStore.size()){
		cout<<primeStore[i].first<<" "<<primeStore[i].second<<endl;
	}
	
	return 0;
	
}

