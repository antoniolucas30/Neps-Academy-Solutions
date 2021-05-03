#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    bool v;
    string a;
    stack<char> cha;

    cin >> n;
	  cin.ignore();

    v=true;
    for(int i=0;i<n;i++){
        getline(cin, a);
        if(a==""){
            continue;
        }
		
		    int tam = a.length();
		
        for(int k=0;k<tam;k++){
            if(a[k]=='{'){
                cha.push('{');
            }
            else if(a[k]=='}'){
                if(cha.empty()){
                    v=false;
                    break;
                }
                else{
                    cha.pop();
                }
            }
        }
        if(!v){
            break;
        }
    }
    if(!cha.empty()){
        v=false;
    }
    if(v){
        cout << 'S' << endl;
    }
    else{
        cout << 'N' << endl;
    }
}
