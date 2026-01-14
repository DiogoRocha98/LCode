class Solution {
    public int chalkReplacer(int[] chalk, int k) {
        long total_chalk = 0;
        
        for (int i : chalk) {
            total_chalk += i;
        }

        long resto = k % total_chalk;

        for (int i = 0; i < chalk.length; i++) {
            if (resto < chalk[i]) {
                return i;
            }
            resto -= chalk[i];
        }
        
        return 0;

    }
}