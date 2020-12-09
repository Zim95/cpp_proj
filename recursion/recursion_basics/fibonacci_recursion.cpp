#include<iostream>
#include<map>

using namespace std;

map<int, int> cache;

int get_key(map<int, int> m, int key) {
    return (m.find(key)!=m.end())?m[key]:0;
};


int fibonacci(int n) {
    if(n==0) {
        return 0;
    }
    if(n==1) {
        return 1;
    }
    int cached_result = get_key(cache, n);
    if(cached_result) {
        return cached_result;
    }
    int result = fibonacci(n-1) + fibonacci(n-2);
    cache.insert(make_pair(n, result));
    return result;
}


int main() {
    int n;
    cin>>n;
    cout << n << "th term = " << fibonacci(n) << endl; 
    return 0;
}