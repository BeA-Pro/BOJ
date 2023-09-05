
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<long long, long long> room;

long long findRoom(long long n)
{
	if (room[n] == 0)
	{
		return n;
	}

	return room[n] = findRoom(room[n]);
}

vector<long long> solution(long long k, vector<long long> room_number) {
	vector<long long> answer;

	for (long long num : room_number)
	{
		if (room[num] == 0)
		{
			room[num] = findRoom(num + 1);
			answer.push_back(num);

			continue;
		}

		long long nextNum = findRoom(num);
		room[nextNum] = findRoom(nextNum + 1);

		answer.push_back(nextNum);
	}

	return answer;
}
// #include <string>
// #include <vector>
// #include <map>
// #include <iostream>
// using namespace std;

// map<long long, pair<long long, vector<long long > > m;

// long long find_parent(long long n){
//     if(m.find(n)==m.end()){
//         return m[n] = n;
//     }
//     if(m[n] == n) return m[n] = find_parent(n+1);
//     return m[n].first = find_parent(m[n]);
// }

// vector<long long> solution(long long k, vector<long long> room_number) {
//     vector<long long> answer;
//     for(int i = 0 ;i < room_number.size(); i++){
//         long long room = room_number[i];
//         answer.push_back(find_parent(room));
//     }

//     return answer;
// }