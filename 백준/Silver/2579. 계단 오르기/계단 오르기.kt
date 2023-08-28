fun main() {
     val count = readln().toInt()
        val stair = Array(count + 1) { 0 }
        val dp = Array(count + 1) { 0 }

        for (i in 1 until stair.size) {
            stair[i] = readln().toInt()
        }

        for (i in dp.indices) {
            when (i) {
                0 -> dp[i] = 0
                1 -> dp[i] = stair[1]
                2 -> dp[i] = stair[1] + stair[2]
                else -> {
                    dp[i] = maxOf((stair[i] + dp[i - 2]), (stair[i] + stair[i - 1] + dp[i - 3]))
                }
            }
        }

        println(dp[count])
}