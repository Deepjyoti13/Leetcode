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
        fill(barcodes.begin(), barcodes.end(), 0);
        mp.erase(numMax);
        int i=0;
        for(i=0; i<2*freqMax; i+=2)
            barcodes[i]=numMax;
        for(auto codes: mp) {
            for(int j=0; j<codes.second; j++, i+=2) {
                if(i>=N) i=1;
                barcodes[i]=codes.first;
            }
        }
        return barcodes;
    }
};