class Solution:
    def Quicksort(a, l, r):
        if l > r:
            return
        
        i, j = l, r
        
        while i < j:
            while i < j and a[j] >= a[l]:
                j -= 1
            while i < j and a[i] <= a[l]:
                i += 1
            if i < j:
                a[i], a[j] = a[j], a[i]
                
        a[l], a[i] = a[i], a[l]
        
        Quicksort(a, l, i-1)
        Quicksort(a, i+1, r)
    def sortArray(self, nums: List[int]) -> List[int]:
        self.Quicksort(nums , 0, len(nums-1))
        return nums
