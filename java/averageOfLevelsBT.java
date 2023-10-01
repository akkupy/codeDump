class Solution{
  public class TreeNode {
      int val;
      TreeNode left;
      TreeNode right;
      TreeNode() {}
      TreeNode(int val) { this.val = val; }
      TreeNode(int val, TreeNode left, TreeNode right) {
          this.val = val;
          this.left = left;
          this.right = right;
     }
  }

public List<Double> averageOfLevels(TreeNode root) {
        Queue<TreeNode> q = new LinkedList<>();
        List<Double> res = new ArrayList<>();

        q.offer(root);
        while(!q.isEmpty()){
            int level = q.size();
            double lvlsum =0;
            for(int i=0; i< level ; i++){
                TreeNode curr = q.poll();
                lvlsum += curr.val;
                if(curr.left != null){
                    q.offer(curr.left);
                }
                if(curr.right != null){
                    q.offer(curr.right);
                }
            }
            res.add(lvlsum/level);
        }

        return res;
    }
}
