class Solution:
    def suggestedProducts(self, products, searchWord):
        products.sort()
 
        results = []
        prefix = ""
        
        for char in searchWord:
            prefix += char
            suggestions = [product for product in products if product.startswith(prefix)]
            results.append(suggestions[:3])
        
        return results

# Test case 
def runTest():
    solution = Solution()

    products1 = ["mobile","mouse","moneypot","monitor","mousepad"]
    searchWord1 = "mouse"
    result1 = solution.suggestedProducts(products1, searchWord1)
    print(f"Test Case 1: {result1}")

    products2 = ["havana"]
    searchWord2 = "havana"
    result2 = solution.suggestedProducts(products2, searchWord2)
    print(f"Test Case 2: {result2}")

if __name__ == "__main__":
    runTest()
