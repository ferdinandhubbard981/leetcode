class Solution(object):
    fibDict = {}

    def fib(self, n):
        """
        :type n: int
        :rtype: int
        """
        if (n < 2):
            return n
        if (n in self.fibDict):
            return self.fibDict[n]
        
        output = self.fib(n-1) + self.fib(n-2)
        self.fibDict[n] = output
        return output
    
            
        
        
        
def main():
    instance = Solution()
    input = 200
    print(instance.fib(input))

if __name__ == "__main__":
    main()