#include <iostream>
#include <map>

using namespace std;

int main () {
    
    char codi;
    string paraula;
    
    map <string, int> d;
    
    while (cin >> codi) {
        cin >> paraula;
        map<string,int>::const_iterator it = d.find(paraula);

        if (codi == 'a') {
            if (it == d.end()) d.insert(make_pair(paraula, 1));
            else ++d[paraula];
        }
        
        else if (codi == 'f') {
            if (it == d.end()) cout << 0 << endl;
            else cout << it -> second << endl;
        }
    }
}
