//============================================================================
// Name        : 929. Unique Email Addresses
// Author      : Yu Li
// Version     :
// Copyright   :
// Description : https://leetcode.com/problems/unique-email-addresses/
//============================================================================


#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;


class Unique_929 {

public:
    int numUniqueEmails(vector<string>& emails) {
    	unordered_set<string> S;
        for (auto email : emails)
        {
            string local, domain;
            int k = 0;
            while (email[k] != '@') k ++ ;
            local = email.substr(0, k);
            domain = email.substr(k + 1);
            string newLocal;
            for (auto c : local)
            {
                if (c == '+') break;
                if (c != '.') newLocal += c;
            }
            S.insert(newLocal + '@' + domain);
        }
        return S.size();
    }
};



int main() {
	vector<string> testV = {"test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"};
	Unique_929 test;
	int res = test.numUniqueEmails(testV);
	cout << res << endl;
	string s = "test";
	if(s.find('a') == string::npos)
		cout << "no 'a' in 'test'\n";
	cout << (s.find('a') == string::npos ? 1 : 0);
	return 0;
}
