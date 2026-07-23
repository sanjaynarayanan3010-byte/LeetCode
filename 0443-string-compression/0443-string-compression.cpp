class Solution {
public:
    int compress(vector<char>& chars) {
        int N = chars.size();
        string s = "";

        int count = 1;
        for(int i=1;i<N;i++){
            if(chars[i] == chars[i-1]){
                count++;
            }
            else{
                s += chars[i-1];
                if(count > 1){
                    string temp = "";
                    while(count){
                        temp += ((count % 10) + '0');
                        count/=10;
                    }
                    cout<<temp<<" ";
                    for(int i=temp.size()-1;i>=0;i--) s += temp[i];
                    cout<<s<<" ";
                }
                count = 1;
            }
        }
        s += chars[N-1];
        if(count > 1){
            string temp = "";
            while(count){
                temp += ((count % 10) + '0');
                count/=10;
            }
            cout<<temp<<" ";
            for(int i=temp.size()-1;i>=0;i--) s += temp[i];
        }
        cout<<s;
        for(int i=0;i<s.size();i++){
            chars[i] = s[i];
        }
        return s.size();
    }
};