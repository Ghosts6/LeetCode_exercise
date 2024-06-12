from typing import List

class Solution:
    def compress(self, chars: List[str]) -> int:
        write_index = 0  
        read_index = 0   

        while read_index < len(chars):
            current_char = chars[read_index]
            count = 0

            while read_index < len(chars) and chars[read_index] == current_char:
                read_index += 1
                count += 1

            chars[write_index] = current_char
            write_index += 1

            if count > 1:
                for digit in str(count):
                    chars[write_index] = digit
                    write_index += 1

        return write_index

# test cases
if __name__ == "__main__":
    solution = Solution()
    
    # case  1
    chars = ['a', 'a', 'b', 'b', 'c', 'c', 'c']
    new_length = solution.compress(chars)
    print(f"compressed array: {chars[:new_length]} with length: {new_length}")
    
    # case  2
    chars = ['a']
    new_length = solution.compress(chars)
    print(f"compressed array: {chars[:new_length]} with length: {new_length}")

