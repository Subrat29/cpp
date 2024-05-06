#include <bits/stdc++.h>  //unordered map 
using namespace std;

int main()
{
    // CREATION
    unordered_map<string, int> m;



    // INSERTION
    // 1
    pair<string, int> p = make_pair("babbar", 3);
    m.insert(p);

    // 2
    pair<string, int> p2("love", 2);
    m.insert(p2);

    // 3
    m["mera"] = 1;

    // Update ho jayegi key ki entry to 6, not new create bc every key corresponds single value only
    m["mera"] = 6;



    // ONE KEY PRINT
    cout << m["mera"] << endl;
    cout << m.at("mera") << endl;

    // IMP -> ONLY IF A UNKNOWN KEY: m["unknownKey"] print krte time, it creates a entry correspond to unknownkey first and enty dal dega 0
    // cout << m.at("unknownKey") << endl; // GIVES ERROR
    // cout << m["unknownKey"] << endl;

    // Now o/p is 0, 0 bc it creates a entry correspond to unknownkey first
    cout << m["unknownKey"] << endl;
    cout << m.at("unknownKey") << endl;



    // SIZE
    cout << m.size() << endl;



    // SEARCH
    cout << m.count("love") << endl;



    // ERASE
    m.erase("love");
    cout << m.size() << endl;



    // FULL MAP PRINT
    //1
    for(auto i: m)
    {
        cout << i.first << " " << i.second << endl;
    }

    //2 by iterator
    unordered_map<string, int> :: iterator it = m.begin();

    while (it != m.end())
    {
        cout << it->first << " " << it->second << endl;
        it++;
    }
    

    return 0;
}