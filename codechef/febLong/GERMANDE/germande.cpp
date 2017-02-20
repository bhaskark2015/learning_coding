
#include<iostream>
using namespace std;

int main(){
	int t;
	cin>>t;
	int CountFromBeg[1000000];
	int OneMayorsCount[1000000];
	while(t--){
		int o1,o2;
		cin>>o1>>o2;

		int n= o1 * o2;
		int count=0;
		short temp;
		for(int i=0;i<n;i++){
			cin>>temp;
			if(temp) count++;
			CountFromBeg[i]=count;
		}

		for(int i=0;i<o2;i++){
			OneMayorsCount[i]=0;
		}

		for(int beg=1,end=o2;beg<=n;beg++,end++){
			//partitionNumber
			int partitionNumber=(beg%o2);

			int CountOfOnes=0;
			if(end<n) 
				CountOfOnes= CountFromBeg[end]-CountFromBeg[beg-1];
			else
				CountOfOnes= CountFromBeg[end%n]+(CountFromBeg[n-1]-CountFromBeg[beg-1]);
			if(CountOfOnes > o2/2){
				OneMayorsCount[partitionNumber]++;
			}

		}

		short OneWins=0;
		for(int i=0;i<o2;i++){
			if(OneMayorsCount[i]> o1/2){
				OneWins=1;
			}
		}

		cout<<OneWins<<endl;

	}
	return 0;
}
