class Solution:
    def findNumberIn2DArray(self, matrix: List[List[int]], target: int) -> bool:
        columns = len(matrix)
        if columns <= 0:
            return False
    
        rows = len(matrix[0])
        if rows <= 0:
            return False

        i = rows -1
        j = 0

        while i >= 0 and j < columns:
            if matrix[j][i] == target:
                return True
            
            if target < matrix[j][i]:
                i -= 1
                continue
            
            if target > matrix[j][i]:
                j += 1
                continue
        
        return False