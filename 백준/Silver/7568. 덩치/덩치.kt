fun main() {
        val count = readln().toInt()
        val sizeOfParticipants = mutableListOf<List<Int>>()
        repeat(count) {
            val sizes = readln().split(" ").map { it.toInt() }
            sizeOfParticipants.add(sizes)
        }

        val results = mutableListOf<Int>()

        (0 until sizeOfParticipants.size).forEach { Firstindex ->
            var a = 1
            (0 until sizeOfParticipants.size).forEach { secondIndex ->
                if (sizeOfParticipants[Firstindex][0] < sizeOfParticipants[secondIndex][0]) {
                    if (sizeOfParticipants[Firstindex][1] < sizeOfParticipants[secondIndex][1]) {
                        a++
                    }
                }
            }
            results.add(a)
        }
        println(results.joinToString(" "))
    }