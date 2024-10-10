#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

int getMinTime(int n, std::vector<int> &cache) {
  std::unordered_map<int, std::vector<int>> service_requests;
  for (int i = 0; i < cache.size(); ++i) {
    service_requests[cache[i]].push_back(i);
  }

  // A priority queue to store the number of requests per service
  std::priority_queue<std::pair<int, int>> pq;
  for (auto &pair : service_requests) {
    pq.push({pair.second.size(), pair.first});
  }

  int total_time = 0;
  std::vector<int> time_slots(n, 0); // time slots for each service

  while (!pq.empty()) {
    auto [count, service] = pq.top();
    pq.pop();
    for (int i = 0; i < count; ++i) {
      if (time_slots[service - 1] == 0) {
        total_time += 1; // first request takes 1 unit time
        time_slots[service - 1] += 1;
      } else {
        total_time += 2; // subsequent requests take 2 units of time
      }
    }
  }

  return total_time;
}

int main() {
  // Sample input
  int n = 3;
  std::vector<int> cache = {1, 1, 3, 1, 1};

  // Output the result
  std::cout << getMinTime(n, cache)
            << std::endl; // Output should be 1 as all requests can be processed
                          // in parallel

  // // Sample input 2
  // int n2 = 4;
  // std::vector<int> cache2 = {3, 3, 1, 4, 2, 1};

  // // Output the result
  // std::cout << getMinTime(n2, cache2) << std::endl; // Output should be 2

  return 0;
}