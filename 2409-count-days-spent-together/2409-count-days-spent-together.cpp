class Solution {
public:
    int countDaysTogether(string aa, string la, string ab, string lb) {
        vector<int> diff(367, 0);
        vector<int> months = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        for(int i=1;i<months.size();i++) months[i] += months[i-1];
        string a = aa.substr(0, 2); int ai = stoi(a);
        string b = la.substr(0, 2); int bi = stoi(b);
        string c = ab.substr(0, 2); int ci = stoi(c);
        string d = lb.substr(0, 2); int di = stoi(d);
        string e = aa.substr(3, 2); int ei = stoi(e);
        string f = la.substr(3, 2); int fi = stoi(f);
        string g = ab.substr(3, 2); int gi = stoi(g);
        string h = lb.substr(3, 2); int hi = stoi(h);
        // cout << ai << " " << bi << " " << ci << " " << di << " " << ei << " " << fi << " " << gi << " " << hi;
        diff[months[ai - 1] + ei]++;
        diff[months[bi - 1] + fi + 1]--;
        diff[months[ci - 1] + gi]++;
        diff[months[di - 1] + hi + 1]--;
        for(int i=1;i<diff.size();i++) diff[i] += diff[i-1];
        int ans = 0;
        for(int i : diff) {
            if(i > 1) ans++;
        }
        return ans;
    }
};