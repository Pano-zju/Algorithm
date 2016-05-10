class BIT{
public:
	int tree[10005];    //�����±��1��ʼ��valsͬ 
	int vals[10005];
	int size;
	//vals[idx]����val 
	void refresh(int idx, int val) {
		while(idx <= size) {
			tree[idx] += val;
			idx += idx & (-idx); 
		}
	}
	//��ȡvals[1...idx]���ۻ��� 
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
		//��ʼ����״���� 
		for(int i = 0 ; i < size ; i++) {
			refresh(i + 1, nums[i]);
		}
	}
};