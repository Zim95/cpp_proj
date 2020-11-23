#include <iostream>
#include <stack>


using namespace std;


int main() {
    stack<int> st;

    int n = 10;
    while (--n) {
        int no;
        cin >> no;
        st.push(no);
    }

    cout << st.top() << endl; // get top value

    while(!st.empty()) {
        int val = st.top();
        cout << "stack value: "<< val << endl;
        st.pop();
    }

    return 0;
}
