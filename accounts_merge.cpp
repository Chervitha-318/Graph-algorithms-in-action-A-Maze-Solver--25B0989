class Solution {
public:
    vector<int> parent;
    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }
    void unite(int a, int b) {
        int pa = find(a);
        int pb = find(b);

        if (pa != pb)
            parent[pb] = pa;
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        int n = accounts.size();
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
        unordered_map<string, int> emailToAccount;

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string email = accounts[i][j];
                if (emailToAccount.find(email) == emailToAccount.end()) {
                    emailToAccount[email] = i;
                }
                else {
                    unite(i, emailToAccount[email]);
                }
            }
        }

        unordered_map<int, vector<string>> mergedEmails;
        for (auto it : emailToAccount) {
            string email = it.first;
            int accountIndex = it.second;
            int root = find(accountIndex);
            mergedEmails[root].push_back(email);
        }

        vector<vector<string>> ans;
        for (auto it : mergedEmails) {
            int accountIndex = it.first;
            vector<string> emails = it.second;
            sort(emails.begin(), emails.end());
            vector<string> account;
            account.push_back(accounts[accountIndex][0]);

            for (string email : emails) {
                account.push_back(email);
            }
            ans.push_back(account);
        }
        return ans;
    }
};
