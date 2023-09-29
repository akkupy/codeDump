function isPalindrome(str) {
    const cleanStr = str.toLowerCase().replace(/[^a-zA-Z0-9]/g, "");
    const reversedStr = cleanStr.split("").reverse().join("");
    return cleanStr === reversedStr;
}

let testString = "A man, a plan, a canal, Panama!";
console.log(`${testString} is a palindrome: ${isPalindrome(testString)}`);
