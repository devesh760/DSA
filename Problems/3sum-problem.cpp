#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size()<3){
            vector<vector<int>>p(0);
            return p;
        }
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        for(int i=0;i<nums.size()-2;++i){
          if(i==0 || (i>0&& (nums[i]!=nums[i-1]))){
            int s = i+1;
            int e = nums.size()-1;
            while(s<e){
                int sum = nums[i] + nums[s] + nums[e];
                if(sum<0){
                    s++;
                }
                else if(sum>0){
                    e--;
                }
                else{
                    vector<int>p(3);
                    p[0] = nums[i];
                    p[1] = nums[s];
                    p[2] = nums[e];
                    ans.push_back(p);
                    while(s<e && (nums[s] == nums[s+1]))s++;
                    while(s<e && (nums[e] == nums[e-1]))e--;
                    s++;
                    e--;
                }
            }
          }
        }
        return ans;
    } 
int main(){
    vector<int>input_arr ={-1,0,1,2,-1,-4};
    auto output_arr = threeSum(input_arr);
    for(auto it:output_arr){
        for(auto i: it){
            cout << i << ' ';
        }
        cout << '\n';
    }
    return 0;
}
