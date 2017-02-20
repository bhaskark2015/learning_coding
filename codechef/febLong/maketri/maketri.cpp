
#include <iostream>
#include <algorithm>
#include <climits>
#include <set>
#include <utility>
#include <algorithm>
using namespace std;

int main() {
	// your code goes here
	int n;
	cin>>n;
	long long unsigned l,r;
	cin>>l>>r;
	long long unsigned *arr= new long long unsigned[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];	
	}

	
	//sorting the input
	sort(arr,arr+n);
	
	
	set < pair< long long unsigned , long long unsigned > > S;

	//finding lower bound
	for(int i=1;i<n;i++){
		long long unsigned lower_bound=arr[i]-arr[i-1]+1;
		long long unsigned upper_bound=arr[i]+arr[i-1]-1;
		S.insert(make_pair(lower_bound,upper_bound));
	}
	
// cout<<"Before union algorithm:"<<endl;
// for(set < pair< long long unsigned , long long unsigned > >::iterator it= S.begin(); it != S.end();it++){
// 					cout<<"pairs first element is :"<<it->first<<" and second element is :"<<it->second<<endl;

// 		}

	set < pair< long long unsigned , long long unsigned > >::iterator next;
	for(set < pair< long long unsigned , long long unsigned > >::iterator it= S.begin(); it != S.end();it++){

		//cout<<"pairs first element is :"<<it->first<<" and second element is :"<<it->second<<endl;
		long long unsigned lower_bound= it->first;
		long long unsigned upper_bound= it->second;
		next= it;
		next++;
		while(next != S.end() && it->second >= next->first ){
			if(next->second > upper_bound)
				upper_bound= next->second;
			S.erase(it);
			it=next;
			next++;
		}
		
		S.erase(it);
		S.insert(make_pair(lower_bound,upper_bound));
	}

// cout<<"After union algorithm"<<endl;
// 		for(set < pair< long long unsigned , long long unsigned > >::iterator it= S.begin(); it != S.end();it++){
// 					cout<<"pairs first element is :"<<it->first<<" and second element is :"<<it->second<<endl;

// 		}

	long long unsigned ans=0;

	for(set < pair< long long unsigned , long long unsigned > >::iterator it= S.begin(); it != S.end();it++){
		long long unsigned lower_bound=it->first;
		long long unsigned upper_bound=it->second;
		if(lower_bound > r || upper_bound < l){
			break;
		}
		else if(lower_bound >= l){
			if(upper_bound <=r){
			   ans+= (upper_bound-lower_bound+1);			
			}
			else{
			   ans+= (r-lower_bound+1);
			   break;
			}
		}
		else {
			if(upper_bound<=r){
			   ans+=(upper_bound-l+1);
			}
			else{
			   ans+=(r-l+1);
			   break;
			}
		}
	}

	cout<<ans;
	return 0;
}