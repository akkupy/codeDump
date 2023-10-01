import 'dart:io';

void main() {
  print("Enter Keyboard Input: ");

  // Read keyboard input
  String? input = stdin.readLineSync();
  
  // Print inserted value
  print("Inserted value: , $input");
}
