// https://leetcode.com/problems/design-twitter/
/*
Design a simplified version of Twitter where users can post tweets,
follow/unfollow another user and is able to see the 10 most recent tweets in the
user's news feed. Your design should support the following methods:

postTweet(userId, tweetId): Compose a new tweet.
getNewsFeed(userId): Retrieve the 10 most recent tweet ids in the user's news
feed. Each item in the news feed must be posted by users who the user followed
or by the user herself. Tweets must be ordered from most recent to least recent.
follow(followerId, followeeId): Follower follows a followee.
unfollow(followerId, followeeId): Follower unfollows a followee.
Example:

Twitter twitter = new Twitter();

// User 1 posts a new tweet (id = 5).
twitter.postTweet(1, 5);

// User 1's news feed should return a list with 1 tweet id -> [5].
twitter.getNewsFeed(1);

// User 1 follows user 2.
twitter.follow(1, 2);

// User 2 posts a new tweet (id = 6).
twitter.postTweet(2, 6);

// User 1's news feed should return a list with 2 tweet ids -> [6, 5].
// Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
twitter.getNewsFeed(1);

// User 1 unfollows user 2.
twitter.unfollow(1, 2);

// User 1's news feed should return a list with 1 tweet id -> [5],
// since user 1 is no longer following user 2.
twitter.getNewsFeed(1);
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <sys/time.h>

using namespace std;

class Twitter {
private:
  struct tweetInfo {
    int id;
    unsigned long time;
    tweetInfo(int x) : id(x){};
  };

  struct user {
    int id;
    unordered_map<int, shared_ptr<user>> followees;
    tweetInfo *myTweets;
    int lastTweetId;
    user(int x) : id(x), lastTweetId(0) {
      myTweets = (tweetInfo *)calloc(10, sizeof(tweetInfo));
    };
  };

  vector<user> users;
  unordered_map<int, shared_ptr<user>> userMap;

  unsigned long getCurrTime() {
    timeval t;
    gettimeofday(&t, NULL);
    return (t.tv_sec + t.tv_usec / 1000000.0);
  }

  shared_ptr<user> getUser(int userId) {
    if (userMap.count(userId)) {
      return userMap[userId];
    }
    userMap[userId] = make_shared<user>(userId);
    return (userMap[userId]);
  }

public:
  /** Initialize your data structure here. */
  Twitter() {}

  /** Compose a new tweet. */
  void postTweet(int userId, int tweetId) {
    auto user = getUser(userId);
    if (user->lastTweetId == 9)
      user->lastTweetId = 0;
    user->myTweets[user->lastTweetId].id = tweetId;
    user->myTweets[user->lastTweetId].time = getCurrTime();
    user->lastTweetId++;
    cout << user->myTweets[user->lastTweetId - 1].time << endl;
    cout << userId << " tweeted " << tweetId << endl;
  }

  /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item
   * in the news feed must be posted by users who the user followed or by the
   * user herself. Tweets must be ordered from most recent to least recent. */
  vector<int> getNewsFeed(int userId) {
    shared_ptr<user> user = getUser(userId);
    while (count < 10) {
      count++;
      unsigned long maxTime = INT_MIN;
      for (auto it = user->followees.begin(); it != user->followees.end();
           it++) {

        if (it->second->myTweets[it->second->lastTweetId - 1].time >= maxTime)
          maxTime = it->second->myTweets[it->second->lastTweetId - 1].time;
      }
      if (user->myTweets[user->lastTweetId - 1].time > maxTime) {
        maxTime = user->myTweets[user->lastTweetId - 1].time;
      }
    }
  }

  /** Follower follows a followee. If the operation is invalid, it should be a
   * no-op. */
  void follow(int followerId, int followeeId) {
    auto follower = getUser(followerId);
    if (follower->followees.count(followeeId)) {
      cout << followerId << " already following " << followeeId << endl;
      return;
    }
    follower->followees[followeeId] = getUser(followeeId);
    cout << followerId << " now following " << followeeId << endl;
  }

  /** Follower unfollows a followee. If the operation is invalid, it should be a
   * no-op. */
  void unfollow(int followerId, int followeeId) {
    auto follower = getUser(followerId);
    if (!follower->followees.count(followeeId)) {
      cout << followerId << " not following " << followeeId << endl;
      return;
    }
    follower->followees.erase(followeeId);
    cout << followerId << " un-followed " << followeeId << endl;
  }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */

int main() {
  Twitter *obj = new Twitter();
  obj->postTweet(1, 5);
  vector<int> param_2 = obj->getNewsFeed(1);
  obj->follow(1, 2);
  obj->unfollow(1, 2);
}
