#include <iostream>
#include <deque>

bool flagResult;
int totalTestes;
int lenStr;
char currentChr;
std::string result = "NS";
std::string input;
std::deque <char> stackStr;

int main(){
  
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> totalTestes;

  for(int i = 0; i < totalTestes; i++){

    flagResult = 1;

    std::cin >> input;
    lenStr = input.length();

    for(int j = 0; j < lenStr; j++){

      currentChr = input[j];

      if(currentChr == ']'){

        if(!stackStr.empty() && stackStr.back() == '[')
          stackStr.pop_back();

        else{
          
          stackStr.push_back(currentChr);
          flagResult = 0;

        }

      }
      
      else if(currentChr == ')'){

        if(!stackStr.empty() && stackStr.back() == '(')
          stackStr.pop_back();

        else{
          
          stackStr.push_back(currentChr);
          flagResult = 0;

        }
      }

      else if(currentChr == '}'){

        if(!stackStr.empty() && stackStr.back() == '{')
          stackStr.pop_back();

        else{
          
          stackStr.push_back(currentChr);
          flagResult = 0;

        }

      }

      else
        stackStr.push_back(currentChr);

    }
    
    if(!stackStr.empty())
      flagResult = 0;

    stackStr.clear();

    std::cout << result[flagResult] << '\n';

  }

  return 0;
}
