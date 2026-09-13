class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        PriorityQueue<int[]>pq = new PriorityQueue<>((a,b) -> b[0]-a[0]);
        int left = 0;
        int [] ans = new int[nums.length-k+1];
        int p = 0;
        for(int i = 0;i<nums.length;i++){
            pq.add(new int[]{nums[i],i});

            while(pq.peek()[1]<left){
                pq.poll();
            }

            if(i-left+1 == k){
               ans[p] = pq.peek()[0];
               left++;
               p++;
            }
        }
return ans;
    }
}
