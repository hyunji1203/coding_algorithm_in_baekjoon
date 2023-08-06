fun main() {
        val count = readln().toInt()
        val sizeOfParticipants = mutableListOf<List<Int>>()
        repeat(count) {
            val sizes = readln().split(" ").map { it.toInt() }
            sizeOfParticipants.add(sizes)
        }

        val results = mutableListOf<Int>()

        sizeOfParticipants.forEach { first ->
            var rank = 1
            sizeOfParticipants.forEach { second ->
                if (first[0] < second[0]) {
                    if (first[1] < second[1]) {
                        rank++
                    }
                }
            }
            results.add(rank)
        }

        println(results.joinToString(" "))
    }