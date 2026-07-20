struct comp {
    bool operator()(const pair<int,int>& p1, const pair<int,int>& p2) {
        return p1.second < p2.second; // Max-heap based on timestamp
    }
};
struct compp {
    bool operator()(const pair<int,int>& p1, const pair<int,int>& p2) {
        return p1.second > p2.second; // Max-heap based on timestamp
    }
};
struct User {
    int userId;
    priority_queue<pair<int,int>, vector<pair<int,int>>, comp> tweets; // need maxheap
    unordered_map<int, struct User*> following;
};
int countt = 1;
class Twitter {
    //unordered_map<int,int> tweets; // maps tweetId to userId
    unordered_map<int, struct User*> users; // maps userId to respective user object
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        //tweets[tweetId] = userId;
        //
        if (users.find(userId) == users.end()) {
            users[userId] = new User{userId};
        }
        struct User* user = users[userId];
        user->tweets.push({tweetId, countt++});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, compp> feed;
        if (users.find(userId) == users.end()) {
            return {};
        }
        struct User* user = users[userId]; // assuming user with userId exists
        for (auto it = user->following.begin();it != user->following.end();it++) {
            priority_queue<pair<int,int>, vector<pair<int,int>>, comp> userTweets = it->second->tweets;
            while (!userTweets.empty() && (feed.empty() || feed.top().second < userTweets.top().second || feed.size() < 10)) {
                if (userTweets.empty()) break;
                if (feed.size() >= 10) {
                    feed.pop();
                }
                feed.push({userTweets.top()});
                userTweets.pop();
            }
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, comp> userTweets = user->tweets;
            while (!userTweets.empty() && (feed.empty() || feed.top().second < userTweets.top().second || feed.size() < 10)) {
                if (userTweets.empty()) break;
                if (feed.size() >= 10) {
                    feed.pop();
                }
                feed.push(userTweets.top());
                userTweets.pop();
            }
        deque<int> ans;
        while (!feed.empty()) {
            ans.push_front(feed.top().first);
            feed.pop();
        }
        return vector<int>(ans.begin(), ans.end());
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        if (users.find(followerId) == users.end()) {
            users[followerId] = new User{followerId};
        }
        if (users.find(followeeId) == users.end()) {
            users[followeeId] = new User{followeeId};
        }
        struct User* user = users[followerId];
        struct User* userToFollow = users[followeeId];
        user->following[followeeId] = userToFollow;
    }
    
    void unfollow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        struct User* user = users[followerId];
        user->following.erase(followeeId);
    }
};
