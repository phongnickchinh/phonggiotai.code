#include<bits/stdc++.h>
using namespace std;
 
#define MAX_N 13
#define MAX_K 12
int n, K;
int onBus=0;
int visited[MAX_N*2+1];
int result[MAX_N*2+1];
int cur_dis=0;
int min_dis=1000000;
int mapp[2*MAX_N+1][2*MAX_N+1];

int minEgde=100000; // sử dụng để tối ưu thuật toán cắt tỉa dựa trên cận dưới nhỏ nhất;
 
int check(int v){
	//mỗi điểm chỉ đến 1 lần
	if(visited[v]) return 0;
	//nếu đi đón, thì xe bus phải còn chỗ
	if(v<=n){
		if(onBus>=K) return 0;
	}
	else{
		//nếu đi đưa thì phải được đón trươc đó mới đưa được:
		if(!visited[v-n]) return 0;
	}
	return 1;
}

 
//mỗi phương án là 1 dãy 2n gồm các điểm đón và điểm trả: ví dụ 2 3 5 6 1 4( đón 2 3 trả 5 6 quay lại đón 1 trả 4)
void Try(int k){
	if(k==(2*n+1)) {
		cur_dis+=mapp[result[2*n]][0];
        min_dis=min(cur_dis, min_dis);
        cur_dis-=mapp[result[2*n]][0];
		return;
	}
	for( int i=1; i<=2*n; i++){
		if(check(i)){
			result[k]=i;
			visited[i]=1;
            cur_dis+=mapp[result[k-1]][result[k]]; //cộng thêm vào tổng quãng đường hiện tại
			if(i<=n) onBus++; else onBus--;
			if((cur_dis + 2*n-k) < min_dis) Try(k+1); //ước lượng chi phí tối thiểu cần thiết đối với cả các khách hàng chưa được phục vụ +với chi phí hiện tại, nhẽ ra là minEgde*(2n-k) nma cheating 1 tí do minEgdr lúc nào cũng bằng 1.
            cur_dis-=mapp[result[k-1]][result[k]]; //backtrack
			if(i<=n) onBus--; else onBus++;
			visited[i]=0;
		}
	}
}
int main(){
	cin>>n>>K;
	result[0]=0;
	for(int i=0; i<=(2*n); i++){
		visited[i]=0;
		for(int j=0; j<=(2*n); j++){
			cin>>mapp[i][j];
            minEgde=min(minEgde, mapp[i][j]);
		}
	}
	Try(1);
	cout<<min_dis;
	// for(int i=0; i<=(2*n); i++){
	// 	cout<<result[i]<<" ";
	// }
	return 0;
}

//--> mới đạt 80% testcase.