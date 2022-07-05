// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;
// vector<int> v;
// int st, en,mid;
// int bs(int x){
//     if(en == 0) en = v.size();
//     while(en - st >= 0){
//         mid = (st + en)/2;
//         if(v[mid] < x){
//             st = mid + 1;
//         }
//         else if(v[mid] > x){
//             en = mid - 1;
//         }
//         else{
//             return 1;
//         }
//     }
//     return 0;
// }
// int main(void){
//     int n,m;
//     cin >> n;
//     int k;
//     for(int i = 0; i < n; i++){
//         cin >> k;
//         v.push_back(k); // 아니 왜 여기서 cin>>v[i]이게 안되는데?
//     }
//     sort(v.begin(), v.end());
//     cin >> m;
//     vector<int> x;
//     for(int i = 0; i < m; i++){
//         cin >> k;
//         x.push_back(k);
//     } 
//     for(int i = 0; i < m; i++){
//         cout << bs(x[i]) << endl;
//         //처음것만 잘나오고 다음 것 잘안 나올 때 전역변수 끝나고 초기화 해주는 거 빼먹음의심해보기
//         st = 0; en = v.size();
//     }
    

// }
#include <bits/stdc++.h>
using namespace std;

int a[100005];
int n;

int binarysearch(int target){
  int st = 0;
  int en = n-1;//함수 내에서만 쓸 변수는 함수내에서 선언해주기(호출할 때마다 계속 선언되더라도 전역으로 쓸 때 계속초기화 해주는 것보다 나음
  while(st <= en){
    int mid = (st+en)/2;
    if(a[mid] < target)
      st = mid+1;
    else if(a[mid] > target)
      en = mid-1;
    else
      return 1;
  }
  return 0; // st > en일 경우 while문을 탈출
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i];
  sort(a, a+n);
  int m;
  cin >> m;
  while(m--){
    int t;
    cin >> t;
    cout << BinarySearch(t) << '\n'; // 입력과 출력을 번갈아해도 상관없음
  }
}