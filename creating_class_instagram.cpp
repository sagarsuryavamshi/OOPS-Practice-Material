// creating a simple instagram User
// Class Object Decide the memener varaiables and  4 member functions own your own.
// Keep the limit of the member variable up to max 5 

#include <iostream>
#include <string>
using namespace std;
class InstagramUser{
    string username;
    long long phone_no ;
    int followers ;
    int following ;
    bool is_private ;

    public:
        InstagramUser(string user, long long phone, int follow, int follow_back, bool private_status);
        void displayUserInfo();
        void updateFollowers(int new_followers);
        void updateFollowing(int new_following);

};

InstagramUser::InstagramUser(string user, long long phone, int follow,
                             int follow_back, bool private_status)
    : username(user), phone_no(phone), followers(follow),
      following(follow_back), is_private(private_status) {}

void InstagramUser::displayUserInfo() {
    cout << "Username: " << username << '\n'
         << "Phone: " << phone_no << '\n'
         << "Followers: " << followers << '\n'
         << "Following: " << following << '\n'
         << "Private: " << (is_private ? "Yes" : "No") << "\n\n";
}

void InstagramUser::updateFollowers(int new_followers) {
    followers += new_followers;
}

void InstagramUser::updateFollowing(int new_following) {
    following += new_following;
}

int main(){
    InstagramUser user1("Sagar",7012018618,1000,500,false);
    user1.displayUserInfo();
    user1.updateFollowers(100);
    user1.updateFollowing(50);
    user1.displayUserInfo();
    return 0;
}