// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;
// vector<int> v;
// int bsfx(int t){
//     int st = 0, en = v.size() - 1,mid,ret = 987654321;
//     while(st <= en){
//         mid = (st + en)/2;
//         if(v[mid] < t){
//             st = mid + 1;
//         }
//         else if(v[mid] > t){
//             en = mid - 1;
//         }
//         else{
//             // for(int i = mid; i >= st; i--){
//             //     if(v[i] == t) cnt++;
//             // }
//             // for(int i = mid + 1; i <= en; i++){
//             //     if(v[i] == t) cnt++;
//             // } => 최악의 경우 선형탐색 고로 끝까지 이진 탐색을 이용해야 -> t와 같은 숫자가 처음으로 나올 때의 idx와 마지막으로 나올 때의 idx구하기 
//             ret = mid;
//             en = mid - 1;
//         }
//     }
//     return ret;
// }
// int bsbx(int t){
//     int st = 0,en = v.size() - 1, ret = 0,mid;
//     while(st <= en){
//         mid = (st + en)/2;
//         if(v[mid] > t){
//             en = mid - 1;
//         }
//         else if(v[mid] < t){
//             st = mid + 1;
//         }
//         else{
//             ret = mid;
//             st = mid + 1;
//         }
//     }
//     return ret;
// }
// int main(void){
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     int n;
//     cin >> n;
//     for(int i = 0,x; i < n; i++){
//         cin >> x;
//         v.push_back(x);
//     }
//     sort(v.begin(), v.end());//이거 빼먹어서 해맴
//     int m;
//     cin >> m;
//     for(int i = 0,x; i < m; i++){
//         cin >> x;
//         int ret = bsbx(x) - bsfx(x);
//         int ans = ret >= 0 ? ret + 1 : 0;
//         // cout << '(' << bsfx(x) << ',' << bsbx(x) << ") ";
//         cout << ans << ' '; // 처음부터 이렇게 한번에 끝내려고 잡고 들어가서 이후 과정에서 나뉠때 많이 고민하게됨
//         //처음부터 나눠서 구한 후 그것들을 연산하여 답을 낸다고 알고리즘을 짯으면 쉽게 해결가능했음. 분기점이 있을 때 이것을 어디에 둘지도 분석대상  
//     }//모든 경우 예외까지 고려했는지 점검후에 컴파일하기
// }
#include <bits/stdc++.h>//내코드와 비교했을 때 내 코드는 값이 나오면 저장하고 넘어가서 더이상 새로 저장되는 값이 없으면 그값이 정답이기에 return하는 식의 어느정도 위에서 바라보는 느낌이였다면 이 코드는 완전 세부적인 과정 끝까지 들여다 보고 특징을 관찰해 코드로 구현했음
using namespace std;

int a[500005];
int n;

int lower_idx(int target, int len){
  int st = 0;
  int en = len;
  while(st < en){
    int mid = (st+en)/2;
    if(a[mid] >= target) en = mid;
    else st = mid+1;
  }
  return st;
}

int upper_idx(int target, int len){//마지막 인댁스보다 한칸뒤를 가리키게 설계 => 아예존재하지 않는 케이스를 걸러낼 수 있음
  int en = len;
  while(st < en){
    int mid = (st+en)/2;
    if(a[mid] > target) en = mid; // mid -1이 아닌 이유
    else st = mid+1;
  }
  return st;//범위 내에 target의 가장 왼쪽 혹은 오른쪽 인댁스값이 계속 존재하게 하게 코드를 설계했기때문에 마지막으로 st와 en이 같아 지는 값이 그 답일 수 밖에 없음
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i];
  sort(a,a+n);
  int m;
  cin >> m;
  while(m--){
    int t;
    cin >> t;
    cout << upper_idx(t,n)-lower_idx(t,n) << '\n';
  }
}

#include <bits/stdc++.h>
using namespace std;

int a[500005];
int n;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i];
  sort(a,a+n);
  int m;
  cin >> m;
  while(m--){
    int t;
    cin >> t;
    cout << upper_bound(a,a+n,t)-lower_bound(a,a+n,t) << '\n';
  }
}