fun main() {
        val expression = readln()
        var minusPosition = -1
        val operatorPosition = mutableListOf<Int>()
        var result = 0

        expression.forEachIndexed { index, it ->
            if (it == '-') {
                if (minusPosition == -1) minusPosition = index
                operatorPosition.add(index)
            }
            if (it == '+') {
                operatorPosition.add(index)
            }
        }

        var lastIndex = 0
        var dividedNumber = 0

        operatorPosition.forEach { index ->
            dividedNumber = expression.substring(lastIndex, index).toInt()
            lastIndex = index + 1

            if (index <= minusPosition || minusPosition == -1) {
                result += dividedNumber
            } else {
                result -= dividedNumber
            }
        }

        dividedNumber = expression.substring(lastIndex, expression.length).toInt()
        if (minusPosition == -1) {
            result += dividedNumber
        } else {
            result -= dividedNumber
        }
        
        println(result)
    }