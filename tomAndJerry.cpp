//problem statement: https://practice.geeksforgeeks.org/problems/tom-and-jerry/0
//Since very long time Tom and Jerry have been fighting with each other for a piece of Cheese. So finally you came to rescue and decided that the result of the fight will be decided by a mathematical game ,
// in which you will write a number N . Tom and Jerry will play the game alternatively and each of them would subtract a number n [n< N] such that N%n=0. 
//The game is repeated turn by turn until the one,who now cannot make a further move looses the game. 
//The game begins with Tom playing first move.It is well understood that both of them will make moves in optimal way.You are to determine who wins the game.

#include<bits/stdc++.h>

using namespace std;

// bool prime[1000000]={1};
// void findPrime(){
//     for(long i=2; i*i<=1000000; i++){
//         if(prime[i]){
//             for(long j=i*i; j<1000000; j+=i){
//                 prime[j]=0;
//             }
//         }
//     }
// }

int main(){
    int t;
    cin>>t;
    long n;
    while(t--){
        cin>>n;
        if(n%2==0) cout<<"1"<<endl;
        else cout<<"0"<<endl;
    }

    return 0;
}
