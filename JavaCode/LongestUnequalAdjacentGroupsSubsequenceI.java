package JavaCode;
import java.util.*;

public class LongestUnequalAdjacentGroupsSubsequenceI {
       public List<String> getLongestSubsequence(String[] words, int[] groups) {
        List<String> result = new ArrayList<>();
        int n = words.length;

        if (n == 0) return result;

        result.add(words[0]);
        int lastGroup = groups[0];

        for (int i = 1; i < n; i++) {
            if (groups[i] != lastGroup) {
                result.add(words[i]);
                lastGroup = groups[i];
            }
        }

        return result;
    }
}
