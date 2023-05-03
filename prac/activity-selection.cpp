#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>

using namespace std;
using namespace std::chrono;

class Activity {
  public:
    int start;
    int finish;
};

bool compare(Activity a, Activity b) {
  return a.finish < b.finish;
}

int randomNumber(int min, int max) {
  std::random_device r;
  std::mt19937 gen(r());
  std::uniform_int_distribution<> dis(min, max);
  return dis(gen);
}
vector<Activity> generate() {
  vector<Activity> activities;
  int randoms[2];
  for(int i = 0; i < 100; i++) {
    int first = randomNumber(1, 100);
    int second = randomNumber(first, 100);
    activities.push_back({first, second});
  }

  return activities;
}

void printMaxActivities(vector<Activity> activities) {
  // sort activity based on the finish time
  sort(activities.begin(), activities.end(), compare);

  int size = activities.size();
  int i = 0, count = 0;

  cout << "Selected activities: ";
  cout << "(" << activities[i].start << ", " << activities[i].finish << ") ";
  for(int j = 1; j < size; j++) {
    if(activities[j].start >= activities[i].finish) {
      cout << "(" << activities[j].start << ", " << activities[j].finish << ") ";
      i = j;
      count++;
    }
  }

  cout << endl;
  cout << "Total selected activities = " << count << endl;
}

int main() {
  auto startTime = high_resolution_clock::now();
  vector<Activity> activities = generate();
  printMaxActivities(activities);
  auto endTime = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(endTime - startTime);
  cout << "Program took " << duration.count() << " microseconds to execute!" << endl;
}
