#include<bits/stdc++.h>
using namespace std; 
int main(){
    int t; cin >> t; 
    while(t--){
        int n; cin >> n;
        map<int, vector<int> > mp;
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            mp[x].push_back(i+1);
        }
        vector<int> res(n+1);
        for(auto x : mp){
            int elem = x.first;
            int siz = mp[elem].size();
            int tower = 1;
            //cout << x.first << ' ';
            res[elem] = 1;
            for(int y = 0; y < siz-1; y++){
                if((mp[elem][y+1]-mp[elem][y]) % 2 == 1 || mp[elem][y+1]-mp[elem][y] == 1){
                    //cout << "jin" << endl;
                    tower++;
                    res[elem] = max(res[elem], tower);
                }   
                else if(tower >= 2 && (mp[elem][y+1]-mp[elem][y]) % 2 == 0){
                    tower-=1;
                    tower++;
                    res[elem] = max(res[elem], tower);
                }
                else{
                    tower = 1;
                    //res[elem] = max(res[elem], tower);
                }          
            }
            //cout << endl;
        }
        for(int i = 1; i < n+1; i++) cout << res[i] << ' ';
        cout << endl;
    }
    return 0;
}