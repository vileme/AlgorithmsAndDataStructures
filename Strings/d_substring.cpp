#include <iostream>
#include <vector>

int main() {
    std::string s;
    std::string text;
    std::cin >> s;
    int k = s.size();
    std::cin>>text;
    std::vector<int> zFunction;
    s=s+"|"+text;
    zFunction.resize(s.length());
    for (int i = 1, l = 0, r = 0; i < s.size(); ++i) {
        if (i <= r)
            zFunction[i] = std::min(r - i + 1, zFunction[i - l]);
        while (i + zFunction[i] < s.size() && s[zFunction[i]] == s[i + zFunction[i]])
            ++zFunction[i];
        if (i + zFunction[i] - 1 > r)
            l = i, r = i + zFunction[i] - 1;
    }
    std::vector<int>ans;
    for(int i = 0;i<zFunction.size();++i){
        if(zFunction[i]==k)ans.push_back(i);
    }
    std::cout<<ans.size()<<"\n";
    for(int i = 0 ; i<ans.size();++i){
        std::cout<<ans[i]-k << ' ';
    }
    return 0;
}