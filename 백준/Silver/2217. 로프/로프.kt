fun main() {
        val count = readln().toInt()
        val ropes = mutableListOf<Int>()
        val weights = mutableListOf<Int>()

        repeat(count) {
            ropes.add(readln().toInt())
        }

        var size = ropes.size
        ropes.sort()
        ropes.forEach { rope ->
            weights.add(rope * size)
            --size
        }

        println(weights.max())
    }