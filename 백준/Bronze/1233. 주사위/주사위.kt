fun main() {
        val dices = readln().split(" ").map { it.toInt() }

        val s1 = dices[0]
        val s2 = dices[1]
        val s3 = dices[2]

        val sum = mutableMapOf<Int, Int>()

        (1..s1).forEach { one ->
            (1..s2).forEach { two ->
                (1..s3).forEach { three ->
                    if (sum.contains(one + two + three)) {
                        sum[one + two + three] = sum[one + two + three]!! + 1
                    } else {
                        sum[one + two + three] = 1
                    }
                }
            }
        }

        val frequencySum = sum.maxOf { it.value }
        val frequencyKey = sum.filterValues { it == frequencySum }.keys
        println(frequencyKey.min())
    }