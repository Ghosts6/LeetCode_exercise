package JavaCode;

import java.util.ArrayList;
import java.util.List;

public class FindWordsContainingCharacter {
    public List<Integer> findWordsContaining(String[] words, char x) {
        List<Integer> result = new ArrayList<>();
        for (int j = 0; j < words.length; j++) {
            if (words[j].indexOf(x) != -1) {
                result.add(j);
            }
        }
        return result;
    }
}
