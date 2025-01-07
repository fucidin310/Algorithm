#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool cmpGenres(pair<int, int> a, pair<int, int> b){
    if(a.first != b.first) return a.first > b.first;
    else return a.second < b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    int size = genres.size();
    int id = 0;
    
    //장르명, 재생된 횟수의 합
    unordered_map<string, int> genresMap;
    //장르명, 재생된 횟수, 고유 번호
    unordered_map<string, vector<pair<int, int>>> playsMap;
    
    for(int i = 0; i < size; i++){
        string genre = genres[i];
        int play = plays[i];
        
        auto it = genresMap.find(genre);
        
        if(it == genresMap.end()){
            genresMap[genre] = play;
            vector<pair<int, int>> tmpVec;
            tmpVec.push_back(make_pair(play, i));
            playsMap[genre] = tmpVec;
        }
        else{
            genresMap[genre] += play;
            playsMap[genre].push_back(make_pair(play, i));            
        }
    }
    
    vector<pair<string, int>> genresVec(genresMap.begin(), genresMap.end());
    sort(genresVec.begin(), genresVec.end(), 
         [](pair<string, int> a, pair<string, int> b)
         {
             return a.second > b.second;
         }
        );
    
    for(int i = 0; i < genresVec.size(); i++){
        string genre = genresVec[i].first;
        
        vector<pair<int, int>>& songs = playsMap[genre];
        
        sort(songs.begin(), songs.end(),
            [](pair<int, int> a, pair<int, int> b)
             {
                 if(a.first != b.first) return a.first > b.first;
                 else return a.second < b.second;
             }
            );
        
        answer.push_back(songs[0].second);
        if (songs.size() > 1) {
            answer.push_back(songs[1].second);
        }
    }
    
    return answer;
}