class NumArray {
public:
     /**
     * Binary Indexed Trees (BIT or Fenwick tree):
     * https://www.topcoder.com/community/data-science/data-science-
     * tutorials/binary-indexed-trees/
     * 
     * Example: given an array a[0]...a[7], we use a array BIT[9] to
     * represent a tree, where index [2] is the parent of [1] and [3], [6]
     * is the parent of [5] and [7], [4] is the parent of [2] and [6], and
     * [8] is the parent of [4]. I.e.,
     * 
     * BIT[] as a binary tree:
     *            ______________*
     *            ______*
     *            __*     __*
     *            *   *   *   *
     * indices: 0 1 2 3 4 5 6 7 8
     * 
     * BIT[i] = ([i] is a left child) ? the partial sum from its left most
     * descendant to itself : the partial sum from its parent (exclusive) to
     * itself. (check the range of "__").
     * 
     * Eg. BIT[1]=a[0], BIT[2]=a[1]+BIT[1]=a[1]+a[0], BIT[3]=a[2],
     * BIT[4]=a[3]+BIT[3]+BIT[2]=a[3]+a[2]+a[1]+a[0],
     * BIT[6]=a[5]+BIT[5]=a[5]+a[4],
     * BIT[8]=a[7]+BIT[7]+BIT[6]+BIT[4]=a[7]+a[6]+...+a[0], ...
     * 
     * Thus, to update a[1]=BIT[2], we shall update BIT[2], BIT[4], BIT[8],
     * i.e., for current [i], the next update [j] is j=i+(i&-i) //double the
     * last 1-bit from [i].
     * 
     * Similarly, to get the partial sum up to a[6]=BIT[7], we shall get the
     * sum of BIT[7], BIT[6], BIT[4], i.e., for current [i], the next
     * summand [j] is j=i-(i&-i) // delete the last 1-bit from [i].
     * 
     * To obtain the original value of a[7] (corresponding to index [8] of
     * BIT), we have to subtract BIT[7], BIT[6], BIT[4] from BIT[8], i.e.,
     * starting from [idx-1], for current [i], the next subtrahend [j] is
     * j=i-(i&-i), up to j==idx-(idx&-idx) exclusive. (However, a quicker
     * way but using extra space is to store the original array.)
     */
    
    /*
    if using 2's complement,
    +a + (-a) will be 0,
    and "-a" is attained by 
    reverting all bits of "+a"
    and then add 1 onto it

    if a = 6,
    a = 110,
    -a = 001+1 = 010
    a & (-a) = 010,
    so we get least significant bit
    */
    
    vector<int> nums;
    vector<int> BIT;
    int n;
    
    void init(int i, int val){
        /*
        the argument i is the index of "nums",
        adding 1 converts it to the index of "BIT"
        */
        i++;
        /*
        BIT[0] is meaningless,
        BIT[1-n] is meaningful
        */
        // cout << "init: ";
        while(i <= n){
            // cout << i << " ";
            BIT[i] += val;
            //double least significant bit
            /*
            current node is next node's left child or grandson,
            so next node's value should contain current node's value
            */
            //go to its parent
            i += (i&-i);
        }
        // cout << endl;
    };
    
    NumArray(vector<int>& nums) {
        this->nums = nums;
        n = nums.size();
        /*
        different from segment tree 
        which requires n*4 space,
        it only needs n+1 space!!
        */
        BIT = vector<int>(n+1);
        for(int i = 0; i < n; i++){
            init(i, nums[i]);
        }
        
        // cout << "BIT: ";
        // for(int i = 1; i <= n; i++){
        //     cout << BIT[i] << " ";
        // }
        // cout << endl;
    }
    
    void update(int i, int val) {
        int diff = val - nums[i];
        //update the data structure "nums"
        nums[i] = val;
        //update the data structure "BIT"
        init(i, diff);
    }
    
    int getSum(int i){
        //get sum of arr[0,i]
        int sum = 0;
        
        //convert from "nums" index to "BIT"'s index
        i++;
        
        // cout << "getSum: ";
        //[1,n] are valid indices of "BIT"
        while(i > 0){
            // cout << i << " ";
            sum += BIT[i];
            //remove least significant bit
            /*
            current node is next node's right child or grandson,
            so next node's value doesn't contain current node's value.
            So to get cumulative sum, we should continue to add next node's value
            */
            //go to the node higher than and to the left of itself
            i -= (i&-i);
        }
        // cout << endl;
        
        return sum;
    };
    
    int sumRange(int i, int j) {
        return getSum(j) - getSum(i-1);
    }
};