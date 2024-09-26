/*

729. My Calendar I


You are implementing a program to use as your calendar. We can add a new event if adding the event will not cause a double booking.
A double booking happens when two events have some non-empty intersection (i.e., some moment is common to both events.).
The event can be represented as a pair of integers start and end that represents a booking on the half-open interval [start, end), the range of real numbers x such that start <= x < end.
Implement the MyCalendar class:
MyCalendar() Initializes the calendar object.
boolean book(int start, int end) Returns true if the event can be added to the calendar successfully without causing a double booking. Otherwise, return false and do not add the event to the calendar.


Example 1:
Input
["MyCalendar", "book", "book", "book"]
[[], [10, 20], [15, 25], [20, 30]]
Output
[null, true, false, true]
Explanation
MyCalendar myCalendar = new MyCalendar();
myCalendar.book(10, 20); // return True
myCalendar.book(15, 25); // return False, It can not be booked because time 15 is already booked by another event.
myCalendar.book(20, 30); // return True, The event can be booked, as the first event takes every time less than 20, but not including 20.


Constraints:
0 <= start < end <= 109
At most 1000 calls will be made to book.


*/

// SOURCE CODE

// BRUTE FORCE - UNORDERED_MAP (TLE)

class MyCalendar
{
public:
    unordered_set<int> dates;

    MyCalendar()
    {
    }

    bool book(int start, int end)
    {
        unordered_set<int> booking;
        for (int i = start; i < end; i++)
        {
            if (dates.count(i) > 0)
            {
                return false;
            }
            booking.insert(i);
        }
        for (auto x : booking)
        {
            dates.insert(x);
        }
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

// BRUTE FORCE - PAIR

class MyCalendar
{
public:
    vector<pair<int, int>> dataRange;

    MyCalendar()
    {
    }

    bool book(int start, int end)
    {
        for (auto const &date : dataRange)
        {
            int prevStart = date.first;
            int prevEnd = date.second;
            if (start < prevEnd && end > prevStart)
                return false;
        }
        dataRange.push_back(make_pair(start, end));
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

// OPTIMIZE - BINARY SEARCH

class MyCalendar
{
public:
    map<int, int> intervals;

    MyCalendar()
    {
    }

    bool book(int start, int end)
    {
        auto next = intervals.lower_bound(start);
        if (next != intervals.end() && next->first < end)
        {
            return false;
        }
        if (next != intervals.begin() && prev(next)->second > start)
        {
            return false;
        }
        intervals[start] = end;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */