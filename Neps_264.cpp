#include <iostream>

long find(long bank, long* vecBanks);
void join(long bank1, long bank2, long* vecBanks, long* dists);

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long lenBanks, lenOp, b1, b2, *vecBanks, *dists;
  char op;

  std::cin >> lenBanks >> lenOp;

  vecBanks = new long[lenBanks], dists = new long[lenBanks]{0};

  for(long i = 0; i < lenBanks; i++)
    vecBanks[i] = i;

  for(long i = 0; i < lenOp; i++){

    std::cin >> op >> b1 >> b2;

    b1--, b2--;

    if(op == 'C'){

      if(find(b1, vecBanks) == find(b2, vecBanks))
        std::cout << "S\n";

      else
        std::cout << "N\n";

    }

    else if(op == 'F'){

      join(b1, b2, vecBanks, dists);

    }

  }

  return 0;
}

long find(long bank, long* vecBanks){

  if(vecBanks[bank] == bank)
    return bank;

  return vecBanks[bank] = find(vecBanks[bank], vecBanks);

}

void join(long bank1, long bank2, long* vecBanks, long* dists){

  long patriarca1 = find(bank1, vecBanks), patriarca2 = find(bank2, vecBanks);

  if(dists[patriarca1] < dists[patriarca2])
    vecBanks[patriarca1] = patriarca2;

  else if(dists[patriarca2] < dists[patriarca1])
    vecBanks[patriarca2] = patriarca1;

  else{

    vecBanks[patriarca1] = patriarca2;
    dists[patriarca2]++;

  }

}
