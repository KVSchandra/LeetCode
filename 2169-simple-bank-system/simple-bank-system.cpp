class Bank {
public:
    int n;
    vector<long long> balance;
    Bank(vector<long long>& balance) {
        n = balance.size();
        this->balance = balance;
    }
    bool transfer(int account1, int account2, long long money) {
        if(account1 > n || account1 < 1 || account2 > n || account2 < 1) {
            return false;
        }
        if(money <= balance[account1-1]) {
            balance[account2-1] += money;
            balance[account1-1] -= money;
            return true;
        }
        return false;
    }
    
    bool deposit(int account, long long money) {
        if(account > n || account < 1) {
            return false;
        }
        balance[account-1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(account > n || account < 1) {
            return false;
        }
        if(balance[account-1] >= money) {
            balance[account-1] -= money;
            return true;
        }
        return false;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */