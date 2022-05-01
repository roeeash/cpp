#include<bits/stdc++.h>
using namespace std;
//get first digit
int getFirstDigit(int a){
   while((a/10)!=0){
      a/=10;
   }
   return a;
}


string solve (vector<int> &A) {
   int n = A.size();
   int sumOdd = 0, sumEven = 0;
   int difference;
   string ans;

   for(int i=0; i<n/2;i++){
      if(i%2 ==0){
         sumEven +=getFirstDigit(A[i]);
      }
      else{
          sumOdd +=getFirstDigit(A[i]);
      }

   }

   for(int i=n/2; i<n;i++){
      if(i%2 ==0){
         sumEven +=(A[i]%10);
      }
      else{
          sumOdd +=(A[i]%10);
      }

   }
   difference = sumOdd-sumEven;
   ans = (difference == 0 || difference%11 == 0) ? "OUI":"NON";

   return ans;


}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i_A=0; i_A<N; i_A++)
    {
    	cin >> A[i_A];
    }

    string out_;
    out_ = solve(A);
    cout << out_;
}