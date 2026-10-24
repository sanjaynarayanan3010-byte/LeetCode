class Solution {
public:
    int countDaysTogether(string aa, string la, string ab, string lb) {
        vector<int> diff(367, 0);
        vector<int> months = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        for(int i=1;i<months.size();i++) months[i] += months[i-1];
        string a = ""; a += aa[0]; a += aa[1]; int ai = stoi(a);
        string b = ""; b += la[0]; b += la[1]; int bi = stoi(b);
        string c = ""; c += ab[0]; c += ab[1]; int ci = stoi(c);
        string d = ""; d += lb[0]; d += lb[1]; int di = stoi(d);
        string e = ""; e += aa[3]; e += aa[4]; int ei = stoi(e);
        string f = ""; f += la[3]; f += la[4]; int fi = stoi(f);
        string g = ""; g += ab[3]; g += ab[4]; int gi = stoi(g);
        string h = ""; h += lb[3]; h += lb[4]; int hi = stoi(h);
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