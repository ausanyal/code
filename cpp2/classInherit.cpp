#include <iostream>
#include <vector>

using namespace std;

class ResMgrIntf {
    public:
        virtual void getOwner()=0;
        virtual vector<int> getV()=0;
};

class ResMgr : public ResMgrIntf {
    public:
        vector<int> v;    
        vector<int> getV() {
            return v;
        }
        void getOwner() {
            cout << "ResMgr\n";
            v.push_back(100);
        }
};

class MockResMgr : public ResMgrIntf {
    public:
        vector<int> v;
        void getOwner() {
            cout << "MockResMgr\n";
        }
        //vector<int> getV() {
        //    return v;
        //}
};

class  RateLimiter {
    private:
        ResMgrIntf& rsrc_mgr;
    public:
        RateLimiter(ResMgrIntf& rsrc_mgr) : rsrc_mgr(rsrc_mgr) {}
        void printOwner() {
            rsrc_mgr.getOwner();
        }
        void getV() {
            auto v = rsrc_mgr.getV();
            cout << v[0] << "\n";
        }
};

class RateLimiterTest {
    public:
    private:
};

int main()
{

    MockResMgr mock;
    ResMgr res;
    RateLimiter rt1(mock);
    rt1.printOwner();

    RateLimiter rt2(res);
    rt2.printOwner();
    rt2.getV();

    return 0;
}
