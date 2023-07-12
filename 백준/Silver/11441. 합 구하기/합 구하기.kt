fun main() {
        val numbersCount = readln().toInt()
        val numbers = readln().split(" ").map { it.toInt() }
        val rangeSums = mutableListOf(0, numbers[0])

        (1 until numbersCount).forEach {
            rangeSums.add(rangeSums[it] + numbers[it])
        }

        val rangesCount = readln().toInt()
        val ranges = mutableListOf<List<Int>>()
        repeat(rangesCount) {
            ranges.add(readln().split(" ").map { it.toInt() })
        }

        val results = ranges.map { (start, end) ->
            rangeSums[end] - rangeSums[start - 1]
        }

        results.forEach { println(it) }
    }