#include <bits/stdc++.h>
#include<iostream>
#include <iomanip>
#include <sstream>

using namespace std;

class MedianFinder
{
    priority_queue<int>leftMaxHeap;
    priority_queue<int,vector<int>,greater<int>>rightMinHeap;

public:
    MedianFinder()
    {

    }
    void addNum(int value)
    {
        if(leftMaxHeap.empty() || value<=leftMaxHeap.top())
            leftMaxHeap.push(value);
        else
            rightMinHeap.push(value);

        if(leftMaxHeap.size()>rightMinHeap.size()+1)
        {
            rightMinHeap.push(leftMaxHeap.top());
            leftMaxHeap.pop();
        }
        else if(leftMaxHeap.size()<rightMinHeap.size())
        {
            leftMaxHeap.push(rightMinHeap.top());
            rightMinHeap.pop();
        }


    }
    double findMedian()
    {
        if(leftMaxHeap.size() == rightMinHeap.size())
        {
            return (leftMaxHeap.top() + rightMinHeap.top()) / 2.0;
        }
        else 
            return leftMaxHeap.top();
    }


};

int main() {
    // Example input (from LeetCode)
    vector<string> commands = {"MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"};
    vector<vector<int>> values = {{}, {1}, {2}, {}, {3}, {}};

    vector<string> output;
    MedianFinder* obj = nullptr;  // class assumed to be defined elsewhere

    for (int i = 0; i < commands.size(); i++) {
        if (commands[i] == "MedianFinder") {
            obj = new MedianFinder();
            output.push_back("null");
        } else if (commands[i] == "addNum") {
            obj->addNum(values[i][0]);
            output.push_back("null");
        } else if (commands[i] == "findMedian") {
            double res = obj->findMedian();
            // format output like LeetCode
            ostringstream ss;
            ss << fixed << setprecision(5) << res;
            string s = ss.str();
            while (s.find('.') != string::npos && (s.back() == '0' || s.back() == '.')) {
                if (s.back() == '.') { s.pop_back(); break; }
                s.pop_back();
            }
            output.push_back(s);
        }
    }

    // Print result in LeetCode format
    cout << "[";
    for (int i = 0; i < output.size(); i++) {
        if (i) cout << ", ";
        if (output[i] == "null") cout << "null";
        else cout << output[i];
    }
    cout << "]" << endl;

    delete obj;
    return 0;
}
