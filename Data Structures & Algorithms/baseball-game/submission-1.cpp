class Solution {
 public:
  int calPoints(vector<string>& operations) {
    std::vector<int> record{};
    for (auto& op : operations) {
      if (op == "C") {
        record.pop_back();
      } else if (op == "D") {
        record.push_back(record.back() * 2);
      } else if (op == "+") {
        record.push_back(record.back() + record[record.size() - 2]);
      } else {
        record.push_back(std::stoi(op));
      }
    }
    return std::accumulate(record.begin(), record.end(), 0);
  }
};