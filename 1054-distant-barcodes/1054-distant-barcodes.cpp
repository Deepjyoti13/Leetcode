class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int, int> mp;
        int freqMax=0, numMax, N = barcodes.size();
        for(int &code: barcodes) {
            mp[code]++;
            if(mp[code]>freqMax) {
                freqMax = mp[code];
                numMax = code;
            }
        }
        vector<int> res(N);
        mp.erase(numMax);
        int i=0;
        for(i=0; i<2*freqMax; i+=2)
            res[i]=numMax;
        for(auto codes: mp) {
            for(int j=0; j<codes.second; j++, i+=2) {
                if(i>=N) i=1;
                res[i]=codes.first;
            }
        }
        return res;
    }
};