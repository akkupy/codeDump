void main()
{
  //Literals
  var isCool=true;
  int k=1;
  "John";
  9.1;
  
  //varius ways to define string literals in dart
  String s1= 'single';
  String s2= "double";
  String s3= 'It\'s easy';
  String s4= "Its easy";
  String s5= 'This is going to be a very long string.' //+
              'This is just sample demo in dart programming launguage';
              //+ is optional 
  
  //string interpolation : use ["my name is $name"] instead of["my name is"+name]
  
  String name="Neha";
  //String message ="My name is $name"; //+ name;
  
  print("My name is $name");
  print("The number of characters in $name is ${name.length}.");
  // whatever is written in curly brackets is treated as expressions.
  
  int l=20;
  int b=10;
  print("The sum of $l and $b is ${l+b}");
  print("The area of rectangle with length $l and breadth $b is ${l*b}");
}
