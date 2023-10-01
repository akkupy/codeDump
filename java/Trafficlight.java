//TrafficLight.java
public class TrafficLight {
  private String color;
  private int duration;

  public TrafficLight(String color, int duration) {
    this.color = color;
    this.duration = duration;
  }

  public void changeColor(String newColor) {
    color = newColor;
  }

  public boolean isRed() {
    return color.equals("red");
  }

  public boolean isGreen() {
    return color.equals("green");
  }

  public int getDuration() {
    return duration;
  }

  public void setDuration(int duration) {
    this.duration = duration;
  }
}//Main.java
 public class Main {
   public static void main(String[] args) {
     TrafficLight light = new TrafficLight("red", 30);

     System.out.println("The light is red: " + light.isRed());
     System.out.println("The light is green: " + light.isGreen());

     light.changeColor("green");

     System.out.println("The light is now green: " + light.isGreen());
     System.out.println("The light duration is: " + light.getDuration());
     light.setDuration(20);
     System.out.println("The light duration is now: " + light.getDuration());
   }
 }