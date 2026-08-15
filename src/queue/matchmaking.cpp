#include "queue/matchmaking.hpp"
#include <sstream>
#include <vector>
#include <string>

using std::vector;
using std::string;


std::string matchmake(std::queue<User> q, User user){
    const auto [name,action]=user;
    if (action=="join"){
        q.push(user);
    }
    int n =q.size();
    for (int i = 0; i < n; i++) {
        User candidate =q.front();
        if (name==candidate.first){
            q.pop();

        } 
        
    }
    if (q.size()>=4){
        std::ostringstream oss;
        std::string m1=q.front().first;
        q.pop();
        std::string m2=q.front().first;
        oss<<m1<<" matched "<<m2;
        return oss.str();

    }
    else{
        return "No match found";
    }

}

