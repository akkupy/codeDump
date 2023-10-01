class Secondmax {
    public static int fsm(int[] arr) {
        int max = Integer.MIN_VALUE;
        int Secmax = Integer.MIN_VALUE;
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] > max) {
                Secmax = max;
                max = arr[i];
            } else if (arr[i] > Secmax && arr[i] != max) {
                Secmax = arr[i];
            }
        }
        return Secmax;
    }

    public static void main(String[] args) {
        int[] arr = { 1, 35, 52, 5, 9, 66, 35 };
        int result = fsm(arr);
        System.out.println(result);
    }

}
