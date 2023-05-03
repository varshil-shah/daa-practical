#include <iostream>
#include <algorithm>
using namespace std;

class Item {
  public:
    int value, weight;
    Item(int val, int wgt) {
      this->value = val;
      this->weight = wgt;
    }
};

bool compare(Item a, Item b) {
  double r1 = (double) a.value / a.weight;
  double r2 = (double) b.value / b.weight;
  return r1 > r2;
}

double fractionalKnapsack(Item A[], int w, int n) {
  sort(A, A + n, compare);

  int currentWeight = 0;
  double finalProfit = 0.0;

  for(int i = 0; i < n; i++) {
    // If adding item won't overflow, add it completely
    if(currentWeight + A[i].weight <= w) {
      currentWeight += A[i].weight;
      finalProfit += A[i].value;
    }

    // If we can't add the product completely,
    // add fractional portion of it
    else {
      int remaining = w - currentWeight;
      finalProfit += A[i].value * ((double) remaining / A[i].weight);
      break;
    }
  }

  return finalProfit;
}

int main() {
  int weight = 15;
  Item A[] = {
    {10, 2},
    {5, 3}, {15, 5}, {7, 7},
    {6, 1}, {18, 4}, {3, 1}
  };

  int n = sizeof(A) / sizeof(Item);
  double result = fractionalKnapsack(A, weight, n);
  cout << "Max profit: " << result << endl;
  return 0;
}
