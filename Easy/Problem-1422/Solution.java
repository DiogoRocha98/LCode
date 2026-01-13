public class Solution {
    public int maxScore(String s) {
        int maxVal = 0;
        int n = s.length();

        for (int i = 1; i < n; i++) {
            int countL = 0, countR = 0;

            for (int j = 0; j < i; j++) {
                if (s.charAt(j) == '0') countL++;
            }

            for (int j = i; j < n; j++) {
                if (s.charAt(j) == '1') countR++;
            }

            maxVal = Math.max(maxVal, countL + countR);
        }

        return maxVal;
    }
}

class problem_1422 {
    public static void main(String[] args) {
        Solution sol = new Solution();

        System.out.println("Exemplo 1 (011101): " + sol.maxScore("011101") + " | Esperado: 5");
        System.out.println("Exemplo 2 (00111): " + sol.maxScore("00111") + " | Esperado: 5");
        System.out.println("Exemplo 3 (1111): " + sol.maxScore("1111") + " | Esperado: 3");
    }
}
