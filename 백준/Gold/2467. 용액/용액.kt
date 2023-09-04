import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.absoluteValue

fun main() {
    val n = readln().toInt()
    val arr = readln().split(" ").map { it.toInt() }
    var minDiff = Int.MAX_VALUE
    var minPair = Pair(0, 0)
    for (i in arr.indices) {
        var l = i + 1
        var r = arr.size - 1
        while (l <= r) {
            val mid = (l + r) / 2
            val temp = arr[i] + arr[mid]
            if (temp < 0) {
                l = mid + 1
            } else {
                r = mid - 1
            }
            if (temp.absoluteValue <= minDiff) {
                minDiff = temp.absoluteValue
                minPair = Pair(arr[i], arr[mid])
            }
        }
    }
    println("${minPair.first} ${minPair.second}")
}
