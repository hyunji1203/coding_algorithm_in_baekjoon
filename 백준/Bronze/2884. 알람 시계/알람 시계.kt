import java.time.LocalTime
import java.util.Scanner

fun main() = with(Scanner(System.`in`)) {
        val hour = nextInt()
        val minute = nextInt()
        val time = LocalTime.of(hour, minute).minusMinutes(45)
        println("${time.hour} ${time.minute}")
    }