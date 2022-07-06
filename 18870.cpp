#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// int a[1000000001];
// int main(void){
//     int n;
//     cin >> n;
//     vector<long long> v;
//     for(int i = 0; i < n; i++){
//         long long x;
//         cin >> x;
//         v.push_back(x);
//     }
//     vector<long long> copied(v);
//     sort(copied.begin(), copied.end());
//     int cnt = 0;
//     a[copied[0]] = cnt;
//     for(int i = 1; i < n; i++){
//         if(copied[i] != copied[i-1]) a[copied[i]] = ++cnt;
//     }
//     for(int i = 0; i < n; i++){
//         cout << a[v[i]] << ' ';
//     }
//     /*필연적 과정
//     전체 백터를 관찰 -> 그 중 x보다 작은 것 원소수 count(중복x) 
//     이중 for문 쓰면 시간초과 -> 다른방법 필연 sort하는 방법,안하는 방법
//     했을때 -> 해당 수를 인댁스로 하는 배열에 정답값 저장해두기(순서처리), 앞에서 부터 숫자가 달라지면 값을 1씩 증가시키도록
//     안했을때 -> 순서가 바뀌지 않기때문에 순서처리할 필요없음, 쓸 수 있는 방법이 없음.
//     */
// }
int n;
int x[1000005];
vector<int> tmp, uni; // unique
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> x[i];
    tmp.push_back(x[i]);
  }
  sort(tmp.begin(), tmp.end());
  for(int i = 0; i < n; i++){
    if(i == 0 || tmp[i-1] != tmp[i])
      uni.push_back(tmp[i]);
  }
  for(int i = 0; i < n; i++)
    cout << lower_bound(uni.begin(), uni.end(), x[i]) - uni.begin() << ' '; //lower_bound의 리턴값형태
    
// uni.erase(unique(uni.begin(), uni.end()), uni.end()); 이 코드로 배열에서 중복을 한번에 날릴 수 있음. unique가 중복된 값들을 백터 뒤로 보내면 이를 erase로 제거
}