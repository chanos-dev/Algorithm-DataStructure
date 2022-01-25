#include<bits/stdc++.h>
using namespace std;

struct Room
{
    string Name;
    vector<Room*> SubRooms;
    Room() {}
    Room(string n) : Name(n) {}
};

bool compare(Room* a, Room* b)
{
    return a->Name < b->Name;
}

void print(int k, Room* rs)
{
    sort(rs->SubRooms.begin(), rs->SubRooms.end(), compare);
    for(Room* r : rs->SubRooms)
    {
        for(int i=0; i<k; i++)
            cout<<"--";
        cout<<r->Name<<"\n";

        if (r->SubRooms.size() > 0)
            print(k+1, r);
    }
}

int main()
{
    int n; cin>>n;
    Room* enter = new Room("enter");

    for(int i=0; i<n; i++)
    {
        int k; cin>>k;

        Room* cur = enter;
        
        for(int j=0; j<k; j++)
        {
            string s; cin>>s;    
            Room* r = new Room(s);
            
            bool isfind = false;

            for(Room* dr : cur->SubRooms)
            {
                if (dr->Name == r->Name)
                {
                    cur = dr;
                    isfind = true;
                }
            }

            if (isfind) continue;

            cur->SubRooms.push_back(r);
            cur = r;
        }
    }

    print(0, enter);
}