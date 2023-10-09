import java.util.PriorityQueue

    fun main() {
        val n = readln().toInt()
        val array = PriorityQueue<Long>()

        repeat(n) {
            array.add(readln().toLong())
        }

        var answer = 0L
        while (array.size > 1) {
            val a = array.poll()
            val b = array.poll()
            val s = a + b
            array.add(s)
            answer += s
        }

        println(answer)
    }