
class Solution {

    fun maximumMoves(
        arr: Array<IntArray>,
        row: Int,
        col: Int,
        dp: Array<IntArray>
    ): Int {

        // Return cached result if already calculated
        if (dp[row][col] != -1) return dp[row][col]

        var maxPath = 0

        // Try up-right, right, and down-right
        for (dir in -1..1) {
            val newRow = row + dir
            val newCol = col + 1

            // Check boundaries and ensure the next cell is strictly greater
            if (
                newRow >= 0 &&
                newRow < arr.size &&
                newCol < arr[0].size &&
                arr[newRow][newCol] > arr[row][col]
            ) {
                // Calculate moves from the next cell
                val moves = 1 + maximumMoves(arr, newRow, newCol, dp)

                maxPath = maxOf(maxPath, moves)
            }
        }

        // Store the result in DP
        dp[row][col] = maxPath
        return dp[row][col]
    }

    fun maxMoves(grid: Array<IntArray>): Int {
        var ans = 0

        val m = grid.size
        val n = grid[0].size

        // -1 means the cell has not been calculated yet
        val dp = Array(m) { IntArray(n) { -1 } }

        // Start from every row in the first column
        for (row in grid.indices) {
            ans = maxOf(ans, maximumMoves(grid, row, 0, dp))
        }

        return ans
    }
}

fun main() {
    val grid = arrayOf(
        intArrayOf(2, 4, 3, 5),
        intArrayOf(5, 4, 9, 3),
        intArrayOf(3, 4, 2, 11),
        intArrayOf(10, 9, 13, 15)
    )

    val solution = Solution()
    val ans = solution.maxMoves(grid)

    println("Maximum moves: $ans")
}
