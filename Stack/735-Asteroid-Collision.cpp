class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> list;
        int n=asteroids.size();
        for(int i=0;i<n;i++){
             if(asteroids[i]>=0){
                    list.push_back(asteroids[i]);
                
            }
            else{
               while(!list.empty() && list.back()>=0 && list.back()< abs(asteroids[i])){
                    list.pop_back();
                }
                if(!list.empty() && list.back()== abs(asteroids[i]))
                    list.pop_back();
                else if(list.empty() || list.back()<0)
                        list.push_back(asteroids[i]);
                
            }
        }
        return list;
    }
};