import java.util.LinkedList;
import java.util.Queue;

class TreeNode {
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

public class Solution {
    public boolean isCousins(TreeNode root, int x, int y) {
        // Nós no mesmo nível da árvore
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        Boolean xStatus = false, yStatus = false;

        while (!q.isEmpty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                TreeNode curNode = q.poll();

                // Nós com pai diferente
                if ((curNode.left != null && curNode.right != null) && 
                    ((curNode.left.val == x && curNode.right.val == y) || (curNode.left.val == y && curNode.right.val == x))) {
                        return false;
                }
                
                if (curNode.left != null) {
                    if (curNode.left.val == x) xStatus = true;
                    if (curNode.left.val == y) yStatus = true;
                    q.offer(curNode.left);
                }
                if (curNode.right != null) {
                    if (curNode.right.val == x) xStatus = true;
                    if (curNode.right.val == y) yStatus = true;
                    q.offer(curNode.right);
                }     
            }

            if (xStatus && yStatus) return true; // Nós primos com pais diferentes
            if (xStatus || yStatus) return false; // Um dos nós em profundidade diferente

        }

        return false;   
    }
}

class problema_993 {

    public static void main(String[] args) {
        Solution sol = new Solution();

        // --- TESTE EXEMPLO 1 ---

        TreeNode root1 = new TreeNode(1);
        root1.left = new TreeNode(2);
        root1.right = new TreeNode(3);
        root1.left.left = new TreeNode(4);

        int x1 = 4, y1 = 3;
        System.out.println("Exemplo 1 (x=4, y=3): " + sol.isCousins(root1, x1, y1) + " | Esperado: false");

        // --- TESTE EXEMPLO 2 ---
        
        TreeNode root2 = new TreeNode(1);
        root2.left = new TreeNode(2);
        root2.right = new TreeNode(3);
        root2.left.right = new TreeNode(4);
        root2.right.right = new TreeNode(5);

        int x2 = 5, y2 = 4;
        System.out.println("Exemplo 2 (x=5, y=4): " + sol.isCousins(root2, x2, y2) + " | Esperado: true");

        // --- TESTE EXEMPLO 3 ---

        TreeNode root3 = new TreeNode(1);
        root3.left = new TreeNode(2);
        root3.right = new TreeNode(3);
        root3.left.right = new TreeNode(4);

        int x3 = 2, y3 = 3;
        System.out.println("Exemplo 3 (x=2, y=3): " + sol.isCousins(root3, x3, y3) + " | Esperado: false");


    }
}
