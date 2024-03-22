#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;
    
    for(int i=0;i<balls.size();i++){
        int tmp = 0;
        int ans = 100000000;
        int tmp_x = balls[i][0], tmp_y = balls[i][1];
        int distX, distY;
        // cout<<tmp_x<<' '<<tmp_y<<'\n';
        // 1번
        if(!(tmp_y == startY && tmp_x < startX)){
            distX = abs(-startX - tmp_x);
            distY = abs(startY - tmp_y);
            ans = distX*distX + distY*distY;
        }

        
        // 2번
        if(!(tmp_y==startY && tmp_x > startX)){
            distX = abs(2*m - startX  - tmp_x);
            distY = abs(startY - tmp_y);
            tmp = distX*distX + distY*distY;
            ans = min(ans,tmp);
        }
        
        
        // 3번
        if(!(tmp_x==startX && tmp_y < startY)){
             distX = abs(startX - tmp_x);
            distY = abs(-startY - tmp_y);
            tmp = distX*distX + distY*distY;
            ans = min(ans,tmp);
        }
       
        // 4번
        if(!(tmp_x==startX && tmp_y > startY)){
            distX = abs(startX - tmp_x);
            distY = abs(2*n - startY - tmp_y);
            tmp = distX*distX + distY*distY;
            ans = min(ans,tmp);
        }
        
        
//         // 5번
//         double slope1,slope2;
//         slope1=startY/startX;
//         slope2=tmp_y/tmp_x;
//         if(slope1==slope2){
//             // cout<<5<<'\n';
//             if(startX < tmp_x){
//                 distX = abs(-startX - tmp_x);
//                 distY = abs(-startY - tmp_y);
//                 tmp = distX*distX + distY*distY;
//                 ans = min(ans,tmp);
//             }
            
//             if(startX > tmp_x){
//                 distX = abs(startX + m - tmp_x);
//                 distY = abs(startY + n - tmp_y);
//                 tmp = distX*distX + distY*distY;
//                 ans = min(ans,tmp);
//             }
//         }
//         // 6번
//         slope1=(startY)/(startX-m);
//         slope2=(tmp_y)/(tmp_x-m);
//         if(slope1==slope2){
//             // cout<<6<<'\n';
//             if(startX > tmp_x){
//                 distX = abs(startX + m - tmp_x);
//                 distY = abs(-startY - tmp_y);
//                 tmp = distX*distX + distY*distY;
//                 ans = min(ans,tmp);
//             }
//             if(startX < tmp_x){
//                 distX = abs(-startX - tmp_x);
//                 distY = abs(startY + n - tmp_y);
//                 tmp = distX*distX + distY*distY;
//                 ans = min(ans,tmp);
//             }
//         }
        answer.push_back(ans);
    }
    return answer;
}