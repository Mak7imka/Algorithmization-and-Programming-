#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Interval {
    int start, end;
};

bool compareByEnd(const Interval& a, const Interval& b) {
    return a.end < b.end;
}

int main() {
    vector<Interval> intervals = {
        {6, 7}, {3, 6}, {1, 3}, {3, 5}, {2, 6},
        {1, 5}, {5, 6}, {4, 7}, {2, 3}
    };
    cout << "Початкові заявки:\n";
    for (const auto& i : intervals)
        cout << "[" << i.start << "; " << i.end << "]";

    sort(intervals.begin(), intervals.end(), compareByEnd);

    vector<Interval> selected;
    int current_end = -1;

    for (const Interval& interval : intervals) {
        if (interval.start >= current_end) {
            selected.push_back(interval);
            current_end = interval.end;
        }
    }

    cout << "\n\nОбрані заявки:\n";
    for (const Interval& i : selected)
        cout << "[" << i.start << "; " << i.end << "] ";
    cout << endl;

    return 0;
}
