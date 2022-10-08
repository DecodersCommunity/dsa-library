import java.util.Arrays;
public class BubbleSort{
    public static void main(String[] args) {
        int[] arr = {-10,-100,-23,0,1,2};
        bubble(arr);
        System.out.println(Arrays.toString(arr));
    }

    static void bubble(int[] arr) {
        boolean swapped;
        // run the steps n-1 times
        for(int i = 0; i < arr.length; i++){
            swapped = false;
            //for each step, max will come at the last respective index
            for(int j = 1; j < arr.length-i; j++){
                // swap if the item is smaller then previous item
                if(arr[j] < arr[j-1]){
                    //swap
                    int temp = arr[j];
                    arr[j] = arr[j-1];
                    arr[j-1] = temp;
                    swapped = true;
                }
            }
            // if you did not swapped for a particular value of i, it means the array is sorted stop the program
            if(!swapped) { //!false = true
                break;
            }
        }
    }
}