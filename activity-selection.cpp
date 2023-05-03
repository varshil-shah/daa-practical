#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Activity {
  public:
    int start;
    int finish;
};

bool compareActivity(Activity a, Activity b) {
  return a.finish < b.finish;
}

int randomNumber(int min, int max) {
  return rand() % (max - min + 1) + min;
}

vector<Activity> generateActivity() {
  vector<Activity> activities;
  int randoms[2];
  for(int i = 0; i < 100; i++) {
    int firstRandomNumber = randomNumber(1, 100);
    int secondRandomNumber = randomNumber(firstRandomNumber, 100);
    activities.push_back({firstRandomNumber, secondRandomNumber});
  }

  return activities;
}

void printMaxActivities(vector<Activity> activities) {
  // sort the activited based on their finish time
  sort(activities.begin(), activities.end(), compareActivity);

  // get the size of vector & declare i variable
  int size = activities.size();
  int i = 0, count = 1;

  cout << "Selected activities: ";
  cout << "(" << activities[i].start << ", " << activities[i].finish << ") ";
  for(int j = 1; j < size; j++) {
    if(activities[j].start >= activities[i].finish) {
      i % 5 == 0 && cout << endl;
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
  vector<Activity> activities = generateActivity();
  printMaxActivities(activities);
  auto endTime = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(endTime - startTime);
  cout << "Progam took " << duration.count() << " microseconds to execute." << endl;
  return 0;
}
