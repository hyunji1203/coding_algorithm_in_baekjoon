data class Meeting(val start: Int, val end: Int)

    fun main() {
        val bufferedReader = System.`in`.bufferedReader()
        val bufferedWriter = System.out.bufferedWriter()
        val inputCount = bufferedReader.readLine().toInt()
        val meetings = mutableListOf<Meeting>()
        repeat(inputCount) {
            val (s, e) = bufferedReader.readLine().toString().split(" ").map { it.toInt() }
            meetings.add(Meeting(s, e))
        }
        meetings.sortWith(compareBy({ it.end }, { it.start }))
        var count = 1
        var e = meetings[0].end
        for (i in 1 until inputCount) {
            if (meetings[i].start >= e) {
                e = meetings[i].end
                count++
            }
        }
        bufferedWriter.write("$count")
        bufferedReader.close()
        bufferedWriter.close()
    }