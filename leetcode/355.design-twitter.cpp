#include <bits/stdc++.h>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;
using ll=long long;
class Twitter {
public:
    struct Tweet{
        int tweetId;
        int postTime;

        Tweet(int tId, int pTime): tweetId(tId), postTime(pTime) {}

        bool operator<(const Tweet& tweet) const{
            return postTime < tweet.postTime;
        }
    };

    unordered_map<int, priority_queue<Tweet>> tweetsByUser; // userid, tweets posted by said user
    unordered_map<int, unordered_set<int>> followList; // follow list of key
    int postTime;
    Twitter() {
        postTime=0;
    }

    void postTweet(int userId, int tweetId) {
        tweetsByUser[userId].push(Tweet(tweetId, postTime));
        postTime++;
    }

    vector<int> getNewsFeed(int userId) {
        const int LIMIT = 10;
        priority_queue<Tweet> feed;

        auto addTweets = [&](int user) {
            auto pq = tweetsByUser[user]; // copy

            for(int i=0; i<LIMIT && !pq.empty(); i++) {
                feed.push(pq.top());
                pq.pop();
            }
        };

        addTweets(userId);

        for(int followee : followList[userId]) {
            addTweets(followee);
        }

        vector<int> ans;

        while(!feed.empty() && ans.size() < 10) {
            ans.push_back(feed.top().tweetId);
            feed.pop();
        }

        return ans;
    }

    void follow(int followerId, int followeeId) {
        if(followeeId!=followerId)
            followList[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if(followList[followerId].contains(followeeId))
            followList[followerId].erase(followeeId);
    }
};
