#include<iostream>
#include<vector>

using namespace std;
int main(void){
    /*
    1. 가장 큰 수부터 집합내의 세 수로 만들 수 있는지 검사
    2. 세 수의 조합으로 만들 수 있는 수가 조합내에 포함되는지 확인 -> 세 수의 조합으로 만들 수 있는 수들을 담는 백터하나 생성(시간복잡도가 n^3) 이후 이분탐색으로 포함여부 확인
    세 수를 선택하는 경우가 사간을 너무 많이 잡아먹어서 혁신적으로 세 수를 선택하는 방식(이분탐색느낌 살짝 가미된 )이 필요할듯한데 잘 안떠오르네
    */
   int n; 
   cin >> n;
   vector<int> U;
   for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        U.push_back(x);
   }
   /*
   1.문제 내말로 확실히 이해 => 가시화,수식등으로 표현
   집합내에 속한 3개의 원소의 합(같은 수를 여러번 써도가능) && 집합내에 포함된 수 두 조건을 만족시키는 수를 찾기
   2.무식한 풀이생각 => 시간복잡도 체크, 핵심파악
   -세 원소의 합으로 나올 수 있는 모든 경우를 다 구해 각각에 대해 집합내의 원소인지 판단해서 답찾기
   -집합내 가장 큰 원소에 대해 포함된 세 원소의 합으로 만들 수 있나 검사해보고 안되면 두번째로 큰수에 대해 검사하는 과정 반복
   3.핵심위주 전체 알고리즘 틀짜기(여러개가 나올 수 있음)
    핵심생각 ==> 세개를 더해서 나오는 것의 발상을 살짝 다르게 접근 -> 하나를 뺀 값이 존재하는지
    집합내의 큰 수에서 집합내 아무수나 하나 빼서 남은 수가 집합내에 포함되는지 이분탐색?이런 아이디어가 떠올랐는데 남은 수는 두 수의 합이라 이 과정을 한번더 해야하는데 그러면 시간복잡도가 넘어서서 포기함
    근데 여기서 이 과정을 쪼개서 두 수의 합을 저장해놓은 배열을 먼저 만들어 놓는다면 시간복잡도가 *이 아니라 +로 계산되어 가능한 알고리즘이 된다(이게 만약 이렇게 더 간단했다면 쉽게 풀었겠다 생각해보고 그것을 실천한 하나의 예)
   */
}
#include <bits/stdc++.h>
using namespace std;

int n;
int a[1005];
vector<int> two;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i];
  sort(a, a+n);
  for(int i = 0; i < n; i++){
    for(int j = i; j < n; j++)
      two.push_back(a[i]+a[j]);
  }
  sort(two.begin(), two.end());
  for(int i = n-1; i > 0; i--){
    for(int j = 0; j < i; j++){
      if(binary_search(two.begin(), two.end(), a[i]-a[j])){
        cout << a[i];
        return 0;
      }
    }
  }
}