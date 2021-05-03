#include <iostream>

struct Node{

  long leftIndex, rightIndex;

  struct Node *leftChild, *rightChild;

  int op;

  struct Node *Constructor(long* vec, long leftIndex, long rightIndex){

    struct Node *currentNode = new Node;
    long middleIndex = (rightIndex + leftIndex) / 2, result1, result2;

    currentNode->leftIndex = leftIndex;
    currentNode->rightIndex = rightIndex;

    if(rightIndex == leftIndex){

      currentNode->leftChild = NULL;
      currentNode->rightChild = NULL;

      if(vec[rightIndex] > 0)
        currentNode->op = 1;

      else if(vec[rightIndex] == 0)
        currentNode->op = 0;

      else
        currentNode->op = -1;

    }

    else{

      currentNode->leftChild = Constructor(vec, leftIndex, middleIndex);
      currentNode->rightChild = Constructor(vec, middleIndex + 1, rightIndex);

      result1 = currentNode->leftChild->op, result2 = currentNode->rightChild->op;

      if(result1 == 0 || result2 == 0)
        currentNode->op = 0;

      else if(result1 == -1 && result2 == -1)
        currentNode->op = 1;

      else if(result1 == 1 && result2 == 1)
        currentNode->op = 1;

      else
        currentNode->op = -1;

    }

    return currentNode;

  }

  int Search(struct Node *currentNode, long indexLeft, long indexRight){

    int ans1, ans2;

    if(currentNode->rightIndex < indexLeft || currentNode->leftIndex > indexRight)
      return 2;

    else if(currentNode->leftIndex >= indexLeft && currentNode->rightIndex <= indexRight)
      return currentNode->op;

    else{

      ans1 = Search(currentNode->leftChild, indexLeft, indexRight);
      ans2 = Search(currentNode->rightChild, indexLeft, indexRight);

      if(ans1 == 0 || ans2 == 0)
        return 0;

      else if(ans1 == 1 && ans2 == 1)
        return 1;

      else if(ans1 == -1 && ans2 == -1)
        return 1;

      else if(ans1 == 2)
        return ans2;

      else if(ans2 == 2)
        return ans1;

      else
        return -1;

    }

  }

  int Modify(struct Node *currentNode, long indexModify, long newValue){

    int resp1, resp2;

    if(currentNode->leftIndex > indexModify || currentNode->rightIndex < indexModify)
      return currentNode->op;

    else if(currentNode->leftIndex == indexModify && currentNode->rightIndex == indexModify){
  
      if(newValue > 0)
        currentNode->op = 1;
      
      else if(newValue == 0)
        currentNode->op = 0;

      else
        currentNode->op = -1;

      return currentNode->op;

    }

    else{

      resp1 = Modify(currentNode->leftChild, indexModify, newValue), resp2 = Modify(currentNode->rightChild, indexModify, newValue);

      if(resp1 == 0 || resp2 == 0)
        currentNode->op = 0;
      
      else if(resp1 == 1 && resp2 == 1)
        currentNode->op = 1;

      else if(resp1 == -1 && resp2 == -1)
        currentNode->op = 1;

      else
        currentNode->op = -1;

      return currentNode->op;

    }

  }

  void Destructor(struct Node *currentNode){

    if(currentNode->leftChild != NULL)
      Destructor(currentNode->leftChild);

    if(currentNode->rightChild != NULL)
      Destructor(currentNode->rightChild);

    delete currentNode->leftChild;
    delete currentNode->rightChild;

  }

};

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long lenVec, lenOp, value1, value2, result, *vec;
  struct Node *rootNode;
  char op;

  while(std::cin >> lenVec >> lenOp){

    vec = new long[lenVec];

    for(long i = 0; i < lenVec; i++)
      std::cin >> vec[i];

    rootNode = rootNode->Constructor(vec, 0, lenVec - 1);

    for(long i = 0; i < lenOp; i++){

      std::cin >> op >> value1 >> value2;

      if(op == 'C'){

        value1--;

        rootNode->Modify(rootNode, value1, value2);

      }

      else{
        
        value1--, value2--;

        result = rootNode->Search(rootNode, value1, value2);

        if(result == 1)
          std::cout << '+';
        else if(result == 0)
          std::cout << 0;
        else
          std::cout << '-';
      }

    }

    std::cout << std::endl;

    rootNode->Destructor(rootNode);
    delete rootNode;

    delete[] vec;

  }

  return 0;
}
