fun checkPrime(number: Int): Boolean {
    if (number <= 1) {
        return false
    }
 
    for (i in 2 until number) {
        if (number % i == 0) {
            return false
        }
    }
 
    return true
}
 
fun main() {
    print("Enter the number to check if it is prime or not : ")
    val number = readLine()!!.toInt()
    if ( checkPrime(number) ) {
        println("$number is a prime number")
    } else {
        println("$number is not a prime number")
    }
}