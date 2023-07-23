fun main() {
        val testCase = readln().toInt()
        val numbers = readln().split(" ").map { it.toInt() }.sorted()
        var result = 0
        
        for (i in numbers.indices) {
            result += numbers[i] * (numbers.size - i)
        }
        
        println(result)
    }