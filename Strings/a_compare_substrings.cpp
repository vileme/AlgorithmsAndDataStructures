#include <iostream>
#include <vector>

int main() {
    std::string s;
    std::cin>>s;
    std::vector<int> zFunction;
    zFunction.resize(s.length());
    for (int i = 1, l = 0, r = 0; i < s.size(); ++i) {
        if (i <= r)
            zFunction[i] = std::min(r - i + 1, zFunction[i - l]);
        while (i + zFunction[i] < s.size() && s[zFunction[i]] == s[i + zFunction[i]])
            ++zFunction[i];
        if (i + zFunction[i] - 1 > r)
            l = i, r = i + zFunction[i] - 1;
    }
    for(int i = 0;i<zFunction.size();++i){
        if(i+zFunction[i]==zFunction.size()){
            if(zFunction.size()%i==0){
                std::cout<<i;
                return 0;
            }
        }
    }
    std::cout<<zFunction.size();
    return 0;
}