#include<iostream>
#include<map>       // stl map  ---> library
                    // map will store data in "key" "value" pair,,, value maybe same but key will not
                    // map is sorted  

using namespace std;

int main()
{

    // creating a map
    map<int, string> m;

    // saving data -> SYNTAX -> m[key] = value
    m[1] = "hello";
    m[3] = "hola";

    // inserting new element
    m.insert({5, "play"});       // SYNTAX -> map_name.insert( {key, value} )

    // finding
    m.count(3);

    // erase
    m.erase(5);

    // find
    m.find(3);
}