class SnapshotArray {
    int cnt{};
    vector<vector<pair<int,int> > > modify;
public:
    SnapshotArray(int length) :modify(length) {}
    
    void set(int index, int val) {
        modify[index].emplace_back(cnt,val);
    }
    
    int snap() {
        return cnt++;
    }
    
    int get(int index, int snap_id) {
        auto i = ranges::upper_bound(modify[index],pair{snap_id + 1 , 0});
        return i == modify[index].begin() ? 0 : (--i)->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */