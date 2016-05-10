class BIT{
public:
	int tree[10005];    //数组下标从1开始，vals同 
	int vals[10005];
	int size;
	//vals[idx]增加val 
	void refresh(int idx, int val) {
		while(idx <= size) {
			tree[idx] += val;
			idx += idx & (-idx); 
		}
	}
	//获取vals[1...idx]的累积和 
	int getSum(int idx) {
		int res = 0;
		while(idx > 0) {
			res += tree[idx];
			idx -= idx & (-idx);
		}
		return res;
	}
	BIT(vector<int>& nums) {
		size = nums.size();
		tree[0] = vals[0] = 0;
		for(int i = 1 ; i <= size ; i++) {
			tree[i] = 0;
			vals[i] = nums[i - 1];
		}
		//初始化树状数组 
		for(int i = 0 ; i < size ; i++) {
			refresh(i + 1, nums[i]);
		}
	}
};