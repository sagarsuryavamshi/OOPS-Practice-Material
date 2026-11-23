// creating a simple instagram User
// Class Object Decide the memener varaiables and  4 member functions own your own.
// Keep the limit of the member variable up to max 5 

#include <iostream>
#include <string>
using namespace std;
class InstagramUser{
    private:
    long long phone_no ;
    string username;
    int followers ;
    int following ;
    bool is_private ; // toggle for private or public account

    public:
    InstagramUser(string uname, long long pno, int foll, int folw, bool flow)
        : username(uname), phone_no(pno), followers(foll), following(folw), is_private(flow) {
            cout << "Instagram user created: " << endl;
        }
        void displayUserInfo() const {
            cout << "Username: " << username << endl;
            cout << "Phone Number: " << phone_no << endl;
            cout << "Followers: " << followers << endl;
            cout << "Following: " << following << endl;
            cout << "Private Account: " << (is_private ? "Yes" : "No") << endl;
        }
        void updateFollowers(int newFollowers) {
            followers += newFollowers;
        }
        void updateFollowing(int newFollowing) {
            following += newFollowing;
        } 
};

int main(){
    InstagramUser user1("Sagar",7012018618,1000,500,false);
    user1.displayUserInfo();
    user1.updateFollowers(100);
    user1.updateFollowing(50);
    user1.displayUserInfo();
    return 0;
}