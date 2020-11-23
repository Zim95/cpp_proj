#include <iostream>
#include <queue>


using namespace std;


int main() {
    queue<int> q;

    int n = 10;
    while (--n) {
        int no;
        cin >> no;
        q.push(no);
    }

    cout << q.front() << endl; // get front value
    cout << q.back() << endl; // get back value

    while(!q.empty()) {
        int val = q.front();
        cout << "queue value: "<< val << endl;
        q.pop();
    }

    return 0;
}
